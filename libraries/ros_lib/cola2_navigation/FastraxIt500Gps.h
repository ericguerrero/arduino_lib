#ifndef _ROS_cola2_navigation_FastraxIt500Gps_h
#define _ROS_cola2_navigation_FastraxIt500Gps_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_navigation
{

  class FastraxIt500Gps : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float latitude;
      int32_t latitude_hemisphere;
      float longitude;
      int32_t longitude_hemisphere;
      const char* time_utc;
      int32_t data_quality;
      float north;
      float east;
      const char* utm_zone;
      float h_dop;
      float v_dop;
      uint8_t raw_data_length;
      char* st_raw_data;
      char* * raw_data;

    FastraxIt500Gps():
      header(),
      latitude(0),
      latitude_hemisphere(0),
      longitude(0),
      longitude_hemisphere(0),
      time_utc(""),
      data_quality(0),
      north(0),
      east(0),
      utm_zone(""),
      h_dop(0),
      v_dop(0),
      raw_data_length(0), raw_data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      union {
        int32_t real;
        uint32_t base;
      } u_latitude_hemisphere;
      u_latitude_hemisphere.real = this->latitude_hemisphere;
      *(outbuffer + offset + 0) = (u_latitude_hemisphere.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude_hemisphere.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude_hemisphere.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude_hemisphere.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude_hemisphere);
      offset += serializeAvrFloat64(outbuffer + offset, this->longitude);
      union {
        int32_t real;
        uint32_t base;
      } u_longitude_hemisphere;
      u_longitude_hemisphere.real = this->longitude_hemisphere;
      *(outbuffer + offset + 0) = (u_longitude_hemisphere.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude_hemisphere.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude_hemisphere.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude_hemisphere.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitude_hemisphere);
      uint32_t length_time_utc = strlen(this->time_utc);
      memcpy(outbuffer + offset, &length_time_utc, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->time_utc, length_time_utc);
      offset += length_time_utc;
      union {
        int32_t real;
        uint32_t base;
      } u_data_quality;
      u_data_quality.real = this->data_quality;
      *(outbuffer + offset + 0) = (u_data_quality.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data_quality.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_data_quality.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_data_quality.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_quality);
      offset += serializeAvrFloat64(outbuffer + offset, this->north);
      offset += serializeAvrFloat64(outbuffer + offset, this->east);
      uint32_t length_utm_zone = strlen(this->utm_zone);
      memcpy(outbuffer + offset, &length_utm_zone, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->utm_zone, length_utm_zone);
      offset += length_utm_zone;
      union {
        float real;
        uint32_t base;
      } u_h_dop;
      u_h_dop.real = this->h_dop;
      *(outbuffer + offset + 0) = (u_h_dop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_h_dop.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_h_dop.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_h_dop.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->h_dop);
      union {
        float real;
        uint32_t base;
      } u_v_dop;
      u_v_dop.real = this->v_dop;
      *(outbuffer + offset + 0) = (u_v_dop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v_dop.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v_dop.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v_dop.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v_dop);
      *(outbuffer + offset++) = raw_data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < raw_data_length; i++){
      uint32_t length_raw_datai = strlen(this->raw_data[i]);
      memcpy(outbuffer + offset, &length_raw_datai, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->raw_data[i], length_raw_datai);
      offset += length_raw_datai;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      union {
        int32_t real;
        uint32_t base;
      } u_latitude_hemisphere;
      u_latitude_hemisphere.base = 0;
      u_latitude_hemisphere.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude_hemisphere.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude_hemisphere.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude_hemisphere.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude_hemisphere = u_latitude_hemisphere.real;
      offset += sizeof(this->latitude_hemisphere);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longitude));
      union {
        int32_t real;
        uint32_t base;
      } u_longitude_hemisphere;
      u_longitude_hemisphere.base = 0;
      u_longitude_hemisphere.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude_hemisphere.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude_hemisphere.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude_hemisphere.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitude_hemisphere = u_longitude_hemisphere.real;
      offset += sizeof(this->longitude_hemisphere);
      uint32_t length_time_utc;
      memcpy(&length_time_utc, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_time_utc; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_time_utc-1]=0;
      this->time_utc = (char *)(inbuffer + offset-1);
      offset += length_time_utc;
      union {
        int32_t real;
        uint32_t base;
      } u_data_quality;
      u_data_quality.base = 0;
      u_data_quality.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data_quality.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_data_quality.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_data_quality.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->data_quality = u_data_quality.real;
      offset += sizeof(this->data_quality);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->north));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->east));
      uint32_t length_utm_zone;
      memcpy(&length_utm_zone, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_utm_zone; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_utm_zone-1]=0;
      this->utm_zone = (char *)(inbuffer + offset-1);
      offset += length_utm_zone;
      union {
        float real;
        uint32_t base;
      } u_h_dop;
      u_h_dop.base = 0;
      u_h_dop.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_h_dop.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_h_dop.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_h_dop.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->h_dop = u_h_dop.real;
      offset += sizeof(this->h_dop);
      union {
        float real;
        uint32_t base;
      } u_v_dop;
      u_v_dop.base = 0;
      u_v_dop.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v_dop.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v_dop.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v_dop.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v_dop = u_v_dop.real;
      offset += sizeof(this->v_dop);
      uint8_t raw_data_lengthT = *(inbuffer + offset++);
      if(raw_data_lengthT > raw_data_length)
        this->raw_data = (char**)realloc(this->raw_data, raw_data_lengthT * sizeof(char*));
      offset += 3;
      raw_data_length = raw_data_lengthT;
      for( uint8_t i = 0; i < raw_data_length; i++){
      uint32_t length_st_raw_data;
      memcpy(&length_st_raw_data, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_raw_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_raw_data-1]=0;
      this->st_raw_data = (char *)(inbuffer + offset-1);
      offset += length_st_raw_data;
        memcpy( &(this->raw_data[i]), &(this->st_raw_data), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "cola2_navigation/FastraxIt500Gps"; };
    const char * getMD5(){ return "a16378822a01b8c80128205456ac55a8"; };

  };

}
#endif