#ifndef _ROS_auv_msgs_StayWaypointReq_h
#define _ROS_auv_msgs_StayWaypointReq_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "auv_msgs/GoalDescriptor.h"
#include "auv_msgs/Bool6Axis.h"
#include "geometry_msgs/Vector3.h"
#include "auv_msgs/RPY.h"

namespace auv_msgs
{

  class StayWaypointReq : public ros::Msg
  {
    public:
      std_msgs::Header header;
      auv_msgs::GoalDescriptor goal;
      bool altitude_mode;
      auv_msgs::Bool6Axis disable_axis;
      geometry_msgs::Vector3 position_tolerance;
      auv_msgs::RPY orientation_tolerance;

    StayWaypointReq():
      header(),
      goal(),
      altitude_mode(0),
      disable_axis(),
      position_tolerance(),
      orientation_tolerance()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_altitude_mode;
      u_altitude_mode.real = this->altitude_mode;
      *(outbuffer + offset + 0) = (u_altitude_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->altitude_mode);
      offset += this->disable_axis.serialize(outbuffer + offset);
      offset += this->position_tolerance.serialize(outbuffer + offset);
      offset += this->orientation_tolerance.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_altitude_mode;
      u_altitude_mode.base = 0;
      u_altitude_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->altitude_mode = u_altitude_mode.real;
      offset += sizeof(this->altitude_mode);
      offset += this->disable_axis.deserialize(inbuffer + offset);
      offset += this->position_tolerance.deserialize(inbuffer + offset);
      offset += this->orientation_tolerance.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "auv_msgs/StayWaypointReq"; };
    const char * getMD5(){ return "669505d5bfd6c5bc3c0e36dd25725479"; };

  };

}
#endif