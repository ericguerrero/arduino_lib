#ifndef _ROS_cola2_ekf_Landmark_h
#define _ROS_cola2_ekf_Landmark_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "geometry_msgs/PoseWithCovariance.h"

namespace cola2_ekf
{

  class Landmark : public ros::Msg
  {
    public:
      ros::Time last_update;
      const char* landmark_id;
      geometry_msgs::PoseWithCovariance pose;

    Landmark():
      last_update(),
      landmark_id(""),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->last_update.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_update.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_update.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_update.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_update.sec);
      *(outbuffer + offset + 0) = (this->last_update.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_update.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_update.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_update.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_update.nsec);
      uint32_t length_landmark_id = strlen(this->landmark_id);
      memcpy(outbuffer + offset, &length_landmark_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->landmark_id, length_landmark_id);
      offset += length_landmark_id;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->last_update.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_update.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_update.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_update.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_update.sec);
      this->last_update.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_update.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_update.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_update.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_update.nsec);
      uint32_t length_landmark_id;
      memcpy(&length_landmark_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_landmark_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_landmark_id-1]=0;
      this->landmark_id = (char *)(inbuffer + offset-1);
      offset += length_landmark_id;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cola2_ekf/Landmark"; };
    const char * getMD5(){ return "78ba0337073af3b5721ddc03b7d33657"; };

  };

}
#endif