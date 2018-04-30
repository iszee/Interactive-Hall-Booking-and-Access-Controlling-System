<?php
	
	class Login extends CI_Controller
	{
		
		public function LoginUser()
		{
			$this->form_validation->set_rules('username','User Name','required');
			$this->form_validation->set_rules('password','Password','required');

			if ($this->form_validation->run() == False) {
				$this->session->set_flashdata('errmsg','Username or Password incorrect');
				$this->load->view('home');

			}
			else{
			
				$this->load->model('Model_user');
				$result = $this->Model_user->LoginUser();


				if ($result != false) {
					$user_data = array(
						'user_id' =>$result->user_id ,
						'user_name' =>$this->input->post('username') ,
						'loggedin' => TRUE
					);


					$this->session->set_userdata($user_data);
					$this->session->set_flashdata('welcome');
					if ($result->userLevel==3) {
						//var_dump($result);
						redirect('Home/logged');
					}
					else{
						redirect('admin_home_con/index');
					}
					

				}
				else{
					$this->session->set_flashdata('errmsg','Username or password incorrect');
					redirect('Home/index');
				}
				//var_dump($result);
			}
		}


		

	}

?>