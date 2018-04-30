

<?php include("profmain.php");  ?>

<!-- <?php echo form_open_multipart('upload/do_upload');?>

<input type="file" name="userfile"  />

<br /><br />

<input type="submit" value="upload" />

</form> -->

<div class="col-md-4" id="proChFile" >
	<form class="form-horizontal" id="fChFile" action="<?php echo base_url();?>/index.php/Upload/do_upload" method="post">
		<div class="form-group">
	    	<div class="col-sm-10" id="inChFile" >
	      		<input type="file" class="form-control" name="userfile">
	    	</div>
	  	</div>
	  	<div class="form-group">
	    	<div class="col-sm-offset-2 col-sm-10">
	      		<button type="submit" class="btn btn-default" name="upload">Update</button>
	    	</div>
	  	</div>
	</form>
</div>
</body>
</html>