<?php


class register extends CI_Controller
{
	
	public function RegisterUser()
	{
		$this->form_validation->set_rules('username','User Name','required');
		$this->form_validation->set_rules('email','Email','required|valid_email|is_unique[user_reg.email]');
		$this->form_validation->set_rules('nic','NIC','required');
		$this->form_validation->set_rules('contact','Contact Number','required');
		$this->form_validation->set_rules('usertype','User Type','required');
		$this->form_validation->set_rules('password','Password','required');

		if ($this->form_validation->run() == False) {
			$this->load->view('Admin');
		}
		else{
			
			$this->load->model('Model_user');
			$response = $this->Model_user->InsertUserData();
			if ($response) {
				$this->session->set_flashdata('msg','registered successfully');
				redirect('Home/admin');
			}

			else ($response){
            $this->session->set_flashdata('msg', 'Something went wrong');
            redirect('Home/admin');
        }
		}


	}
}




?>