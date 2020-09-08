#include <marker_to_mrpt/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <tf2/LinearMath/Quaternion.h>

#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <std_msgs/Int32.h>
    
namespace marker_to_mrpt {

void MarkerToMRPTNodelet::onInit() {

    NODELET_INFO ("Initializing nodelet MarkerToMRPTNodelet...");
        MarkerToMRPTROS::init(getNodeHandle(), getPrivateNodeHandle());
}
}


PLUGINLIB_EXPORT_CLASS (marker_to_mrpt::MarkerToMRPTNodelet, nodelet::Nodelet)
//int main(int argc, char **argv) {}
