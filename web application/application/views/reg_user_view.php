 <!DOCTYPE HTML>


<h3>Registered Users</h3>


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
            <td>User ID</td>
            <td>First Name</td>
            <td>Last Name</td>
            <td>NIC No</td>
            <td>Email</td> 
            <td>Tel No</td>
            <td>Card Id</td>
            <td>User Level</td>   
        </tr>
    </thead>
    <tbody>
    <?php
        if ($users) {
            foreach ($users as $user) {
    ?>
                <tr>
                    <td><?php echo $user->user_id?></td>
                    <td><?php echo $user->fName?></td>
                    <td><?php echo $user->lName?></td>
                    <td><?php echo $user->nic?></td>
                    <td><?php echo $user->email?></td>
                    <td><?php echo $user->phNum?></td>
                    <td><?php echo $user->card_id?></td>
                    <td><?php echo $user->userLevel?></td>
                    
                    <td>
                    <a href="<?php echo base_url('reg_user_con/edit/'.$user->user_id); ?>" class="btn btn-info">Edit</a>
					<a href="<?php echo base_url('reg_user_con/delete/'.$user->user_id); ?>" class="btn btn-danger" onclick="return confirm('Do you want to delete this record?');">Delete</a>
                    </td>
                </tr>
    <?php   
            }
        }
    ?>
    </tbody>

</table>

<a href="<?php echo base_url('reg_user_con/add'); ?>" class="btn btn-primary">Add New User</a>