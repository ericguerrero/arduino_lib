#ifndef _ROS_SERVICE_SetNedOrigin_h
#define _ROS_SERVICE_SetNedOrigin_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cola2_navigation
{

static const char SETNEDORIGIN[] = "cola2_navigation/SetNedOrigin";

  class SetNedOriginRequest : public ros::Msg
  {
    public:
      float latitude;
      float longitude;

    SetNedOriginRequest():
      latitude(0),
      longitude(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->longitude);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longitude));
     return offset;
    }

    const char * getType(){ return SETNEDORIGIN; };
    const char * getMD5(){ return "680c6dc7da65a2421a822205dcbdb600"; };

  };

  class SetNedOriginResponse : public ros::Msg
  {
    public:
      bool success;

    SetNedOriginResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return SETNEDORIGIN; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetNedOrigin {
    public:
    typedef SetNedOriginRequest Request;
    typedef SetNedOriginResponse Response;
  };

}
#endif
