<?php

class reg_user_model extends CI_Model 
{

    public function getUser(){          //retreive users from db
        $this->db->select('*')->from('reguser')
        ->group_by('reguser.user_id');
        $query = $this->db->get();

        if($query->num_rows() > 0){
            return $query->result();
        }
        else {
            return false;
        }
        

    }

    public function getCard(){
        $this->db->select('*')->from('cards')       //check for available cards
        ->where('accStatus',0)
        ->group_by('cards.card_id');
        $query = $this->db->get();

        if($query->num_rows() > 0){
            return $query->result();
        }
        else {
            return false;
        }
    }

    public function getUserById($id){       //retreive user by id for edit
        $this->db->select('*')->from('reguser')
        ->group_by('reguser.user_id')
        ->where('reguser.user_id', $id);
        $query = $this->db->get();

        if($query->num_rows() > 0){
            return $query->row();
        }
        else {
            return false;
        }
        
    }
    
    public function update($id,$field){     //insert to reguser with updated details
		$this->db->where('user_id', $id);
		$this->db->update('reguser', $field);
		echo $this->db->last_query();extit;
		if($this->db->affected_rows() > 0){
			return true;
		}else{
			return false;
		}
    }

    public function delete($id){        //delete reg user
        
        $sql = "update cards set accStatus=0 where card_id = (select card_id from reguser where user_id = '$id')";
        $this->db->query($sql);
        $this->db->where('user_id',$id);
        $this->db->delete('reguser');
        
        if($this->db->affected_rows() > 0){ 
			return true;
		}else{
            return false;
          
		}
    }

    public function insertToUser($data_user){ //return to controller if user id created
        
        //check user name alreay taken
        $exist = $this->db->get_where('users',array('userName'=>$data_user['userName']));
        if ($exist->num_rows()>0) {
            return false;
        }

        else{
            $this->db->insert('users',$data_user);
            if($this->db->affected_rows() > 0){
                $user_id = $this->db->insert_id();
               
                return $user_id;
           
            }
            else{
              
                return false;

            }
        }
        
        
         
         
 
 
     }

     public function insertToReg($data_reg){   //according to user id insert to reguser table
        
         $this->db->insert('reguser',$data_reg);
 
         
 
 
     }

     public function newCard(){  //allocate card to reg user

        $result = $this->db->get_where('cards',array('accStatus' => 0));
        $row = $result->row();
        if($row){
            $card_id = $row->card_id;
            $this->db->where('card_id',$card_id);
            $this->db->update('cards',array('accStatus' => -1));
            return $card_id;
        }
        else {
            return false;
        }
        
     }

    
    
}
