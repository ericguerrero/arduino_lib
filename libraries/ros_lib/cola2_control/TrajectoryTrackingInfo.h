#ifndef _ROS_cola2_control_TrajectoryTrackingInfo_h
#define _ROS_cola2_control_TrajectoryTrackingInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_control
{

  class TrajectoryTrackingInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float elapsed_time;
      int32_t current_section;
      float xs;
      float ys;
      float xc;
      float yc;
      float xe;
      float ye;
      float vel;
      float distance_to_the_end;
      float e;
      float beta;
      float gamma;
      float desired_gamma;
      float last_gamma;
      float current_gamma;
      float pose_north;
      float pose_east;
      float desired_surge;
      float desired_yaw;

    TrajectoryTrackingInfo():
      header(),
      elapsed_time(0),
      current_section(0),
      xs(0),
      ys(0),
      xc(0),
      yc(0),
      xe(0),
      ye(0),
      vel(0),
      distance_to_the_end(0),
      e(0),
      beta(0),
      gamma(0),
      desired_gamma(0),
      last_gamma(0),
      current_gamma(0),
      pose_north(0),
      pose_east(0),
      desired_surge(0),
      desired_yaw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->elapsed_time);
      union {
        int32_t real;
        uint32_t base;
      } u_current_section;
      u_current_section.real = this->current_section;
      *(outbuffer + offset + 0) = (u_current_section.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_section.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_section.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_section.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_section);
      offset += serializeAvrFloat64(outbuffer + offset, this->xs);
      offset += serializeAvrFloat64(outbuffer + offset, this->ys);
      offset += serializeAvrFloat64(outbuffer + offset, this->xc);
      offset += serializeAvrFloat64(outbuffer + offset, this->yc);
      offset += serializeAvrFloat64(outbuffer + offset, this->xe);
      offset += serializeAvrFloat64(outbuffer + offset, this->ye);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance_to_the_end);
      offset += serializeAvrFloat64(outbuffer + offset, this->e);
      offset += serializeAvrFloat64(outbuffer + offset, this->beta);
      offset += serializeAvrFloat64(outbuffer + offset, this->gamma);
      offset += serializeAvrFloat64(outbuffer + offset, this->desired_gamma);
      offset += serializeAvrFloat64(outbuffer + offset, this->last_gamma);
      offset += serializeAvrFloat64(outbuffer + offset, this->current_gamma);
      offset += serializeAvrFloat64(outbuffer + offset, this->pose_north);
      offset += serializeAvrFloat64(outbuffer + offset, this->pose_east);
      offset += serializeAvrFloat64(outbuffer + offset, this->desired_surge);
      offset += serializeAvrFloat64(outbuffer + offset, this->desired_yaw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->elapsed_time));
      union {
        int32_t real;
        uint32_t base;
      } u_current_section;
      u_current_section.base = 0;
      u_current_section.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_section.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_section.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_section.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_section = u_current_section.real;
      offset += sizeof(this->current_section);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->xs));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ys));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->xc));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yc));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->xe));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ye));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance_to_the_end));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->e));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->beta));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gamma));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->desired_gamma));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->last_gamma));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->current_gamma));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pose_north));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pose_east));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->desired_surge));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->desired_yaw));
     return offset;
    }

    const char * getType(){ return "cola2_control/TrajectoryTrackingInfo"; };
    const char * getMD5(){ return "eb978825b413ca057e387703c9e48a01"; };

  };

}
#endif