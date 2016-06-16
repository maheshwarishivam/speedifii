<?php

namespace speedifii\libraries\curl;

/**
 * Class CurlRequest
 * @package speedifii\libraries\curl
 */
class CurlResponse {
    
    /**
     * @var Curl Response Status
     */
    private $status;
    
    
    /**
     * @var Curl Response Headers
     */
    private $headers;
    
    
    /**
     * @var Curl Response Body
     */
    private $body = array();
    
    
    /**
     * @var Curl Response Cookies
     */
    private $cookies;
    
    
    /**
     * @var Curl Response Content-Type
     */
    private $contentType;
    
    
    /**
     * @var Curl Response Length
     */
    private $length;
    
    
    /**
     * @var Curl Response Raw Body
     */
    private $rawBody;
    
    
    /**
     * @return Curl Status
     */
    public function getStatus()
    {
        return $this->status;
    }
    
    
    /**
     * @return Curl Headers
     */
    public function getHeaders()
    {
        return $this->headers;
    }
    
    
    /**
     * @return Curl Body
     */
    public function getBody()
    {
        return $this->body;
    }
    
    
    /**
     * @return Curl Cookies
     */
    public function getCookies()
    {
        return $this->cookies;
    }
    
    
    /**
     * @return Curl Content-Type
     */
    public function getContentType()
    {
        return $this->contentType;
    }
    
    
    /**
     * @return Curl Length
     */
    public function getLength()
    {
        return $this->length;
    }
    
    
    /**
     * @return Curl Raw Body
     */
    public function getRawBody()
    {
        return $this->rawBody;
    }
    
    
    /**
     * @param Set Curl Status
     */
    public function setStatus($status)
    {
        $this->status = $status;
    }
    
    
    /**
     * @param Set Curl Headers
     */
    public function setHeaders($headers)
    {
        $this->headers = $headers;
    }
    
    
    /**
     * @param Set Curl Body
     */
    public function setBody($body)
    {
        $this->body = $body;
    }
    
    
    /**
     * @param Set Curl Cookies
     */
    public function setCookies($cookies)
    {
        $this->cookies = $cookies;
    }
    
    
    /**
     * @param Set Curl Content-Type
     */
    public function setContentType($contentType)
    {
        $this->contentType = $contentType;
    }
    
    
    /**
     * @param Set Curl Length
     */
    public function setLength($length)
    {
        $this->length = $length;
    }
    
    
    /**
     * @param Set Curl Raw Body
     */
    public function setRawBody($rawBody)
    {
        $this->rawBody = $rawBody;
    }
    
    
    /**
     * Set All variables as Array.
     * @return Array
     */
    private function toArray()
    {
        return array(
            'headers' => $this->headers,
            'body' => $this->body,
            'cookies' => $this->cookies,
            'status' => $this->status,
            'contentType' => $this->contentType,
            'length' => $this->length,
            'rawBody' => $this->rawBody
        );
    }
    
    
    /**
     * Set All variables as Array.
     * @return JSON Encoded.
     */
    private function toJSON()
    {
        return json_encode($this->toArray());
    }
    
    
    /**
     * Set All variables as Array.
     * @return JSON Encoded.
     */
    public function __toString() {
        return $this->toJSON();
    }
}
