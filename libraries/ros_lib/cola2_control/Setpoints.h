#ifndef _ROS_cola2_control_Setpoints_h
#define _ROS_cola2_control_Setpoints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_control
{

  class Setpoints : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t setpoints_length;
      float st_setpoints;
      float * setpoints;

    Setpoints():
      header(),
      setpoints_length(0), setpoints(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = setpoints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < setpoints_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoints[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t setpoints_lengthT = *(inbuffer + offset++);
      if(setpoints_lengthT > setpoints_length)
        this->setpoints = (float*)realloc(this->setpoints, setpoints_lengthT * sizeof(float));
      offset += 3;
      setpoints_length = setpoints_lengthT;
      for( uint8_t i = 0; i < setpoints_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_setpoints));
        memcpy( &(this->setpoints[i]), &(this->st_setpoints), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "cola2_control/Setpoints"; };
    const char * getMD5(){ return "d13a8e7b230df87e00dd540874a14b59"; };

  };

}
#endif