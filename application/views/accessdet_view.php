<h3>Access details</h3>


<table class="table table-bordered table-responsive">
    <thead>
        <tr>
            <td>Access ID</td>
            <td>Date</td>
            <td>Time</td>
            <td>User Id</td>    
        </tr>
    </thead>
    <tbody>
    <?php
        if ($accesses) {
            foreach ($accesses as $access) {
    ?>
                <tr>
                    <td><?php echo $access->access_id?></td>
                    <td><?php echo $access->date?></td>
                    <td><?php echo $access->time.'.00'?></td>
                    <td><?php echo $access->user_id?></td>
                   
                </tr>
    <?php   
            }
        }
    ?>
    </tbody>

</table>