<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>RACnRS |Home </title>

    <!--bootstrap css-->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <link rel="stylesheet" href=<?php echo base_url();?>css/header.css>
    <link rel="stylesheet" href=<?php echo base_url();?>css/tourLog.css>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
<!-- <body background="<?php echo base_url()?>/images/back.jpg"> -->
<div class="navi">
<nav class="navbar navbar-inverse" >
    <div class="wrp">
    <div class="container-fluid" id="menu">
        <div class="navbar-brand">
            <a href=<?php echo base_url(); ?>home><img src=<?php echo base_url();?>images/logon.png alt=""/></a>
        </div>

        <ul class="nav navbar-nav navbar-left">
            <li class=""><a href="<?php echo base_url(); ?>index.php/Home/logged">Home</a></li>
            <li class=""><a href="<?php echo base_url(); ?>index.php/Home/tour">Take Me a Tour</a></li>
            <li class=""><a href="<?php echo base_url(); ?>index.php/Product_update/view_infore">Our Products</a></li>
            <!-- <li class=""><a href=<?php echo base_url(); ?>contact>Contact Us</a></li> -->
        </ul>

        <ul class="nav navbar-nav navbar-right">

            <li>
                <?php foreach ($imagepath as $value) {?>
                <img src="<?php echo $value['userImage'];?> " class="img-rounded" id="img" style="width: 75px;border-radius: 63px; margin-top: 47px;">

                 <?php }?>
            </li>
            <li class=""><a href="<?php echo base_url()?>/index.php/Upload/load_update"><?php echo $this->session->userdata('user_name'); ?></a></li>
            <li class=""><a href="<?php echo base_url()?>/index.php/Logout/logoutuser"><span class="glyphicon glyphicon-log-out"></span></a></li>

        </ul>
    </div>
    </div>
</nav>

</div>
<div class="jumbotron text-center"><h1>Take Me A Tour</h1></div>
<section id="carousel">    				
<div class="container">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <div class="quote"><i class="fa fa-quote-left fa-4x"></i></div>
            <div class="carousel slide" id="fade-quote-carousel" data-ride="carousel" data-interval="30000">
              <!-- Carousel indicators -->
              <ol class="carousel-indicators">
                <li data-target="#fade-quote-carousel" data-slide-to="0" class="active"></li>
                <li data-target="#fade-quote-carousel" data-slide-to="1"></li>
                <li data-target="#fade-quote-carousel" data-slide-to="2"></li>
                <!-- <li data-target="#fade-quote-carousel" data-slide-to="3"></li>
                <li data-target="#fade-quote-carousel" data-slide-to="4"></li>
                <li data-target="#fade-quote-carousel" data-slide-to="5"></li> -->
              </ol>
              <!-- Carousel items -->
              
              <div class="carousel-inner">
                <div class="active item">
                    <div class="profile-circle" style="background-color: rgba(145,169,216,.2);">
                    <img src="<?php echo base_url()?>/images/reg.png" height=200>
                    </div>
                        <blockquote>
                        <h1 style="font-size:300%;">HOW TO GET REGISTERED</h1>
                        <h3>For a lecturer to be registered,</h3><br>
                        <p style="text-align:justify;">
                                1.	Go to the Academics and Publications branch<br>
                                2.	Give details and get registered to receive an authentication code and card<br>
                                3.	Click sign up on the website and enter the received authentication code<br>
                                4.	Give a username and password to be registered on the website<br>
                                5.  Take the card to the lab assistant to get it registered<br><br>
                        <h3>For a student to be registered,</h3><br>
                        <p style="text-align:justify;">       
                                1.	Meet the person in charge of the lab to get registered<br>
                                2.	Receive a registered tag from him<br>
                                3.	Use it to access the lab<br>

                        </p>
                        </blockquote>
                    </div>

                <div class="item">
                    <div class="profile-circle" style="background-color: rgba(0,255,0,1);">
                    <img src="<?php echo base_url()?>/images/device.jpg" style="width:200px;height:200px;border:0;">
                    </div>
                    <blockquote>
                        <h1 style="font-size:300%;">HOW TO USE THE DEVICE</h1><br>
                        <p style="text-align:justify;">
                        1.	The device will be located outside the lab with a remote attached next to it.<br><br>
                        2.	Using the remote you’re able to switch between card and password mode.<br><br>
                        3.	Type the password using the remote or use the card to access the lab.<br><br>
                        4.	Use the arrows in the remote to view the schedule of the lab.
                        </p>
                        </blockquote>	
                </div>

                <div class="item">
                    <div class="profile-circle" style="background-color: rgba(77,5,51,.2);">
                    <img src="<?php echo base_url()?>/images/website.jpg" height=200>
                    </div>
                    <blockquote>
                        <h1 style="font-size:300%;">HOW TO USE THE WEBSITE</h1><br>
                        <p style="text-align:left;">
                            1.	On the top right corner, your username will be visible. By clicking it, you will be directed to a page where you can edit your profile.<br><br>
                            2.	In the homepage, to the left a calendar will be available with all the bookings so far of the electronics lab on a daily, weekly and monthly basis. Use this to view the schedule.<br><br>
                            3.	In the homepage, using the window on the right you can book the hall by inserting the necessary details.<br>
                        </p>
                    </blockquote>
                </div>
            </div>
        </div>							
    </div>
</div>
</section>
</body>
</html>
