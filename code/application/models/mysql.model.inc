<?php

namespace application\model;

Class mysqlModel
{
    private $connection = null;
    /**
     * BaseModel constructor.
     */
    public function __construct()
    {
        $this->db();
    }
    
    public final function db()
    {
        $this->DB_SERVER        = $GLOBALS['config']['database']['host'];
        $this->DB_USER          = $GLOBALS['config']['database']['username'];
        $this->DB_PASSWORD      = $GLOBALS['config']['database']['password'];
        $this->DB               = $GLOBALS['config']['database']['database_name'];
        $this->PORT             = $GLOBALS['config']['database']['port'];

        $this->connection = mysqli_connect($this->DB_SERVER, $this->DB_USER, $this->DB_PASSWORD, $this->DB, $this->PORT);
        if ($this->connection->connect_error) {
            die('Connect Error: ' . $this->connection->connect_error);
        }
        mysqli_select_db($this->connection, $GLOBALS['config']['database']['database_name']) or die ("Unable to select database");
    }
    
    protected final function get()
    {
        
    }
    
    protected final function close()
    {
        
    }
    
    protected final function query($sql)
    {
        $result = $this->connection->query($sql);
        return $result;
    }
    
    public function select_query($table, $col = '*')
    {        
        $col_value = (is_array($col)) ? implode(',', $col):$col;

        $result = $this->connection->query("SELECT ".$col_value." FROM " . $table);
        
        while ($row = $result->fetch_assoc()) {
            $rows[] = $row;
        }
        return $rows;
    }
    
    public function insert_query($table, $data = array())
    { 
        $col = '';
        $value = '';
        
        foreach($data as $key=>$data_value){
            
            $col .= ',`'.$key.'`';
            $value .= ", '".$data_value."'";
            
        }
        
        $col = substr($col, 1);
        $value = substr($value, 1);
        
        $result = $this->connection->query("INSERT INTO `".$table."` (".$col.") VALUES(".$value.")");
        
        return $result;
    }
    
    public function update_query($table, $data = array(), $where_data = array())
    {        
        
        $value = '';
        $where = '';
        
        foreach($data as $key=>$data_value){
            
            $value .= ", `".$key."`='".$data_value."'";
            
        }
        $value = substr($value, 1);
        
        foreach($where_data as $key=>$data_value){
            
            $where .= "and `".$key."`='".$data_value."' ";
            
        }
        $where = substr($where, 3);
        
        $result = $this->connection->query("UPDATE `".$table."` SET ".$value." WHERE ".$where );

        return $result;
    }
    
    public function delete_query($table, $data = array())
    {        
        
        $value = '';
        
        foreach($data as $key=>$data_value){
            
            $value .= "and ".$key."='".$data_value."' ";
            
        }
        $value = substr($value, 3);
        
        $result = $this->connection->query("DELETE FROM `".$table."` WHERE ".$value );

        return $result;
    }
    
}


/* EOF */