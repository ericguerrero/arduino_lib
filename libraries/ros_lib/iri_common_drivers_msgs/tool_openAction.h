#ifndef _ROS_iri_common_drivers_msgs_tool_openAction_h
#define _ROS_iri_common_drivers_msgs_tool_openAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "iri_common_drivers_msgs/tool_openActionGoal.h"
#include "iri_common_drivers_msgs/tool_openActionResult.h"
#include "iri_common_drivers_msgs/tool_openActionFeedback.h"

namespace iri_common_drivers_msgs
{

  class tool_openAction : public ros::Msg
  {
    public:
      iri_common_drivers_msgs::tool_openActionGoal action_goal;
      iri_common_drivers_msgs::tool_openActionResult action_result;
      iri_common_drivers_msgs::tool_openActionFeedback action_feedback;

    tool_openAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/tool_openAction"; };
    const char * getMD5(){ return "310e509b685d460bd9d5a7c15911bbec"; };

  };

}
#endif