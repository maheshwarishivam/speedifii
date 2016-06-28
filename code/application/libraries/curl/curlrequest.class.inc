<?php

namespace speedifii\libraries\curl;

/**
 * Class CurlRequest
 * @package speedifii\libraries\curl
 */
class CurlRequest {
    
    /**
     * @var Curl URL
     */
    private $url;
    
    
    /**
     * @var Curl Method
     */
    private $method;
    
    
    /**
     * @var Curl Body in Array
     */
    private $body = array();
    
    
    /**
     * @var Curl Cookies in Array
     */
    private $cookies;
    
    
    /**
     * @var Curl Headers
     */
    private $headers;
    
    
    /**
     * @var Curl Request Type
     */
    private $reqType;
    
    
    /**
     * @var Curl Raw Body
     */
    private $rawBody;
    
    
    /**
     * @return Request Url
     */
    public function getUrl()
    {
        return $this->url;
    }
    
    
    /**
     * @return Request Method
     */
    public function getMethod()
    {
        return $this->method;
    }
    
    
    /**
     * @return Request Body
     */
    public function getBody()
    {
        return $this->body;
    }
    
    
    /**
     * @return Request Cookies
     */
    public function getCookies()
    {
        return $this->cookies;
    }
    
    
    /**
     * @return Request Headers
     */
    public function getHeaders()
    {
        return $this->headers;
    }
    
    
    /**
     * @return Request Type
     */
    public function getReqType()
    {
        return $this->reqType;
    }
    
    
    /**
     * @return Request Raw Body
     */
    public function getRawBody()
    {
        return $this->rawBody;
    }
    
    
    /**
     * @param Set Url
     */
    public function setUrl($url)
    { 
        $this->url = $url;
    }
    
    /**
     * @param Set Method
     */
    public function setMethod($method)
    {
        $this->method = $method;
    }
    
    /**
     * @param Set Body
     */
    public function setBody($body)
    { 
        $this->body = $body;
    }
    
    /**
     * @param Set Cookies
     */
    public function setCookies($cookies)
    {
        $this->cookies = $cookies;
    }
    
    /**
     * @param Set Headers
     */
    public function setHeaders($headers)
    {
        $this->headers = $headers;
    }
    
    /**
     * @param Set Request Type
     */
    public function setReqType($reqType)
    {
        $this->reqType = $reqType;
    }
    
    /**
     * @param Set Raw Body
     */
    public function setRawBody($rawBody)
    {
        $this->rawBody = $rawBody;
    }
    
    
    /**
     * Set All variables as Array.
     * @return Array
     */
    public function toArray()
    {
        return array(
            'url' => $this->url,
            'method' => $this->method,
            'body' => $this->body,
            'cookies' => $this->cookies,
            'headers' => $this->headers,
            'reqType' => $this->reqType,
            'rawBody' => $this->rawBody
        );
    }
    
    
    /**
     * Set All variables as Array.
     * @return JSON Encoded.
     */
    public function toJSON()
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
