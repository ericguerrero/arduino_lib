#ifndef _ROS_iri_common_drivers_msgs_tool_openGoal_h
#define _ROS_iri_common_drivers_msgs_tool_openGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

  class tool_openGoal : public ros::Msg
  {
    public:

    tool_openGoal()
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

    const char * getType(){ return "iri_common_drivers_msgs/tool_openGoal"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif