<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Home extends CI_Controller {

	/**
	 * Index Page for this controller.
	 *
	 * Maps to the following URL
	 * 		http://example.com/index.php/welcome
	 *	- or -
	 * 		http://example.com/index.php/welcome/index
	 *	- or -
	 * Since this controller is set as the default controller in
	 * config/routes.php, it's displayed at http://example.com/
	 *
	 * So any other public methods not prefixed with an underscore will
	 * map to /index.php/welcome/<method_name>
	 * @see https://codeigniter.com/user_guide/general/urls.html
	 */
	public function index()
	{
		$this->load->view('home');
	}

	public function test() { 
         $this->load->helper('url');
    }

    public function admin()
	{
		$this->load->view('Admin');
	}

	public function logged()
	{
        $this->load->model('Model_profile');
        $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
        $data=array(
            'imagepath'=> $result
        );
        $this->load->Model('Model_profile');
        $dat=$this->Model_profile->getSched($this->session->userdata('user_id'));
        $info = array('sched' =>$dat );
        $this->load->view('nheader',$data);		
        $this->load->view('tempCal',$info);

        $this->load->view('logged');
	
	}

	/*public function admin_1()
	{
		$this->load->view('admin_1');
	}*/
	public function tour(){
		$this->load->model('Model_profile');
        $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
        $data=array(
            'imagepath'=> $result
        );
       
		$this->load->view('tourLog',$data);
	}

	public function s1(){
		$this->load->view('logged');
	}

	/*public function userSignUp()
	{
		$this->load->view('userSignUp');
	}*/
}
