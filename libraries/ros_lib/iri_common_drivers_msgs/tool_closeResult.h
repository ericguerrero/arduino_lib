#ifndef _ROS_iri_common_drivers_msgs_tool_closeResult_h
#define _ROS_iri_common_drivers_msgs_tool_closeResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

  class tool_closeResult : public ros::Msg
  {
    public:
      bool successful;

    tool_closeResult():
      successful(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_successful;
      u_successful.real = this->successful;
      *(outbuffer + offset + 0) = (u_successful.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->successful);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_successful;
      u_successful.base = 0;
      u_successful.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->successful = u_successful.real;
      offset += sizeof(this->successful);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/tool_closeResult"; };
    const char * getMD5(){ return "6ccdb752b565be6d250259ff3d0c7ea1"; };

  };

}
#endif