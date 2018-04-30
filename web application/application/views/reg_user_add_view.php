

<h3>Add Registered User</h3>

<a href="<?php echo base_url('reg_user_con/index'); ?>" class="btn btn-primary">Back</a>
	
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
    <?php
    if($this->session->flashdata('suc')){?>
    <div class="alert alert-success">
    <h5 class="text-success"><?php echo $this->session->flashdata('suc');?></h5>

    </div>
    <?php }?>
	<form action="<?php echo base_url('reg_user_con/submit') ?>" id="addform" method="post" class="form-horizontal">
		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('fName'); ?></h6>
			<label for="fName" class="col-md-2 text-right">First Name</label>
			<div class="col-md-5">
				<input type="text" name="fName" class="form-control" >
			</div>
		</div>
		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('lName'); ?></h6>
			<label for="lName" class="col-md-2 text-right">Last Name</label>
			<div class="col-md-5">
				<input name="lName" class="form-control">
			</div>
		</div>
		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('nic'); ?></h6>
			<label for="nic" class="col-md-2 text-right">NIC No</label>
			<div class="col-md-5">
				<input name="nic" class="form-control" >
			</div>
		</div>
		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('email'); ?></h6>
			<label for="email" class="col-md-2 text-right">Email</label>
			<div class="col-md-5">
				<input name="email" class="form-control" >
			</div>
		</div>
		<div class="form-group">
		<h6 class="text-danger"><?php echo form_error('phNum'); ?></h6>
			<label for="phNum" class="col-md-2 text-right">Tel No</label>
			<div class="col-md-5">
				<input name="phNum" class="form-control">
			</div>
		</div>
		
		 <!--js for dropdown-->
		 <script type="text/javascript">
			$(document).on('click', '.dropdown-menu li a', function() {
				$('#datebox').val($(this).html());
			}); 
			</script>
		<div class="form-group" >
		<h6 class="text-danger"><?php echo form_error('card_id'); ?></h6>
			<label for="card_id" class="col-md-2 text-right">Card Id</label>
			<div class="col-md-5">
			<div class="input-group">                                            
			<input type="TextBox" id="datebox" name="card_id" class="form-control" ></input>
			<div class="input-group-btn">
				<button type="button" class="btn dropdown-toggle" data-toggle="dropdown">
					<span class="caret"></span>
				</button>
				
				<ul id="demolist" class="dropdown-menu">
				<?php 
					if ($res){
						foreach ($res as $row){
				?>
					<li><a href="#"><?php echo $row->card_id;?></a></li>
								
				<?php	;}
					 }
					 elseif ($res == null) {?>
						<li><a href="#">No cards</a></li>
				<?php	 }
				 ?>
					
				</ul>
			</div>
		</div>
				
			</div>
		</div>

		 
		<div class="form-group" >
		<h6 class="text-danger"><?php echo form_error('userLevel'); ?></h6>
			<label for="userLevel" class="col-md-2 text-right">User Level</label>
			<div class="col-md-5">
			<div class="input-group">                                            
			<div class="radio">
				<label><input type="radio" value="1" name="userLevel">1</label>
				<label><input type="radio" value="2" name="userLevel">2</label>
				<label><input type="radio" value="3" name="userLevel">3</label>
      		</div>
		</div>
				
			</div>
		</div>
		
		<div class="form-group">
			<label class="col-md-2 text-right"></label>
			<div class="col-md-5">
				<input type="button" name="btnSave" onclick="form_reset();"class="btn btn-primary" value="Save">
			</div>
		</div>
	</form>

	<script type="text/javascript">
		function form_reset(){
			var frm = document.getElementById('addform');
			frm.submit();
			frm.reset();
		}
	</script>