<?php

//namespace application\model;

use application\model\MysqlModel;

class IndexModel extends MysqlModel
{
    
    /**
     * IndexModel constructor.
     */
    public function __construct()
    {
        parent::__construct();
    }
    
    public function user_list($table, $data){
        
       $result = $this->sql_db->fetchRowMany("select * from users where id=:id", array('id'=>14));
       
        
        return $result;
       
    }
    
    
}


/* EOF */