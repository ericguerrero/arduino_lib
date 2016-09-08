#ifndef _ROS_auv_msgs_InterventionStrategySpec_h
#define _ROS_auv_msgs_InterventionStrategySpec_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Transform.h"

namespace auv_msgs
{

  class InterventionStrategySpec : public ros::Msg
  {
    public:
      geometry_msgs::Transform grasp_frame;
      int32_t preshape;
      enum { PRESHAPE_CYLINDRICAL_PRECISION = 1 };
      enum { PRESHAPE_CYLINDRICAL_POWER = 2 };
      enum { PRESHAPE_ONE_FINGER = 3 };
      enum { PRESHAPE_HOOK = 4 };

    InterventionStrategySpec():
      grasp_frame(),
      preshape(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->grasp_frame.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_preshape;
      u_preshape.real = this->preshape;
      *(outbuffer + offset + 0) = (u_preshape.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_preshape.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_preshape.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_preshape.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->preshape);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->grasp_frame.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_preshape;
      u_preshape.base = 0;
      u_preshape.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_preshape.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_preshape.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_preshape.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->preshape = u_preshape.real;
      offset += sizeof(this->preshape);
     return offset;
    }

    const char * getType(){ return "auv_msgs/InterventionStrategySpec"; };
    const char * getMD5(){ return "3c4b77f7990aea517de29ed69dd3e105"; };

  };

}
#endif