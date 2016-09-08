#ifndef _ROS_auv_msgs_WaypointSts_h
#define _ROS_auv_msgs_WaypointSts_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "auv_msgs/GoalDescriptor.h"

namespace auv_msgs
{

  class WaypointSts : public ros::Msg
  {
    public:
      std_msgs::Header header;
      auv_msgs::GoalDescriptor goal;
      bool achieved;

    WaypointSts():
      header(),
      goal(),
      achieved(0)
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
      } u_achieved;
      u_achieved.real = this->achieved;
      *(outbuffer + offset + 0) = (u_achieved.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->achieved);
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
      } u_achieved;
      u_achieved.base = 0;
      u_achieved.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->achieved = u_achieved.real;
      offset += sizeof(this->achieved);
     return offset;
    }

    const char * getType(){ return "auv_msgs/WaypointSts"; };
    const char * getMD5(){ return "52121c2ea15ce1a73bc5b64465141d80"; };

  };

}
#endif