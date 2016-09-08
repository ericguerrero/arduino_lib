#ifndef _ROS_iri_common_drivers_msgs_gripper_forceActionFeedback_h
#define _ROS_iri_common_drivers_msgs_gripper_forceActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "iri_common_drivers_msgs/gripper_forceFeedback.h"

namespace iri_common_drivers_msgs
{

  class gripper_forceActionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      iri_common_drivers_msgs::gripper_forceFeedback feedback;

    gripper_forceActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/gripper_forceActionFeedback"; };
    const char * getMD5(){ return "666d1d759f2ab5bb4b72cf6f0b5024ac"; };

  };

}
#endif