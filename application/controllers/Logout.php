<?php

class Logout extends CI_Controller

{
    public function logoutuser()
    {
        $this->session->unset_userdata('data_one');
        $this->session->unset_userdata('data_two');
        $this->session->unset_userdata('data_three');
        $this->session->unset_userdata('data_one');
        $this->session->sess_destroy();
        redirect('Home/index');
    }
}
?>