<!DOCTYPE HTML>

<h3>Tag Details</h3>

<div class="container">
  
  <?php if ($this->session->flashdata('error_msg')) { ?>
    <div class="alert alert-danger">
    <h5 class="text-danger"><?php echo $this->session->flashdata('exist');?></h5>

    </div>
  <?php }?>	
    <?php
    if($this->session->flashdata('success_msg')){?>
    <div class="alert alert-success">
    <h5 class="text-success"><?php echo $this->session->flashdata('suc');?></h5>

    </div>
    <?php }?>

<table class="table table-bordered table-responsive">
    <thead>
        <tr>
            <td>Tag ID</td>
            <td>Tag Label</td>
            <td>Tag Status</td> 
        </tr>
    </thead>
    <tbody>
    <?php
        if ($tags) {
            foreach ($tags as $tag) {
    ?>
                <tr>
                    <td><?php echo $tag->tag_id?></td>
                    <td><?php echo $tag->tagLable?></td>
                    <td><?php echo $tag->tagStatus?></td>
                    <td>
					<a href="<?php echo base_url('tag_con/delete/'.$tag->tag_id); ?>" class="btn btn-danger" onclick="return confirm('Do you want to delete this record?');">Delete</a>
                    </td>
                </tr>
    <?php   
            }
        }
    ?>
    </tbody>

</table>
