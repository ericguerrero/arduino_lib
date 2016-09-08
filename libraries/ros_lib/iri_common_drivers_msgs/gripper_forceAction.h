#ifndef _ROS_iri_common_drivers_msgs_gripper_forceAction_h
#define _ROS_iri_common_drivers_msgs_gripper_forceAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "iri_common_drivers_msgs/gripper_forceActionGoal.h"
#include "iri_common_drivers_msgs/gripper_forceActionResult.h"
#include "iri_common_drivers_msgs/gripper_forceActionFeedback.h"

namespace iri_common_drivers_msgs
{

  class gripper_forceAction : public ros::Msg
  {
    public:
      iri_common_drivers_msgs::gripper_forceActionGoal action_goal;
      iri_common_drivers_msgs::gripper_forceActionResult action_result;
      iri_common_drivers_msgs::gripper_forceActionFeedback action_feedback;

    gripper_forceAction():
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

    const char * getType(){ return "iri_common_drivers_msgs/gripper_forceAction"; };
    const char * getMD5(){ return "be98d053438b86e359158237fe8e378e"; };

  };

}
#endif