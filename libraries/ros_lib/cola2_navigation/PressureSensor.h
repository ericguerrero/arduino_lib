#ifndef _ROS_cola2_navigation_PressureSensor_h
#define _ROS_cola2_navigation_PressureSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_navigation
{

  class PressureSensor : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float pressure;
      float temperature;

    PressureSensor():
      header(),
      pressure(0),
      temperature(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->pressure);
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pressure));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temperature));
     return offset;
    }

    const char * getType(){ return "cola2_navigation/PressureSensor"; };
    const char * getMD5(){ return "82136f25002ce1ecac032c05bba11697"; };

  };

}
#endif