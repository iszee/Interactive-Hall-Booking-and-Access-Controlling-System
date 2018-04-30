<?php

class tag_model extends CI_Model 
{
    public function getTag(){       //retrieve tags from db
        
        $query = $this->db->get('tags');
        if($query->num_rows() > 0){
            return $query->result();
        }
        else {
            return false;
        }
    }

    public function delete($id){        //delete tags from db
        $this->db->where('tag_id',$id);
        $this->db->delete('tags');
        if($this->db->affected_rows() > 0){
			return true;
		}else{
            return false;
          
		}
    }

    
}
