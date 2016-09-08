#ifndef _ROS_iri_common_drivers_msgs_gripper_forceGoal_h
#define _ROS_iri_common_drivers_msgs_gripper_forceGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

  class gripper_forceGoal : public ros::Msg
  {
    public:
      bool close;
      float speed;
      float force_limit;

    gripper_forceGoal():
      close(0),
      speed(0),
      force_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_close;
      u_close.real = this->close;
      *(outbuffer + offset + 0) = (u_close.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->close);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_force_limit;
      u_force_limit.real = this->force_limit;
      *(outbuffer + offset + 0) = (u_force_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force_limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_close;
      u_close.base = 0;
      u_close.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->close = u_close.real;
      offset += sizeof(this->close);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_force_limit;
      u_force_limit.base = 0;
      u_force_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->force_limit = u_force_limit.real;
      offset += sizeof(this->force_limit);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/gripper_forceGoal"; };
    const char * getMD5(){ return "523ba597e5c15c17e70d70b8d0a7506d"; };

  };

}
#endif