#ifndef _ROS_cola2_control_MPCInfo_h
#define _ROS_cola2_control_MPCInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_control
{

  class MPCInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float dt;
      float setpoint;
      float feedback;
      float desired_setpoint;
      float best_output;
      float best_output_score;

    MPCInfo():
      header(),
      dt(0),
      setpoint(0),
      feedback(0),
      desired_setpoint(0),
      best_output(0),
      best_output_score(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->dt);
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint);
      offset += serializeAvrFloat64(outbuffer + offset, this->feedback);
      offset += serializeAvrFloat64(outbuffer + offset, this->desired_setpoint);
      offset += serializeAvrFloat64(outbuffer + offset, this->best_output);
      offset += serializeAvrFloat64(outbuffer + offset, this->best_output_score);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dt));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->feedback));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->desired_setpoint));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->best_output));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->best_output_score));
     return offset;
    }

    const char * getType(){ return "cola2_control/MPCInfo"; };
    const char * getMD5(){ return "df88553c61426435c2c0bd28f4d6e610"; };

  };

}
#endif