#ifndef _ROS_iri_common_drivers_msgs_RadarObject209_h
#define _ROS_iri_common_drivers_msgs_RadarObject209_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace iri_common_drivers_msgs
{

  class RadarObject209 : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t sensorId;
      uint16_t obj_id;
      uint8_t index;
      float longdisp;
      float latdisp;
      float vrellong;
      float vrellat;
      uint8_t rollcount;
      float rcs;
      float lifetime;

    RadarObject209():
      header(),
      sensorId(0),
      obj_id(0),
      index(0),
      longdisp(0),
      latdisp(0),
      vrellong(0),
      vrellat(0),
      rollcount(0),
      rcs(0),
      lifetime(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sensorId >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensorId >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sensorId);
      *(outbuffer + offset + 0) = (this->obj_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obj_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->obj_id);
      *(outbuffer + offset + 0) = (this->index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->index);
      union {
        float real;
        uint32_t base;
      } u_longdisp;
      u_longdisp.real = this->longdisp;
      *(outbuffer + offset + 0) = (u_longdisp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longdisp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longdisp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longdisp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longdisp);
      union {
        float real;
        uint32_t base;
      } u_latdisp;
      u_latdisp.real = this->latdisp;
      *(outbuffer + offset + 0) = (u_latdisp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latdisp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latdisp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latdisp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latdisp);
      union {
        float real;
        uint32_t base;
      } u_vrellong;
      u_vrellong.real = this->vrellong;
      *(outbuffer + offset + 0) = (u_vrellong.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vrellong.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vrellong.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vrellong.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vrellong);
      union {
        float real;
        uint32_t base;
      } u_vrellat;
      u_vrellat.real = this->vrellat;
      *(outbuffer + offset + 0) = (u_vrellat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vrellat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vrellat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vrellat.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vrellat);
      *(outbuffer + offset + 0) = (this->rollcount >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rollcount);
      union {
        float real;
        uint32_t base;
      } u_rcs;
      u_rcs.real = this->rcs;
      *(outbuffer + offset + 0) = (u_rcs.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rcs.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rcs.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rcs.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rcs);
      union {
        float real;
        uint32_t base;
      } u_lifetime;
      u_lifetime.real = this->lifetime;
      *(outbuffer + offset + 0) = (u_lifetime.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lifetime.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lifetime.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lifetime.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lifetime);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->sensorId =  ((uint16_t) (*(inbuffer + offset)));
      this->sensorId |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sensorId);
      this->obj_id =  ((uint16_t) (*(inbuffer + offset)));
      this->obj_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->obj_id);
      this->index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->index);
      union {
        float real;
        uint32_t base;
      } u_longdisp;
      u_longdisp.base = 0;
      u_longdisp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longdisp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longdisp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longdisp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longdisp = u_longdisp.real;
      offset += sizeof(this->longdisp);
      union {
        float real;
        uint32_t base;
      } u_latdisp;
      u_latdisp.base = 0;
      u_latdisp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latdisp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latdisp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latdisp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latdisp = u_latdisp.real;
      offset += sizeof(this->latdisp);
      union {
        float real;
        uint32_t base;
      } u_vrellong;
      u_vrellong.base = 0;
      u_vrellong.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vrellong.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vrellong.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vrellong.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vrellong = u_vrellong.real;
      offset += sizeof(this->vrellong);
      union {
        float real;
        uint32_t base;
      } u_vrellat;
      u_vrellat.base = 0;
      u_vrellat.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vrellat.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vrellat.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vrellat.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vrellat = u_vrellat.real;
      offset += sizeof(this->vrellat);
      this->rollcount =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rollcount);
      union {
        float real;
        uint32_t base;
      } u_rcs;
      u_rcs.base = 0;
      u_rcs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rcs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rcs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rcs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rcs = u_rcs.real;
      offset += sizeof(this->rcs);
      union {
        float real;
        uint32_t base;
      } u_lifetime;
      u_lifetime.base = 0;
      u_lifetime.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lifetime.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lifetime.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lifetime.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lifetime = u_lifetime.real;
      offset += sizeof(this->lifetime);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/RadarObject209"; };
    const char * getMD5(){ return "55b65dbd73b07d8169b3a3aef6dd3b37"; };

  };

}
#endif