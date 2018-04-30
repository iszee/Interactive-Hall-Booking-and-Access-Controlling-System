<!DOCTYPE html>
<html>
<head>
    <title>Product Upda</title>

    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <link rel="stylesheet" href=http://localhost/groupProjectNewELab/css/header.css>

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
<body>

<!-- <div class="navi">
    <nav class="navbar navbar-inverse" >
        <div class="wrp">
            <div class="container-fluid" id="menu">
                <div class="navbar-brand">
                    <a href=http://localhost/groupProjectNewELab/home><img src=http://localhost/groupProjectNewELab/images/logon.png alt=""/></a>
                </div>

                <ul class="nav navbar-nav navbar-left">
                    <li class=""><a href=http://localhost/groupProjectNewELab/home>Home</a></li>
                    <li class=""><a href=http://localhost/groupProjectNewELab/services>Take Me a Tour</a></li>
                    <li class=""><a href=http://localhost/groupProjectNewELab/gallery>Our Products</a></li>
                    <li class=""><a href=http://localhost/groupProjectNewELab/contact>Contact Us</a></li>
                </ul>

                <ul class="nav navbar-nav navbar-right">
                    <li class=""><a href=http://localhost/groupProjectNewELab/about></a></li>
                    <li class=""><a href="#"><span class="glyphicon glyphicon-log-out"></span></a></li>

                </ul>
            </div>
        </div>
    </nav>
</div> -->

<br>


    <div class="container">
        <?php echo form_open_multipart('Product_update/do_upload');?>
<!--<form class="form-horizontal" action="">-->
    <div class="form-group">
        <label class="control-label col-sm-2" for="Pid">Product ID:</label>
        <div class="col-sm-4">
            <input type="text" class="form-control" id="pid" placeholder="Product ID" name="PID">
        </div>
    </div>

    <div class="form-group">

        <label class="control-label col-sm-2" for="Pdes">Product Description:</label>
        <div class="col-sm-4">

            <input type="text" class="form-control" id="pdes" placeholder="Product Description" name="PDES">
        </div>
    </div>

    <div class="form-group">
        <div>
        <label class="control-label col-sm-2" for="Inputfile">Image:</label>

        <div class="col-sm-6" >
            
        <input type="file" class="form-control-file"  name="Imageinput" >
        </div>
            
    </div>
    <div class="form-group">
        <div class="col-sm-offset-2 col-sm-10">
    <button type="submit" class="btn btn-default" name="submit">Submit</button>
        </div>
    </div>
<?php echo form_close();?>
