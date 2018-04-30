<!DOCTYPE html>
<html>
<head>
	<title>RACnRS | Home</title>
	<link rel="stylesheet" type="text/css" href="<?php echo base_url() ?>/assets/css/style.css">
	
</head>
	<body>




		<div class="subSection" id="ss1">
<p style="font-size: 30px;">User Bookings</p>
		<div class="table-wrapper">
			<table class="table table-bordered table-responsive" id="tab">
				<thead>
					<tr>
						<td>Type</td>
						<td>Start Time</td>
						<td>End Time</td> 
						<td>Date</td> 
					</tr>
				</thead>
				<tbody>
				<?php
					if ($sched != null) {
						foreach ($sched as $sched) {
				?>
							<tr>
								<td><?php echo $sched['scheType']?></td>
								<td><?php echo $sched['startTime']?></td>
								<td><?php echo $sched['endTime']?></td>
								<td><?php echo $sched['scheDate']?></td>

								<td>
								<a href="#" class="btn btn-danger" onclick="return confirm('Do you want to delete this record?');">Delete</a>
								</td>
							</tr>
				<?php   
						}
					}
				?>
				</tbody>

			</table>


			
		</div>
		</div>
		<div class="sect sectTwo" id="s2">
			<div >
				<p style="color: white; font-size: 40px; padding-top: 50px; padding-left: 50px;">Our Product</p>
			</div>
			<div class="col-md-6" id="product">
				<img class="proimg" src="<?php echo base_url() ?>assets/images/1.JPG" >
			</div>
			<div class="col-md-6" >
				<p id="proDescription">
					Arduino device is the most significant product of our system. This is attached outside the door of E-Lab. A number of functions are included in the device so that the user can easily get an idea about the schedule of the E-Lab. And also our device has an access control system in order to maintain the security. The LED display shows you the necessary details of the booked and free time slots. Explore some functions of the device.....
				</p>
				<div>
					<a href="<?php echo base_url();?>/index.php/Product_update/view_infore "><button class="button" style="vertical-align:middle" ><span>Read More</span></button></a>
					
				</div>
			</div>
			
		</div>
		<div class="subSection" id="ss2">
		<br><center>
			<h2><u>Contact Us</u></h2>
			<p><b>Email :</b> <u><i>elab.ucsc@cmb.ac.lk</i></u></p>
			<p><b>Address :</b> UCSC Building Complex, No.35, Reid Avenue, Colombo 07</p>
			<p><b>Tel :</b> +94 -11- 2581245/ 7</p>
			<p><b>Fax :</b> +94-11-2587239</p>
			</center>
		</div>
	</body>
</html>