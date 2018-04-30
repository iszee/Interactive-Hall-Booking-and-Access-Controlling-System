<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class tag_user_con extends CI_Controller 
{
   function __construct(){
       parent:: __construct();
       $this->load->model('tag_user_model','m');        //load model as m
   } 

   public function index(){
      $this->load->model('Model_profile');
        $result=$this->Model_profile->get_image($this->session->userdata('user_id')); //load profile data
        $data=array(
            'imagepath'=> $result
        );
        $this->load->view('adminheader',$data);
       $data['users'] = $this->m->getUser();
       $this->load->view('tag_user_view', $data);
       
   }

   public function edit($id){
       $data['user'] = $this->m->getUserById($id);      //edit tag users
       $this->load->model('Model_profile');        //get profile data to admin header
       $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
       $dat=array(
           'imagepath'=> $result
       );
       $this->load->view('adminheader',$dat);
       $this->load->view('user/edit_view', $data);
       
   }

   public function delete($id){         //dlete tag user
    $result = $this->m->delete($id);
    if($result){
        $this->session->set_flashdata('success_msg', 'User deleted successfully');
    }else{
        $this->session->set_flashdata('error_msg', 'Faill to delete user');
    }
    redirect(base_url('tag_user_con/index'));
   }

   public function update(){        //update tag users
    $result = $this->m->update();
    if($result){
        $this->session->set_flashdata('success_msg', 'User updated successfully');
    }else{
        $this->session->set_flashdata('error_msg', 'Faill to update User');
    }
    redirect(base_url('tag_user_con/index'));
   }

}
