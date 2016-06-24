<?php

//namespace application\model;

use application\model\MySqlModel;

class IndexModel extends MySqlModel
{
    
    /**
     * IndexModel constructor.
     */
    public function __construct()
    {
        parent::__construct();
    }
    
    public function user_list($table){
        
        //$result = $this->db->fetchRowMany("select * from ".$table);
        $table = array('name');
        //$arr = array('id'=>9);
        $result = $this->getSingle($table)->orderBy('id ASC')->limit('45')->exec('users');
        
        //$result = $this->insert(array('name'=>'praveen', 'email'=>'pravvvvvvr'))->exec('users');
        //$this->update(array('name'=>'praveen', 'email'=>'prav v pn'), array('id'=>10))->exec('users');
        //$this->delete(array('id'=>11))->exec('users');
        
        //$result = $this->db->insertMany('users', array('name' => 'p1', 'name' => 'p12', 'name' => 'p123'));
        
        return $result;
       
    }
    
    
}


/* EOF */