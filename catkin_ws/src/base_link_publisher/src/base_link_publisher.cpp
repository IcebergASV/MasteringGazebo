#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <tf2_msgs/TFMessage.h>
#include <tf2_ros/transform_broadcaster.h>

int main(int argc, char** argv) {

    ros::init(argc, argv, "base_link_publisher");
    ros::NodeHandle nh;
    
    //used to attempt ot publish directly to /tf using ros::Publisher pub = nh.advertise<tf2_msgs::TFMessage>("/tf", 1000);
    ros::Rate loop_rate(10);
    
    tf2_ros::TransformBroadcaster tf2_bdcst;
    // used to attempt to publish directly to /tf using tf2_msgs::TFMessage base_link;
	geometry_msgs::TransformStamped tfstamped;
	tfstamped.header.seq = 1;
	tfstamped.header.stamp = ros::Time::now();
	tfstamped.header.frame_id = "base_link";
	tfstamped.child_frame_id = "laser_scan";
	tfstamped.transform.translation.x = 0.8;
	tfstamped.transform.translation.y =0.0;
	tfstamped.transform.translation.z = 0.3;
	tfstamped.transform.rotation.x = 0;
	tfstamped.transform.rotation.y = 0;
	tfstamped.transform.rotation.z = 0;
	tfstamped.transform.rotation.w = 0;
	    
    // used to attempt to publish directly to /tf using base_link.transforms[0] = tfstamped;
    

    while (ros::ok())
    {
        // used to attempt to publish directly to /tf using pub.publish(base_link);
        tf2_bdcst.sendTransform(tfstamped);
        ros::spinOnce();
        loop_rate.sleep();
    }
    
    return 0;
}