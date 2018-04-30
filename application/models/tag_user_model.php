<?php

class tag_user_model extends CI_Model 
{

    public function getUser(){  //get tag users from db for view
        $this->db->select('*')->select('nonreguser.*,nstudent.* ')->from('nonreguser')      //get data from nonreg JOIN nstudent
        ->join('nstudent', 'nstudent.nuser_id = nonreguser.user_id')
        ->group_by('nonreguser.user_id');
        $query = $this->db->get();

        if($query->num_rows() > 0){
            return $query->result();
        }
        else {
            return false;
        }
        

    }

    public function getUserById($id){
        $this->db->select('*')->select('nonreguser.*,nstudent.* ')->from('users')       //get user from nonreg JOIN nstudent by id
        ->join('nonreguser', 'nonreguser.user_id = users.user_id', 'LEFT')
        ->join('nstudent', 'nstudent.nuser_id = nonreguser.user_id', 'LEFT')
        ->group_by('users.user_id')
        ->where('users.user_id', $id);
        $query = $this->db->get();

        if($query->num_rows() > 0){
            return $query->row();
        }
        else {
            return false;
        }
        
    }
    
    public function update(){                   //update tag user from edit view (edit view at the user folder)
        $id = $this->input->post('txt_hidden');
		$field = array(
			'fName'=>$this->input->post('fname'),
			'lName'=>$this->input->post('lname'),
			'nic'=>$this->input->post('nic')
			);
		$this->db->where('user_id', $id);
		$this->db->update('nonreguser', $field);
		echo $this->db->last_query();extit;
		if($this->db->affected_rows() > 0){
			return true;
		}else{
			return false;
		}
    }

    public function delete($id){
         //delete from nstudent and update tag status
        $sql = "update tags set tagStatus='0' where tag_id = (select tagId from nstudent where nuser_id = '$id')"; //update tag status
        $this->db->query($sql);
        $this->db->where('nuser_id',$id); //delete tag user
        $this->db->delete('nstudent');
        
        
        if($this->db->affected_rows() > 0){ 
			return true;
		}else{
            return false;
          
		}
    }
    
}
