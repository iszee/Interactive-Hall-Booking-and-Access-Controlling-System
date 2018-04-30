<?php
class Product_model extends CI_Model
{

    public function UpdateProductData($path)
    {
        $data = array(
            'product_id' => $this->input->post('PID', 'TRUE'),
            'prodDes' => $this->input->post('PDES', 'TRUE'),
            'prodImagePath' => $path
        );

        return $this->db->insert('products', $data);
    }
}
?>