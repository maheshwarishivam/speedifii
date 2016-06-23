<?php

//namespace application\model;

use application\model\CurlModel;

class IndexCurlModel extends CurlModel
{
    
    /**
     * IndexModel constructor.
     */
    public function __construct()
    {
        parent::__construct();
    }
    
    public function userList($data){
        
        $this->curl->curlReq->setUrl($data['url']);
        $this->curl->curlReq->setMethod($data['method']);
        $this->curl->curlReq->setHeaders($data['headers']);
        $this->curl->call();
        
        return $this->curl->curlRes->toArray();
    }

    
    public function userDetail($data){
        
        $this->curl->curlReq->setUrl($data['url']);
        $this->curl->curlReq->setMethod($data['method']);
        $this->curl->curlReq->setHeaders($data['headers']);
        $this->curl->call();
        
        return $this->curl->curlRes->toArray();
    }    

    
    public function updateUserDetail($data){
        
        $this->curl->curlReq->setUrl($data['url']);
        $this->curl->curlReq->setMethod($data['method']);
        $this->curl->curlReq->setHeaders($data['headers']);
        $this->curl->curlReq->setReqType($data['reqType']);
        $this->curl->curlReq->setRawBody($data['rawbody']);
        $this->curl->call();
        
        return $this->curl->curlRes->toArray();
    } 

    
    public function userDelete($data){
        
        $this->curl->curlReq->setUrl($data['url']);
        $this->curl->curlReq->setMethod($data['method']);
        $this->curl->curlReq->setHeaders($data['headers']);
        $this->curl->call();
        
        return $this->curl->curlRes->toArray();
    }     

    
    public function addUser($data){
        
        $this->curl->curlReq->setUrl($data['url']);
        $this->curl->curlReq->setMethod($data['method']);
        $this->curl->curlReq->setHeaders($data['headers']);
        $this->curl->curlReq->setReqType($data['rawType']);
        $this->curl->curlReq->setRawBody($data['rawBody']);
        $this->curl->call();
        
        return $this->curl->curlRes->toArray();
    } 
    
}


/* EOF */