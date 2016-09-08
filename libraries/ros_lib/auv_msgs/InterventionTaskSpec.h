#ifndef _ROS_auv_msgs_InterventionTaskSpec_h
#define _ROS_auv_msgs_InterventionTaskSpec_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auv_msgs/InterventionStrategySpec.h"

namespace auv_msgs
{

  class InterventionTaskSpec : public ros::Msg
  {
    public:
      int32_t task_type;
      uint8_t strategy_spec_length;
      auv_msgs::InterventionStrategySpec st_strategy_spec;
      auv_msgs::InterventionStrategySpec * strategy_spec;
      enum { TASK_RECOVERY = 1 };
      enum { TASK_HOOK_CABLE = 2 };
      enum { TASK_PUSH_BUTTON = 3 };
      enum { TASK_OPEN_VALVE = 4 };

    InterventionTaskSpec():
      task_type(0),
      strategy_spec_length(0), strategy_spec(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_task_type;
      u_task_type.real = this->task_type;
      *(outbuffer + offset + 0) = (u_task_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_task_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_task_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_task_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->task_type);
      *(outbuffer + offset++) = strategy_spec_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < strategy_spec_length; i++){
      offset += this->strategy_spec[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_task_type;
      u_task_type.base = 0;
      u_task_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_task_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_task_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_task_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->task_type = u_task_type.real;
      offset += sizeof(this->task_type);
      uint8_t strategy_spec_lengthT = *(inbuffer + offset++);
      if(strategy_spec_lengthT > strategy_spec_length)
        this->strategy_spec = (auv_msgs::InterventionStrategySpec*)realloc(this->strategy_spec, strategy_spec_lengthT * sizeof(auv_msgs::InterventionStrategySpec));
      offset += 3;
      strategy_spec_length = strategy_spec_lengthT;
      for( uint8_t i = 0; i < strategy_spec_length; i++){
      offset += this->st_strategy_spec.deserialize(inbuffer + offset);
        memcpy( &(this->strategy_spec[i]), &(this->st_strategy_spec), sizeof(auv_msgs::InterventionStrategySpec));
      }
     return offset;
    }

    const char * getType(){ return "auv_msgs/InterventionTaskSpec"; };
    const char * getMD5(){ return "2b8fadd4bfa9a8a880fc736d196c3441"; };

  };

}
#endif