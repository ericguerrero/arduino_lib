#ifndef _ROS_auv_msgs_VehiclePose_h
#define _ROS_auv_msgs_VehiclePose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auv_msgs/NED.h"
#include "auv_msgs/RPY.h"

namespace auv_msgs
{

  class VehiclePose : public ros::Msg
  {
    public:
      auv_msgs::NED position;
      auv_msgs::RPY orientation;

    VehiclePose():
      position(),
      orientation()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "auv_msgs/VehiclePose"; };
    const char * getMD5(){ return "67cb677ee7631f5b7f56213f26ce044c"; };

  };

}
#endif