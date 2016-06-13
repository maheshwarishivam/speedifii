<?php

namespace speedifii\libraries\mysql\crud;

use speedifii\libraries\mysql\Mysql;
use speedifii\libraries\mysql\MysqlException;

/**
 * Interface CrudStoreInterface
 * @package speedifii\libraries\mysql\crud
 */
interface CrudStoreInterface
{
    /**
     * @param Mysql $mysql
     * @param CrudManager $crudManager
     */
    public function __construct(Mysql $mysql, CrudManager $crudManager);

    /**
     * @return string
     */
    public function getTableName();

    /**
     * @return CrudModelInterface
     */
    public function getModel();

    /**
     * @param CrudModelInterface $model
     *
     * @return CrudModelInterface
     */
    public function crudCreate(CrudModelInterface $model);

    /**
     * @param array $conds
     * @param array $sorting
     *
     * @return null|CrudModelInterface[]
     */
    public function crudRead(array $conds = [], array $sorting = []);

    /**
     * @param array $conds
     *
     * @return null|CrudModelInterface
     */
    public function crudReadOne(array $conds);

    /**
     * @param CrudModelInterface $model
     * @param array $conds
     *
     * @return CrudModelInterface
     */
    public function crudUpdate(CrudModelInterface $model, array $conds);

    /**
     * @param array $conds
     *
     * @throws MysqlException
     */
    public function crudDelete(array $conds);
}

/* EOF */
