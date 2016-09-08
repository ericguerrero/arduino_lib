#ifndef _ROS_SERVICE_change_wp_pair_h
#define _ROS_SERVICE_change_wp_pair_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

static const char CHANGE_WP_PAIR[] = "iri_common_drivers_msgs/change_wp_pair";

  class change_wp_pairRequest : public ros::Msg
  {
    public:
      uint8_t new_pair;

    change_wp_pairRequest():
      new_pair(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->new_pair >> (8 * 0)) & 0xFF;
      offset += sizeof(this->new_pair);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->new_pair =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->new_pair);
     return offset;
    }

    const char * getType(){ return CHANGE_WP_PAIR; };
    const char * getMD5(){ return "96aa8da1e211860add1d79132d59a1ea"; };

  };

  class change_wp_pairResponse : public ros::Msg
  {
    public:
      uint8_t success;

    change_wp_pairResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->success >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->success =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return CHANGE_WP_PAIR; };
    const char * getMD5(){ return "6cca7c80398b8b31af04b80534923f16"; };

  };

  class change_wp_pair {
    public:
    typedef change_wp_pairRequest Request;
    typedef change_wp_pairResponse Response;
  };

}
#endif
