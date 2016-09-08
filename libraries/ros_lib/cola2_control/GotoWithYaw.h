#ifndef _ROS_SERVICE_GotoWithYaw_h
#define _ROS_SERVICE_GotoWithYaw_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cola2_control
{

static const char GOTOWITHYAW[] = "cola2_control/GotoWithYaw";

  class GotoWithYawRequest : public ros::Msg
  {
    public:
      float north_lat;
      float east_lon;
      float z;
      bool altitude_mode;
      float tolerance;
      float yaw;

    GotoWithYawRequest():
      north_lat(0),
      east_lon(0),
      z(0),
      altitude_mode(0),
      tolerance(0),
      yaw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->north_lat);
      offset += serializeAvrFloat64(outbuffer + offset, this->east_lon);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      union {
        bool real;
        uint8_t base;
      } u_altitude_mode;
      u_altitude_mode.real = this->altitude_mode;
      *(outbuffer + offset + 0) = (u_altitude_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->altitude_mode);
      union {
        float real;
        uint32_t base;
      } u_tolerance;
      u_tolerance.real = this->tolerance;
      *(outbuffer + offset + 0) = (u_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tolerance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tolerance);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->north_lat));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->east_lon));
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        bool real;
        uint8_t base;
      } u_altitude_mode;
      u_altitude_mode.base = 0;
      u_altitude_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->altitude_mode = u_altitude_mode.real;
      offset += sizeof(this->altitude_mode);
      union {
        float real;
        uint32_t base;
      } u_tolerance;
      u_tolerance.base = 0;
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tolerance = u_tolerance.real;
      offset += sizeof(this->tolerance);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
     return offset;
    }

    const char * getType(){ return GOTOWITHYAW; };
    const char * getMD5(){ return "3b2de9a098ea50878c6d86201d7d87d8"; };

  };

  class GotoWithYawResponse : public ros::Msg
  {
    public:
      bool attempted;

    GotoWithYawResponse():
      attempted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_attempted;
      u_attempted.real = this->attempted;
      *(outbuffer + offset + 0) = (u_attempted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->attempted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_attempted;
      u_attempted.base = 0;
      u_attempted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->attempted = u_attempted.real;
      offset += sizeof(this->attempted);
     return offset;
    }

    const char * getType(){ return GOTOWITHYAW; };
    const char * getMD5(){ return "70f46e6393e2715db0559943d3e7b477"; };

  };

  class GotoWithYaw {
    public:
    typedef GotoWithYawRequest Request;
    typedef GotoWithYawResponse Response;
  };

}
#endif
