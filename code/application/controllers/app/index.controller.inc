<?php

use speedifii\controllers\BaseController;
use speedifii\SpeediFii;

/**
 * Class IndexController
 * @package application\controllers\app\
 */
class IndexController extends BaseController
{
    /**
     * @ Index Action
     */
    public function indexAction()
    {
        // TODO: Implement IndexAction() method.
        //Load a custom language. Default language is already loaded
        //All languages mentioned in autoload config are also loaded automatically
        $this->load->language('hi_in');
        //Get the language replacements ready
        $replacements = array(
            'USER_NAME'=>'Shivam',
            'USER_FULL_NAME'=>'Shivam Maheshwari',
            'APP_NAME'=> 'SpeediFii'
        );

        //Prepare the data to be sent to the View
        $viewData = array(
            'title'=>SpeediFii::__('Welcome',$replacements),//Use default language as defined in Config
            'message'=>SpeediFii::__('Welcome to SpeediFii',$replacements,'hi_in')//Specify new language. This languages must be loaded
        );

        //Set the data for View.
        $this->res->setBody($viewData);
        //Render
        $this->sendOK();
    }
}

/* EOF */