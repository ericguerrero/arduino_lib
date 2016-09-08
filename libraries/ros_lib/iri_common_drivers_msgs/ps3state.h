#ifndef _ROS_iri_common_drivers_msgs_ps3state_h
#define _ROS_iri_common_drivers_msgs_ps3state_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace iri_common_drivers_msgs
{

  class ps3state : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int8_t button;
      enum { PS3_BUTTON_SELECT = 0 };
      enum { PS3_BUTTON_STICK_LEFT = 1 };
      enum { PS3_BUTTON_STICK_RIGHT = 2 };
      enum { PS3_BUTTON_START = 3 };
      enum { PS3_BUTTON_CROSS_UP = 4 };
      enum { PS3_BUTTON_CROSS_RIGHT = 5 };
      enum { PS3_BUTTON_CROSS_DOWN = 6 };
      enum { PS3_BUTTON_CROSS_LEFT = 7 };
      enum { PS3_BUTTON_REAR_LEFT_2 = 8 };
      enum { PS3_BUTTON_REAR_RIGHT_2 = 9 };
      enum { PS3_BUTTON_REAR_LEFT_1 = 10 };
      enum { PS3_BUTTON_REAR_RIGHT_1 = 11 };
      enum { PS3_BUTTON_ACTION_TRIANGLE = 12 };
      enum { PS3_BUTTON_ACTION_CIRCLE = 13 };
      enum { PS3_BUTTON_ACTION_CROSS = 14 };
      enum { PS3_BUTTON_ACTION_SQUARE = 15 };
      enum { PS3_BUTTON_PAIRING = 16 };
      enum { PS3_AXIS_STICK_LEFT_LEFTWARDS = 0 };
      enum { PS3_AXIS_STICK_LEFT_UPWARDS = 1 };
      enum { PS3_AXIS_STICK_RIGHT_LEFTWARDS = 2 };
      enum { PS3_AXIS_STICK_RIGHT_UPWARDS = 3 };
      enum { PS3_AXIS_BUTTON_CROSS_UP = 4 };
      enum { PS3_AXIS_BUTTON_CROSS_RIGHT = 5 };
      enum { PS3_AXIS_BUTTON_CROSS_DOWN = 6 };
      enum { PS3_AXIS_BUTTON_CROSS_LEFT = 7 };
      enum { PS3_AXIS_BUTTON_REAR_LEFT_2 = 8 };
      enum { PS3_AXIS_BUTTON_REAR_RIGHT_2 = 9 };
      enum { PS3_AXIS_BUTTON_REAR_LEFT_1 = 10 };
      enum { PS3_AXIS_BUTTON_REAR_RIGHT_1 = 11 };
      enum { PS3_AXIS_BUTTON_ACTION_TRIANGLE = 12 };
      enum { PS3_AXIS_BUTTON_ACTION_CIRCLE = 13 };
      enum { PS3_AXIS_BUTTON_ACTION_CROSS = 14 };
      enum { PS3_AXIS_BUTTON_ACTION_SQUARE = 15 };
      enum { PS3_AXIS_ACCELEROMETER_LEFT = 16 };
      enum { PS3_AXIS_ACCELEROMETER_FORWARD = 17 };
      enum { PS3_AXIS_ACCELEROMETER_UP = 18 };
      enum { PS3_AXIS_GYRO_YAW = 19 };

    ps3state():
      header(),
      button(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_button;
      u_button.real = this->button;
      *(outbuffer + offset + 0) = (u_button.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_button;
      u_button.base = 0;
      u_button.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->button = u_button.real;
      offset += sizeof(this->button);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/ps3state"; };
    const char * getMD5(){ return "04c2fe2530f36ae31ed7156c46b5dfb8"; };

  };

}
#endif