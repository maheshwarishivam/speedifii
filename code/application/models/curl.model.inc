<?php

namespace application\model;

use speedifii\model\BaseModel;
use speedifii\libraries\curl\Curl;

/**
 * Class CurlModel
 * @package application\models\
 */
Class CurlModel extends BaseModel
{
    /**
     * @var Curl $Params Variable
     */
    protected $params = null;
    
    /**
     * @var Curl $url Variable
     */
    protected $url = null;
    
    /**
     * CurlModel constructor.
     */
    public function __construct()
    {
        parent::__construct();
        
        $this->getConnection();
    }
    
    /**
     * @Call Library Curl Class File
     */
    protected function getConnection(){
        $this->conn = new Curl();
    }
    
    
    protected function closeConnection(){
        
    }
    
    /**
     * @Set Params Data
     * 
     * @param Array $data
     */
    protected function setParams($data){  
        $this->params = $data;
    }
            
    protected function getSingle(){
        
    }
    
    protected function getMany(){
        
    }
    
    protected function getCount(){
        
    }
    
    protected function where($condition = array()){
        
    }
    
    protected function orderBy($type = array()){
        
    }
    
    protected function limit($data){
        
    }
    
    protected function distinct($type = false){
        
    }
    
    protected function fields($fields = array()){
        
    }
    
    protected function insert($fields = array()){
        
    }
    
    protected function update($data = array(), $where = array()){
        
    }
    
    protected function delete($where = array()){
        
    }
    
    protected function rawQuery($query){
        
    }
    
    protected function replace($data){
        
    }
    
    protected function replaceMany($data){
        
    }
    
    protected function insertMany($data, $insertIgnore){
        
    }
    
    protected function fetchRowManyCursor($query, $where){
        
        
    }
    
    protected function fetchRowMany($query, $where){
        
        
    }
    
    protected function fetchRow($query, $where){
        
        
    }
    
    protected function fetchColumnManyCursor($query, $where){
        
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    protected function fetchColumnMany($query, $where){
        
        
    }
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return null|string
     */
    protected function fetchColumn($query, $where){
        
    }
    
    /**
     * @param string $query
     *
     * @return bool
     * @throws MysqlException
     */
    protected function executeSql($query){
        
        
    }
    
    /**
     * @return bool|int
     */
    protected function getLastQueryRowCount(){
        
        
    }
    
    /**
     * @Set Url Data
     * 
     * @param String $data
     */
    protected function setUrl($data){
        $this->url = $data;
    }
    
    /**
     * @Set Method Data
     * 
     * @param String $data
     */
    protected function setMethod($data){
        $this->conn->setMethod($data);
    }
    
    /**
     * @Set Headers Data
     * 
     * @param Array $data
     */
    protected function setHeaders($data){
        $this->conn->setHeaders($data);
    }
    
    /**
     * @Set ReqType Data
     * 
     * @param String $data
     */
    protected function setReqType($data){
        $this->conn->setReqType($data);
    }
    
    /**
     * @Set RawBody Data
     * 
     * @param String $data
     */
    protected function setRawBody($data){
        $this->conn->setRawBody($data);
    }
    
    /**
     * @Return All Details of Request
     * 
     * @return Array 
     */
    protected function toArray(){
        return $this->conn->toArray();
    }
    
    /**
     * @Return All Details of Request
     * 
     * @return JSON 
     */
    protected function toJSON(){
        return $this->conn->toJSON();
    }

    /**
     * @Set All Params in Url
     * 
     */
    protected function makeRequest(){
        
        $url = '';
        
        if(count($this->params) > 0){
            
            $url = '?'.implode('&', array_map(
                function ($v, $k) { return sprintf("%s=%s", $k, $v); },
                $this->params,
                array_keys($this->params)
            ));
            
        }
        
        $url = $this->url.$url;
        $this->conn->setUrl($url);
    }

    /**
     * @Call Curl Main Function
     * 
     */
    protected function call(){
        $this->conn->call();
    }
    
}

/* EOF */