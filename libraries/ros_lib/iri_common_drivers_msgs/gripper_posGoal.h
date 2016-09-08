#ifndef _ROS_iri_common_drivers_msgs_gripper_posGoal_h
#define _ROS_iri_common_drivers_msgs_gripper_posGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

  class gripper_posGoal : public ros::Msg
  {
    public:
      float position;
      float speed;
      float force_limit;

    gripper_posGoal():
      position(0),
      speed(0),
      force_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_position;
      u_position.real = this->position;
      *(outbuffer + offset + 0) = (u_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position);
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
        float real;
        uint32_t base;
      } u_position;
      u_position.base = 0;
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->position = u_position.real;
      offset += sizeof(this->position);
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

    const char * getType(){ return "iri_common_drivers_msgs/gripper_posGoal"; };
    const char * getMD5(){ return "9a9b8d3ced3d61876dc6a6c6e0685011"; };

  };

}
#endif