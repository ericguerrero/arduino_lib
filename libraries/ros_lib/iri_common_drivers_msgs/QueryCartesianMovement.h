#ifndef _ROS_SERVICE_QueryCartesianMovement_h
#define _ROS_SERVICE_QueryCartesianMovement_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace iri_common_drivers_msgs
{

static const char QUERYCARTESIANMOVEMENT[] = "iri_common_drivers_msgs/QueryCartesianMovement";

  class QueryCartesianMovementRequest : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose;
      float velocity;
      float acceleration;

    QueryCartesianMovementRequest():
      pose(),
      velocity(0),
      acceleration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->acceleration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acceleration));
     return offset;
    }

    const char * getType(){ return QUERYCARTESIANMOVEMENT; };
    const char * getMD5(){ return "116be44edbf944d33d3282858c218a44"; };

  };

  class QueryCartesianMovementResponse : public ros::Msg
  {
    public:
      uint8_t success;

    QueryCartesianMovementResponse():
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

    const char * getType(){ return QUERYCARTESIANMOVEMENT; };
    const char * getMD5(){ return "6cca7c80398b8b31af04b80534923f16"; };

  };

  class QueryCartesianMovement {
    public:
    typedef QueryCartesianMovementRequest Request;
    typedef QueryCartesianMovementResponse Response;
  };

}
#endif
