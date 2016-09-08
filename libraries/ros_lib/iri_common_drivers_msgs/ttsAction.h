#ifndef _ROS_iri_common_drivers_msgs_ttsAction_h
#define _ROS_iri_common_drivers_msgs_ttsAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "iri_common_drivers_msgs/ttsActionGoal.h"
#include "iri_common_drivers_msgs/ttsActionResult.h"
#include "iri_common_drivers_msgs/ttsActionFeedback.h"

namespace iri_common_drivers_msgs
{

  class ttsAction : public ros::Msg
  {
    public:
      iri_common_drivers_msgs::ttsActionGoal action_goal;
      iri_common_drivers_msgs::ttsActionResult action_result;
      iri_common_drivers_msgs::ttsActionFeedback action_feedback;

    ttsAction():
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

    const char * getType(){ return "iri_common_drivers_msgs/ttsAction"; };
    const char * getMD5(){ return "6122a42b9d59f5eb18c5a51f0152b131"; };

  };

}
#endif