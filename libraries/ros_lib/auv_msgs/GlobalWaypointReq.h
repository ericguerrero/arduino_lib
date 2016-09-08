#ifndef _ROS_auv_msgs_GlobalWaypointReq_h
#define _ROS_auv_msgs_GlobalWaypointReq_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "auv_msgs/GoalDescriptor.h"
#include "auv_msgs/DecimalLatLon.h"
#include "auv_msgs/RPY.h"
#include "auv_msgs/Bool6Axis.h"
#include "geometry_msgs/Vector3.h"

namespace auv_msgs
{

  class GlobalWaypointReq : public ros::Msg
  {
    public:
      std_msgs::Header header;
      auv_msgs::GoalDescriptor goal;
      bool altitude_mode;
      auv_msgs::DecimalLatLon position;
      float depth;
      float altitude;
      auv_msgs::RPY orientation;
      auv_msgs::Bool6Axis disable_axis;
      geometry_msgs::Vector3 position_tolerance;
      auv_msgs::RPY orientation_tolerance;

    GlobalWaypointReq():
      header(),
      goal(),
      altitude_mode(0),
      position(),
      depth(0),
      altitude(0),
      orientation(),
      disable_axis(),
      position_tolerance(),
      orientation_tolerance()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_altitude_mode;
      u_altitude_mode.real = this->altitude_mode;
      *(outbuffer + offset + 0) = (u_altitude_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->altitude_mode);
      offset += this->position.serialize(outbuffer + offset);
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
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->disable_axis.serialize(outbuffer + offset);
      offset += this->position_tolerance.serialize(outbuffer + offset);
      offset += this->orientation_tolerance.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_altitude_mode;
      u_altitude_mode.base = 0;
      u_altitude_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->altitude_mode = u_altitude_mode.real;
      offset += sizeof(this->altitude_mode);
      offset += this->position.deserialize(inbuffer + offset);
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
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->disable_axis.deserialize(inbuffer + offset);
      offset += this->position_tolerance.deserialize(inbuffer + offset);
      offset += this->orientation_tolerance.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "auv_msgs/GlobalWaypointReq"; };
    const char * getMD5(){ return "f90e850f757b53f3641907daf353af05"; };

  };

}
#endif