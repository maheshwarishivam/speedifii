<?php

namespace speedifii\model;


/**
 * Class BaseModel
 * @package speedifii\model
 */
 abstract class BaseModel
{
    protected $conn = null;
    /**
     * BaseModel constructor.
     */
    public function __construct()
    {
        
    }
    
    abstract protected function getConnection();
    
    abstract protected function closeConnection();
    
    abstract protected function setParams($data);
    
    abstract protected function getSingle();
    
    abstract protected function getMany();
            
    abstract protected function getCount();
    
    abstract protected function where($condition);
    
    abstract protected function orderBy($type);
    
    abstract protected function limit($data);
    
    abstract protected function distinct($type);
    
    abstract protected function fields($fields);    
    
    abstract protected function insert($data);

    abstract protected function update($data, $where);
    
    abstract protected function delete($where);
    
    abstract protected function rawQuery($query);
    
    /**
     * @param string $tableName
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    abstract protected function replace($data);
    
    /**
     * @param string $tableName
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    abstract protected function replaceMany($data);
    
    /**
     * @param string $tableName
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
    
    protected final function exec(){
        
        $this->makeRequest();
        return $this->call();
        
    }
    
}





/* EOF */