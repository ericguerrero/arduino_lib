#ifndef _ROS_cola2_control_DynamicModelInfo_h
#define _ROS_cola2_control_DynamicModelInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_control
{

  class DynamicModelInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float dt;
      float setpoint;
      float feedback;
      float damping;
      float F_or_M;
      float acceleration;
      float predicted_velocity;

    DynamicModelInfo():
      header(),
      dt(0),
      setpoint(0),
      feedback(0),
      damping(0),
      F_or_M(0),
      acceleration(0),
      predicted_velocity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->dt);
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint);
      offset += serializeAvrFloat64(outbuffer + offset, this->feedback);
      offset += serializeAvrFloat64(outbuffer + offset, this->damping);
      offset += serializeAvrFloat64(outbuffer + offset, this->F_or_M);
      offset += serializeAvrFloat64(outbuffer + offset, this->acceleration);
      offset += serializeAvrFloat64(outbuffer + offset, this->predicted_velocity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dt));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->feedback));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->damping));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->F_or_M));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acceleration));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->predicted_velocity));
     return offset;
    }

    const char * getType(){ return "cola2_control/DynamicModelInfo"; };
    const char * getMD5(){ return "0dd90a64c579aabef0df955af71c1399"; };

  };

}
#endif