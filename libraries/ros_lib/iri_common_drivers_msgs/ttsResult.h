#ifndef _ROS_iri_common_drivers_msgs_ttsResult_h
#define _ROS_iri_common_drivers_msgs_ttsResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

  class ttsResult : public ros::Msg
  {
    public:
      bool ok;

    ttsResult():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/ttsResult"; };
    const char * getMD5(){ return "6f6da3883749771fac40d6deb24a8c02"; };

  };

}
#endif