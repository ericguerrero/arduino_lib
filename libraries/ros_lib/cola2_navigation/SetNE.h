#ifndef _ROS_SERVICE_SetNE_h
#define _ROS_SERVICE_SetNE_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cola2_navigation
{

static const char SETNE[] = "cola2_navigation/SetNE";

  class SetNERequest : public ros::Msg
  {
    public:
      float north;
      float east;

    SetNERequest():
      north(0),
      east(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->north);
      offset += serializeAvrFloat64(outbuffer + offset, this->east);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->north));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->east));
     return offset;
    }

    const char * getType(){ return SETNE; };
    const char * getMD5(){ return "1699d4fe5f0d08ad6891c8912601b4b4"; };

  };

  class SetNEResponse : public ros::Msg
  {
    public:
      bool success;

    SetNEResponse():
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

    const char * getType(){ return SETNE; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetNE {
    public:
    typedef SetNERequest Request;
    typedef SetNEResponse Response;
  };

}
#endif
