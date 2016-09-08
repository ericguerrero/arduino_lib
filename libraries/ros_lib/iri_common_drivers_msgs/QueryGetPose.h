#ifndef _ROS_SERVICE_QueryGetPose_h
#define _ROS_SERVICE_QueryGetPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace iri_common_drivers_msgs
{

static const char QUERYGETPOSE[] = "iri_common_drivers_msgs/QueryGetPose";

  class QueryGetPoseRequest : public ros::Msg
  {
    public:

    QueryGetPoseRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return QUERYGETPOSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class QueryGetPoseResponse : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose;
      bool success;

    QueryGetPoseResponse():
      pose(),
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
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
      offset += this->pose.deserialize(inbuffer + offset);
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

    const char * getType(){ return QUERYGETPOSE; };
    const char * getMD5(){ return "4f3e6779e94ecb8339284b8b3f87c8ea"; };

  };

  class QueryGetPose {
    public:
    typedef QueryGetPoseRequest Request;
    typedef QueryGetPoseResponse Response;
  };

}
#endif
