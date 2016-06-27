<?php

namespace speedifii\libraries\curl;

/**
 * Class Curl
 * @package speedifii\libraries\curl
 */
class Curl {
    
    /**
     * @var CurlRequest
     */
    private $curlReq;
    
    
    /**
     * @var CurlResponse
     */
    private $curlRes;
    
    
    /**
     * @return CurlRequest Object
     */
    public function getReq()
    {
        return $this->curlReq;
    }
    
    
    /**
     * @return CurlResponse Object
     */
    public function getRes()
    {
        return $this->curlRes;
    }
    
    /**
     * @var CurlRequest String
     */
    public function setUrl($url){
        $this->curlReq->setUrl($url);
    }
    
    /**
     * @var CurlRequest String
     */
    public function setMethod($url){
        $this->curlReq->setMethod($url);
    }
    
    /**
     * @var CurlRequest Array
     */
    public function setHeaders($url){
        $this->curlReq->setHeaders($url);
    }
    
    /**
     * @var CurlRequest String
     */
    public function setReqType($url){
        $this->curlReq->setReqType($url);
    }
    
    /**
     * @var CurlRequest String
     */
    public function setRawBody($url){
        $this->curlReq->setRawBody($url);
    }
    
    /**
     * @return CurlResponse Array
     */
    public function toArray(){
        return $this->curlRes->toArray();
    }
    
    /**
     * @var CurlRequest JSON
     */
    public function toJSON(){
        return $this->curlRes->toJSON();
    }

    /**
     * Curl constructor, Create CurlRequest and CurlResponse Object.
     */
    function __construct()
    {
        $this->curlReq = new CurlRequest();
        $this->curlRes = new CurlResponse();
    }
    
    
    /**
     * Get details of CurlRequest Object.
     * Hit Curl function.
     * Set Curl response details in CurlResponse Object.
     */
    public final function call(){ 
        
        $method = $this->curlReq->getMethod();
        
        switch($method){
            case 'GET': 
                $this->getCall();	
                break;

            case 'POST': 
                $this->postCall();
                break;

            case 'PUT': 
                $this->putCall();
                break;

            case 'DELETE': 
                $this->deleteCall();
                break;

            case 'PATCH': 
                $this->patchCall();
                break;
        }
    }
    
    
    /**
     * Get details of CurlRequest Object.
     * Hit Curl function for getting Curl response.
     * Method type is GET.
     * Set Curl response details in CurlResponse Object.
     */
    private final function getCall(){  

        $headers = $this->curlReq->getHeaders();
        $url     = $this->curlReq->getUrl(); 
        $cookies = $this->curlReq->getCookies();

        if(count( $cookies )>0 ){
            foreach($cookies as $row){
                $headers[] = $row;
            }
        }
        
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_HEADER, 1);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt($ch, CURLOPT_FAILONERROR, 0);
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT_MS, 10000);
        curl_setopt($ch, CURLOPT_TIMEOUT_MS, 10000);
        $http_result = curl_exec($ch);
        $contentType = curl_getinfo($ch, CURLINFO_CONTENT_TYPE);
        $length = curl_getinfo($ch, CURLINFO_CONTENT_LENGTH_DOWNLOAD);
       	$status = curl_getinfo($ch, CURLINFO_HTTP_CODE);
        $err_msg = curl_error($ch);
        $err_num = curl_errno($ch);
        curl_close($ch);
        
        if ($http_result === false ) {

            $content = '{"error" : "1", "messages": "' . $err_num."--".$err_msg . '"}';
			
        } else { 
			
            preg_match_all('/^Set-Cookie:\s*([^;]*)/mi', $http_result, $matches);
            $cookies = array();
            
            foreach ($matches[1] as $item) {
                parse_str($item, $cookie);
                $cookies = array_merge($cookies, $cookie);
            }
			
            /*list($headers, $content) = explode("\r\n\r\n", $http_result, 2); */
            
            $start_m = strpos($http_result, '[');
            $start = strpos($http_result, '{');

            if(($start_m < $start) && !empty($start_m)){

                $body = substr($http_result, $start_m);
                $headers = substr($http_result, 0, $start_m);

            } else if(!empty($start)) {

                $body = substr($http_result, $start);
                $headers = substr($http_result, 0, $start);
            }
            
        }
        
        $this->curlRes->setStatus($status);
        $this->curlRes->setHeaders($headers);
        $this->curlRes->setBody($body); 
        $this->curlRes->setContentType($contentType);
        $this->curlRes->setRawBody($http_result);
        $this->curlRes->setLength($length);
        $this->curlRes->setCookies($cookies);
    }
    
    
    /**
     * Get details of CurlRequest Object.
     * Hit Curl function for update deatils.
     * Method type is POST.
     * Set Curl response details in CurlResponse Object.
     */
    private final function postCall(){
        $headers = $this->curlReq->getHeaders();
        $url     = $this->curlReq->getUrl(); 
        $cookies = $this->curlReq->getCookies();
        $resType = $this->curlReq->getReqType();
        
        $body = ( $resType != 'raw') ? $this->curlReq->getBody():$this->curlReq->getRawBody();
        
        if(count( $cookies )>0 ){
            foreach($cookies as $row){
                $headers[] = $row;
            }
        }
	
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_HEADER, 1);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt($ch, CURLOPT_FAILONERROR, 0);
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
        curl_setopt($ch, CURLOPT_POST, 1 );
        curl_setopt($ch, CURLOPT_POSTFIELDS, $body);
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT_MS, 10000);
        curl_setopt($ch, CURLOPT_TIMEOUT_MS, 10000);
        $http_result = curl_exec($ch);
        $contentType = curl_getinfo($ch, CURLINFO_CONTENT_TYPE);
        $length = curl_getinfo($ch, CURLINFO_CONTENT_LENGTH_DOWNLOAD);
       	$status = curl_getinfo($ch, CURLINFO_HTTP_CODE);
        $err_msg = curl_error($ch);
        $err_num = curl_errno($ch);
        curl_close($ch);
      	
        if ($http_result === false ) {

            $content = '{"error" : "1", "messages": "' . $err_num."--".$err_msg . '"}';
			
        } else { 
			
            preg_match_all('/^Set-Cookie:\s*([^;]*)/mi', $http_result, $matches);
            $cookies = array();
            
            foreach ($matches[1] as $item) {
                parse_str($item, $cookie);
                $cookies = array_merge($cookies, $cookie);
            }
			
            /*list($headers, $content) = explode("\r\n\r\n", $http_result, 2); */
            
            $start_m = strpos($http_result, '[');
            $start = strpos($http_result, '{');

            if(($start_m < $start) && !empty($start_m)){

                $body = substr($http_result, $start_m);
                $headers = substr($http_result, 0, $start_m);

            } else if(!empty($start)) {

                $body = substr($http_result, $start);
                $headers = substr($http_result, 0, $start);
            }
		
        }

        $this->curlRes->setStatus($status);
        $this->curlRes->setHeaders($headers);
        $this->curlRes->setBody($body); 
        $this->curlRes->setContentType($contentType);
        $this->curlRes->setRawBody($http_result);
        $this->curlRes->setLength($length);
        $this->curlRes->setCookies($cookies);
    }
    
    
    /**
     * Get details of CurlRequest Object.
     * Hit Curl function for update deatils.
     * Method type is PUT.
     * Set Curl response details in CurlResponse Object.
     */
    private final function putCall(){
        
        $headers = $this->curlReq->getHeaders();
        $url     = $this->curlReq->getUrl(); 
        $cookies = $this->curlReq->getCookies();
        $resType = $this->curlReq->getReqType();
        
        $body = ( $resType != 'raw') ? $this->curlReq->getBody():$this->curlReq->getRawBody();
        
        if(count( $cookies )>0 ){
            foreach($cookies as $row){
                $headers[] = $row;
            }
        }
		
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_HEADER, 1);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt($ch, CURLOPT_FAILONERROR, 0);
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_setopt($ch, CURLOPT_POSTFIELDS, $body); 
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT_MS, 10000);
        curl_setopt($ch, CURLOPT_TIMEOUT_MS, 10000);
        $http_result = curl_exec($ch);
        $contentType = curl_getinfo($ch, CURLINFO_CONTENT_TYPE);
        $length = curl_getinfo($ch, CURLINFO_CONTENT_LENGTH_DOWNLOAD);
       	$status = curl_getinfo($ch, CURLINFO_HTTP_CODE);
        $err_msg = curl_error($ch);
        $err_num = curl_errno($ch);
        curl_close($ch);
      	
        if ($http_result === false ) {

            $content = '{"error" : "1", "messages": "' . $err_num."--".$err_msg . '"}';
			
        } else { 
			
            preg_match_all('/^Set-Cookie:\s*([^;]*)/mi', $http_result, $matches);
            $cookies = array();
            
            foreach ($matches[1] as $item) {
                parse_str($item, $cookie);
                $cookies = array_merge($cookies, $cookie);
            }
			
            /*list($headers, $content) = explode("\r\n\r\n", $http_result, 2); */
            
            $start_m = strpos($http_result, '[');
            $start = strpos($http_result, '{');
            
            if(($start_m < $start) && !empty($start_m)){

                $body = substr($http_result, $start_m);
                $headers = substr($http_result, 0, $start_m);

            } else if(!empty($start)) {

                $body = substr($http_result, $start);
                $headers = substr($http_result, 0, $start);
            }
        }
        $this->curlRes->setStatus($status);
        $this->curlRes->setHeaders($headers);
        $this->curlRes->setBody($body); 
        $this->curlRes->setContentType($contentType);
        $this->curlRes->setRawBody($http_result);
        $this->curlRes->setLength($length);
        $this->curlRes->setCookies($cookies);
    }
    
    
    /**
     * Get details of CurlRequest Object.
     * Hit Curl function for delete data.
     * Method type is DELETE.
     * Set Curl response details in CurlResponse Object.
     */
    private final function deleteCall(){
        $headers = $this->curlReq->getHeaders();
        $url     = $this->curlReq->getUrl(); 
        $cookies = $this->curlReq->getCookies();
        $resType = $this->curlReq->getReqType();
        
        $body = ( $resType != 'raw') ? $this->curlReq->getBody():$this->curlReq->getRawBody();
        
        if(count( $cookies )>0 ){
            foreach($cookies as $row){
                $headers[] = $row;
            }
        }
		
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_HEADER, 1);
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "DELETE");
        curl_setopt($ch, CURLOPT_POSTFIELDS, $body);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT_MS, 10000);
        curl_setopt($ch, CURLOPT_TIMEOUT_MS, 10000);
        $http_result = curl_exec($ch);
        $contentType = curl_getinfo($ch, CURLINFO_CONTENT_TYPE);
        $length = curl_getinfo($ch, CURLINFO_CONTENT_LENGTH_DOWNLOAD);
       	$status = curl_getinfo($ch, CURLINFO_HTTP_CODE);
        $err_msg = curl_error($ch);
        $err_num = curl_errno($ch);
        curl_close($ch);
      	
        if ($http_result === false ) {

            $content = '{"error" : "1", "messages": "' . $err_num."--".$err_msg . '"}';
			
        } else { 
			
            preg_match_all('/^Set-Cookie:\s*([^;]*)/mi', $http_result, $matches);
            $cookies = array();
            
            foreach ($matches[1] as $item) {
                parse_str($item, $cookie);
                $cookies = array_merge($cookies, $cookie);
            }
			
            /*list($headers, $content) = explode("\r\n\r\n", $http_result, 2); */
            
            $start_m = strpos($http_result, '[');
            $start = strpos($http_result, '{');

            if(($start_m < $start) && !empty($start_m)){

                $body = substr($http_result, $start_m);
                $headers = substr($http_result, 0, $start_m);

            } else if(!empty($start)) {

                $body = substr($http_result, $start);
                $headers = substr($http_result, 0, $start);
            }
		
        }
		
        $this->curlRes->setStatus($status);
        $this->curlRes->setHeaders($headers);
        $this->curlRes->setBody($body); 
        $this->curlRes->setContentType($contentType);
        $this->curlRes->setRawBody($http_result);
        $this->curlRes->setLength($length);
        $this->curlRes->setCookies($cookies);
    }
    
    
    /**
     * Get details of CurlRequest Object.
     * Hit Curl function for delete data.
     * Method type is DELETE.
     * Set Curl response details in CurlResponse Object.
     */
    private final function patchCall(){
        $headers = $this->curlReq->getHeaders();
        $url     = $this->curlReq->getUrl(); 
        $cookies = $this->curlReq->getCookies();
        $resType = $this->curlReq->getReqType();
        
        $body = ( $resType != 'raw') ? $this->curlReq->getBody():$this->curlReq->getRawBody();
        
        if(count( $cookies )>0 ){
            foreach($cookies as $row){
                $headers[] = $row;
            }
        }
		
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_HEADER, 1);
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "PATCH");
        curl_setopt($ch, CURLOPT_POSTFIELDS, $body);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT_MS, 10000);
        curl_setopt($ch, CURLOPT_TIMEOUT_MS, 10000);
        $http_result = curl_exec($ch);
        $contentType = curl_getinfo($ch, CURLINFO_CONTENT_TYPE);
        $len = curl_getinfo($ch, CURLINFO_CONTENT_LENGTH_DOWNLOAD);
       	$status = curl_getinfo($ch, CURLINFO_HTTP_CODE);
        $err_msg = curl_error($ch);
        $err_num = curl_errno($ch);
        curl_close($ch);
      	
        if ($http_result === false ) {

            $content = '{"error" : "1", "messages": "' . $err_num."--".$err_msg . '"}';
			
        } else { 
			
            preg_match_all('/^Set-Cookie:\s*([^;]*)/mi', $http_result, $matches);
            $cookies = array();
            
            foreach ($matches[1] as $item) {
                parse_str($item, $cookie);
                $cookies = array_merge($cookies, $cookie);
            }
			
            /*list($headers, $content) = explode("\r\n\r\n", $http_result, 2); */
            
            $start_m = strpos($http_result, '[');
            $start = strpos($http_result, '{');

            if(($start_m < $start) && !empty($start_m)){

                $body = substr($http_result, $start_m);
                $headers = substr($http_result, 0, $start_m);

            } else if(!empty($start)) {

                $body = substr($http_result, $start);
                $headers = substr($http_result, 0, $start);
            }
		
        }
		
        $this->curlRes->setStatus($status);
        $this->curlRes->setHeaders($headers);
        $this->curlRes->setBody($content); 
        $this->curlRes->setContentType($contentType);
        $this->curlRes->setRawBody($http_result);
        $this->curlRes->setLength($len);
        $this->curlRes->setCookies($cookies);
    }
}
