<?php

namespace speedifii\model;


/**
 * Class BaseModel
 * @package speedifii\model
 */
 abstract class BaseModel
{
    
    /**
     * BaseModel constructor.
     */
    public function __construct()
    {
        
    }
    
    public abstract function getConnection();
    
    public abstract function closeConnection();
    
    public abstract function setParams($select);
    
    public abstract function getSingle($select);
    
    public abstract function getMany($select);
            
    public abstract function getCount($table);
    
    public abstract function where($condition);
    
    public abstract function orderBy($type);
    
    public abstract function limit($data);
    
    public abstract function distinct($type);
    
    public abstract function fields($fields);    
    
    public abstract function insert($data);

    public abstract function update($data, $where);
    
    public abstract function delete($where);
    
    public abstract function rawQuery($query);
    
    /**
     * @param string $tableName
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    public abstract function replace($tableName, $data);
    
    /**
     * @param string $tableName
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    public abstract function replaceMany($tableName, $data);
    
    /**
     * @param string $tableName
     * @param array $data
     * @param bool $insertIgnore
     *
     * @return array|bool
     * @throws MysqlException
     */
    public abstract function insertMany($tableName, $data, $insertIgnore);//
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return MysqlQueryIterator|null
     */
    public abstract function fetchRowManyCursor($query, $where);
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    public abstract function fetchRowMany($query, $where);
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    public abstract function fetchRow($query, $where);
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return MysqlQueryIterator|null
     */
    public abstract function fetchColumnManyCursor($query, $where);
    
    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    public abstract function fetchColumnMany($query, $where);

    /**
     * @param string $query
     * @param array $conds
     *
     * @return null|string
     */
    public abstract function fetchColumn($query, $where);
    
    /**
     * @param string $query
     *
     * @return bool
     * @throws MysqlException
     */
    public abstract function executeSql($query);
    
    /**
     * @return bool|int
     */
    public abstract function getLastQueryRowCount();
    
    public abstract function exec($table);

}





/* EOF */