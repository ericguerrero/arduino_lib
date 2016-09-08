#ifndef _ROS_SERVICE_QueryRobotPoseFromToolPose_h
#define _ROS_SERVICE_QueryRobotPoseFromToolPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace iri_common_drivers_msgs
{

static const char QUERYROBOTPOSEFROMTOOLPOSE[] = "iri_common_drivers_msgs/QueryRobotPoseFromToolPose";

  class QueryRobotPoseFromToolPoseRequest : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped tool_pose;

    QueryRobotPoseFromToolPoseRequest():
      tool_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->tool_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->tool_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return QUERYROBOTPOSEFROMTOOLPOSE; };
    const char * getMD5(){ return "1f49009e637ac367cacdab60da3707bd"; };

  };

  class QueryRobotPoseFromToolPoseResponse : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped robot_pose;

    QueryRobotPoseFromToolPoseResponse():
      robot_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->robot_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->robot_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return QUERYROBOTPOSEFROMTOOLPOSE; };
    const char * getMD5(){ return "bb46cd500e029a262f0c2284fecd8ed7"; };

  };

  class QueryRobotPoseFromToolPose {
    public:
    typedef QueryRobotPoseFromToolPoseRequest Request;
    typedef QueryRobotPoseFromToolPoseResponse Response;
  };

}
#endif
