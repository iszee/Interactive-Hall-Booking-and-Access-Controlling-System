<!DOCTYPE html>
<html>
<head>
	<title>RACnRS | Admin</title>
	<link rel="stylesheet" type="text/css" href="<?php echo base_url() ?>/assets/css/style.css">
	<link rel="stylesheet" type="text/css" href="<?php echo base_url() ?>/assets/css/style2.css">
</head>
<body>
	<nav>
		<b>RACnRS</b>
		<a href="#">HOME</a>
		<a class="user" href="Admin.html" >Admin</a>
	</nav>
  
	<div class="register_form" style="color : whitesmoke;">
      <?php if ($this->session->flashdata('msg')) {
        echo "<h3>".$this->session->flashdata('msg')."<h3>";
    }
    ?>
        <?php echo validation_errors(); ?>
        <?php echo form_open('register/RegisterUser' , 'class=form_reg'); ?>
        
            <label><b><u>User Registration Form</u></b></label>
            <hr>
            <label>User Name</label><br>
            <input type="text" name="username" class="input_fill" ><br>
            <label>Email</label><br>
            <input type="email" name="email" class="input_fill" ><br>
            <label>NIC</label><br>
            <input type="text" name="nic" class="input_fill" ><br>
            <label>Contact Number </label><br>
            <input type="text" name="contact" class="input_fill" ><br>
            <label>User Type</label><br>
            <input type="text" name="usertype" class="input_fill" ><br>
            <label>Password</label><br>
            <input type="password" name="password" class="input_fill" id="password" ><br>
            <label>Confirm Password</label><br>
            <input type="password" name="cpassword" id="cpassword" class="input_fill" required onkeyup='check();'><br>
            <span id='message'></span>
            <br>
            <button type="submit" class="btn">Register</button>
            <button type="reset" class="btn">Reset</button>
        
        <?php echo form_close(); ?>
    </div>
    <script type="text/javascript">
        	var check = function() {
			  if (document.getElementById('password').value ==
			    document.getElementById('cpassword').value) {
			    document.getElementById('message').style.color = 'green';
			    document.getElementById('message').innerHTML = 'Password matching';
			  } else {
			    document.getElementById('message').style.color = 'red';
			    document.getElementById('message').innerHTML = 'Password not matching';
			  }
			}
        </script>
    <div class="img1">
        <center>
        	<iframe src="https://calendar.google.com/calendar/embed?height=600&amp;wkst=1&amp;bgcolor=%23FFFFFF&amp;src=jt499m1v7f9gnac4eckj10s4ro%40group.calendar.google.com&amp;color=%235F6B02&amp;ctz=Asia%2FColombo" style="border-width:0" width="500" height="500" frameborder="0" scrolling="no"></iframe>
        </center>
    </div>
</body>
</html>