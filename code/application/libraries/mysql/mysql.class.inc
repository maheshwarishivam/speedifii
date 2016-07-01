<?php

namespace speedifii\libraries\mysql;
use Simplon\Mysql\MysqlException;
use Simplon\Mysql\MysqlQueryIterator;

/**
 * Class MySql
 * @package speedifii\libraries\mysql
 */
class MySql
{

    /**
     * @var \Simplon\Mysql\Mysql
     */
    private $dbConn;

    /**
     * @param $host
     * @param $user
     * @param $password
     * @param $database
     * @param int $fetchMode
     * @param string $charset
     * @param array $options
     *
     * @throws MysqlException
     */
    public function __construct($host, $user, $password, $database, $fetchMode = \PDO::FETCH_ASSOC, $charset = 'utf8', array $options = [])
    {
        $this->dbConn = new \Simplon\Mysql\Mysql($host, $user, $password, $database, $fetchMode, $charset, $options);
    }

    /**
     * @return Mysql
     */
    public function close()
    {
        return $this->dbConn->close();
    }

    /**
     * @return bool|int
     */
    public function getRowCount()
    {
        return $this->dbConn->getRowCount();
    }

    /**
     * @param string $query
     *
     * @return bool
     * @throws MysqlException
     */
    public function executeSql($query)
    {
        return $this->dbConn->executeSql($query);
    }

    /**
     * @param string $dbName
     *
     * @return bool
     * @throws MysqlException
     */
    public function selectDb($dbName)
    {
        return $this->dbConn->selectDb($dbName);
    }

    /**
     * @param string $query
     * @param array $conds
     *
     * @return null|string
     */
    public function fetchColumn($query, array $conds = [])
    {
        return $this->dbConn->fetchColumn($query, $conds);
    }

    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    public function fetchColumnMany($query, array $conds = [])
    {
        return $this->dbConn->fetchColumnMany($query, $conds);
    }

    /**
     * @param string $query
     * @param array $conds
     *
     * @return MysqlQueryIterator|null
     */
    public function fetchColumnManyCursor($query, array $conds = [])
    {
        return $this->dbConn->fetchColumnManyCursor($query, $conds);
    }

    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    public function fetchRow($query, array $conds = [])
    {
        return $this->dbConn->fetchRow($query, $conds);
    }

    /**
     * @param string $query
     * @param array $conds
     *
     * @return array|null
     */
    public function fetchRowMany($query, array $conds = [])
    {
        return $this->dbConn->fetchRowMany($query, $conds);
    }

    /**
     * @param string $query
     * @param array $conds
     *
     * @return MysqlQueryIterator|null
     */
    public function fetchRowManyCursor($query, array $conds = [])
    {
        return $this->dbConn->fetchRowManyCursor($query, $conds);
    }

    /**
     * @param string $tableName
     * @param array $data
     * @param bool $insertIgnore
     *
     * @return int|bool
     * @throws MysqlException
     */
    public function insert($tableName, array $data, $insertIgnore = false)
    {
        return $this->dbConn->insert($tableName, $data, $insertIgnore);
    }

    /**
     * @param string $tableName
     * @param array $data
     * @param bool $insertIgnore
     *
     * @return array|bool
     * @throws MysqlException
     */
    public function insertMany($tableName, array $data, $insertIgnore = false)
    {
        return $this->dbConn->insertMany($tableName, $data, $insertIgnore);
    }

    /**
     * @param string $tableName
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    public function replace($tableName, array $data)
    {
        return $this->dbConn->replace($tableName, $data);
    }

    /**
     * @param string $tableName
     * @param array $data
     *
     * @return array|bool
     * @throws MysqlException
     */
    public function replaceMany($tableName, array $data)
    {
        return $this->dbConn->replaceMany($tableName, $data);
    }

    /**
     * @param string $tableName
     * @param array $conds
     * @param array $data
     * @param null $condsQuery
     *
     * @return bool
     * @throws MysqlException
     */
    public function update($tableName, array $conds, array $data, $condsQuery = null)
    {
        return $this->dbConn->update($tableName, $conds, $data, $condsQuery);
    }

    /**
     * @param string $tableName
     * @param array $conds
     * @param null $condsQuery
     *
     * @return bool
     * @throws MysqlException
     */
    public function delete($tableName, array $conds = [], $condsQuery = null)
    {
        return $this->dbConn->delete($tableName, $conds, $condsQuery);
    }
}

/* EOF */