#ifndef _ROS_cola2_control_StandardControllerInfo_h
#define _ROS_cola2_control_StandardControllerInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_control
{

  class StandardControllerInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float setpoint;
      float sensed;
      float feedback;
      float control;
      float feedforward;
      float output;
      float saturated_output;

    StandardControllerInfo():
      header(),
      setpoint(0),
      sensed(0),
      feedback(0),
      control(0),
      feedforward(0),
      output(0),
      saturated_output(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint);
      offset += serializeAvrFloat64(outbuffer + offset, this->sensed);
      offset += serializeAvrFloat64(outbuffer + offset, this->feedback);
      offset += serializeAvrFloat64(outbuffer + offset, this->control);
      offset += serializeAvrFloat64(outbuffer + offset, this->feedforward);
      offset += serializeAvrFloat64(outbuffer + offset, this->output);
      offset += serializeAvrFloat64(outbuffer + offset, this->saturated_output);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sensed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->feedback));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->control));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->feedforward));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->output));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->saturated_output));
     return offset;
    }

    const char * getType(){ return "cola2_control/StandardControllerInfo"; };
    const char * getMD5(){ return "1f11c08bb110faac6667561e7c56a368"; };

  };

}
#endif