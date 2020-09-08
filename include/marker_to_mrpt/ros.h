#ifndef MARKER_TO_MRPT_WRAPPER_H
#define MARKER_TO_MRPT_WRAPPER_H

#include <ros/ros.h>

#include <marker_msgs/MarkerDetection.h>
#include <dynamic_reconfigure/server.h>
#include <marker_to_mrpt/MarkerToMRPTConfig.h>
#include <mrpt_msgs/ObservationRangeBeacon.h>


namespace marker_to_mrpt {

class MarkerToMRPTROS {
    
private:
    ros::Subscriber sub_marker;
    ros::Publisher pub_beacon_;
    ros::Timer timer_;
    ros::NodeHandle nh_;
    ros::NodeHandle private_nh_;
    marker_to_mrpt::MarkerToMRPTConfig config_;
    dynamic_reconfigure::Server<marker_to_mrpt::MarkerToMRPTConfig> reconfigureServer_; /// parameter server stuff
    dynamic_reconfigure::Server<marker_to_mrpt::MarkerToMRPTConfig>::CallbackType reconfigureFnc_;  /// parameter server stuff
    void callbackConfigLocalPlanner ( marker_to_mrpt::MarkerToMRPTConfig &config, uint32_t level ); /// callback function on incoming parameter changes

public:
    void init(ros::NodeHandle &public_nh, ros::NodeHandle &private_nh);
    void callbackMarkerDetection ( const marker_msgs::MarkerDetection::ConstPtr& scan);

};
}

#endif  // MARKER_TO_MRPT_WRAPPER_H
