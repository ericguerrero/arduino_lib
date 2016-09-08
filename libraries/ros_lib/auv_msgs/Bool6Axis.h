#ifndef _ROS_auv_msgs_Bool6Axis_h
#define _ROS_auv_msgs_Bool6Axis_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auv_msgs
{

  class Bool6Axis : public ros::Msg
  {
    public:
      bool x;
      bool y;
      bool z;
      bool roll;
      bool pitch;
      bool yaw;

    Bool6Axis():
      x(0),
      y(0),
      z(0),
      roll(0),
      pitch(0),
      yaw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->x);
      union {
        bool real;
        uint8_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->y);
      union {
        bool real;
        uint8_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->z);
      union {
        bool real;
        uint8_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->roll);
      union {
        bool real;
        uint8_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        bool real;
        uint8_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->yaw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        bool real;
        uint8_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        bool real;
        uint8_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        bool real;
        uint8_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      union {
        bool real;
        uint8_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        bool real;
        uint8_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
     return offset;
    }

    const char * getType(){ return "auv_msgs/Bool6Axis"; };
    const char * getMD5(){ return "38f836659cedbc069e466741ffb25422"; };

  };

}
#endif