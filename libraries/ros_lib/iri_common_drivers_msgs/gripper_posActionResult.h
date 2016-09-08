#ifndef _ROS_iri_common_drivers_msgs_gripper_posActionResult_h
#define _ROS_iri_common_drivers_msgs_gripper_posActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "iri_common_drivers_msgs/gripper_posResult.h"

namespace iri_common_drivers_msgs
{

  class gripper_posActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      iri_common_drivers_msgs::gripper_posResult result;

    gripper_posActionResult():
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

    const char * getType(){ return "iri_common_drivers_msgs/gripper_posActionResult"; };
    const char * getMD5(){ return "4347a0183731c673e3f603e542768132"; };

  };

}
#endif