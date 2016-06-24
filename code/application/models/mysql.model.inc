<?php

namespace application\model;

use speedifii\model\BaseModel;
use speedifii\libraries\mysql\MySql;

Class MySqlModel extends BaseModel
{
    /**
     * @var MySql Object
     */
    private $select = null;
    
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
     * @var MySql Object
     */
    public $db = null;//TODO: Rename to $db


    public function __construct() 
    {  
        parent::__construct();
        $this->getConnection();
        
    }
    
    public function getConnection(){
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
        
        $this->db = new MySql($this->host, $this->userName, $this->password, $this->databaseName, $this->fetchMode, $this->charset, $option);
    }
    
    public function closeConnection(){
        $this->db->close();
    }
    
    public function setParams($data){
        
    }
            
    public function getSingle($select = array()){
        
        $this->operation_type = 'get';
        $this->select = $select;
        
        return $this;
        
    }
    
    public function getMany($select = array()){
        
        $this->operation_type = 'get';
        $this->select = $select;
        
        return $this;
        
    }
    
    public function getCount($select = ''){
        
        $this->operation_type = 'get';
        $this->select = $select;
        
        return $this;
        
    }
    
    public function where($condition = array()){
        
        $this->where = $condition;
        
        return $this;
        
    }
    
    public function orderBy($type = ''){
        
        $this->orderBy = $type;
        
        return $this;
        
    }
    
    public function limit($data){
        
        $this->limit = $data;
        
        return $this;
        
    }
    
    public function distinct($type = ''){
        
        $this->distinct = $type;
        
        return $this;
        
    }
    
    public function fields($fields = array()){
        
        $this->fields = $fields;
        
        return $this;
        
    }
    
    public function insert($fields = array()){
        
        $this->operation_type = 'insert';
        $this->fields = $fields;
        
        return $this;
        
    }
    
    public function update($data = array(), $where = array()){
        
        $this->operation_type = 'update';
        $this->fields = $data;
        $this->where = $where;
        
        return $this;
        
    }
    
    public function delete($where = array()){
        
        $this->operation_type = 'delete';
        $this->where = $where;
        
        return $this;
        
    }
    
    public function rawQuery($query){
        
        $this->query = $where;
        
        return $this;
        
    }
    
    /**
     * @param string $tableName
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    public function replace($tableName, $data){
        
        return $this->db->replace($tableName, $data);
        
    }
    
    /**
     * @param string $tableName
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    public function replaceMany($tableName, $data){
        
        
        return $this->db->replaceMany($tableName, $data);
        
    }
    
    /**
     * @param string $tableName
     * @param array $data
     * @param bool $insertIgnore
     *
     * @return array|bool
     * @throws MysqlException
     */
    public function insertMany($tableName, $data, $insertIgnore = false){
        
        return $this->db->insertMany($tableName, $data, $insertIgnore);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return MysqlQueryIterator|null
     */
    public function fetchRowManyCursor($query, $where){
        
        return $this->db->fetchRowManyCursor($query, $where);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    public function fetchRowMany($query, $where){
        
        return $this->db->fetchRowMany($query, $where);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    public function fetchRow($query, $where){
        
        return $this->db->fetchRow($query, $where);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return MysqlQueryIterator|null
     */
    public function fetchColumnManyCursor($query, $where){
        
        return $this->db->fetchColumnManyCursor($query, $where);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    public function fetchColumnMany($query, $where){
        
        return $this->db->fetchColumnMany($query, $where);
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return null|string
     */
    public function fetchColumn($query, $where){
        
        return $this->db->fetchColumn($query, $where);
        
    }
    
    /**
     * @param string $query
     *
     * @return bool
     * @throws MysqlException
     */
    public function executeSql($query){
        
        return $this->db->executeSql($query);
        
    }
    
    /**
     * @return bool|int
     */
    public function getLastQueryRowCount(){
        
        return $this->db->getRowCount();
        
    }
    
    public function exec($table){
        
        //echo $query .$this->operation_type; 
        
        if($this->operation_type == 'get'){
            
            $select_query = 'Select ' . ((empty($this->distinct))? '':' DISTINCT ' . $this->distinct);
            
            //Select Query
            $select = implode(', ', $this->select);
            
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
            
            $query = $select_query . $distinct . $select . ' from '. $table . $where . $orderBy . $limit;
            
            return $this->db->fetchRowMany($query);
            
        } else if($this->operation_type == 'insert'){
            
            return $this->db->insert($table, $this->fields);
            
        } else if($this->operation_type == 'update'){
            
            return $this->db->update($table, $this->where, $this->fields);
            
        } else if($this->operation_type == 'delete'){
            
            return $this->db->delete($table, $this->where);
            
        }
    }
}


/* EOF */