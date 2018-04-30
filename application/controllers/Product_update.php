<?php

class Product_update extends CI_Controller

{
    public function index()
//        Loading the user image
    {
        $this->load->model('Model_profile');
            $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
            $data=array(
                'imagepath'=> $result
            );
        $this->load->view('adminheader',$data);

        $this->load->view('product_update');
    }


    public function Home(){
        $this->load->model('Product_model');
//        if (isset($_POST['submit'])){
//            if ($this->Product_update->UpdateProductData()){
//                redirect('product_update/index');
//            }
//            else{
//                this->load->view('test')
//        }
        $this->Product_model->UpdateProductData();
//        $this->session->set_flshdata('success','Ok');
        //$this->load->view('product_update');

//        uploading the image
    }
    public function do_upload()
    {
        $config['upload_path']          = './uploads/';
        $config['allowed_types']        = 'jpg|png|jpeg';
        $config['max_size']             = 10000;
        $config['max_width']            = 20240;
        $config['max_height']           = 76800;
        $this->load->library('upload', $config);
        if ( ! $this->upload->do_upload('Imageinput'))
        {
            //$error = array('error' => $this->upload->display_errors());
            redirect("Product_update/Index");
        }
        else
        {
            $data = array('upload_data' => $this->upload->data());
            //print_r($data);
            $image_path=base_url("uploads/".$data['upload_data']['raw_name'].$data['upload_data']['file_ext']);
            //$arr['image']= $image_path;
            unset($data['submit']);
            $this->load->model('Product_model');  
            $this->Product_model->UpdateProductData($image_path);         
            redirect("Product_update/Index");       
        }
        //$this->load->view('nheader');
        //$this->load->view('cimage');*/
    }

//    loading the view
    public function view_infore(){
        $this->load->model('Model_profile');
        $result=$this->Model_profile->get_image($this->session->userdata('user_id'));
        $data=array(
            'imagepath'=> $result
        );
        $this->load->view("productsinfo",$data);
    }
}