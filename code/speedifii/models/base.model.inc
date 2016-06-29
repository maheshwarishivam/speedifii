<?php

namespace speedifii\model;


/**
 * Class BaseModel
 * @package speedifii\model
 */
 abstract class BaseModel
{
     
    /**
     * @var MySql Connection Object
     */
    protected $conn = null;
    
    /**
     * BaseModel constructor.
     */
    public function __construct()
    {
        
    }
    
    /** 
     * @return MySql Object
     */
    abstract protected function getConnection();
    
    /** 
     * @return bool
     */
    abstract protected function closeConnection();
    
    /** 
     * @param Array $data
     *
     * @return Array
     */
    abstract protected function setParams($data);
    
    /** 
     * @return Array
     */
    abstract protected function getSingle();
    
    /** 
     * @return Array
     */
    abstract protected function getMany();
            
    /** 
     * @return bool|int
     */
    abstract protected function getCount();
    
    /** 
     * @param Array $condition
     *
     * @return bool|int
     */
    abstract protected function where($condition);
    
    /** 
     * @param String $type
     *
     * @return bool|int
     */
    abstract protected function orderBy($type);
    
    /** 
     * @param String $data
     *
     * @return bool|int
     */
    abstract protected function limit($data);
    
    /** 
     * @param String $type
     *
     * @return bool|int
     */
    abstract protected function distinct($type);
    
    /** 
     * @param array $fields
     *
     * @return bool|int
     */
    abstract protected function fields($fields);    
    
    /** 
     * @param array $data
     *
     * @return bool|int
     */
    abstract protected function insert($data);

    /** 
     * @param array $data|$where
     *
     * @return bool|int
     */
    abstract protected function update($data, $where);
    
    /** 
     * @param array $where
     *
     * @return bool|int
     */
    abstract protected function delete($where);
    
    /**
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    abstract protected function rawQuery($query);
    
    /**
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    abstract protected function replace($data);
    
    /**
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    abstract protected function replaceMany($data);
    
    /**
     * @param array $data
     * @param bool $insertIgnore
     *
     * @return array|bool
     * @throws MysqlException
     */
    abstract protected function insertMany($data, $insertIgnore);//
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return MysqlQueryIterator|null
     */
    abstract protected function fetchRowManyCursor($query, $where);
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    abstract protected function fetchRowMany($query, $where);
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    abstract protected function fetchRow($query, $where);
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return MysqlQueryIterator|null
     */
    abstract protected function fetchColumnManyCursor($query, $where);
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    abstract protected function fetchColumnMany($query, $where);

    /**
     * @param string $query
     * @param array $conds
     *
     * @return null|string
     */
    abstract protected function fetchColumn($query, $where);
    
    /**
     * @param string $query
     *
     * @return bool
     * @throws MysqlException
     */
    abstract protected function executeSql($query);
    
    /**
     * @return bool|int
     */
    abstract protected function getLastQueryRowCount();
    
    /**
     * @return Array|bool|int
     */
    protected final function exec(){
        
        $this->makeRequest();
        return $this->call();
        
    }
    
}





/* EOF */