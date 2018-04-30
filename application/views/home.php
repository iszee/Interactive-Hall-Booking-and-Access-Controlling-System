<!DOCTYPE html>
<html>
<head>
	<title>RACnRS | Log in or Sign Up</title>
	<link rel="stylesheet" type="text/css" href="<?php echo base_url() ?>/assets/css/style1.css">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
</head>
<body>
	<section class="b1">
		<div class="in">
			<div class="content">
				<p><b>Welcome to the UCSC </b></p>
				<p><b> E-Lab</b></p>
				<a class="btn" id="login" href="#">LOG IN</a>
				
				<div class="arrow-up"></div>
				
			</div>

			<div align="center">
				<?php if ($this->session->flashdata('errmsg')) {
        		echo "<h3 style='color:red'>".$this->session->flashdata('errmsg')."<h3>";
    			} 
    			?>
			</div>
			
			<div class="login-form">
			
				<?php echo validation_errors(); ?>
        		<?php echo form_open('Login/LoginUser'); ?>
						<label>User name</label>
						<div>
							<input type="text" name="username" placeholder="username" >
						</div>
						<label>Password</label>
						<div>
							<input type="Password" name="password" placeholder="password" >
						</div>
						<div>
							<input type="submit" value="Log In" >
						</div>
						<div>
							<a href="#" style="text-decoration: none;position: relative;top:20px;font-size: 14px;color: gray; ">Lost Your Password?</a>
						</div>
					<?php echo form_close(); ?>
			</div>
			


		</div>
	</section>
	<script type="text/javascript">
		$(document).ready(function(){
			var arrow = $(".arrow-up");
			var form = $(".login-form");
			var status = false;
			$("#login").click(function(event){
				event.preventDefault();
				if (status == false) {
					arrow.fadeIn();
					form.fadeIn();
					status = true;
				}else{
					arrow.fadeOut();
					form.fadeOut();
					status = false;
				}
			})
		})
	</script>
	
</body>

<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
</html>