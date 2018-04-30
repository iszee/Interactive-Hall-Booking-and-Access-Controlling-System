<?php

class accessdet_con extends CI_Controller 
{
    public function __construct(){
        parent:: __construct();
        $this->load->model('accessdet_model','m');      //load model as m
    } 
 
    public function index(){
    	$this->load->model('Model_profile');
        $result=$this->Model_profile->get_image($this->session->userdata('user_id'));   //load profile data
        $data=array(
            'imagepath'=> $result
        );

        $this->load->view('adminheader',$data);
        $data['accesses'] = $this->m->getAccess();
        $this->load->view('accessdet_view', $data);
    }
}
