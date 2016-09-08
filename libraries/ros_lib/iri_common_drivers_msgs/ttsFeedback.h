#ifndef _ROS_iri_common_drivers_msgs_ttsFeedback_h
#define _ROS_iri_common_drivers_msgs_ttsFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

  class ttsFeedback : public ros::Msg
  {
    public:
      bool busy;

    ttsFeedback():
      busy(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_busy;
      u_busy.real = this->busy;
      *(outbuffer + offset + 0) = (u_busy.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->busy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_busy;
      u_busy.base = 0;
      u_busy.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->busy = u_busy.real;
      offset += sizeof(this->busy);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/ttsFeedback"; };
    const char * getMD5(){ return "06f6731b96bef0a1982b1e3c82971af6"; };

  };

}
#endif