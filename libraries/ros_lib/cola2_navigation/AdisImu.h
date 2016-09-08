#ifndef _ROS_cola2_navigation_AdisImu_h
#define _ROS_cola2_navigation_AdisImu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_navigation
{

  class AdisImu : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float MX;
      float MY;
      float MZ;
      float GX;
      float GY;
      float GZ;
      float AX;
      float AY;
      float AZ;
      float T;
      float B;
      const char* F;
      float E;
      float W;

    AdisImu():
      header(),
      MX(0),
      MY(0),
      MZ(0),
      GX(0),
      GY(0),
      GZ(0),
      AX(0),
      AY(0),
      AZ(0),
      T(0),
      B(0),
      F(""),
      E(0),
      W(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->MX);
      offset += serializeAvrFloat64(outbuffer + offset, this->MY);
      offset += serializeAvrFloat64(outbuffer + offset, this->MZ);
      offset += serializeAvrFloat64(outbuffer + offset, this->GX);
      offset += serializeAvrFloat64(outbuffer + offset, this->GY);
      offset += serializeAvrFloat64(outbuffer + offset, this->GZ);
      offset += serializeAvrFloat64(outbuffer + offset, this->AX);
      offset += serializeAvrFloat64(outbuffer + offset, this->AY);
      offset += serializeAvrFloat64(outbuffer + offset, this->AZ);
      offset += serializeAvrFloat64(outbuffer + offset, this->T);
      offset += serializeAvrFloat64(outbuffer + offset, this->B);
      uint32_t length_F = strlen(this->F);
      memcpy(outbuffer + offset, &length_F, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->F, length_F);
      offset += length_F;
      offset += serializeAvrFloat64(outbuffer + offset, this->E);
      offset += serializeAvrFloat64(outbuffer + offset, this->W);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->MX));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->MY));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->MZ));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->GX));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->GY));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->GZ));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->AX));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->AY));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->AZ));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->T));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->B));
      uint32_t length_F;
      memcpy(&length_F, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_F; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_F-1]=0;
      this->F = (char *)(inbuffer + offset-1);
      offset += length_F;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->E));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->W));
     return offset;
    }

    const char * getType(){ return "cola2_navigation/AdisImu"; };
    const char * getMD5(){ return "01c02841f046e37069d593142ffe18eb"; };

  };

}
#endif