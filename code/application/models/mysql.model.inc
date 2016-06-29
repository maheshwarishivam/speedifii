<?php

namespace application\model;

use speedifii\model\BaseModel;
use speedifii\libraries\mysql\MySql;

/**
 * Class MySqlModel
 * @package application\models\
 */
Class MySqlModel extends BaseModel
{
    /**
     * @var MySql Object
     */
    private $where = null;
    
    /**
     * @var MySql Object
     */
    private $fields = null;
    
    /**
     * @var MySql Object
     */
    private $distinct = '';
    
    /**
     * @var MySql Object
     */
    private $orderBy = '';
    
    /**
     * @var MySql Object
     */
    private $params = '';
    
    /**
     * @var MySql Object
     */
    private $limit = '';
    
    /**
     * @var MySql Object
     */
    private $query = '';
    
    /**
     * @var MySql Object
     */
    private $operation_type = '';
    
    /**
     * @var MySql Table
     */
    protected $table = null;
    
    
    /**
     * @var MySql Object
     */
    protected $conn = null;

    /**
     * MySqlModel constructor.
     */
    public function __construct() 
    {  
        parent::__construct();
        $this->getConnection();
        
    }
    
    /**
     * @MySql Get Databse Connection Function
     */
    protected function getConnection(){
        $this->host         = $GLOBALS['config']['database']['host'];
        $this->userName     = $GLOBALS['config']['database']['username'];
        $this->password     = $GLOBALS['config']['database']['password'];
        $this->databaseName = $GLOBALS['config']['database']['databaseName'];
        $this->fetchMode    = \PDO::FETCH_ASSOC;
        $this->charset      = $GLOBALS['config']['database']['charset'];

        $option = array(
            'port' => $GLOBALS['config']['database']['port'],
            'unixSocket' => $GLOBALS['config']['database']['unixSocket']
        );
        
        $this->conn = new MySql($this->host, $this->userName, $this->password, $this->databaseName, $this->fetchMode, $this->charset, $option);
    }
    
    /**
     * @MySql Close Databse Connection Function
     * 
     * @return bool
     */
    protected function closeConnection(){

        //$this->conn->close();
    }
    
    /**
     * @MySql setParams
     * 
     * @param Array $data
     * 
     * @return Object
     */
    protected function setParams($data){
        
        $this->params = $data;
        
        return $this;
        
    }
            
    /**
     * @MySql Return Single Records Function
     * 
     * @return Object
     */
    protected function getSingle(){
        
        $this->operation_type = 'getSingle';
        
        return $this;
        
    }
    
    /**
     * @MySql Return Multiple Records Function
     * 
     * @return Object
     */
    protected function getMany(){
        
        $this->operation_type = 'getMany';
        
        return $this;
        
    }
    
    /**
     * @MySql Return Int Records Function
     * 
     * @return Object
     */
    protected function getCount(){
        
        $this->operation_type = 'getCount';
        
        return $this;
        
    }
    
    /**
     * @MySql Return Int Records Function
     * 
     * @param Array $condition
     * 
     * @return Object
     */
    protected function where($condition = array()){
        
        $this->where = $condition;
        
        return $this;
        
    }
    
    /**
     * @param String $type
     * 
     * @return Object
     */
    protected function orderBy($type = ''){
        
        $this->orderBy = $type;
        
        return $this;
        
    }
    
    /**
     * @param String $data
     * 
     * @return Object
     */
    protected function limit($data){
        
        $this->limit = $data;
        
        return $this;
        
    }
    
    /**
     * @param String $type
     * 
     * @return Object
     */
    protected function distinct($type = ''){
        
        $this->distinct = $type;
        
        return $this;
        
    }
    
    /**
     * @param Array $fields
     * 
     * @return Object
     */
    protected function fields($fields = array()){
        
        $this->fields = $fields;
        
        return $this;
        
    }
    
    /**
     * @param Array $fields
     * 
     * @return Object
     */
    protected function insert($fields = array()){
        
        $this->operation_type = 'insert';
        $this->fields = $fields;
        
        return $this;
        
    }
    
    /**
     * @param Array $data|$where
     * 
     * @return Object
     */
    protected function update($data = array(), $where = array()){
        
        $this->operation_type = 'update';
        $this->fields = $data;
        $this->where = $where;
        
        return $this;
        
    }
    
    /**
     * @param Array $where
     * 
     * @return Object
     */
    protected function delete($where = array()){
        
        $this->operation_type = 'delete';
        $this->where = $where;
        
        return $this;
        
    }
    
    /**
     * @param String $query
     * 
     * @return Object
     */
    protected function rawQuery($query){
        
        $this->query = $query;
        
        return $this;
        
    }
    
    /**
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    protected function replace($data){
        
        return $this->conn->replace($this->table, $data);
        
    }
    
    /**
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    protected function replaceMany($data){
        
        
        return $this->conn->replaceMany($this->table, $data);
        
    }
    
    /**
     * @param array $data
     * @param bool $insertIgnore
     *
     * @return array|bool
     * @throws MysqlException
     */
    protected function insertMany($data, $insertIgnore = false){
        
        return $this->conn->insertMany($this->table, $data, $insertIgnore);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return MysqlQueryIterator|null
     */
    protected function fetchRowManyCursor($query, $where){
        
        return $this->conn->fetchRowManyCursor($query, $where);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    protected function fetchRowMany($query, $where){
        
        return $this->conn->fetchRowMany($query, $where);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    protected function fetchRow($query, $where){
        
        return $this->conn->fetchRow($query, $where);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return MysqlQueryIterator|null
     */
    protected function fetchColumnManyCursor($query, $where){
        
        return $this->conn->fetchColumnManyCursor($query, $where);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    protected function fetchColumnMany($query, $where){
        
        return $this->conn->fetchColumnMany($query, $where);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return null|string
     */
    protected function fetchColumn($query, $where){
        
        return $this->conn->fetchColumn($query, $where);
        
    }
    
    /**
     * @param string $query
     *
     * @return bool
     * @throws MysqlException
     */
    protected function executeSql($query){
        
        return $this->conn->executeSqlQuery($query);
        
    }
    
    /**
     * @return bool|int
     */
    protected function getLastQueryRowCount(){
        
        return $this->conn->getRowCount();
        
    }
    
    /**
     * @Make MySql Query For Fetching Records
     */
    protected function makeRequest(){ 
       
        if($this->operation_type != 'insert' || $this->operation_type != 'update' || $this->operation_type != 'delete'){
            
            $select_query = 'Select ' . ((empty($this->distinct))? '':' DISTINCT ' . $this->distinct);
            
            //Select Query
            $select = implode(', ', $this->fields);
            
            if(count($this->where) > 0){
                $where = ' where ';

                $where .= implode(' AND ', array_map(
                    function ($v, $k) { return sprintf("%s='%s'", $k, $v); },
                    $this->where,
                    array_keys($this->where)
                ));
            } else {
                $where = '';
            }
                
            $distinct = (!empty($this->distinct) && (!empty($select)))?', ':'';
            $select = (empty($select) && empty($this->distinct))?' * ':$select;
            
            // Limit Query
            $limit = (empty($this->limit))?' ':' LIMIT ' . $this->limit;
            
            // Order By Query
            $orderBy = (empty($this->orderBy))?' ':' ORDER BY ' . $this->orderBy;
            
            $this->query = $select_query . $distinct . $select . ' from '. $this->table . $where . $orderBy . $limit;
            
        }
    }
    
    /**
     * @Execute MySql Query
     * 
     * @return Array|bool
     */
    protected function call(){
        
        if($this->operation_type == 'insert'){
            
            return $this->conn->insert($this->table, $this->fields);
            
        } else if($this->operation_type == 'update'){
            
            return $this->conn->update($this->table, $this->where, $this->fields);
            
        } else if($this->operation_type == 'delete'){
            
            return $this->conn->delete($this->table, $this->where);
            
        } else {
            
            if($this->operation_type == 'getSingle'){
                
                return $this->conn->fetchRow($this->query);
                
            } else if($this->operation_type == 'getCount'){
                
                $data = $this->conn->fetchRowMany($this->query);
                
                return count($data);
                
            } else {
                
                return $this->conn->fetchRowMany($this->query);
                
            }
        }
    }
}


/* EOF */