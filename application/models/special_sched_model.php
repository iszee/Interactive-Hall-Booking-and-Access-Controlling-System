<?php

class special_sched_model extends CI_Model 
{


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

     public function insertToOthers($data_nonreg,$data_nlec,$data_sched){   //according to user id insert to nonreg, schedule2 and nlec table
        
         $this->db->insert('nonreguser',$data_nonreg);
         $this->db->insert('nlecture',$data_nlec);
         $this->db->insert('schedule',$data_sched);
 
         
 
 
     }
}

