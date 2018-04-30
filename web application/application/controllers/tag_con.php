<?php

class tag_con extends CI_Controller 
{
   function __construct(){
       parent:: __construct();
       $this->load->model('tag_model','m');
   } 

   public function index(){
        $this->load->model('Model_profile');
        $result=$this->Model_profile->get_image($this->session->userdata('user_id')); //load profile data
        $dat=array(
            'imagepath'=> $result
        );
      $this->load->view('adminheader',$dat);
       $data['tags'] = $this->m->getTag();
       $this->load->view('tag_view', $data);
       
   }


   public function delete($id){     //delete tags
    $result = $this->m->delete($id);
    if($result){
        $this->session->set_flashdata('success_msg', 'Tag deleted successfully');
    }else{
        $this->session->set_flashdata('error_msg', 'Faill to delete tag');
    }
    redirect(base_url('tag_con/index'));
   }

   

   public function submit(){
    $result = $this->m->submit();
    if($result){
        $this->session->set_flashdata('success_msg', 'Record added successfully');
    }else{
        $this->session->set_flashdata('error_msg', 'Faill to add record');
    }
    redirect(base_url('tag_con/index'));
   }

}