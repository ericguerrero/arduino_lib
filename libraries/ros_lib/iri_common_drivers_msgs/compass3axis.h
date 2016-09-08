#ifndef _ROS_iri_common_drivers_msgs_compass3axis_h
#define _ROS_iri_common_drivers_msgs_compass3axis_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace iri_common_drivers_msgs
{

  class compass3axis : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float angles[3];
      float covariances[9];
      bool alarms[3];

    compass3axis():
      header(),
      angles(),
      covariances(),
      alarms()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->angles[i]);
      }
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->covariances[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        bool real;
        uint8_t base;
      } u_alarmsi;
      u_alarmsi.real = this->alarms[i];
      *(outbuffer + offset + 0) = (u_alarmsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->alarms[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angles[i]));
      }
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->covariances[i]));
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        bool real;
        uint8_t base;
      } u_alarmsi;
      u_alarmsi.base = 0;
      u_alarmsi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->alarms[i] = u_alarmsi.real;
      offset += sizeof(this->alarms[i]);
      }
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/compass3axis"; };
    const char * getMD5(){ return "a78a36c0da6797b6cab1e7e993c489c3"; };

  };

}
#endif