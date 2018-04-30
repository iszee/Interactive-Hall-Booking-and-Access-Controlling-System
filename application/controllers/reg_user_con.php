<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class reg_user_con extends CI_Controller 
{
   function __construct(){
       parent:: __construct();
       $this->load->model('reg_user_model','m');
   } 

   public function index(){
        $this->load->model('Model_profile');        //get profile data to admin header
        $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
        $dat=array(
            'imagepath'=> $result
        );
        $this->load->view('adminheader',$dat);
       $data['users'] = $this->m->getUser();    //get all the register users to view
       $this->load->view('reg_user_view', $data);
       
   }

   public function edit($id){
       $data['user'] = $this->m->getUserById($id);      //get particular user data call by id to edit
       $this->load->model('Model_profile');        //get profile data to admin header
       $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
       $dat=array(
           'imagepath'=> $result
       );
       $this->load->view('adminheader',$dat);
       $this->load->view('reg_user_edit_view', $data);
       
   }

   public function delete($id){
    $result = $this->m->delete($id);        //delete user call to model
    if($result){    //get the return from model
        $this->session->set_flashdata('success_msg', 'User deleted successfully');
    }else{
        $this->session->set_flashdata('error_msg', 'Faill to delete User');
    }
    redirect(base_url('reg_user_con/index'));
   }

   public function update(){

    $id = $this->input->post('txt_hidden');     // hidden id at edit view
    $field = array(                             //update data with new posts
        'fName'=>$this->input->post('fname'),
        'lName'=>$this->input->post('lname'),
        'nic'=>$this->input->post('nic'),
        'email'=>$this->input->post('email'),
        'phNum'=>$this->input->post('phNum')
        );
    $result = $this->m->update($id,$field);     //cal to model update
    if($result){                                //return from update
        $this->session->set_flashdata('success_msg', 'User updated successfully');
    }else{
        $this->session->set_flashdata('error_msg', 'Faill to update user');
    }
    redirect(base_url('reg_user_con/index'));
   }

   public function add(){   //load reg user add view
    $data['res'] = $this->m->getCard();     //load available cards to add reg user


       $this->load->model('Model_profile');        //get profile data to admin header
       $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
       $dat=array(
           'imagepath'=> $result
       );
    $this->load->view('adminheader',$dat);
    $this->load->view('reg_user_add_view',$data);
    }

    public function submit(){

        $this->session->unset_userdata('suc');          //unset earlier session data
        $this->session->unset_userdata('notag');
		$this->session->unset_userdata('exist');
        


        //form validation
        $this->form_validation->set_rules('fName', 'First Name', 'required');
        $this->form_validation->set_rules('lName', 'Last Name', 'required');
        
        $this->form_validation->set_rules('nic', 'NIC No', 'required|is_unique[reguser.nic]',array('is_unique'=>'NIC No already exist'));
        
        $this->form_validation->set_rules('email', 'Email', 'required|valid_email|is_unique[reguser.email]',array('is_unique'=>'email is already exist'));
        $this->form_validation->set_rules('phNum', 'Tel No', 'required');
        $this->form_validation->set_rules('card_id', 'Card Id', 'required');
        $this->form_validation->set_rules('userLevel', 'User Level', 'required');

        $data['res'] = $this->m->getCard();  //check for cards
        if ($this->form_validation->run() == TRUE) {
            $data_user = array('userName' => $this->input->post('nic'));
            
            $card_id = $this->m->newCard();  //allocate card
            if($card_id){
    
                    //get the the genrated user id 
                $user_id = $this->m->insertToUser($data_user);

                if($user_id){
                    $data_reg = array(
                        'user_id' => $user_id,
                        'fName' => $this->input->post('fName'),
                        'lName' => $this->input->post('lName'),
                        'nic' => $this->input->post('nic'),
                        'email' => $this->input->post('email'),
                        'phNum' => $this->input->post('phNum'),
                        'card_id' => $this->input->post('card_id'),
                        'userLevel' => $this->input->post('userLevel'),
                    );

                    $this->m->insertToReg($data_reg);
                    
                    $this->session->set_flashdata('suc', 'Data inserted successfully');

                    $this->load->model('Model_profile');        //get profile data to admin header
                    $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
                    $dat=array(
                        'imagepath'=> $result
                    );
                  
                    $this->load->view('adminheader',$dat);
                    $this->load->view('reg_user_add_view',$data);
                    
                }
                else{
                    $this->session->set_flashdata('exist', 'User Name already taken please try with another');
                    $this->load->model('Model_profile');        //get profile data to admin header
                    $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
                    $dat=array(
                        'imagepath'=> $result
                    );
                    $this->load->view('adminheader',$dat);
                    $this->load->view('reg_user_add_view',$data);
    
                    
                }
            }
            else{
                $this->session->set_flashdata('notag', 'No Cards available');
                $this->load->model('Model_profile');        //get profile data to admin header
                $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
                $dat=array(
                    'imagepath'=> $result
                );
                $this->load->view('adminheader',$dat);
                $this->load->view('reg_user_add_view',$data);
                
            }

        }
    
            
        
        
         else {
            $this->session->set_flashdata('notValid', 'Please fill all the details');
             $this->load->model('Model_profile');        //get profile data to admin header
             $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
             $dat=array(
                 'imagepath'=> $result
             );
            $this->load->view('adminheader',$dat);
            $this->load->view('reg_user_add_view',$data);
        }
       

    
        
    
    

    
    
}


}
