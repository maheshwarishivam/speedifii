<?php

//namespace application\model;

use application\model\curlModel;

class Index_curl extends curlModel
{
    
    /**
     * IndexModel constructor.
     */
    public function __construct()
    {
        parent::__construct();
    }
    
    public function user_list($table, $data){
        
        $headers = array(
            'Content-Type:application/json',
            'APIKey:62f7b668181f54c08191cf62a2373ff7',
            'AuthToken:396dbaa0de83aeb3971c6b6cdca35a0f'
        );
        
        $this->curl->curlReq->setUrl('http://api.raccoon.dev.canbrand.in/company/users?page=1&limit=100');
        $this->curl->curlReq->setMethod('GET');
        //$this->curl->curlReq->setBody('lll');
        //$this->curl->curlReq->setCookies('lll');
        $this->curl->curlReq->setHeaders($headers);
        //$this->curl->curlReq->setReqType('lll');
        $this->curl->call();
        
        return $this->curl->curlRes->toArray();
    }
    
    
}


/* EOF */