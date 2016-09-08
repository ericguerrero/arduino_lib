#ifndef _ROS_auv_msgs_ImageFeature_h
#define _ROS_auv_msgs_ImageFeature_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace auv_msgs
{

  class ImageFeature : public ros::Msg
  {
    public:
      geometry_msgs::Point position;
      uint8_t descriptor_length;
      float st_descriptor;
      float * descriptor;

    ImageFeature():
      position(),
      descriptor_length(0), descriptor(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      *(outbuffer + offset++) = descriptor_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < descriptor_length; i++){
      union {
        float real;
        uint32_t base;
      } u_descriptori;
      u_descriptori.real = this->descriptor[i];
      *(outbuffer + offset + 0) = (u_descriptori.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_descriptori.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_descriptori.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_descriptori.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->descriptor[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      uint8_t descriptor_lengthT = *(inbuffer + offset++);
      if(descriptor_lengthT > descriptor_length)
        this->descriptor = (float*)realloc(this->descriptor, descriptor_lengthT * sizeof(float));
      offset += 3;
      descriptor_length = descriptor_lengthT;
      for( uint8_t i = 0; i < descriptor_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_descriptor;
      u_st_descriptor.base = 0;
      u_st_descriptor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_descriptor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_descriptor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_descriptor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_descriptor = u_st_descriptor.real;
      offset += sizeof(this->st_descriptor);
        memcpy( &(this->descriptor[i]), &(this->st_descriptor), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "auv_msgs/ImageFeature"; };
    const char * getMD5(){ return "60381b047909bcb02393bcf9f30b71e5"; };

  };

}
#endif