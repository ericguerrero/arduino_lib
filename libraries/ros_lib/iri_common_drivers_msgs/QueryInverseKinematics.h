#ifndef _ROS_SERVICE_QueryInverseKinematics_h
#define _ROS_SERVICE_QueryInverseKinematics_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "sensor_msgs/JointState.h"

namespace iri_common_drivers_msgs
{

static const char QUERYINVERSEKINEMATICS[] = "iri_common_drivers_msgs/QueryInverseKinematics";

  class QueryInverseKinematicsRequest : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose;

    QueryInverseKinematicsRequest():
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

    const char * getType(){ return QUERYINVERSEKINEMATICS; };
    const char * getMD5(){ return "3f8930d968a3e84d471dff917bb1cdae"; };

  };

  class QueryInverseKinematicsResponse : public ros::Msg
  {
    public:
      sensor_msgs::JointState joints;

    QueryInverseKinematicsResponse():
      joints()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joints.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joints.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return QUERYINVERSEKINEMATICS; };
    const char * getMD5(){ return "13b568889983e6c4080c58d8e7c2c89c"; };

  };

  class QueryInverseKinematics {
    public:
    typedef QueryInverseKinematicsRequest Request;
    typedef QueryInverseKinematicsResponse Response;
  };

}
#endif
