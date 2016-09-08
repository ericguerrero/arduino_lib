#ifndef _ROS_cola2_ekf_Map_h
#define _ROS_cola2_ekf_Map_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cola2_ekf/Landmark.h"

namespace cola2_ekf
{

  class Map : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t landmark_length;
      cola2_ekf::Landmark st_landmark;
      cola2_ekf::Landmark * landmark;

    Map():
      header(),
      landmark_length(0), landmark(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = landmark_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < landmark_length; i++){
      offset += this->landmark[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t landmark_lengthT = *(inbuffer + offset++);
      if(landmark_lengthT > landmark_length)
        this->landmark = (cola2_ekf::Landmark*)realloc(this->landmark, landmark_lengthT * sizeof(cola2_ekf::Landmark));
      offset += 3;
      landmark_length = landmark_lengthT;
      for( uint8_t i = 0; i < landmark_length; i++){
      offset += this->st_landmark.deserialize(inbuffer + offset);
        memcpy( &(this->landmark[i]), &(this->st_landmark), sizeof(cola2_ekf::Landmark));
      }
     return offset;
    }

    const char * getType(){ return "cola2_ekf/Map"; };
    const char * getMD5(){ return "bfefa1e499a59de8f56216762bc4a2db"; };

  };

}
#endif