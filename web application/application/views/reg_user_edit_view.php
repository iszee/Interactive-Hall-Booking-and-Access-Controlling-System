<h3>Edit Registrered Users</h3>
<a href="<?php echo base_url('reg_user_con/index'); ?>" class="btn btn-primary">Back</a>

	<form  action="<?php echo base_url('reg_user_con/update') ?>" method="post" class="form-horizontal">
		<input type="hidden" name="txt_hidden" value="<?php echo $user->user_id; ?>">
		<div class="form-group">
			<label for="fname" class="col-md-2 text-right">First Name</label>
			<div class="col-md-5">
				<input type="text" value="<?php echo $user->fName; ?>" name="fname" class="form-control" required>
			</div>
		</div>
		<div class="form-group">
			<label for="lname" class="col-md-2 text-right">Last Name</label>
			<div class="col-md-5">
				<input name="lname" class="form-control" value="<?php echo $user->lName; ?>" required>
			</div>
		</div>
        <div class="form-group">
			<label for="nic" class="col-md-2 text-right">NIC No</label>
			<div class="col-md-5">
				<input name="nic" class="form-control" value="<?php echo $user->nic; ?>" required>
			</div>
		</div>
        <div class="form-group">
			<label for="email" class="col-md-2 text-right">Email</label>
			<div class="col-md-5">
				<input name="email" class="form-control" value="<?php echo $user->email; ?>" required>
			</div>
		</div>
        <div class="form-group">
			<label for="phNum" class="col-md-2 text-right">Tel No</label>
			<div class="col-md-5">
				<input name="phNum" class="form-control" value="<?php echo $user->phNum; ?>" required>
			</div>
		</div>
        
		<div class="form-group">
			<label class="col-md-2 text-right"></label>
			<div class="col-md-5">
				<input type="submit" name="btnUpdate" class="btn btn-primary" value="Update">
			</div>
		</div>
	</form>
	