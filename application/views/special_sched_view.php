<script src="<?php echo base_url().'bootstrap/dist/js/bootstrap.bundle.min.js'?>"></script>
<script type="text/javascript">
	
      function genCode() {

          var digit =  Math.floor(Math.random() * 10);;
          
          for (var i = 0; i < 3 ; i++) {
            var digit1 = Math.floor(Math.random() * 10);

            digit = "" + digit + digit1;

          }
          var tb = document.getElementById('sc');
          tb.value = digit;
    }
</script>



</script>
<h3>Add Special Schedule</h3>
	
  <div class="container">
  
  <?php if ($this->session->flashdata('exist')) { ?>
    <div class="alert alert-danger">
    <h5 class="text-danger"><?php echo $this->session->flashdata('exist');?></h5>

    </div>
  <?php }?>	
    <?php
    if($this->session->flashdata('suc')){?>
    <div class="alert alert-success">
    <h5 class="text-success"><?php echo $this->session->flashdata('suc');?></h5>

    </div>
    <?php }?>
	<form action="<?php echo base_url() ?>/special_sched_con/submit" method="post" class="form-horizontal">
         
		
		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('fName'); ?></h6>
			<label for="fName" class="col-md-2 text-right">First Name</label>
			<div class="col-md-8">
				<input type="text" name="fName" class="form-control">
			</div>
		</div>
		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('lName'); ?></h6>
			<label for="lName" class="col-md-2 text-right">Last Name</label>
			<div class="col-md-8">
				<input name="lName" class="form-control">
			</div>
		</div>
		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('nic'); ?></h6>
			<label for="nic" class="col-md-2 text-right">NIC No</label>
			<div class="col-md-8">
				<input name="nic" class="form-control">
			</div>
		</div>

		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('startTime'); ?></h6>
			<label for="startTime" class="col-md-2 text-right">Start Time</label>
			<div class="col-md-8">
				<input type="time" name="startTime" class="form-control">
			</div>
		</div>

		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('endTime'); ?></h6>
			<label for="endTime" class="col-md-2 text-right">End Time</label>
			<div class="col-md-8">
				<input type="time" name="endTime" class="form-control">
			</div>
		</div>

		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('scheDate'); ?></h6>
			<label for="scheDate" class="col-md-2 text-right">Date</label>
			<div class="col-md-8">
				<input type="date" name="scheDate" class="form-control">
			</div>
		</div>
		
		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('passDevice'); ?></h6>
			<label for="passDevice" class="col-md-2 text-right">Password</label>
			<div class="col-md-8">
				<input name="passDevice" id="sc" class="form-control">
				<a class="btn btn-success" onclick="genCode();">Generate</a>
			</div>
		</div>
		<div class="form-group">
			<label class="col-md-2 text-right"></label>
			<div class="col-md-8">
				<input type="submit" name="btnSave" class="btn btn-primary" value="Save">
			</div>
		</div>
	</form>