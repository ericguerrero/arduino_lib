#ifndef _ROS_iri_common_drivers_msgs_RadarCluster209Array_h
#define _ROS_iri_common_drivers_msgs_RadarCluster209Array_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "iri_common_drivers_msgs/RadarCluster209.h"

namespace iri_common_drivers_msgs
{

  class RadarCluster209Array : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t sensorId;
      uint8_t clusters_length;
      iri_common_drivers_msgs::RadarCluster209 st_clusters;
      iri_common_drivers_msgs::RadarCluster209 * clusters;

    RadarCluster209Array():
      header(),
      sensorId(0),
      clusters_length(0), clusters(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sensorId >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensorId >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sensorId);
      *(outbuffer + offset++) = clusters_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < clusters_length; i++){
      offset += this->clusters[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->sensorId =  ((uint16_t) (*(inbuffer + offset)));
      this->sensorId |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sensorId);
      uint8_t clusters_lengthT = *(inbuffer + offset++);
      if(clusters_lengthT > clusters_length)
        this->clusters = (iri_common_drivers_msgs::RadarCluster209*)realloc(this->clusters, clusters_lengthT * sizeof(iri_common_drivers_msgs::RadarCluster209));
      offset += 3;
      clusters_length = clusters_lengthT;
      for( uint8_t i = 0; i < clusters_length; i++){
      offset += this->st_clusters.deserialize(inbuffer + offset);
        memcpy( &(this->clusters[i]), &(this->st_clusters), sizeof(iri_common_drivers_msgs::RadarCluster209));
      }
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/RadarCluster209Array"; };
    const char * getMD5(){ return "c1263ac85008b9085d9f6d834c6ef497"; };

  };

}
#endif