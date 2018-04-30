<h3>Edit Tag Users</h3>
	<a href="<?php echo base_url('tag_user_con/index'); ?>" class="btn btn-primary">Back</a>
   
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

    
	<form  action="<?php echo base_url('tag_user_con/update') ?>" method="post" class="form-horizontal">
		<input type="hidden" name="txt_hidden" value="<?php echo $user->user_id; ?>">
		<div class="form-group">
			<label for="fname" class="col-md-2 text-right">First Name</label>
			<div class="col-md-10">
				<input type="text" value="<?php echo $user->fName; ?>" name="fname" class="form-control" required>
			</div>
		</div>
		<div class="form-group">
			<label for="lname" class="col-md-2 text-right">Last Name</label>
			<div class="col-md-10">
				<input name="lname" class="form-control" value="<?php echo $user->lName; ?>" required>
			</div>
		</div>
        <div class="form-group">
			<label for="nic" class="col-md-2 text-right">NIC No</label>
			<div class="col-md-10">
				<input name="nic" class="form-control" value="<?php echo $user->nic; ?>" required>
			</div>
		</div>
		<div class="form-group">
			<label class="col-md-2 text-right"></label>
			<div class="col-md-10">
				<input type="submit" name="btnUpdate" class="btn btn-primary" value="Update">
			</div>
		</div>
	</form>
	