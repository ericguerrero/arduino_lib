#ifndef _ROS_iri_common_drivers_msgs_ttsActionResult_h
#define _ROS_iri_common_drivers_msgs_ttsActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "iri_common_drivers_msgs/ttsResult.h"

namespace iri_common_drivers_msgs
{

  class ttsActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      iri_common_drivers_msgs::ttsResult result;

    ttsActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/ttsActionResult"; };
    const char * getMD5(){ return "b05528ce2d57b2b18c666f6eabecb171"; };

  };

}
#endif