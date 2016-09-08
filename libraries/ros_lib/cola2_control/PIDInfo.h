#ifndef _ROS_cola2_control_PIDInfo_h
#define _ROS_cola2_control_PIDInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_control
{

  class PIDInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float dt;
      float setpoint;
      float feedback;
      float ek;
      float edotk;
      float eik;
      float tau;
      float saturated_tau;

    PIDInfo():
      header(),
      dt(0),
      setpoint(0),
      feedback(0),
      ek(0),
      edotk(0),
      eik(0),
      tau(0),
      saturated_tau(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->dt);
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint);
      offset += serializeAvrFloat64(outbuffer + offset, this->feedback);
      offset += serializeAvrFloat64(outbuffer + offset, this->ek);
      offset += serializeAvrFloat64(outbuffer + offset, this->edotk);
      offset += serializeAvrFloat64(outbuffer + offset, this->eik);
      offset += serializeAvrFloat64(outbuffer + offset, this->tau);
      offset += serializeAvrFloat64(outbuffer + offset, this->saturated_tau);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dt));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->feedback));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ek));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->edotk));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eik));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tau));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->saturated_tau));
     return offset;
    }

    const char * getType(){ return "cola2_control/PIDInfo"; };
    const char * getMD5(){ return "8b80c52f2e46dd4fc05ab75d1e314a30"; };

  };

}
#endif