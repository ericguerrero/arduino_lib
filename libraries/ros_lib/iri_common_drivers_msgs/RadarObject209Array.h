#ifndef _ROS_iri_common_drivers_msgs_RadarObject209Array_h
#define _ROS_iri_common_drivers_msgs_RadarObject209Array_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "iri_common_drivers_msgs/RadarObject209.h"

namespace iri_common_drivers_msgs
{

  class RadarObject209Array : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t sensorId;
      uint8_t tracks_length;
      iri_common_drivers_msgs::RadarObject209 st_tracks;
      iri_common_drivers_msgs::RadarObject209 * tracks;

    RadarObject209Array():
      header(),
      sensorId(0),
      tracks_length(0), tracks(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sensorId >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensorId >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sensorId);
      *(outbuffer + offset++) = tracks_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tracks_length; i++){
      offset += this->tracks[i].serialize(outbuffer + offset);
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
      uint8_t tracks_lengthT = *(inbuffer + offset++);
      if(tracks_lengthT > tracks_length)
        this->tracks = (iri_common_drivers_msgs::RadarObject209*)realloc(this->tracks, tracks_lengthT * sizeof(iri_common_drivers_msgs::RadarObject209));
      offset += 3;
      tracks_length = tracks_lengthT;
      for( uint8_t i = 0; i < tracks_length; i++){
      offset += this->st_tracks.deserialize(inbuffer + offset);
        memcpy( &(this->tracks[i]), &(this->st_tracks), sizeof(iri_common_drivers_msgs::RadarObject209));
      }
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/RadarObject209Array"; };
    const char * getMD5(){ return "3939b7540ecbf8807cdc00c9960a451b"; };

  };

}
#endif