#ifndef _ROS_auv_msgs_BodyVelocityReq_h
#define _ROS_auv_msgs_BodyVelocityReq_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "auv_msgs/GoalDescriptor.h"
#include "geometry_msgs/Twist.h"
#include "auv_msgs/Bool6Axis.h"

namespace auv_msgs
{

  class BodyVelocityReq : public ros::Msg
  {
    public:
      std_msgs::Header header;
      auv_msgs::GoalDescriptor goal;
      geometry_msgs::Twist twist;
      auv_msgs::Bool6Axis disable_axis;

    BodyVelocityReq():
      header(),
      goal(),
      twist(),
      disable_axis()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      offset += this->disable_axis.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      offset += this->disable_axis.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "auv_msgs/BodyVelocityReq"; };
    const char * getMD5(){ return "3fba36bb29f45cb10b845a6831e9b677"; };

  };

}
#endif