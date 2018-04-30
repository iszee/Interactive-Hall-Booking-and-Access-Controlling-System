<?php

class Upload extends CI_Controller {

        public function load_update(){
            $this->load->model('Model_profile');
            $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
            $data=array(
                'imagepath'=> $result
            );
            //$this->session->set_flashdata('msg',$msg);
           // $this->load->view('nheader',$data);

            $this->load->view('profile',$data);
        }
        public function update_data(){
            $this->form_validation->set_rules('tp','Phone Number','numeric');
            if ($this->form_validation->run() == TRUE){
                $this->load->model('Model_profile');
                $update=$this->Model_profile->update_data($this->session->userdata('user_id'));
                $this->session->set_flashdata('suc','Successfully Updated');
                 $this->load_update();
                /*if($update==True){
                $this->session->set_flashdata('suc','Successfully Updated');  
                }
                else{
                 $this->session->set_flashdata('err','Something went wrong');
                }
                $this->load_update();*/
            }
            else{
                $this->session->set_flashdata('err','Something went wrong');
                 $this->load_update();
            }
        }

        public function load_security($msg=""){
            $this->load->model('Model_profile');
            $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
            $data=array(
                'imagepath'=>$result
            );
            $this->session->set_flashdata('msg',$msg);
            //$this->load->view('nheader',$data);
            $this->load->view('security',$data);
        }
        public function update_wpass(){
            $this->load->model('Model_profile');
            $respond=$this->Model_profile->update_wpass($this->session->userdata('user_id'));
            //var_dump($respond);
            if($respond==true){
                //$this->session->set_flashdata('msg','Successful');

                $this->load_security("Successful");
            }
            else{
                $this->load_security("Provided Current Password invalid");
            }

        }

        public function update_Dpass(){
            $this->form_validation->set_rules('Dpass','Password','numeric');
            $this->load->model('Model_profile');
            $respond=$this->Model_profile->update_dpass($this->session->userdata('user_id'));
            if($respond==true){
                
                 $this->load_security("Successful");
            }
            else{
                $this->load_security("Provided Current Password invalid");
            }
        }
 
        public function index()
        {
                //$this->load->view('nheader');
                $this->load->view('profmain');
        }

        public function do_upload()
        {
                $config['upload_path']          = './uploads/';
                $config['allowed_types']        = 'jpg|png|jpeg';
                $config['max_size']             = 10000;
                $config['max_width']            = 20240;
                $config['max_height']           = 76800;

                $this->load->library('upload', $config);

                if ( ! $this->upload->do_upload('userfile'))
                {
                    echo "error";
                       // $error = array('error' => $this->upload->display_errors());
                       // $this->load->view('cimage', $error);

                }
                else
                {
                        $data = array('upload_data' => $this->upload->data());
                       // $this->load->view('upload_success', $data);
                        // get the parth of the image detail are return as array of array
                        $image_path=base_url("uploads/".$data['upload_data']['raw_name'].$data['upload_data']['file_ext']);

                        $arr['image']= $image_path;
                        unset($data['submit']);
                        $this->load->model('Model_profile');
                       // $this->Model_profile->getid( $this->session->userdata('user_name'));
                        $this->Model_profile->upload_image($arr, $this->session->userdata('user_id'));
                }
               // $this->load->view('nheader');
                $this->load_update();
        }
        public function load_admin(){

            $this->load->model('Model_profile');
            $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
            $data=array(
                'imagepath'=> $result
            );
            $this->load->view('admin_profile',$data);
        }
        public function load_secadmin(){

            $this->load->model('Model_profile');
            $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
            $data=array(
                'imagepath'=> $result
            );
            $this->load->view('admin_security',$data);
        }

}
?>