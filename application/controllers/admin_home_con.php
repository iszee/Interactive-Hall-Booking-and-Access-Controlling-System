<?php

class admin_home_con extends CI_Controller
{
    public function index(){    // load admin home at login
    	$this->load->model('Model_profile');
        $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
        $data=array(
            'imagepath'=> $result
        );
        $dat=$this->Model_profile->getSched($this->session->userdata('user_id'));
        $info = array('sched' =>$dat );
        $this->load->view('adminheader',$data);
        $this->load->view('tempCal');
    
        $this->load->view('logged',$info);
    }
    
    
}
