#ifndef _ROS_iri_common_drivers_msgs_ttsActionGoal_h
#define _ROS_iri_common_drivers_msgs_ttsActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "iri_common_drivers_msgs/ttsGoal.h"

namespace iri_common_drivers_msgs
{

  class ttsActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      iri_common_drivers_msgs::ttsGoal goal;

    ttsActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/ttsActionGoal"; };
    const char * getMD5(){ return "841cba3276252f826c7530f06a15d743"; };

  };

}
#endif