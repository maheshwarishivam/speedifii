<?php

namespace application\model;

use speedifii\model\BaseModel;
use speedifii\libraries\curl\Curl;

Class curlModel extends BaseModel
{
    
    /**
     * BaseModel constructor.
     */
    public function __construct()
    {
        $this->curl = new Curl();
       
    }
    
}


/* EOF */