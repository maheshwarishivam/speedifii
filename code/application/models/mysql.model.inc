<?php

namespace application\model;

use speedifii\model\BaseModel;
use speedifii\libraries\mysql\Mysql;

Class MysqlModel extends BaseModel
{
    /**
     * @var Mysql Object
     */
    public $sql_db = null;


    public function __construct() 
    { 
        
        $this->getConnection();
        
    }
    
    public function getConnection(){
        $this->DB_SERVER        = $GLOBALS['config']['database']['host'];
        $this->DB_USER          = $GLOBALS['config']['database']['username'];
        $this->DB_PASSWORD      = $GLOBALS['config']['database']['password'];
        $this->DB               = $GLOBALS['config']['database']['database_name'];
        $this->PORT             = $GLOBALS['config']['database']['port'];
        
        $this->sql_db = new Mysql($this->DB_SERVER, $this->DB_USER, $this->DB_PASSWORD, $this->DB);
    }
    
    public function closeConnection(){
        
    }
    
}


/* EOF */