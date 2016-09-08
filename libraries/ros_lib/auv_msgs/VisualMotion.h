#ifndef _ROS_auv_msgs_VisualMotion_h
#define _ROS_auv_msgs_VisualMotion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Duration.h"
#include "geometry_msgs/Pose.h"

namespace auv_msgs
{

  class VisualMotion : public ros::Msg
  {
    public:
      std_msgs::Header header;
      bool estimation_ok;
      int32_t error_num;
      std_msgs::Duration motion_duration;
      geometry_msgs::Pose pose_change;

    VisualMotion():
      header(),
      estimation_ok(0),
      error_num(0),
      motion_duration(),
      pose_change()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_estimation_ok;
      u_estimation_ok.real = this->estimation_ok;
      *(outbuffer + offset + 0) = (u_estimation_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->estimation_ok);
      union {
        int32_t real;
        uint32_t base;
      } u_error_num;
      u_error_num.real = this->error_num;
      *(outbuffer + offset + 0) = (u_error_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_num);
      offset += this->motion_duration.serialize(outbuffer + offset);
      offset += this->pose_change.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_estimation_ok;
      u_estimation_ok.base = 0;
      u_estimation_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->estimation_ok = u_estimation_ok.real;
      offset += sizeof(this->estimation_ok);
      union {
        int32_t real;
        uint32_t base;
      } u_error_num;
      u_error_num.base = 0;
      u_error_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error_num = u_error_num.real;
      offset += sizeof(this->error_num);
      offset += this->motion_duration.deserialize(inbuffer + offset);
      offset += this->pose_change.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "auv_msgs/VisualMotion"; };
    const char * getMD5(){ return "9582ef9fe925f88d2b684a950b355c55"; };

  };

}
#endif