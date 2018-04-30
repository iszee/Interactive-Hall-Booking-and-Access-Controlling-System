<!DOCTYPE html>
<html>
<head>
  <title>Our Products</title>
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <link rel="stylesheet" href=http://localhost/groupProjectNewELab/css/header.css>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>


</head>
<body>

<div class="navi">
    <nav class="navbar navbar-inverse" >
        <div class="wrp">
            <div class="container-fluid" id="menu">
                <div class="navbar-brand">
                    <a href=http://localhost/groupProjectNewELab/home><img src=http://localhost/groupProjectNewELab/images/logon.png alt=""/></a>
                </div>

                <ul class="nav navbar-nav navbar-left">
                    <li class=""><a href="<?php echo base_url(); ?>index.php/Home/logged">Home</a></li>
                    <li class=""><a href="<?php echo base_url(); ?>index.php/Home/tour">Take Me a Tour</a></li>
                    <li class=""><a href="<?php echo base_url(); ?>index.php/Product_update/view_infore">Our Products</a></li>
                    <!-- <li class=""><a href=http://localhost/groupProjectNewELab/contact>Contact Us</a></li> -->
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



<div class="jumbotron text-center">
  <h1> Our Products</h1>
</div>
  
<div class="container">
  <div class="row">
<font style="Century Gothic" size="4">
      <h2>Arduino Device</h2>
      Arduino device is the most significant product of our system. This is attached outside the door of E-Lab. A number of functions are
          included in the device so that the user can easily get an idea about the schedule of the E-Lab.
      And also our device has an access control system in order to maintain the security. The LED display shows you the
      necessary details of the booked and free time slots. Explore some functions of the device.....
        <p>
      <br>
        <div class="container">
            <div class="row">
                <div class="col-sm-2">
        <div>
            <button type="button" class="btn btn-link one" onclick="document.getElementById('view').src='http://localhost/groupProjectNewELab/assets/images/1.2.jpg'"><font style="Century Gothic" size="4">View Schedule</button>
        </div>

        <script>
            $(".one").click(function(){
                $(".1").collapse('toggle');
            });
        </script>

        </p>

    </div>
      <div class="col-sm-4" >
          <div class="collapse 1">
            In this function the user can review schedule. You can scroll down and see the up coming evets. It also shows
              the free time slots available for the day.
          </div>
      </div>

      <div class="col-sm-4">
          <div class="collapse 1">
          <img id="view" style="width:550px">
          </div>
      </div>
  </div>
<br>

    <div class="row">
        <div class="col-sm-2">
            <div>
                <button type="button" class="btn btn-link two" onclick="document.getElementById('view2').src='http://localhost/groupProjectNewELab/assets/images/1.3.jpg'"><font style="Century Gothic" size="4">Access Control</button>
            </div>
            </p>

        </div>
        <div class="col-sm-4" >
            <div class="collapse 2">
                    Access controlling is another function of the system. Users with the RFID card can access by detecting their
                registered card. If the card is not registered then the access is denied by the device. Also the users with the
                RFID tags can access and also the tags don't have to be registered.
            </div>
        </div>

        <div class="col-sm-4">
            <div class="collapse 2">
                <img id="view2" style="width:550px">
            </div>
        </div>
    </div>


<script>
        $(".two").click(function(){
            $(".2").collapse('toggle');
        });
</script>
<br>

<div class="row">
    <div class="col-sm-2">
        <div>
            <button type="button" class="btn btn-link three" onclick="document.getElementById('view3').src='http://localhost/groupProjectNewELab/assets/images/1.1.jpg'"><font style="Century Gothic" size="4">Card Registration</button>
        </div>
        </p>

    </div>
    <div class="col-sm-4" >
        <div class="collapse 3">
            When card mode is on we can register and detect cards. To register cards first a super user has to use his/her card
            and then a non registered card can be register
        </div>
    </div>

    <div class="col-sm-4">
        <div class="collapse 3">
            <img id="view3" style="width:550px">
        </div>
    </div>
</div>
</div>

<script>
    $(".three").click(function(){
        $(".3").collapse('toggle');
    });
</script>
</div>


</body>
</html>