<?php


class tag_issue_con extends CI_Controller {

	function __construct(){
		parent:: __construct();
		$this->load->model('tag_issue_model', 'm');     //load model
	}

	public function index(){
        $this->load->model('Model_profile');        //get profile data to admin header
        $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
        $dat=array(
            'imagepath'=> $result
        );
		$this->load->view('adminheader',$dat);
		$this->load->view('tag_issue_view');
	}

	public function insert(){

		$this->session->unset_userdata('suc');      //unset erlier session data
		

		//form validation
		$this->form_validation->set_rules('fname', 'First Name', 'required');
		$this->form_validation->set_rules('lname', 'Last Name', 'required');
		$this->form_validation->set_rules('nic', 'NIC No', 'required');

		if($this->form_validation->run() == TRUE){

			$data_user = array('userName' => $this->input->post('fname'));
			
			$tag_id = $this->m->newTag();  //allocate tag
			if($tag_id){

					//get the the genrated user id 
				$user_id = $this->m->insertToUser($data_user);
				
				if($user_id){
					$data_stud = array(         //data for nonreg user table
						'user_id' => $user_id,
						'fName' => $this->input->post('fname'),
						'lName' => $this->input->post('lname'),
						'nic' => $this->input->post('nic'),
					);
		
					
					$data_tag = array(          //data for nstudent table
						'nuser_id' => $user_id,
						'tagId' =>  $tag_id,
					);
		
					$this->m->insertToOthers($data_stud,$data_tag); //insert to others
					$this->session->set_flashdata('suc', 'tag user added successfully');

                    $this->load->model('Model_profile');        //get profile data to admin header
                    $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
                    $dat=array(
                        'imagepath'=> $result
                    );
					
					$this->load->view('adminheader',$dat);
					$this->load->view('tag_issue_view');
				}
				else{
                    $this->load->model('Model_profile');        //get profile data to admin header
                    $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
                    $dat=array(
                        'imagepath'=> $result
                    );
					$this->session->set_flashdata('exist', 'User Name already taken please try with another');
					$this->load->view('adminheader',$dat);
					$this->load->view('tag_issue_view');

					
				}
			}
			else{
                $this->load->model('Model_profile');        //get profile data to admin header
                $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
                $dat=array(
                    'imagepath'=> $result
                );
				$this->session->set_flashdata('notag', 'No tags available');
				$this->load->view('adminheader',$dat);
				$this->load->view('tag_issue_view');
				
			}

			
		}
		else {
			$this->session->set_flashdata('notValid', 'Please fill all te details');
            $this->load->model('Model_profile');        //get profile data to admin header
            $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
            $dat=array(
                'imagepath'=> $result
            );
			$this->load->view('adminheader',$dat);
			$this->load->view('tag_issue_view',TRUE);
			
			
			}


		
			
		
		

		
        
	}
}
