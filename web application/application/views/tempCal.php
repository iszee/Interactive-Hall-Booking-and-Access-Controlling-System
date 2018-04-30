<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href=<?php echo base_url();?>css/calendar.css>
    <script type="text/javascript">
        // date variables
        var min=0;
        var hour=14;
        var date=25;
        var mon=11;
        var year=2017;
        var now = new Date();
        now.setMinutes(min);
        now.setHours(hour);
        now.setDate(date);
        now.setMonth(mon);
        now.setFullYear(year);
        today = now.toISOString();
        //document.write(now);
        //document.write('  xxxx   ');
        //document.write(today);
        var twoHoursLater = new Date(now.getTime() + (2 * 1000 * 60 * 60));
        twoHoursLater = twoHoursLater.toISOString();

        // Google api console clientID and apiKey
        var clientId = '872484677182-cjsnh52fvdne337nieh7naj29csnjp6c.apps.googleusercontent.com';
        var apiKey = 'AIzaSyC9mQLI0NM9BxufBBYUc-LkFHazKCVjthU';

        // enter the scope of current project (this API must be turned on in the Google console)
        var scopes = 'https://www.googleapis.com/auth/calendar';

        // OAuth2 functions
        function handleClientLoad() {
           gapi.client.setApiKey(apiKey);
            window.setTimeout(checkAuth, 1);
        }

        function checkAuth() {
            gapi.auth.authorize({ client_id: clientId, scope: scopes, immediate: true }, handleAuthResult);
        }

        // show/hide the 'authorize' button, depending on application state
        function handleAuthResult(authResult) {
            var authorizeButton = document.getElementById('authorize-button');
            var eventButton = document.getElementById('btnCreateEvents');
            var resultPanel = document.getElementById('result-panel');
            var resultTitle = document.getElementById('result-title');

            if (authResult && !authResult.error) {
                authorizeButton.style.visibility = 'hidden'; 		// if authorized, hide button
                resultPanel.className = resultPanel.className.replace(/(?:^|\s)panel-danger(?!\S)/g, '')	// remove red class
                resultPanel.className += ' panel-success'; 			// add green class
                resultTitle.innerHTML = 'Application Authorized'		// display 'authorized' text
                eventButton.style.visibility = 'visible';
                $("#txtEventDetails").attr("visibility", "visible");
            } else {													// otherwise, show button
                authorizeButton.style.visibility = 'visible';
                $("#txtEventDetails").attr("visibility", "hidden");
                eventButton.style.visibility = 'hidden';
                resultPanel.className += ' panel-danger'; 			// make panel red
                authorizeButton.onclick = handleAuthClick; 			// setup function to handle button click
            }
        }

        // function triggered when user authorizes app
        function handleAuthClick(event) {
            gapi.auth.authorize({ client_id: clientId, scope: scopes, immediate: false }, handleAuthResult);
            return false;
        }

        function refreshICalendarframe() {
            var iframe = document.getElementById('divifm')
            iframe.innerHTML = iframe.innerHTML;
        }
        // setup event details

        // function load the calendar api and make the api call
        function makeApiCall() {
            var eventResponse = document.getElementById('event-response');

            gapi.client.load('calendar', 'v3', function () {					// load the calendar api (version 3)
                var request = gapi.client.calendar.events.insert
                ({
                    'calendarId': 'nctrdb3d8fmos0g7t39tdvk4a8@group.calendar.google.com', // calendar ID
                    "resource": resource							// pass event details with api call
                });

                // handle the response from our api call
                request.execute(function (resp) {
                    if (resp.status == 'confirmed') {
                        eventResponse.innerHTML = "Event created successfully. View it <a href='" + resp.htmlLink + "'>online here</a>.";
                        eventResponse.className += ' panel-success';
                        refreshICalendarframe();
                    } else {
                        document.getElementById('event-response').innerHTML = "There was a problem. Reload page and try again.";
                        eventResponse.className += ' panel-danger';
                    }
                });
            });
        }
        var eventType;
        var startTime;
        var endTime;
        var eventDes;
        var userEmail;
        var userName;
        eventType='Lecture';
        startTime='10:00';
        endTime='12:00';
        eventDes='additional lecture';
        userName='iszee';
        userEmail='nhpi.madz@gmail.com';

        var resource = {
            "summary": eventType,
            "start": {
                "dateTime": today
            },
            "end": {
                "dateTime": twoHoursLater
            },
            "description":eventDes,
            "location":"UCSC E-LAB",
            "attendees":[
                {
                    "email":userEmail,
                    "displayName":userName,
                    "organizer":true,
                    "self":false,
                    "resource":false,
                    "optional":false,
                    "responseStatus":"needsAction",
                    "comment":"This is event first",
                    "additionalGuests":3

                }
            ],
        };

        // FUNCTION TO DELETE EVENT
        function deleteEvent() {
            gapi.client.load('calendar', 'v3', function() {
                var request = gapi.client.calendar.events.delete({
                    'calendarId': 'nctrdb3d8fmos0g7t39tdvk4a8@group.calendar.google.com',
                    'eventId': 'Hdusrtsbs8'
                });
                request.execute(function(resp) {
                    if (resp.status == 'confirmed') {
                        alert("Event was successfully removed from the calendar!");
                    }
                    else{
                        alert('An error occurred, please try again later.')
                    }
                });
            });
        }


    </script>
    <script src="https://apis.google.com/js/client.js?onload=handleClientLoad" type="text/javascript"></script>
</head>
<body>

<div class="sect  sectOne" id="s1">
            <button id="authorize-button" style="visibility: hidden" class="btn btn-primary">Authorize</button>
            <!--<button id="btnCreateEvents" class="btn btn-primary" onclick="makeApiCall();">Create Events</button>-->
            <!-- <button id="btnDeleteEvents" class="btn btn-primary" onclick="deleteEvent();">Delete Events</button> -->
        <div class="cal" id="divifm" style="float: left;border-radius: 30px">
            <iframe src="https://calendar.google.com/calendar/embed?title=UCSC%20E-LAB&amp;showPrint=0&amp;height=500&amp;wkst=2&amp;bgcolor=%2333ccff&amp;src=nctrdb3d8fmos0g7t39tdvk4a8%40group.calendar.google.com&amp;color=%238D6F47&amp;ctz=Asia%2FColombo" style="border-width:0" width="500" height="500" frameborder="0" scrolling="no"></iframe>
        </div>

        <div class="col-lg-5" id="form" style="background-color: #e6ebff; float: right; margin-right: 50px;margin-top: 20px">
    
        <?php echo validation_errors(); ?>

        <?php if($this->session->flashdata('suc')){?>
            <div class='alert alert-success'>successfully added</div>        
        <?php ;} ?>
         <?php if($this->session->flashdata('err')){?>
            <div class='alert alert-warning'><?php echo $this->session->flashdata('err');?></div>        
        <?php ;} ?>
        
        <form method="POST" action="<?php echo base_url(); ?>index.php/calendar/check_timeslot" class="form-horizontal" style="margin-top: 10px; border-radius: 30px">
            <div class="form-group">
                <label class="control-label col-sm-2" for="date">Date:</label>
                <div class="col-sm-10">
                    <input type="date" class="form-control" id="date" name="date" required>
                </div>
            </div>
            <div class="form-group">
                <label class="control-label col-sm-2" for="time">Start Time:</label>
                <div class="col-sm-10">
                    <select class="form-control" id="#" name="starttime" required>
                        <option selected type="hidden" disabled>Choose Start Time</option>
                        <option >08</option>
                        <option >09</option>
                        <option >10</option>
                        <option >11</option>
                        <option >12</option>
                        <option >13</option>
                        <option >14</option>
                        <option >15</option>
                        <option >16</option>
                        <option >17</option>
                        <option >18</option>
                        <option >19</option>
                    </select>
                </div>
            </div>

            <div class="form-group">
                <label class="control-label col-sm-2" for="time">End Time:</label>
                <div class="col-sm-10">
                   <select class="form-control" id="#" name="endtime" required>
                        <option selected type="hidden" disabled>Choose Start Time</option>
                        <option >08</option>
                        <option >09</option>
                        <option >10</option>
                        <option >11</option>
                        <option >12</option>
                        <option >13</option>
                        <option >14</option>
                        <option >15</option>
                        <option >16</option>
                        <option >17</option>
                        <option >18</option>
                        <option >19</option>
                    </select>
                </div>
            </div>

            <div class="form-group">
                <label class="control-label col-sm-2">Purpose</label>
                <div>
                    <label class="radio-inline"><input type="radio" name="optradio" value="lecture">Lecture</label>
                    <label class="radio-inline"><input type="radio" name="optradio"  value="meeting">Meeting</label>
                    <label class="radio-inline"><input type="radio" name="optradio"  value="practical">Practical Session</label>
                </div>
            </div>
            <div class="form-group">
                <label class="control-label col-sm-2" for="comment">Description:</label>
                <div class="col-sm-10">
                    <textarea class="form-control" rows="5" id="comment" placeholder="Write small descrition about your booking" required name="comment"></textarea>
                </div>
            </div>
            <div class="form-group">
                <div class="col-sm-offset-2 col-sm-10">
                    <button type="submit" onclick="makeApiCall();" class="btn btn-default">Confirm Booking</button>
                </div>
            </div>
        </form>
    </div>
</div>
</body>
</html>
