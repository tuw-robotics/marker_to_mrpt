#include <marker_to_mrpt/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <geometry_msgs/Pose.h>

#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <std_msgs/Int32.h>

namespace marker_to_mrpt {

void MarkerToMRPTROS::init(ros::NodeHandle &public_nh, ros::NodeHandle &private_nh) {

    ROS_INFO ("Initializing MarkerToMRPTROS...");
    nh_ = public_nh;
    private_nh_ = private_nh;
    pub_beacon_ = private_nh_.advertise<mrpt_msgs::ObservationRangeBeacon>("beacon", 1000);
    reconfigureFnc_ = boost::bind ( &MarkerToMRPTROS::callbackConfigLocalPlanner, this,  _1, _2 );
    reconfigureServer_.setCallback ( reconfigureFnc_ );
    sub_marker = nh_.subscribe("marker_detection", 10, &MarkerToMRPTROS::callbackMarkerDetection, this);
}


void MarkerToMRPTROS::callbackConfigLocalPlanner ( marker_to_mrpt::MarkerToMRPTConfig &config, uint32_t level ) {
    ROS_INFO ("callbackConfig");
    config_ = config;
}

void MarkerToMRPTROS::callbackMarkerDetection(const marker_msgs::MarkerDetection::ConstPtr &msg) {
    ROS_INFO ("callbackMarkerDetection");
    
}
}
