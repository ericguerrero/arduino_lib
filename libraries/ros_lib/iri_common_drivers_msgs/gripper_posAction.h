#ifndef _ROS_iri_common_drivers_msgs_gripper_posAction_h
#define _ROS_iri_common_drivers_msgs_gripper_posAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "iri_common_drivers_msgs/gripper_posActionGoal.h"
#include "iri_common_drivers_msgs/gripper_posActionResult.h"
#include "iri_common_drivers_msgs/gripper_posActionFeedback.h"

namespace iri_common_drivers_msgs
{

  class gripper_posAction : public ros::Msg
  {
    public:
      iri_common_drivers_msgs::gripper_posActionGoal action_goal;
      iri_common_drivers_msgs::gripper_posActionResult action_result;
      iri_common_drivers_msgs::gripper_posActionFeedback action_feedback;

    gripper_posAction():
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

    const char * getType(){ return "iri_common_drivers_msgs/gripper_posAction"; };
    const char * getMD5(){ return "53215205283f8801d1bcb8960f1e45b6"; };

  };

}
#endif