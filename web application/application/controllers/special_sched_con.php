<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class special_sched_con extends CI_Controller 
{
   function __construct(){
       parent:: __construct();
       $this->load->model('special_sched_model','m');       // load model as m
   } 

   public function index(){
        $this->load->model('Model_profile');
        $result=$this->Model_profile->get_image($this->session->userdata('user_id'));       //load profile data
        $data=array(
            'imagepath'=> $result
        );
        $this->load->view('adminheader',$data);
       $this->load->view('special_sched_view');
       
   }



    public function submit(){

        $this->session->unset_userdata('suc');  //unset erlier session data
        $this->session->unset_userdata('exist');
        
        

        //form validation
        $this->form_validation->set_rules('fName', 'First Name', 'required');
        $this->form_validation->set_rules('lName', 'Last Name', 'required');
        $this->form_validation->set_rules('nic', 'NIC No', 'required');
        $this->form_validation->set_rules('startTime', 'Start Time', 'required');
        $this->form_validation->set_rules('endTime', 'End Time', 'required');
        $this->form_validation->set_rules('scheDate', 'Date', 'required');
        $this->form_validation->set_rules('passDevice', 'Password', 'required|is_unique[nlecture.passDevice]');

      
        if ($this->form_validation->run() == TRUE) {
            $data_user = array('userName' => $this->input->post('fName'));
            
    
                    //get the the genrated user id 
                $user_id = $this->m->insertToUser($data_user);
                
                if($user_id){
                    $data_nonreg = array(       //data for nonreg table
                        'user_id' => $user_id,
						'fName' => $this->input->post('fName'),
						'lName' => $this->input->post('lName'),
						'nic' => $this->input->post('nic'),
                    );

                    $data_nlec = array(     //data for nlecture table
                        'nuser_id' => $user_id,
                        'passDevice' => $this->input->post('passDevice')

                    );

                    $data_sched = array(        //data for schedule table
                        'scheType' => "special",
                        'user_id' => $user_id,
                        'startTime' => $this->input->post('startTime'),
                        'endTime' => $this->input->post('endTime'),
                        'scheDate' => $this->input->post('scheDate')
                    );

                    $this->m->insertToOthers($data_nonreg,$data_nlec,$data_sched);
                    
                    $this->session->set_flashdata('suc', 'Schedule added successfully');
                    $this->load->model('Model_profile');
                    $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
                    $dat=array(
                        'imagepath'=> $result
                    );
                    
                    $this->load->view('adminheader',$dat);
                    $this->load->view('special_sched_view');
                }
                else{
                    $this->session->set_flashdata('exist', 'User Name already taken please try with another');
                    $this->load->model('Model_profile');
                    $result=$this->Model_profile->get_image($this->session->userdata('user_id'));       //load profile data
                    $dat=array(
                        'imagepath'=> $result
                    );
                    $this->load->view('adminheader',$dat);
                    $this->load->view('special_sched_view');
    
                    
                }
            
           

        }
    
            
        
        
         else {
             $this->load->model('Model_profile');
             $result=$this->Model_profile->get_image($this->session->userdata('user_id'));       //load profile data
             $data=array(
                 'imagepath'=> $result
             );
            $this->load->view('adminheader',$data);
            $this->load->view('special_sched_view');
        }
       

    
        
    
    

    
    
}


}
