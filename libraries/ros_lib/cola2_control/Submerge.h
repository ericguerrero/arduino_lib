#ifndef _ROS_SERVICE_Submerge_h
#define _ROS_SERVICE_Submerge_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cola2_control
{

static const char SUBMERGE[] = "cola2_control/Submerge";

  class SubmergeRequest : public ros::Msg
  {
    public:
      float z;
      bool altitude_mode;

    SubmergeRequest():
      z(0),
      altitude_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      union {
        bool real;
        uint8_t base;
      } u_altitude_mode;
      u_altitude_mode.real = this->altitude_mode;
      *(outbuffer + offset + 0) = (u_altitude_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->altitude_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        bool real;
        uint8_t base;
      } u_altitude_mode;
      u_altitude_mode.base = 0;
      u_altitude_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->altitude_mode = u_altitude_mode.real;
      offset += sizeof(this->altitude_mode);
     return offset;
    }

    const char * getType(){ return SUBMERGE; };
    const char * getMD5(){ return "a5b1cc5e2f36e6dedd958c4f6e4c7784"; };

  };

  class SubmergeResponse : public ros::Msg
  {
    public:
      bool attempted;

    SubmergeResponse():
      attempted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_attempted;
      u_attempted.real = this->attempted;
      *(outbuffer + offset + 0) = (u_attempted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->attempted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_attempted;
      u_attempted.base = 0;
      u_attempted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->attempted = u_attempted.real;
      offset += sizeof(this->attempted);
     return offset;
    }

    const char * getType(){ return SUBMERGE; };
    const char * getMD5(){ return "70f46e6393e2715db0559943d3e7b477"; };

  };

  class Submerge {
    public:
    typedef SubmergeRequest Request;
    typedef SubmergeResponse Response;
  };

}
#endif
