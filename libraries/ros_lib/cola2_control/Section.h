#ifndef _ROS_cola2_control_Section_h
#define _ROS_cola2_control_Section_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_control
{

  class Section : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float direction;
      float xs;
      float ys;
      float xc;
      float yc;
      float xe;
      float ye;
      float vel;

    Section():
      header(),
      direction(0),
      xs(0),
      ys(0),
      xc(0),
      yc(0),
      xe(0),
      ye(0),
      vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->direction);
      offset += serializeAvrFloat64(outbuffer + offset, this->xs);
      offset += serializeAvrFloat64(outbuffer + offset, this->ys);
      offset += serializeAvrFloat64(outbuffer + offset, this->xc);
      offset += serializeAvrFloat64(outbuffer + offset, this->yc);
      offset += serializeAvrFloat64(outbuffer + offset, this->xe);
      offset += serializeAvrFloat64(outbuffer + offset, this->ye);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->direction));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->xs));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ys));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->xc));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yc));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->xe));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ye));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel));
     return offset;
    }

    const char * getType(){ return "cola2_control/Section"; };
    const char * getMD5(){ return "3774caeb1b9fed9e26a4ca621cd707b3"; };

  };

}
#endif