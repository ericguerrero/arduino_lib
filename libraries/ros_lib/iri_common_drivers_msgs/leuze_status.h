#ifndef _ROS_iri_common_drivers_msgs_leuze_status_h
#define _ROS_iri_common_drivers_msgs_leuze_status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace iri_common_drivers_msgs
{

  class leuze_status : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t alarm1;
      uint8_t alarm2;
      uint8_t ossd1;
      uint8_t ossd2;
      uint8_t current_pair;

    leuze_status():
      header(),
      alarm1(0),
      alarm2(0),
      ossd1(0),
      ossd2(0),
      current_pair(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->alarm1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->alarm1);
      *(outbuffer + offset + 0) = (this->alarm2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->alarm2);
      *(outbuffer + offset + 0) = (this->ossd1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ossd1);
      *(outbuffer + offset + 0) = (this->ossd2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ossd2);
      *(outbuffer + offset + 0) = (this->current_pair >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_pair);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->alarm1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->alarm1);
      this->alarm2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->alarm2);
      this->ossd1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ossd1);
      this->ossd2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ossd2);
      this->current_pair =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->current_pair);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/leuze_status"; };
    const char * getMD5(){ return "ecaafc9afd030f4a97142645a5dcf81b"; };

  };

}
#endif