<?php

namespace speedifii\model;


/**
 * Class BaseModel
 * @package speedifii\model
 */
 abstract class BaseModel
{
    
    /**
     * BaseModel constructor.
     */
    public function __construct()
    {
        
    }
    
   public abstract function getConnection();
    
    public abstract function closeConnection();
}





/* EOF */