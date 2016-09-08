#ifndef _ROS_auv_msgs_DecimalLatLon_h
#define _ROS_auv_msgs_DecimalLatLon_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auv_msgs
{

  class DecimalLatLon : public ros::Msg
  {
    public:
      float latitude;
      float longitude;

    DecimalLatLon():
      latitude(0),
      longitude(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->longitude);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longitude));
     return offset;
    }

    const char * getType(){ return "auv_msgs/DecimalLatLon"; };
    const char * getMD5(){ return "680c6dc7da65a2421a822205dcbdb600"; };

  };

}
#endif