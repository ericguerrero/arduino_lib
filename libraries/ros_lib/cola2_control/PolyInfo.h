#ifndef _ROS_cola2_control_PolyInfo_h
#define _ROS_cola2_control_PolyInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_control
{

  class PolyInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float setpoint;
      float feedback;
      float setpoint_poly_result;
      float feedback_poly_result;
      float ret;
      float saturated_ret;

    PolyInfo():
      header(),
      setpoint(0),
      feedback(0),
      setpoint_poly_result(0),
      feedback_poly_result(0),
      ret(0),
      saturated_ret(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint);
      offset += serializeAvrFloat64(outbuffer + offset, this->feedback);
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint_poly_result);
      offset += serializeAvrFloat64(outbuffer + offset, this->feedback_poly_result);
      offset += serializeAvrFloat64(outbuffer + offset, this->ret);
      offset += serializeAvrFloat64(outbuffer + offset, this->saturated_ret);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->feedback));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint_poly_result));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->feedback_poly_result));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ret));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->saturated_ret));
     return offset;
    }

    const char * getType(){ return "cola2_control/PolyInfo"; };
    const char * getMD5(){ return "fcde580cf977a431fac5b95b5c77d8b1"; };

  };

}
#endif