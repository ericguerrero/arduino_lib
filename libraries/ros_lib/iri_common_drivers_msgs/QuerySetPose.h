#ifndef _ROS_SERVICE_QuerySetPose_h
#define _ROS_SERVICE_QuerySetPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace iri_common_drivers_msgs
{

static const char QUERYSETPOSE[] = "iri_common_drivers_msgs/QuerySetPose";

  class QuerySetPoseRequest : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose;

    QuerySetPoseRequest():
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return QUERYSETPOSE; };
    const char * getMD5(){ return "f192399f711a48924df9a394d37edd67"; };

  };

  class QuerySetPoseResponse : public ros::Msg
  {
    public:
      bool success;

    QuerySetPoseResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return QUERYSETPOSE; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class QuerySetPose {
    public:
    typedef QuerySetPoseRequest Request;
    typedef QuerySetPoseResponse Response;
  };

}
#endif
