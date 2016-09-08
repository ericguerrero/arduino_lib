#ifndef _ROS_auv_msgs_GoalDescriptor_h
#define _ROS_auv_msgs_GoalDescriptor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auv_msgs
{

  class GoalDescriptor : public ros::Msg
  {
    public:
      const char* requester;
      uint32_t id;
      uint32_t priority;
      enum { PRIORITY_LOW =  0 };
      enum { PRIORITY_NORMAL =  10 };
      enum { PRIORITY_AVOID_OBSTACLE =  20 };
      enum { PRIORITY_EMERGENCY =  30 };
      enum { PRIORITY_MANUAL_OVERRIDE =  40 };

    GoalDescriptor():
      requester(""),
      id(0),
      priority(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_requester = strlen(this->requester);
      memcpy(outbuffer + offset, &length_requester, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->requester, length_requester);
      offset += length_requester;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->priority >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->priority >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->priority >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->priority >> (8 * 3)) & 0xFF;
      offset += sizeof(this->priority);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_requester;
      memcpy(&length_requester, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_requester; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_requester-1]=0;
      this->requester = (char *)(inbuffer + offset-1);
      offset += length_requester;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      this->priority =  ((uint32_t) (*(inbuffer + offset)));
      this->priority |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->priority |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->priority |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->priority);
     return offset;
    }

    const char * getType(){ return "auv_msgs/GoalDescriptor"; };
    const char * getMD5(){ return "dbad5128112e1cb789315dd314ee3b12"; };

  };

}
#endif