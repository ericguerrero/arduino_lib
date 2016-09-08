#ifndef _ROS_auv_msgs_BodyForceReq_h
#define _ROS_auv_msgs_BodyForceReq_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "auv_msgs/GoalDescriptor.h"
#include "geometry_msgs/Wrench.h"
#include "auv_msgs/Bool6Axis.h"

namespace auv_msgs
{

  class BodyForceReq : public ros::Msg
  {
    public:
      std_msgs::Header header;
      auv_msgs::GoalDescriptor goal;
      geometry_msgs::Wrench wrench;
      auv_msgs::Bool6Axis disable_axis;

    BodyForceReq():
      header(),
      goal(),
      wrench(),
      disable_axis()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      offset += this->wrench.serialize(outbuffer + offset);
      offset += this->disable_axis.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
      offset += this->wrench.deserialize(inbuffer + offset);
      offset += this->disable_axis.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "auv_msgs/BodyForceReq"; };
    const char * getMD5(){ return "fc3830ccd35475b5740ab2420d89c9cb"; };

  };

}
#endif