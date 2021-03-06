<?php

namespace speedifii\controllers;

use speedifii\core\Loader;
use speedifii\core\Request;
use speedifii\core\Response;
use speedifii\SpeediFii;

/**
 * Class BaseController
 * @package speedifii\controllers
 */
abstract class BaseController
{

    /**
     * @var request
     */
    protected $req;

    /**
     * @var response
     */
    protected $res;

    /**
     * @var Loader load
     */
    protected $load;

    /**
     * BaseController constructor.
     */
    public function __construct()
    {
        //Create Request and Response Objects
        $this->req = new Request();
        $this->res = new Response();
        //Instantiate the component loader
        $this->load = new Loader();
    }

    /**
     * IndexAction
     */
    public abstract function IndexAction();

    /**
     * Sends a HTTP 200 OK response
     */
    protected final function sendOK()
    {
        $this->res->setStatus(200);
        $this->render();
    }

    /**
     * Sends a 201 Created response
     */
    protected final function sendCreated()
    {
        $this->res->setStatus(201);
        $this->render();
    }

    /**
     * Sends a 202 Accepted response
     */
    protected final function sendAccepted()
    {
        $this->res->setStatus(202);
        $this->render();
    }

    /**
     * Sends a 204 No Content response and removes response body (if set previously)
     */
    protected final function sendNoContent()
    {
        $this->res->setStatus(204);
        $this->res->setBody(NULL);
        $this->render();
    }

    /**
     * Sends a 301 Moved Permanently (If $permanent = true) or 302 Found response (if $permanent = false)
     * @param $url
     * @param bool $permanent
     */
    public function redirect($url, $permanent = false)
    {
        $this->res->setStatus($permanent ? 301 : 302);
        $this->res->setRawBody($url);
        $this->render();
    }

    /**
     * Sends a 304 Not Modified response and removes response body (if set previously)
     */
    protected final function sendNotModified()
    {
        $this->res->setStatus(304);
        $this->res->setBody(NULL);
        $this->render();
    }

    /**
     * Sends a 400 Bad Request response
     */
    protected final function sendBadRequest()
    {
        $this->res->setStatus(400);
        $this->render();
    }

    /**
     * Sends a 401 Unauthorised response
     * It does NOT automatically include a WWW-Authenticate header
     */
    protected final function sendUnAuthorised()
    {
        $this->res->setStatus(401);
        $this->render();
    }

    /**
     * Sends a 403 Forbidden response
     */
    protected final function sendForbidden()
    {
        $this->res->setStatus(403);
        $this->render();
    }

    /**
     * Sends a 404 Not Found response
     */
    protected final function sendNotFound()
    {
        $this->res->setStatus(404);
        $this->render();
    }

    /**
     * Sends a 405 Method Not Allowed response
     */
    protected final function sendMethodNotAllowed()
    {
        $this->res->setStatus(405);
        $this->render();
    }

    /**
     * Sends a 500 Internal Server Error response
     */
    protected final function sendError()
    {
        $this->res->setStatus(500);
        $this->render();
    }

    /**
     * Sends a 504 Bad Gateway response
     */
    protected final function sendBadGateway()
    {
        $this->res->setStatus(502);
        $this->render();
    }

    /**
     * Sends a 503 Service Unavailable response
     */
    protected final function sendServiceUnavailable()
    {
        $this->res->setStatus(503);
        $this->render();
    }

    /**
     * Sends a 504 Gateway Timeout response
     */
    protected final function sendGatewayTimeout()
    {
        $this->res->setStatus(504);
        $this->render();
    }

    /**
     * Send a custom response by specifying a HTTP response code
     * @param int $responseCode
     */
    protected final function sendResponse($responseCode = 200)
    {
        $this->res->setStatus($responseCode);
        $this->render();
    }

    /**
     * Renders the response
     *
     * If $view is not specified, we will try to guess it. If not found, we will raise an error
     * View will be ignored if responseFormat is JSON
     *
     * Application Logs will be written AFTER sending the response.
     *
     * Another response should not be attempted after calling this function. If attempted, it will be logged instead.
     */
    private function render()
    {
        SpeediFii::log()->notice('Preparing the response');
        SpeediFii::log()->debug('Response to be sent',$this->res->toArray());
        if (!headers_sent($filename, $linenum)) {
            $resStatus = $this->res->getStatus();
            if ($resStatus == 301 || $resStatus == 302) {
                $rawBody = $this->res->getRawBody();
                SpeediFii::log()->info('Redirecting to: ' . $rawBody() .' with HTTP Status: ' . $resStatus);
                //Handle redirects
                header('Location: ' . $this->appUrl($rawBody) , TRUE, $resStatus);
            } else {
                //Send HTTP Response Code
                http_response_code($resStatus);

                SpeediFii::log()->notice('Response HTTP Status is ' . $resStatus);

                $resCookies = $this->res->getCookies();

                SpeediFii::log()->debug('Setting Response Cookies',$resCookies);

                //Set cookies
                foreach ($resCookies as $cookie => $c) {
                    setcookie($cookie, $c['value'], time() + $c['expire'], $c['path'], $c['domain'], $c['secure'], $c['httponly']);
                }

                $resHeaders = $this->res->getHeaders();

                SpeediFii::log()->debug('Setting Response Headers',$resHeaders);

                //Set Headers
                foreach ($this->res->getHeaders() as $header => $h) {
                    header($header . ': ' . $h['value'], $h['replace']);
                }

                if($this->res->getRawBody() != null){
                    SpeediFii::log()->info('Sending Raw Body');
                    $resRawBody = $this->res->getRawBody();
                    SpeediFii::log()->debug('Raw Body: ' . $resRawBody);
                    echo $resRawBody;
                } else if ($this->res->getResponseFormat() == 'JSON') {
                    SpeediFii::log()->info('Sending JSON Response');
                    //Send JSON response
                    if ($this->res->getBody() != NULL) {
                        //Handle UTF-8 Special Chars
                        $responseJSON = html_entity_decode(json_encode(array_map('htmlentities', $this->res->getBody())));
                        if ($responseJSON) {
                            SpeediFii::log()->debug('JSON Response: ' . $responseJSON);
                            echo $responseJSON;
                        } else {
                            SpeediFii::log()->error('Response format was set to JSON, but malformed response JSON found. Sending 500 Internal Server Error instead with empty body. JSON last error Code: ' . json_last_error(), array('body'=>$this->res->getBody()));
                            $this->res->setBody(null);
                            $this->sendError();
                        }
                    }
                } else {
                    //Send HTML response
                    SpeediFii::log()->info('Sending HTML Response');

                    //Bind data to view and render
                    $view = strtolower(PLATFORM) . DS . strtolower(CONTROLLER) . DS . strtolower(ACTION);
                    $responseHTML = $this->renderView($view, $this->res->getBody());
                    SpeediFii::log()->debug('HTML Response: ' . $responseHTML);
                    echo $responseHTML;
                }
            }
        } else {
            //Log Error
            SpeediFii::log()->error("Headers already sent in $filename on line $linenum. Not sending response.",array('headersAlreadySent'=>headers_sent(),'newResponse'=>$this->res->toArray()));
        }
    }

    /**
     * Binds data to HTML view and returns the final HTML
     * @param array $data
     * @param string $viewPath
     * @return string
     */
    private function renderView($viewPath, Array $data = array())
    {
        SpeediFii::log()->debug('View: ' . $viewPath);
        SpeediFii::log()->debug('Data to bind to view',$data);
        return call_user_func(function () use ($data) {
            extract($data, EXTR_SKIP);
            unset($data);
            ob_start();
            include VIEW_PATH . func_get_arg(0) . '.view.phtml';
            return ob_get_clean();
        }, $viewPath);
    }

    /**
     * Return correct url for relative paths
     * If an absolute URL is passed instead, returns it as it is
     * @param string $url
     * @return string
     */
    protected final function appUrl($url = '/') {
        return (substr($url,0,4)!='http')?$GLOBALS['config']['application']['app_url'] . trim($url,'/') . '/': $url;
    }

}

/* EOF */