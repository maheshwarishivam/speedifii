<?php

namespace speedifii\libraries\mysql\crud;

/**
 * Interface CrudModelInterface
 * @package speedifii\libraries\mysql\crud
 */
interface CrudModelInterface
{
    /**
     * @return CrudModelInterface
     */
    public function beforeSave();

    /**
     * @return CrudModelInterface
     */
    public function beforeUpdate();

    /**
     * @param array $data
     *
     * @return CrudModelInterface
     */
    public function fromArray(array $data);

    /**
     * @return array
     */
    public function toArray();
}

/* EOF */