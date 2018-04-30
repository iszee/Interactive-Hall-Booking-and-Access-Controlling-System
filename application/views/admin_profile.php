<?php include("admin_prof.php");?>
					<div class="col-md-6">
						<h4>UPDATE DETAILS</h4>
						<small>You can only update following details only</small>

            <?php echo validation_errors(); ?>

            <?php if($this->session->flashdata('suc')){?>
              <div class='alert alert-success'>successfully added</div>        
            <?php ;} ?>
            <?php if($this->session->flashdata('err')){?>
            <div class='alert alert-warning'><?php echo $this->session->flashdata('err');?></div>        
            <?php ;} ?>

						 <form action="<?php echo base_url()?>/index.php/Upload/update_data" method="post">
  							<div class="form-group">
  								<br />
   								<label for="fname">First Name:</label>
   								<input type="text" class="form-control" name="firstName" required>
  							</div>
  							<div class="form-group">
   								 <label for="lname">Last Name:</label>
   								 <input type="text" class="form-control" name="lastName" required>  
  							</div>
  							<div class="form-group">
   								<label for="pwd">Phone Number</label>
    							<input type="text" class="form-control" name="tp" required>
  							</div>
  		
  							<button type="submit" class="btn btn-default">Update</button>
							</form> 
						
					</div>
          <div>
            
            <?php foreach ($imagepath as $value) {?>
              <img src="<?php echo $value['userImage'];?> " class="img-rounded" id="img" style="width: 300px; margin-left: 20px; border-radius: 10px;">

              <?php }?>

            <?php echo form_open_multipart('upload/do_upload');?>
              <div class="row">
                <input type="file" id="brows" name="userfile" style="margin-left: 30px; margin-top: 10px;">
                <input type="submit" value="upload" id=s"size" style="margin-left: 30px; margin-top: 10px;" > 
              </div>
            <?php echo form_close();?>
          
          </div>

			</div>
		</div>


</body>
</html>