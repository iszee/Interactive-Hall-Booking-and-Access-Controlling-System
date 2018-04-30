<!DOCTYPE html>
<html>

<h3>Add Tag User</h3>

<a href="<?php echo base_url('tag_user_con/index'); ?>" class="btn btn-primary">Back</a>

  <div class="container">
  
  <?php if ($this->session->flashdata('exist')) { ?>
    <div class="alert alert-danger">
    <h5 class="text-danger"><?php echo $this->session->flashdata('exist');?></h5>

    </div>
  <?php }?>
  <?php if($this->session->flashdata('notag')){?>
    
    <div class="alert alert-danger">
    <h5 class="text-danger"><?php echo $this->session->flashdata('notag');?></h5>

    </div>
    <?php } ?>
    <?php if ($this->session->flashdata('success_msg')) { ?>
    <div class="alert alert-success">
    <h5 class="text-success"><?php echo $this->session->flashdata('success_msg');?></h5>

    </div>
  <?php }?>
  <?php if($this->session->flashdata('error_msg')){?>
    
    <div class="alert alert-danger">
    <h5 class="text-danger"><?php echo $this->session->flashdata('error_msg');?></h5>

    </div>
    <?php } ?>
    <?php
    if($this->session->flashdata('suc')){?>
    <div class="alert alert-success">
    <h5 class="text-success"><?php echo $this->session->flashdata('suc');?></h5>

    </div>
    <?php }?>
    
  <?php  
  
 
    echo form_open('tag_issue_con/insert');  
 
    ?>
    <form>
   

      <div class="form-group">
      <h6 class="text-danger"><?php echo form_error('fname'); ?></h6>
        <label for="fname">First Name</label>
        <input type="text" class="form-control" name="fname">
      </div>

      <div class="form-group">
      <h6 class="text-danger"><?php echo form_error('lname'); ?></h6>
      <label for="lname">Last Name</label>
        <input type="text" class="form-control" name="lname">
      </div>

      <div class="form-group">
      <h6 class="text-danger"><?php echo form_error('nic'); ?></h6>
      <label for="nic">NIC No</label>
        <input type="text" class="form-control" name="nic">
      </div>

      <button type="submit" class="btn btn-primary">Issue</button>

     

    </form>
    <?php echo 
      form_close();
      ?>
  </div>




</html>
