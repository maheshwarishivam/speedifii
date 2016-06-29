<?php

namespace speedifii\core;
/**
 * Class Response
 * @package speedifii\core
 */
class Response
{
    /**
     * @var array
     */
    private $headers;

    /**
     * Associative array containing the data to be sent back as JSON or to be sent to View
     * @var array
     */
    private $body;

    /**
     * @var array
     */
    private $cookies;

    /**
     * @var int
     */
    private $status;
    
    /**
     * @var String
     */
    private $rawBody;
    
    /**
     * Response format to be sent.
     *
     * Should be one of HTML / JSON. Defaults to HTML
     *
     * If response format is JSON, UTF-8 Special Chars will be preserved
     * @var string
     */
    private $responseFormat;

    /**
     * Response constructor.
     */
    public function __construct()
    {
        $this->headers = array();
        $this->body = array();
        $this->cookies = array();
        $this->status = 200;
        $this->rawBody = '';
        $this->responseFormat = 'HTML';
    }

    /**
     * Add or Update a header to be sent
     * @param string $header
     * @param string $value
     * @param bool $replace
     */
    public function setHeader($header, $value, $replace = true)
    {
        $this->headers[$header] = array(
            'value' => $value,
            'replace' => $replace
        );
    }

    /**
     * Remove the given header from being sent
     * @param string $header
     */
    public function removeHeader($header)
    {
        if (isset($this->headers[$header])) {
            unset($this->headers[$header]);
        }
    }

    /**
     * Set or update the response body.
     *
     * If $body is not an array, it will be ignored.
     * Set to NULL to not send any response body.
     * @param array $body
     */
    public function setBody($body)
    {
        if ($body == NULL || is_array($body)) {
            $this->body = $body;
        }
    }

    /**
     * Add of Update a response cookie
     * @param string $cookieName
     * @param string $cookieValue
     * @param int $cookieExpire
     * @param string $cookiepath
     * @param string $cookieDomain
     * @param bool $cookieSecure
     * @param bool $cookieHttpOnly
     */
    public function setCookie($cookieName, $cookieValue, $cookieExpire = 0, $cookiepath = '', $cookieDomain = '', $cookieSecure = false, $cookieHttpOnly = false)
    {
        $this->cookies[$cookieName] = array(
            'value' => $cookieValue,
            'expire' => $cookieExpire,
            'path' => $cookiepath,
            'domain' => $cookieDomain,
            'secure' => $cookieSecure,
            'httponly' => $cookieHttpOnly
        );
    }

    /**
     * Delete a cookie
     * @param string $cookieName
     */
    public function removeCookie($cookieName)
    {
        if (isset($this->cookies[$cookieName])) {
            $this->setCookie($cookieName, false);
        }
    }

    /**
     * @param int $status
     */
    public function setStatus($status)
    {
        $this->status = $status;
    }

    /**
     * @param string $responseFormat
     */
    public function setResponseFormat($responseFormat = 'HTML')
    {
        $this->responseFormat = ($responseFormat == 'HTML' || $responseFormat == 'JSON') ? $responseFormat : 'HTML';
    }

    /**
     * @return array
     */
    public function getHeaders()
    {
        return $this->headers;
    }

    /**
     * @return array
     */
    public function getBody()
    {
        return $this->body;
    }

    /**
     * @return array
     */
    public function getCookies()
    {
        return $this->cookies;
    }

    /**
     * @return int
     */
    public function getStatus()
    {
        return $this->status;
    }

    /**
     * @return String
     */
    public function getRawBody()
    {
        return $this->rawBody;
    }

    /**
     * @param String $rawBody
     */
    public function setRawBody($rawBody)
    {
        $this->rawBody = $rawBody;
    }

    /**
     * Retuns the Format in which response should be sent.
     *
     * Can be one of HTML / JSON
     * @return string
     */
    public function getResponseFormat()
    {
        return $this->responseFormat;
    }

    /**
     * Returns current response object as array
     * @return array
     */
    public function toArray()
    {
        return array(
            'headers' => $this->headers,
            'body' => $this->body,
            'cookies' => $this->cookies,
            'rawBody' => $this->rawBody,
            'status' => $this->status,
            'responseFormat' => $this->responseFormat
        );
    }

    /**
     * Returns the current response as JSON String
     * @return string
     */
    public function toJSON()
    {
        return json_encode($this->toArray());
    }

    /**
     * Returns the current response as JSON String
     * @return string
     */
    public function __toString()
    {
        return json_encode($this->toArray());
    }
}


/* EOF */