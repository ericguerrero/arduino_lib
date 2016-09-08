#ifndef _ROS_iri_common_drivers_msgs_gripper_forceResult_h
#define _ROS_iri_common_drivers_msgs_gripper_forceResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

  class gripper_forceResult : public ros::Msg
  {
    public:
      float final_position;

    gripper_forceResult():
      final_position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_final_position;
      u_final_position.real = this->final_position;
      *(outbuffer + offset + 0) = (u_final_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_final_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_final_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_final_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->final_position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_final_position;
      u_final_position.base = 0;
      u_final_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_final_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_final_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_final_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->final_position = u_final_position.real;
      offset += sizeof(this->final_position);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/gripper_forceResult"; };
    const char * getMD5(){ return "115537b1ad3616f3c1b195a7c5c87b3c"; };

  };

}
#endif