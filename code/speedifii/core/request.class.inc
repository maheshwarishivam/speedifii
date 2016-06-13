<?php

namespace speedifii\core;
/**
 * Class Request
 * @package speedifii\core
 */
class Request
{

    /**
     * @var array reqHeaders
     */
    private $headers;

    /**
     * @var string reqBody
     */
    private $body;

    /**
     * @var string reqMethod
     */
    private $method;

    /**
     * @var array reqCookies
     */
    private $cookies;

    /**
     * @var string $contentType
     */
    private $contentType;

    /**
     * @var string $contentLength
     */
    private $contentLength;

    /**
     * @var array $files
     */
    private $files;

    /**
     * Request constructor.
     */
    public function __construct()
    {
        $this->headers = $this->parseRequestHeaders();
        $this->method = $_SERVER['REQUEST_METHOD'];
        $this->cookies = $_COOKIE;
        $this->contentLength = isset($_SERVER['CONTENT_LENGTH']) ? $_SERVER['CONTENT_LENGTH'] : '0';
        $this->contentType = isset($_SERVER['CONTENT_TYPE']) ? $_SERVER['CONTENT_TYPE'] : NULL;

        //Parse request Body
        if ($this->method == 'POST') {
            if (strpos($this->contentType, 'multipart/form-data') !== false || strpos($this->contentType, 'application/x-www-form-urlencoded') !== false) {
                $this->body = array_merge($_POST, $_GET);
            } else {
                $reqArr = json_decode(file_get_contents('php://input'), true);
                if ($reqArr) {
                    $this->body = array_merge($reqArr, $_GET);
                } else {
                    $this->body = $_GET;
                }
            }
        } else if ($this->method == 'GET') {
            $this->body = $_GET;
        } else {
            $this->body = array_merge($this->parseNonGetPostRequest(), $_GET);
        }

        //Parse Request Files
        $this->files = $_FILES;
    }

    /**
     * @return array reqHeaders
     */
    public function getHeaders()
    {
        return $this->headers;
    }

    /**
     * @return array reqBody
     */
    public function getBody()
    {
        return $this->body;
    }

    /**
     * @return string reqMethod
     */
    public function getMethod()
    {
        return $this->method;
    }

    /**
     * @return array reqCookies
     */
    public function getCookies()
    {
        return $this->cookies;
    }

    /**
     * @return string
     */
    public function getContentType()
    {
        return $this->contentType;
    }

    /**
     * @return string
     */
    public function getContentLength()
    {
        return $this->contentLength;
    }

    /**
     * @return array
     */
    public function getFiles()
    {
        return $this->files;
    }

    /**
     * Parse Request Headers
     * @return array
     */
    private function parseRequestHeaders()
    {
        $headers = array();
        foreach ($_SERVER as $key => $value) {
            if (substr($key, 0, 5) <> 'HTTP_') {
                continue;
            }
            $header = str_replace(' ', '-', ucwords(str_replace('_', ' ', strtolower(substr($key, 5)))));
            if ($header != 'Cookie') {
                $headers[$header] = $value;
            }
        }
        return $headers;
    }

    /**
     * Parse request body and files if request is not GET or POST
     * @return array
     */
    private function parseNonGetPostRequest()
    {
        /* PUT data comes in on the stdin stream */
        $putdata = fopen("php://input", "r");

        /* Open a file for writing */
        // $fp = fopen("myputfile.ext", "w");

        $raw_data = '';

        /* Read the data 1 KB at a time
           and write to the file */
        while ($chunk = fread($putdata, 1024))
            $raw_data .= $chunk;

        /* Close the streams */
        fclose($putdata);

        // Fetch content and determine boundary
        $boundary = substr($raw_data, 0, strpos($raw_data, "\r\n"));

        if (empty($boundary)) {
            if (strpos($this->contentType, 'multipart/form-data') !== false || strpos($this->contentType, 'application/x-www-form-urlencoded') !== false) {
                parse_str($raw_data, $data);
                return $data;
            } else {
                $dataArr = json_decode($raw_data, true);
                if (is_array($dataArr)) {
                    return $dataArr;
                } else {
                    return array();
                }
            }
        }

        // Fetch each part
        $parts = array_slice(explode($boundary, $raw_data), 1);
        $data = array();

        foreach ($parts as $part) {
            // If this is the last part, break
            if ($part == "--\r\n") break;

            // Separate content from headers
            $part = ltrim($part, "\r\n");
            list($raw_headers, $body) = explode("\r\n\r\n", $part, 2);

            // Parse the headers list
            $raw_headers = explode("\r\n", $raw_headers);
            $headers = array();
            foreach ($raw_headers as $header) {
                list($name, $value) = explode(':', $header);
                $headers[strtolower($name)] = ltrim($value, ' ');
            }

            // Parse the Content-Disposition to get the field name, etc.
            if (isset($headers['content-disposition'])) {
                $filename = null;
                $tmp_name = null;
                preg_match(
                    '/^(.+); *name="([^"]+)"(; *filename="([^"]+)")?/',
                    $headers['content-disposition'],
                    $matches
                );
                if (!empty($matches)) {
                    list(, $type, $name) = $matches;
                    //Parse File
                    if (isset($matches[4])) {
                        //if labeled the same as previous, skip
                        if (isset($_FILES[$matches[2]])) {
                            continue;
                        }

                        //get filename
                        $filename = $matches[4];

                        //get tmp name
                        $filename_parts = pathinfo($filename);
                        $tmp_name = tempnam(ini_get('upload_tmp_dir'), $filename_parts['filename']);

                        //populate $_FILES with information, size may be off in multibyte situation
                        $_FILES[$matches[2]] = array(
                            'error' => 0,
                            'name' => $filename,
                            'tmp_name' => $tmp_name,
                            'size' => strlen($body),
                            'type' => $value
                        );

                        //place in temporary directory
                        file_put_contents($tmp_name, $body);
                    } //Parse Field
                    else {
                        $data[$name] = substr($body, 0, strlen($body) - 2);
                    }
                }
            }

        }
        return $data;
    }

}


/* EOF */