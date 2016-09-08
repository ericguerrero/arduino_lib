#ifndef _ROS_iri_common_drivers_msgs_gripper_posResult_h
#define _ROS_iri_common_drivers_msgs_gripper_posResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

  class gripper_posResult : public ros::Msg
  {
    public:
      float final_position;
      bool force_limit;

    gripper_posResult():
      final_position(0),
      force_limit(0)
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
      union {
        bool real;
        uint8_t base;
      } u_force_limit;
      u_force_limit.real = this->force_limit;
      *(outbuffer + offset + 0) = (u_force_limit.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->force_limit);
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
      union {
        bool real;
        uint8_t base;
      } u_force_limit;
      u_force_limit.base = 0;
      u_force_limit.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->force_limit = u_force_limit.real;
      offset += sizeof(this->force_limit);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/gripper_posResult"; };
    const char * getMD5(){ return "1375884c46884af8ec362a5e83c26afb"; };

  };

}
#endif