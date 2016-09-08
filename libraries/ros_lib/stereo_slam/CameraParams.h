#ifndef _ROS_stereo_slam_CameraParams_h
#define _ROS_stereo_slam_CameraParams_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace stereo_slam
{

  class CameraParams : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float cx;
      float cy;
      float fx;

    CameraParams():
      header(),
      cx(0),
      cy(0),
      fx(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->cx);
      offset += serializeAvrFloat64(outbuffer + offset, this->cy);
      offset += serializeAvrFloat64(outbuffer + offset, this->fx);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->fx));
     return offset;
    }

    const char * getType(){ return "stereo_slam/CameraParams"; };
    const char * getMD5(){ return "a35e7954d536b20b51c8108ac5cec179"; };

  };

}
#endif