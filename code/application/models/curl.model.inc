<?php

namespace application\model;

use speedifii\model\BaseModel;
use speedifii\libraries\curl\Curl;

Class CurlModel extends BaseModel
{
    
    public $curl = null;
    
    /**
     * CurlModel constructor.
     */
    public function __construct()
    {
        parent::__construct();
        
        $this->getConnection();
    }
    
    
    public function getConnection(){
        $this->curl = new Curl();
    }
    
    
    public function closeConnection(){
        
    }
    
    public function setParams($data){
        
    }
            
    public function getSingle($select = ' * '){
        
    }
    
    public function getMany($select = ' * '){
        
    }
    
    public function getCount($select = ' * '){
        
    }
    
    public function where($condition = array()){
        
    }
    
    public function orderBy($type = array()){
        
    }
    
    public function limit($data){
        
    }
    
    public function distinct($type = false){
        
    }
    
    public function fields($fields = array()){
        
    }
    
    public function insert($fields = array()){
        
    }
    
    public function update($data = array(), $where = array()){
        
    }
    
    public function delete($where = array()){
        
    }
    
    public function rawQuery($query){
        
    }
    
    public function replace($tableName, $data){
        
    }
    
    public function replaceMany($tableName, $data){
        
    }
    
    public function insertMany($tableName, $data, $insertIgnore){
        
    }
    
    public function fetchRowManyCursor($query, $where){
        
        
    }
    
    public function fetchRowMany($query, $where){
        
        
    }
    
    public function fetchRow($query, $where){
        
        
    }
    
    public function fetchColumnManyCursor($query, $where){
        
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    public function fetchColumnMany($query, $where){
        
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return null|string
     */
    public function fetchColumn($query, $where){
        
    }
    
    /**
     * @param string $query
     *
     * @return bool
     * @throws MysqlException
     */
    public function executeSql($query){
        
        
    }
    
    /**
     * @return bool|int
     */
    public function getLastQueryRowCount(){
        
        
    }
    
    public function exec($table){
        
    }
    
}

/* EOF */