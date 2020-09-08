#ifndef MARKER_TO_MRPT_NODELET_H
#define MARKER_TO_MRPT_NODELET_H

#include <nodelet/nodelet.h>
#include <marker_to_mrpt/ros.h>


namespace marker_to_mrpt {


class MarkerToMRPTNodelet: public MarkerToMRPTROS, public nodelet::Nodelet {
public:
    virtual void onInit();
};

}

#endif  // MARKER_TO_MRPT_NODELET_H
