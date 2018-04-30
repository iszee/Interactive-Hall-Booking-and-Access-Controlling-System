<?php

class accessdet_model extends CI_Model 
{
    public function getAccess(){
        
        $query = $this->db->get('accesshistory');       //retreive access history from db
        if($query->num_rows() > 0){
            return $query->result();
        }
        else {
            return false;
        }
    }
}
