#ifndef _ROS_iri_common_drivers_msgs_RadarCluster209_h
#define _ROS_iri_common_drivers_msgs_RadarCluster209_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

  class RadarCluster209 : public ros::Msg
  {
    public:
      float azimut;
      uint8_t index;
      uint8_t rollcount;
      float range;
      float rcs;
      float vrel;

    RadarCluster209():
      azimut(0),
      index(0),
      rollcount(0),
      range(0),
      rcs(0),
      vrel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_azimut;
      u_azimut.real = this->azimut;
      *(outbuffer + offset + 0) = (u_azimut.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_azimut.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_azimut.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_azimut.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->azimut);
      *(outbuffer + offset + 0) = (this->index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->index);
      *(outbuffer + offset + 0) = (this->rollcount >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rollcount);
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.real = this->range;
      *(outbuffer + offset + 0) = (u_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range);
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
      } u_vrel;
      u_vrel.real = this->vrel;
      *(outbuffer + offset + 0) = (u_vrel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vrel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vrel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vrel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vrel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_azimut;
      u_azimut.base = 0;
      u_azimut.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_azimut.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_azimut.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_azimut.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->azimut = u_azimut.real;
      offset += sizeof(this->azimut);
      this->index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->index);
      this->rollcount =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rollcount);
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.base = 0;
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range = u_range.real;
      offset += sizeof(this->range);
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
      } u_vrel;
      u_vrel.base = 0;
      u_vrel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vrel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vrel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vrel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vrel = u_vrel.real;
      offset += sizeof(this->vrel);
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/RadarCluster209"; };
    const char * getMD5(){ return "43cd75b3b50d81b9690fcd1db587a1a0"; };

  };

}
#endif