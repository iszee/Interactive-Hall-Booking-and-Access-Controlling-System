<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>RACnRS |Home </title>

    <!--bootstrap css-->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <link rel="stylesheet" href=<?php echo base_url();?>css/header.css>
        <link rel="stylesheet" href=<?php echo base_url();?>css/table.css>

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
<body>
<div class="navi">
<nav class="navbar navbar-inverse" >
    <div class="wrp">
    <div class="container-fluid" id="menu">
        <div class="navbar-brand">
            <a href=<?php echo base_url('index.php/Home/logged'); ?>><img src=<?php echo base_url();?>images/logon.png alt=""/></a>
        </div>

        <ul class="nav navbar-nav navbar-left">
            <li class=""><a href="<?php echo base_url(); ?>index.php/Home/logged">Home</a></li>
            <li class=""><a href="<?php echo base_url(); ?>index.php/Home/tour">Take Me a Tour</a></li>
            <li class=""><a href="#s2">Our Products</a></li>
            <li class=""><a href="#ss2">Contact Us</a></li>
        </ul>

        <ul class="nav navbar-nav navbar-right">
            <li>
                <?php foreach ($imagepath as $value) {?>
                <img src="<?php echo $value['userImage'];?> " class="img-rounded" id="img" style="width: 75px;border-radius: 63px; margin-top: 47px;">

                 <?php }?>
            </li>
            <li class=""><a href="<?php echo base_url()?>/index.php/Upload/load_update"><?php echo $this->session->userdata['user_name']; ?></a></li>
            <li class=""><a href="<?php echo base_url()?>/index.php/Logout/logoutuser"><span class="glyphicon glyphicon-log-out"></span></a></li>

        </ul>
    </div>
    </div>
</nav>
</div>
</body>
</html>
