<?php

//namespace application\model;

use application\model\MySqlModel;

class IndexModel extends MySqlModel
{
    
    public $IndexModel = null;
    /**
     * IndexModel constructor.
     */
    public function __construct()
    {
        parent::__construct();
        $this->table = 'users';
    }
    
    public function user_list($table){
        
        $this->IndexModel = new IndexModel();
        //$result = $this->db->fetchRowMany("select * from ".$table);
        $table = array('id','name');
        //$arr = array('id'=>9);
        //$result = $this->IndexModel->getMany()->where(array('name'=>'praveen'))->orderBy('id ASC')->fields($table)->limit('45')->exec();
        
        $result = $this->IndexModel->insert(array('name'=>'praveen', 'email'=>'pravvvvvvr'))->exec();
        //$result = $this->IndexModel->update()->fields(array('name'=>'praveen', 'email'=>'prav v pn'))->where(array('id'=>7))->exec();
        //$this->IndexModel->delete(array('id'=>11))->exec('users');
        
        //$result = $this->IndexModel->insertMany(array('name' => 'p1', 'name' => 'p12', 'name' => 'p123'));
        
        //$result = $this->IndexModel->executeSql("select * from users");
        echo "<pre>"; print_r($result); die;
        return $result;
       
    }
    
    
}


/* EOF */