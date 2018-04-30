<?php include("profmain.php");?>
			
					<div class="col-md-6">
						<h4>Change Password</h4>
					
            <div>
              Web Site
						 <form action="<?php echo base_url();?>/index.php/Upload/update_wpass" method="post">
  							<div class="form-group">
  								<br />
   								<label for="fname">New password:</label>
   								<input type="text" class="form-control" name="wpass" required>
  							</div>
                <button type="submit" class="btn btn-default" >Update</button>


              </form> 
            </div>

              <div>
                <br />
                Device<small>(should contain only digits)</small>
              <form action="<?php echo base_url();?>/index.php/Upload/update_Dpass" method="post">
  							<div class="form-group">
   								 <label for="fname">New password:</label>
   								 <input type="text" class="form-control" name="Dpass" required>  
  							</div>
  		
  							<button type="submit" class="btn btn-default">Update</button>
							</form> 
            </div>
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