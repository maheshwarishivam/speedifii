<?php

namespace application\model;

use speedifii\model\BaseModel;
use speedifii\libraries\curl\Curl;

Class CurlModel extends BaseModel
{
    
    public $curl = null;
    
    /**
     * CurlModel constructor.
     */
    public function __construct()
    {
        parent::__construct();
        
        $this->getConnection();
    }
    
    
    public function getConnection(){
        $this->curl = new Curl();
    }
    
    
    public function closeConnection(){
        
    }
    
}

/* EOF */