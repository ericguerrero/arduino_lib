#ifndef _ROS_SERVICE_QueryJointsMovement_h
#define _ROS_SERVICE_QueryJointsMovement_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

static const char QUERYJOINTSMOVEMENT[] = "iri_common_drivers_msgs/QueryJointsMovement";

  class QueryJointsMovementRequest : public ros::Msg
  {
    public:
      uint8_t positions_length;
      float st_positions;
      float * positions;
      float velocity;
      float acceleration;

    QueryJointsMovementRequest():
      positions_length(0), positions(NULL),
      velocity(0),
      acceleration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = positions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < positions_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->positions[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->acceleration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t positions_lengthT = *(inbuffer + offset++);
      if(positions_lengthT > positions_length)
        this->positions = (float*)realloc(this->positions, positions_lengthT * sizeof(float));
      offset += 3;
      positions_length = positions_lengthT;
      for( uint8_t i = 0; i < positions_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_positions));
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acceleration));
     return offset;
    }

    const char * getType(){ return QUERYJOINTSMOVEMENT; };
    const char * getMD5(){ return "c92880f9b86c20ad7d091aed4b13fa07"; };

  };

  class QueryJointsMovementResponse : public ros::Msg
  {
    public:
      uint8_t success;

    QueryJointsMovementResponse():
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

    const char * getType(){ return QUERYJOINTSMOVEMENT; };
    const char * getMD5(){ return "6cca7c80398b8b31af04b80534923f16"; };

  };

  class QueryJointsMovement {
    public:
    typedef QueryJointsMovementRequest Request;
    typedef QueryJointsMovementResponse Response;
  };

}
#endif
