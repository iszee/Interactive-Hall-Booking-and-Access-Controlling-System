<!DOCTYPE HTML>

<h3>Tag Users</h3>

<div class="container">
  
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



<table class="table table-bordered table-responsive">
    <thead>
        <tr>
            <td>First Name</td>
            <td>Last Name</td>
            <td>NIC No</td>
            <td>Tag ID</td>    
        </tr>
    </thead>
    <tbody>
    <?php
        if ($users) {
            foreach ($users as $user) {
    ?>
                <tr>
                    <td><?php echo $user->fName?></td>
                    <td><?php echo $user->lName?></td>
                    <td><?php echo $user->nic?></td>
                    <td><?php echo $user->tagId?></td>
                    <td>
                    <a href="<?php echo base_url('tag_user_con/edit/'.$user->user_id); ?>" class="btn btn-info">Edit</a>
					<a href="<?php echo base_url('tag_user_con/delete/'.$user->user_id); ?>" class="btn btn-danger" onclick="return confirm('Do you want to delete this record?');">Delete</a>
                    </td>
                </tr>
    <?php   
            }
        }
    ?>
    </tbody>

</table>

<a href="<?php echo base_url('tag_issue_con/index'); ?>" class="btn btn-primary">Add New User</a>
