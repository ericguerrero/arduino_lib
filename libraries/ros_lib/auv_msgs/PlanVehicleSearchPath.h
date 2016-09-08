#ifndef _ROS_SERVICE_PlanVehicleSearchPath_h
#define _ROS_SERVICE_PlanVehicleSearchPath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auv_msgs/VehiclePose.h"

namespace auv_msgs
{

static const char PLANVEHICLESEARCHPATH[] = "auv_msgs/PlanVehicleSearchPath";

  class PlanVehicleSearchPathRequest : public ros::Msg
  {
    public:
      bool depth_mode;
      float altitude;
      float depth;
      float start_north;
      float start_east;
      float end_north;
      float end_east;
      float max_bottom_gradient;

    PlanVehicleSearchPathRequest():
      depth_mode(0),
      altitude(0),
      depth(0),
      start_north(0),
      start_east(0),
      end_north(0),
      end_east(0),
      max_bottom_gradient(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_depth_mode;
      u_depth_mode.real = this->depth_mode;
      *(outbuffer + offset + 0) = (u_depth_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->depth_mode);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_depth;
      u_depth.real = this->depth;
      *(outbuffer + offset + 0) = (u_depth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_depth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_depth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_depth.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->depth);
      union {
        float real;
        uint32_t base;
      } u_start_north;
      u_start_north.real = this->start_north;
      *(outbuffer + offset + 0) = (u_start_north.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_start_north.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_start_north.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_start_north.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_north);
      union {
        float real;
        uint32_t base;
      } u_start_east;
      u_start_east.real = this->start_east;
      *(outbuffer + offset + 0) = (u_start_east.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_start_east.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_start_east.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_start_east.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_east);
      union {
        float real;
        uint32_t base;
      } u_end_north;
      u_end_north.real = this->end_north;
      *(outbuffer + offset + 0) = (u_end_north.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_end_north.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_end_north.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_end_north.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_north);
      union {
        float real;
        uint32_t base;
      } u_end_east;
      u_end_east.real = this->end_east;
      *(outbuffer + offset + 0) = (u_end_east.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_end_east.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_end_east.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_end_east.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_east);
      union {
        float real;
        uint32_t base;
      } u_max_bottom_gradient;
      u_max_bottom_gradient.real = this->max_bottom_gradient;
      *(outbuffer + offset + 0) = (u_max_bottom_gradient.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_bottom_gradient.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_bottom_gradient.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_bottom_gradient.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_bottom_gradient);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_depth_mode;
      u_depth_mode.base = 0;
      u_depth_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->depth_mode = u_depth_mode.real;
      offset += sizeof(this->depth_mode);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_depth;
      u_depth.base = 0;
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->depth = u_depth.real;
      offset += sizeof(this->depth);
      union {
        float real;
        uint32_t base;
      } u_start_north;
      u_start_north.base = 0;
      u_start_north.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_start_north.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_start_north.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_start_north.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->start_north = u_start_north.real;
      offset += sizeof(this->start_north);
      union {
        float real;
        uint32_t base;
      } u_start_east;
      u_start_east.base = 0;
      u_start_east.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_start_east.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_start_east.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_start_east.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->start_east = u_start_east.real;
      offset += sizeof(this->start_east);
      union {
        float real;
        uint32_t base;
      } u_end_north;
      u_end_north.base = 0;
      u_end_north.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_end_north.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_end_north.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_end_north.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->end_north = u_end_north.real;
      offset += sizeof(this->end_north);
      union {
        float real;
        uint32_t base;
      } u_end_east;
      u_end_east.base = 0;
      u_end_east.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_end_east.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_end_east.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_end_east.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->end_east = u_end_east.real;
      offset += sizeof(this->end_east);
      union {
        float real;
        uint32_t base;
      } u_max_bottom_gradient;
      u_max_bottom_gradient.base = 0;
      u_max_bottom_gradient.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_bottom_gradient.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_bottom_gradient.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_bottom_gradient.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_bottom_gradient = u_max_bottom_gradient.real;
      offset += sizeof(this->max_bottom_gradient);
     return offset;
    }

    const char * getType(){ return PLANVEHICLESEARCHPATH; };
    const char * getMD5(){ return "a35aefb191d9deb40033668383f7e750"; };

  };

  class PlanVehicleSearchPathResponse : public ros::Msg
  {
    public:
      bool success;
      int32_t error_num;
      uint8_t pose_length;
      auv_msgs::VehiclePose st_pose;
      auv_msgs::VehiclePose * pose;
      uint8_t altitude_mode_length;
      bool st_altitude_mode;
      bool * altitude_mode;
      enum { ERROR_MISSING_BATHYMETRY =  1 };
      enum { ERROR_OTHER =  -1 };

    PlanVehicleSearchPathResponse():
      success(0),
      error_num(0),
      pose_length(0), pose(NULL),
      altitude_mode_length(0), altitude_mode(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
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
      *(outbuffer + offset++) = pose_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pose_length; i++){
      offset += this->pose[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = altitude_mode_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < altitude_mode_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_altitude_modei;
      u_altitude_modei.real = this->altitude_mode[i];
      *(outbuffer + offset + 0) = (u_altitude_modei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->altitude_mode[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
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
      uint8_t pose_lengthT = *(inbuffer + offset++);
      if(pose_lengthT > pose_length)
        this->pose = (auv_msgs::VehiclePose*)realloc(this->pose, pose_lengthT * sizeof(auv_msgs::VehiclePose));
      offset += 3;
      pose_length = pose_lengthT;
      for( uint8_t i = 0; i < pose_length; i++){
      offset += this->st_pose.deserialize(inbuffer + offset);
        memcpy( &(this->pose[i]), &(this->st_pose), sizeof(auv_msgs::VehiclePose));
      }
      uint8_t altitude_mode_lengthT = *(inbuffer + offset++);
      if(altitude_mode_lengthT > altitude_mode_length)
        this->altitude_mode = (bool*)realloc(this->altitude_mode, altitude_mode_lengthT * sizeof(bool));
      offset += 3;
      altitude_mode_length = altitude_mode_lengthT;
      for( uint8_t i = 0; i < altitude_mode_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_altitude_mode;
      u_st_altitude_mode.base = 0;
      u_st_altitude_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_altitude_mode = u_st_altitude_mode.real;
      offset += sizeof(this->st_altitude_mode);
        memcpy( &(this->altitude_mode[i]), &(this->st_altitude_mode), sizeof(bool));
      }
     return offset;
    }

    const char * getType(){ return PLANVEHICLESEARCHPATH; };
    const char * getMD5(){ return "a49f66d103bc0d426a45032f4254908b"; };

  };

  class PlanVehicleSearchPath {
    public:
    typedef PlanVehicleSearchPathRequest Request;
    typedef PlanVehicleSearchPathResponse Response;
  };

}
#endif
