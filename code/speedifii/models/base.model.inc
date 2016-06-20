<?php

namespace speedifii\model;

use application\model\curlModel;
use application\model\mysqlModel;

/**
 * Class BaseModel
 * @package speedifii\model
 */
 abstract class BaseModel
{
    
    /**
     * @var request
     */
    protected $sql_db = null;

    /**
     * @var response
     */
    protected $curl = null;
    
    /**
     * @var request
     */
    protected $model_method = 'mysql';
    
    
    function setModelMethod( $method ){
        $this->model_method = $method;
    }
    
    /**
     * BaseModel constructor.
     */
    protected function __construct()
    {
        //Create Request and Response Objects
        $this->curl = new curlModel();
        $this->sql_db = new mysqlModel();
    }
    
    protected final function get()
    {
        
    }
    
    protected final function close()
    {
        
    }
}





/* EOF */