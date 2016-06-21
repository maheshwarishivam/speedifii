<?php

namespace speedifii\model;


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
    
   // protected $sql_lib = null;

    /**
     * @var response
     */
    protected $curl = null;
    
    /**
     * BaseModel constructor.
     */
    protected function __construct()
    {
        
    }
    
    protected final function get()
    {
        
    }
    
    protected final function close()
    {
        
    }
}





/* EOF */