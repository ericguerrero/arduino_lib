#ifndef _ROS_auv_msgs_GPS_h
#define _ROS_auv_msgs_GPS_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "auv_msgs/DecimalLatLon.h"
#include "ros/time.h"

namespace auv_msgs
{

  class GPS : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t fix_quality;
      auv_msgs::DecimalLatLon global_position;
      float altitude;
      float hdop;
      ros::Time gps_time;
      float latitude;
      float longitude;
      enum { FIX_NONE =  0 };
      enum { FIX_GPS =  1 };
      enum { FIX_DGPS =  2 };
      enum { FIX_PPS =  3 };

    GPS():
      header(),
      fix_quality(0),
      global_position(),
      altitude(0),
      hdop(0),
      gps_time(),
      latitude(0),
      longitude(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_fix_quality;
      u_fix_quality.real = this->fix_quality;
      *(outbuffer + offset + 0) = (u_fix_quality.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fix_quality.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fix_quality.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fix_quality.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fix_quality);
      offset += this->global_position.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_hdop;
      u_hdop.real = this->hdop;
      *(outbuffer + offset + 0) = (u_hdop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hdop.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hdop.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hdop.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hdop);
      *(outbuffer + offset + 0) = (this->gps_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gps_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gps_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gps_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gps_time.sec);
      *(outbuffer + offset + 0) = (this->gps_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gps_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gps_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gps_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gps_time.nsec);
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->longitude);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_fix_quality;
      u_fix_quality.base = 0;
      u_fix_quality.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fix_quality.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fix_quality.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fix_quality.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fix_quality = u_fix_quality.real;
      offset += sizeof(this->fix_quality);
      offset += this->global_position.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_hdop;
      u_hdop.base = 0;
      u_hdop.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hdop.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hdop.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hdop.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hdop = u_hdop.real;
      offset += sizeof(this->hdop);
      this->gps_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->gps_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gps_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->gps_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->gps_time.sec);
      this->gps_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->gps_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gps_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->gps_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->gps_time.nsec);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longitude));
     return offset;
    }

    const char * getType(){ return "auv_msgs/GPS"; };
    const char * getMD5(){ return "4b5e1435d3fded59a3229e4d45d4c463"; };

  };

}
#endif