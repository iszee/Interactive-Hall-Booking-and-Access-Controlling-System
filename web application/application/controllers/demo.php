<?php
/**
 * Created by PhpStorm.
 * User: Isuru Nanayakkara
 * Date: 02-Dec-17
 * Time: 5:53 PM
 */

class demo extends CI_Controller
{
    function index(){
        $this->load->view('nheader');
        $this->load->view('calendar');

        $this->load->view('logged');

    }
}