#ifndef _ROS_stereo_slam_GraphPoses_h
#define _ROS_stereo_slam_GraphPoses_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace stereo_slam
{

  class GraphPoses : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t id_length;
      int32_t st_id;
      int32_t * id;
      uint8_t x_length;
      float st_x;
      float * x;
      uint8_t y_length;
      float st_y;
      float * y;
      uint8_t z_length;
      float st_z;
      float * z;
      uint8_t qx_length;
      float st_qx;
      float * qx;
      uint8_t qy_length;
      float st_qy;
      float * qy;
      uint8_t qz_length;
      float st_qz;
      float * qz;
      uint8_t qw_length;
      float st_qw;
      float * qw;

    GraphPoses():
      header(),
      id_length(0), id(NULL),
      x_length(0), x(NULL),
      y_length(0), y(NULL),
      z_length(0), z(NULL),
      qx_length(0), qx(NULL),
      qy_length(0), qy(NULL),
      qz_length(0), qz(NULL),
      qw_length(0), qw(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = id_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < id_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_idi;
      u_idi.real = this->id[i];
      *(outbuffer + offset + 0) = (u_idi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_idi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_idi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id[i]);
      }
      *(outbuffer + offset++) = x_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < x_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->x[i]);
      }
      *(outbuffer + offset++) = y_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < y_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->y[i]);
      }
      *(outbuffer + offset++) = z_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < z_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->z[i]);
      }
      *(outbuffer + offset++) = qx_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < qx_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qx[i]);
      }
      *(outbuffer + offset++) = qy_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < qy_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qy[i]);
      }
      *(outbuffer + offset++) = qz_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < qz_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qz[i]);
      }
      *(outbuffer + offset++) = qw_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < qw_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qw[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t id_lengthT = *(inbuffer + offset++);
      if(id_lengthT > id_length)
        this->id = (int32_t*)realloc(this->id, id_lengthT * sizeof(int32_t));
      offset += 3;
      id_length = id_lengthT;
      for( uint8_t i = 0; i < id_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_id;
      u_st_id.base = 0;
      u_st_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_id = u_st_id.real;
      offset += sizeof(this->st_id);
        memcpy( &(this->id[i]), &(this->st_id), sizeof(int32_t));
      }
      uint8_t x_lengthT = *(inbuffer + offset++);
      if(x_lengthT > x_length)
        this->x = (float*)realloc(this->x, x_lengthT * sizeof(float));
      offset += 3;
      x_length = x_lengthT;
      for( uint8_t i = 0; i < x_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_x));
        memcpy( &(this->x[i]), &(this->st_x), sizeof(float));
      }
      uint8_t y_lengthT = *(inbuffer + offset++);
      if(y_lengthT > y_length)
        this->y = (float*)realloc(this->y, y_lengthT * sizeof(float));
      offset += 3;
      y_length = y_lengthT;
      for( uint8_t i = 0; i < y_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_y));
        memcpy( &(this->y[i]), &(this->st_y), sizeof(float));
      }
      uint8_t z_lengthT = *(inbuffer + offset++);
      if(z_lengthT > z_length)
        this->z = (float*)realloc(this->z, z_lengthT * sizeof(float));
      offset += 3;
      z_length = z_lengthT;
      for( uint8_t i = 0; i < z_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_z));
        memcpy( &(this->z[i]), &(this->st_z), sizeof(float));
      }
      uint8_t qx_lengthT = *(inbuffer + offset++);
      if(qx_lengthT > qx_length)
        this->qx = (float*)realloc(this->qx, qx_lengthT * sizeof(float));
      offset += 3;
      qx_length = qx_lengthT;
      for( uint8_t i = 0; i < qx_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_qx));
        memcpy( &(this->qx[i]), &(this->st_qx), sizeof(float));
      }
      uint8_t qy_lengthT = *(inbuffer + offset++);
      if(qy_lengthT > qy_length)
        this->qy = (float*)realloc(this->qy, qy_lengthT * sizeof(float));
      offset += 3;
      qy_length = qy_lengthT;
      for( uint8_t i = 0; i < qy_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_qy));
        memcpy( &(this->qy[i]), &(this->st_qy), sizeof(float));
      }
      uint8_t qz_lengthT = *(inbuffer + offset++);
      if(qz_lengthT > qz_length)
        this->qz = (float*)realloc(this->qz, qz_lengthT * sizeof(float));
      offset += 3;
      qz_length = qz_lengthT;
      for( uint8_t i = 0; i < qz_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_qz));
        memcpy( &(this->qz[i]), &(this->st_qz), sizeof(float));
      }
      uint8_t qw_lengthT = *(inbuffer + offset++);
      if(qw_lengthT > qw_length)
        this->qw = (float*)realloc(this->qw, qw_lengthT * sizeof(float));
      offset += 3;
      qw_length = qw_lengthT;
      for( uint8_t i = 0; i < qw_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_qw));
        memcpy( &(this->qw[i]), &(this->st_qw), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "stereo_slam/GraphPoses"; };
    const char * getMD5(){ return "aef753297f6c6106581a1f6e87afa65f"; };

  };

}
#endif