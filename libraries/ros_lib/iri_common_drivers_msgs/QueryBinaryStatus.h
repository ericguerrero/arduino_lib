#ifndef _ROS_SERVICE_QueryBinaryStatus_h
#define _ROS_SERVICE_QueryBinaryStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

static const char QUERYBINARYSTATUS[] = "iri_common_drivers_msgs/QueryBinaryStatus";

  class QueryBinaryStatusRequest : public ros::Msg
  {
    public:

    QueryBinaryStatusRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return QUERYBINARYSTATUS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class QueryBinaryStatusResponse : public ros::Msg
  {
    public:
      bool success;

    QueryBinaryStatusResponse():
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

    const char * getType(){ return QUERYBINARYSTATUS; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class QueryBinaryStatus {
    public:
    typedef QueryBinaryStatusRequest Request;
    typedef QueryBinaryStatusResponse Response;
  };

}
#endif
