<?php

//namespace application\model;

use speedifii\model\BaseModel;
use application\model\mysqlModel;

class Index extends BaseModel
{
    public $db = null;
    
    /**
     * IndexModel constructor.
     */
    public function __construct()
    {
        parent::__construct();
    }
    
    public function user_list($table, $data){
        $result = $this->sql_db->select_query($table, $data);
        
        
        return $result;
       
    }
    
    public function user_insert($table, $data){
        $result = $this->sql_db->insert_query($table, $data);
        
        return $result;
       
    }
    
    public function user_delete($table, $data){
        $result = $this->sql_db->delete_query($table, $data);
        
        
        return $result;
       
    }
    
    public function user_update($table, $data, $where){
        $result = $this->sql_db->update_query($table, $data, $where);
        
        
        return $result;
       
    }
    
}


/* EOF */