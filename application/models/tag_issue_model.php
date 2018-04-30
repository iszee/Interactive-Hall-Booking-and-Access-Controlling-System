<?php

class tag_issue_model extends CI_Model
{

    public function insertToUser($data_user){ //return to controller if user id created
        
        //check user name alreay taken
        $exist = $this->db->get_where('users',array('userName'=>$data_user['userName']));
        if ($exist->num_rows()>0) {
            return false;
        }

        else{
            $this->db->insert('users',$data_user);      //insert to user table
            if($this->db->affected_rows() > 0){
                $user_id = $this->db->insert_id();
                return $user_id;
            }
            else{
                return false;
            }
        }
        
         
         
 
 
     }

     public function newTag(){  //allocate a tag to user and make it status active and return tag id

        $result = $this->db->get_where('tags',array('tagStatus' => "0"));
        $row = $result->row();      //get only one row from result
        if($row){
            $tag_id = $row->tag_id;
            $this->db->where('tag_id',$tag_id);
            $this->db->update('tags',array('tagStatus' => "1"));
            return $tag_id;
        }
        else {
            return false;
        }
        
     }

    public function insertToOthers($data_stud,$data_tag){   //according to user id insert to other tables
       
        $this->db->insert('nonreguser',$data_stud);
        $this->db->insert('nstudent',$data_tag);

        


    }
    
}
