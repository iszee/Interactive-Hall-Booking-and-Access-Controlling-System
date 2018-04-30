
<script src=<?php echo base_url();?>js/jquery.min.js></script>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
<div class="header">
	<link rel="stylesheet" href=<?php echo base_url();?>css/style.css>
		<div class="wrap">
			<div class="logo">
				<a href=<?php echo base_url(); ?>home><img src=<?php echo base_url();?>images/logon.png alt=""/></a>
			</div>
			<div class="top-nav">
				<div class="menu">
				<span class="menu"> </span>
			   		<ul id="header menu">
						<li class=""><a href=<?php echo base_url(); ?>home>Home</a></li>
						<li class=""><a href=<?php echo base_url(); ?>about>My Profile</a></li>
						<li class=""><a href=<?php echo base_url(); ?>services>Take Me a Tour</a></li>
						<li class=""><a href=<?php echo base_url(); ?>gallery>Our Products</a></li>
						<li class=""><a href=<?php echo base_url(); ?>contact>Contact Us</a></li>
                        <li class="nav navbar-nav navbar-right">
                            <a href="#">
                                <span class="glyphicon glyphicon-log-out"></span>
                            </a>
                        </li>


                    </ul>

					<div class="clear"></div>
	   		  	</div>
				<!-- script-for-nav -->
					<script>
						$( "span.menu" ).click(function() {
						  $( ".top-nav ul" ).slideToggle(300, function() {
							// Animation complete.
						  });
						});
					</script>
				<!-- script-for-nav -->
	   	   </div>
            <div class="user">


            </div>

			<div class="clear"></div>
	  </div>
 </div>
