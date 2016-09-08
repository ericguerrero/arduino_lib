#ifndef _ROS_cola2_navigation_ImuAngleEstimatorInfo_h
#define _ROS_cola2_navigation_ImuAngleEstimatorInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_navigation
{

  class ImuAngleEstimatorInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float period;
      float ax;
      float ay;
      float az;
      float mx;
      float my;
      float mz;
      float gx;
      float gy;
      float gz;
      float tilt_roll;
      float tilt_pitch;
      float tilt_yaw;
      float rate_tilt_roll;
      float rate_tilt_pitch;
      float rate_tilt_yaw;
      float tilt_angular_velocity_x;
      float tilt_angular_velocity_y;
      float tilt_angular_velocity_z;
      float bias_roll_from_this_iteration;
      float bias_pitch_from_this_iteration;
      float bias_yaw_from_this_iteration;
      float bias_roll;
      float bias_pitch;
      float bias_yaw;
      int32_t bias_buffer_size;
      float corrected_angular_velocity_x;
      float corrected_angular_velocity_y;
      float corrected_angular_velocity_z;
      int32_t number_of_iterations;
      float iteration_roll;
      float iteration_pitch;
      float iteration_yaw;
      float corrected_rate_roll_from_tilt;
      float corrected_rate_pitch_from_tilt;
      float corrected_rate_yaw_from_tilt;
      float corrected_rate_roll;
      float corrected_rate_pitch;
      float corrected_rate_yaw;
      float merging_filter_coefficient;
      float gyro_roll_innovation;
      float gyro_pitch_innovation;
      float gyro_yaw_innovation;
      float tilt_roll_innovation;
      float tilt_pitch_innovation;
      float tilt_yaw_innovation;
      float roll_innovation;
      float pitch_innovation;
      float yaw_innovation;
      float merged_roll;
      float merged_pitch;
      float merged_yaw;
      float merged_minus_tilt_roll;
      float merged_minus_tilt_pitch;
      float merged_minus_tilt_yaw;
      const char* status;
      float filter_elapsed_time;

    ImuAngleEstimatorInfo():
      header(),
      period(0),
      ax(0),
      ay(0),
      az(0),
      mx(0),
      my(0),
      mz(0),
      gx(0),
      gy(0),
      gz(0),
      tilt_roll(0),
      tilt_pitch(0),
      tilt_yaw(0),
      rate_tilt_roll(0),
      rate_tilt_pitch(0),
      rate_tilt_yaw(0),
      tilt_angular_velocity_x(0),
      tilt_angular_velocity_y(0),
      tilt_angular_velocity_z(0),
      bias_roll_from_this_iteration(0),
      bias_pitch_from_this_iteration(0),
      bias_yaw_from_this_iteration(0),
      bias_roll(0),
      bias_pitch(0),
      bias_yaw(0),
      bias_buffer_size(0),
      corrected_angular_velocity_x(0),
      corrected_angular_velocity_y(0),
      corrected_angular_velocity_z(0),
      number_of_iterations(0),
      iteration_roll(0),
      iteration_pitch(0),
      iteration_yaw(0),
      corrected_rate_roll_from_tilt(0),
      corrected_rate_pitch_from_tilt(0),
      corrected_rate_yaw_from_tilt(0),
      corrected_rate_roll(0),
      corrected_rate_pitch(0),
      corrected_rate_yaw(0),
      merging_filter_coefficient(0),
      gyro_roll_innovation(0),
      gyro_pitch_innovation(0),
      gyro_yaw_innovation(0),
      tilt_roll_innovation(0),
      tilt_pitch_innovation(0),
      tilt_yaw_innovation(0),
      roll_innovation(0),
      pitch_innovation(0),
      yaw_innovation(0),
      merged_roll(0),
      merged_pitch(0),
      merged_yaw(0),
      merged_minus_tilt_roll(0),
      merged_minus_tilt_pitch(0),
      merged_minus_tilt_yaw(0),
      status(""),
      filter_elapsed_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->period);
      offset += serializeAvrFloat64(outbuffer + offset, this->ax);
      offset += serializeAvrFloat64(outbuffer + offset, this->ay);
      offset += serializeAvrFloat64(outbuffer + offset, this->az);
      offset += serializeAvrFloat64(outbuffer + offset, this->mx);
      offset += serializeAvrFloat64(outbuffer + offset, this->my);
      offset += serializeAvrFloat64(outbuffer + offset, this->mz);
      offset += serializeAvrFloat64(outbuffer + offset, this->gx);
      offset += serializeAvrFloat64(outbuffer + offset, this->gy);
      offset += serializeAvrFloat64(outbuffer + offset, this->gz);
      offset += serializeAvrFloat64(outbuffer + offset, this->tilt_roll);
      offset += serializeAvrFloat64(outbuffer + offset, this->tilt_pitch);
      offset += serializeAvrFloat64(outbuffer + offset, this->tilt_yaw);
      offset += serializeAvrFloat64(outbuffer + offset, this->rate_tilt_roll);
      offset += serializeAvrFloat64(outbuffer + offset, this->rate_tilt_pitch);
      offset += serializeAvrFloat64(outbuffer + offset, this->rate_tilt_yaw);
      offset += serializeAvrFloat64(outbuffer + offset, this->tilt_angular_velocity_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->tilt_angular_velocity_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->tilt_angular_velocity_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->bias_roll_from_this_iteration);
      offset += serializeAvrFloat64(outbuffer + offset, this->bias_pitch_from_this_iteration);
      offset += serializeAvrFloat64(outbuffer + offset, this->bias_yaw_from_this_iteration);
      offset += serializeAvrFloat64(outbuffer + offset, this->bias_roll);
      offset += serializeAvrFloat64(outbuffer + offset, this->bias_pitch);
      offset += serializeAvrFloat64(outbuffer + offset, this->bias_yaw);
      union {
        int32_t real;
        uint32_t base;
      } u_bias_buffer_size;
      u_bias_buffer_size.real = this->bias_buffer_size;
      *(outbuffer + offset + 0) = (u_bias_buffer_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bias_buffer_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bias_buffer_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bias_buffer_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bias_buffer_size);
      offset += serializeAvrFloat64(outbuffer + offset, this->corrected_angular_velocity_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->corrected_angular_velocity_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->corrected_angular_velocity_z);
      union {
        int32_t real;
        uint32_t base;
      } u_number_of_iterations;
      u_number_of_iterations.real = this->number_of_iterations;
      *(outbuffer + offset + 0) = (u_number_of_iterations.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_of_iterations.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_of_iterations.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_of_iterations.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_of_iterations);
      offset += serializeAvrFloat64(outbuffer + offset, this->iteration_roll);
      offset += serializeAvrFloat64(outbuffer + offset, this->iteration_pitch);
      offset += serializeAvrFloat64(outbuffer + offset, this->iteration_yaw);
      offset += serializeAvrFloat64(outbuffer + offset, this->corrected_rate_roll_from_tilt);
      offset += serializeAvrFloat64(outbuffer + offset, this->corrected_rate_pitch_from_tilt);
      offset += serializeAvrFloat64(outbuffer + offset, this->corrected_rate_yaw_from_tilt);
      offset += serializeAvrFloat64(outbuffer + offset, this->corrected_rate_roll);
      offset += serializeAvrFloat64(outbuffer + offset, this->corrected_rate_pitch);
      offset += serializeAvrFloat64(outbuffer + offset, this->corrected_rate_yaw);
      offset += serializeAvrFloat64(outbuffer + offset, this->merging_filter_coefficient);
      offset += serializeAvrFloat64(outbuffer + offset, this->gyro_roll_innovation);
      offset += serializeAvrFloat64(outbuffer + offset, this->gyro_pitch_innovation);
      offset += serializeAvrFloat64(outbuffer + offset, this->gyro_yaw_innovation);
      offset += serializeAvrFloat64(outbuffer + offset, this->tilt_roll_innovation);
      offset += serializeAvrFloat64(outbuffer + offset, this->tilt_pitch_innovation);
      offset += serializeAvrFloat64(outbuffer + offset, this->tilt_yaw_innovation);
      offset += serializeAvrFloat64(outbuffer + offset, this->roll_innovation);
      offset += serializeAvrFloat64(outbuffer + offset, this->pitch_innovation);
      offset += serializeAvrFloat64(outbuffer + offset, this->yaw_innovation);
      offset += serializeAvrFloat64(outbuffer + offset, this->merged_roll);
      offset += serializeAvrFloat64(outbuffer + offset, this->merged_pitch);
      offset += serializeAvrFloat64(outbuffer + offset, this->merged_yaw);
      offset += serializeAvrFloat64(outbuffer + offset, this->merged_minus_tilt_roll);
      offset += serializeAvrFloat64(outbuffer + offset, this->merged_minus_tilt_pitch);
      offset += serializeAvrFloat64(outbuffer + offset, this->merged_minus_tilt_yaw);
      uint32_t length_status = strlen(this->status);
      memcpy(outbuffer + offset, &length_status, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
      offset += serializeAvrFloat64(outbuffer + offset, this->filter_elapsed_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->period));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ax));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ay));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->az));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->my));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mz));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gz));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tilt_roll));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tilt_pitch));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tilt_yaw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rate_tilt_roll));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rate_tilt_pitch));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rate_tilt_yaw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tilt_angular_velocity_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tilt_angular_velocity_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tilt_angular_velocity_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bias_roll_from_this_iteration));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bias_pitch_from_this_iteration));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bias_yaw_from_this_iteration));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bias_roll));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bias_pitch));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bias_yaw));
      union {
        int32_t real;
        uint32_t base;
      } u_bias_buffer_size;
      u_bias_buffer_size.base = 0;
      u_bias_buffer_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bias_buffer_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bias_buffer_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bias_buffer_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bias_buffer_size = u_bias_buffer_size.real;
      offset += sizeof(this->bias_buffer_size);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->corrected_angular_velocity_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->corrected_angular_velocity_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->corrected_angular_velocity_z));
      union {
        int32_t real;
        uint32_t base;
      } u_number_of_iterations;
      u_number_of_iterations.base = 0;
      u_number_of_iterations.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_of_iterations.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_of_iterations.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_of_iterations.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number_of_iterations = u_number_of_iterations.real;
      offset += sizeof(this->number_of_iterations);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->iteration_roll));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->iteration_pitch));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->iteration_yaw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->corrected_rate_roll_from_tilt));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->corrected_rate_pitch_from_tilt));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->corrected_rate_yaw_from_tilt));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->corrected_rate_roll));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->corrected_rate_pitch));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->corrected_rate_yaw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->merging_filter_coefficient));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gyro_roll_innovation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gyro_pitch_innovation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gyro_yaw_innovation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tilt_roll_innovation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tilt_pitch_innovation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tilt_yaw_innovation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->roll_innovation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pitch_innovation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yaw_innovation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->merged_roll));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->merged_pitch));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->merged_yaw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->merged_minus_tilt_roll));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->merged_minus_tilt_pitch));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->merged_minus_tilt_yaw));
      uint32_t length_status;
      memcpy(&length_status, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filter_elapsed_time));
     return offset;
    }

    const char * getType(){ return "cola2_navigation/ImuAngleEstimatorInfo"; };
    const char * getMD5(){ return "b4f60752b6b98a29d968638a91dc1365"; };

  };

}
#endif