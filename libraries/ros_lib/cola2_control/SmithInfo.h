#ifndef _ROS_cola2_control_SmithInfo_h
#define _ROS_cola2_control_SmithInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_control
{

  class SmithInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float sensed;
      float output;
      float prediction;
      float delayed_prediction;
      float feedback;

    SmithInfo():
      header(),
      sensed(0),
      output(0),
      prediction(0),
      delayed_prediction(0),
      feedback(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->sensed);
      offset += serializeAvrFloat64(outbuffer + offset, this->output);
      offset += serializeAvrFloat64(outbuffer + offset, this->prediction);
      offset += serializeAvrFloat64(outbuffer + offset, this->delayed_prediction);
      offset += serializeAvrFloat64(outbuffer + offset, this->feedback);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sensed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->output));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->prediction));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->delayed_prediction));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->feedback));
     return offset;
    }

    const char * getType(){ return "cola2_control/SmithInfo"; };
    const char * getMD5(){ return "93ac34bd2dce4759dd16ab1c0b1921ef"; };

  };

}
#endif