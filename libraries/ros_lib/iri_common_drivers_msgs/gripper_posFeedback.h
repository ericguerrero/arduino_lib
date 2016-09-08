#ifndef _ROS_iri_common_drivers_msgs_gripper_posFeedback_h
#define _ROS_iri_common_drivers_msgs_gripper_posFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

  class gripper_posFeedback : public ros::Msg
  {
    public:
      float current_position;

    gripper_posFeedback():
      current_position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_current_position;
      u_current_position.real = this->current_position;
      *(outbuffer + offset + 0) = (u_current_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_current_position;
      u_current_position.base = 0;
      u_current_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_position = u_current_position.real;
      offset += sizeof(this->current_position);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/gripper_posFeedback"; };
    const char * getMD5(){ return "a447468e6d196264c01d04f925289e8a"; };

  };

}
#endif