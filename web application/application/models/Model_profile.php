<?php

class Model_profile extends CI_Model
{
	public function update_data($id){

		$fName=$this->input->post('firstName');
		$lName=$this->input->post('lastName');
		$phNum=$this->input->post('tp');
 
		//$this->update('reguser',$data,$uname);
		$sql = "UPDATE reguser SET fName='$fName',lName='$lName',phNum='$phNum'  WHERE user_id='$id'"; 
		$this->db->query($sql);
		return True;

	}
	public function update_wpass($id){
		$this->db->select('user_id');
		$this->db->where('passWeb',$this->input->post('cpass'));
		$respond=$this->db->get('reguser');
		//return $respond->result_array();
		//var_dump($respond->num_rows());
		if($respond->num_rows()==1){
			$wpass=$this->input->post('wpass');
			$sql = "UPDATE reguser SET passWeb='$wpass'  WHERE user_id='$id'";
			$this->db->query($sql);
			return true;
		}
		else{
			return false;
		}
		
	}
	public function update_Dpass($id){
		$this->db->select('user_id');
		$this->db->where('passDevice',$this->input->post('cpass'));
		$respond=$this->db->get('reguser');
		//return $respond->result_array();
		//var_dump($respond->num_rows());
		if($respond->num_rows()==1){
			$wpass=$this->input->post('Dpass');
			$sql = "UPDATE reguser SET passDevice='$wpass'  WHERE user_id='$id'";
			$this->db->query($sql);
			return true;
		}
		else{
			return false;
		}
		
	}

	/*public function getid($username){
		$sql = "SELECT user_id FROM users  WHERE userName='$username'";
		$data = $this->db->query($sql);
		// above code segment used to get id where user name =$username
		return $data->result_array();

	}*/

	public function upload_image($path,$id){
		$img=$path['image'] ;
		$sql = "UPDATE reguser SET userImage='$img'  WHERE user_id='$id'";
		$this->db->query($sql); // store image path in db

	

	}
	public function get_image($id){
		$sql="SELECT userImage FROM reguser WHERE user_id='$id'";
		$result=$this->db->query($sql);

		if($result->num_rows()==1){
			return $result->result_array();
			//echo "hello";
		}
		else{
			return false;
			//echo "hello";
		}

	}
	public function getSched($id)
    {

        $this->db->where('user_id', $id);
        $query = $this->db->get('schedule');
        if ($query->num_rows() > 0) {
            return $query->result_array();
        } else {
            return false;
        }
    }
}