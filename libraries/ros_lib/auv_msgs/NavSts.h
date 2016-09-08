#ifndef _ROS_auv_msgs_NavSts_h
#define _ROS_auv_msgs_NavSts_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "auv_msgs/DecimalLatLon.h"
#include "auv_msgs/NED.h"
#include "geometry_msgs/Point.h"
#include "auv_msgs/RPY.h"

namespace auv_msgs
{

  class NavSts : public ros::Msg
  {
    public:
      std_msgs::Header header;
      auv_msgs::DecimalLatLon global_position;
      auv_msgs::DecimalLatLon origin;
      auv_msgs::NED position;
      float altitude;
      geometry_msgs::Point body_velocity;
      auv_msgs::RPY orientation;
      auv_msgs::RPY orientation_rate;
      auv_msgs::NED position_variance;
      auv_msgs::RPY orientation_variance;
      uint8_t status;
      enum { STATUS_FAULT =  0 };
      enum { STATUS_LOCAL_FRAME_OK =  1 };
      enum { STATUS_GLOBAL_FRAME_OK =  2 };
      enum { STATUS_POSITION_OK =  3 };
      enum { STATUS_VELOCITY_OK =  4 };
      enum { STATUS_ESTIMATION_ERROR_OK =  8 };
      enum { STATUS_ALL_OK =  15 };

    NavSts():
      header(),
      global_position(),
      origin(),
      position(),
      altitude(0),
      body_velocity(),
      orientation(),
      orientation_rate(),
      position_variance(),
      orientation_variance(),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->global_position.serialize(outbuffer + offset);
      offset += this->origin.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
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
      offset += this->body_velocity.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->orientation_rate.serialize(outbuffer + offset);
      offset += this->position_variance.serialize(outbuffer + offset);
      offset += this->orientation_variance.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->global_position.deserialize(inbuffer + offset);
      offset += this->origin.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
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
      offset += this->body_velocity.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->orientation_rate.deserialize(inbuffer + offset);
      offset += this->position_variance.deserialize(inbuffer + offset);
      offset += this->orientation_variance.deserialize(inbuffer + offset);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
     return offset;
    }

    const char * getType(){ return "auv_msgs/NavSts"; };
    const char * getMD5(){ return "4ce9d43f0d458ab76be6de8266700753"; };

  };

}
#endif