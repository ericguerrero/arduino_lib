#ifndef _ROS_cola2_control_ThrustersInfo_h
#define _ROS_cola2_control_ThrustersInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_control
{

  class ThrustersInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t thruster_voltages_length;
      float st_thruster_voltages;
      float * thruster_voltages;
      uint8_t thruster_currents_length;
      float st_thruster_currents;
      float * thruster_currents;
      uint8_t thruster_rpms_length;
      float st_thruster_rpms;
      float * thruster_rpms;
      uint8_t thruster_controller_temperatures_length;
      float st_thruster_controller_temperatures;
      float * thruster_controller_temperatures;
      uint8_t thruster_output_powers_length;
      float st_thruster_output_powers;
      float * thruster_output_powers;
      uint8_t thruster_warnings_length;
      char* st_thruster_warnings;
      char* * thruster_warnings;
      uint8_t thruster_errors_length;
      char* st_thruster_errors;
      char* * thruster_errors;
      float total_ms_in_driver;
      uint8_t setpoints_length;
      float st_setpoints;
      float * setpoints;
      uint8_t processed_setpoints_length;
      float st_processed_setpoints;
      float * processed_setpoints;

    ThrustersInfo():
      header(),
      thruster_voltages_length(0), thruster_voltages(NULL),
      thruster_currents_length(0), thruster_currents(NULL),
      thruster_rpms_length(0), thruster_rpms(NULL),
      thruster_controller_temperatures_length(0), thruster_controller_temperatures(NULL),
      thruster_output_powers_length(0), thruster_output_powers(NULL),
      thruster_warnings_length(0), thruster_warnings(NULL),
      thruster_errors_length(0), thruster_errors(NULL),
      total_ms_in_driver(0),
      setpoints_length(0), setpoints(NULL),
      processed_setpoints_length(0), processed_setpoints(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = thruster_voltages_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < thruster_voltages_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->thruster_voltages[i]);
      }
      *(outbuffer + offset++) = thruster_currents_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < thruster_currents_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->thruster_currents[i]);
      }
      *(outbuffer + offset++) = thruster_rpms_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < thruster_rpms_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->thruster_rpms[i]);
      }
      *(outbuffer + offset++) = thruster_controller_temperatures_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < thruster_controller_temperatures_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->thruster_controller_temperatures[i]);
      }
      *(outbuffer + offset++) = thruster_output_powers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < thruster_output_powers_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->thruster_output_powers[i]);
      }
      *(outbuffer + offset++) = thruster_warnings_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < thruster_warnings_length; i++){
      uint32_t length_thruster_warningsi = strlen(this->thruster_warnings[i]);
      memcpy(outbuffer + offset, &length_thruster_warningsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->thruster_warnings[i], length_thruster_warningsi);
      offset += length_thruster_warningsi;
      }
      *(outbuffer + offset++) = thruster_errors_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < thruster_errors_length; i++){
      uint32_t length_thruster_errorsi = strlen(this->thruster_errors[i]);
      memcpy(outbuffer + offset, &length_thruster_errorsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->thruster_errors[i], length_thruster_errorsi);
      offset += length_thruster_errorsi;
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->total_ms_in_driver);
      *(outbuffer + offset++) = setpoints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < setpoints_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoints[i]);
      }
      *(outbuffer + offset++) = processed_setpoints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < processed_setpoints_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->processed_setpoints[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t thruster_voltages_lengthT = *(inbuffer + offset++);
      if(thruster_voltages_lengthT > thruster_voltages_length)
        this->thruster_voltages = (float*)realloc(this->thruster_voltages, thruster_voltages_lengthT * sizeof(float));
      offset += 3;
      thruster_voltages_length = thruster_voltages_lengthT;
      for( uint8_t i = 0; i < thruster_voltages_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_thruster_voltages));
        memcpy( &(this->thruster_voltages[i]), &(this->st_thruster_voltages), sizeof(float));
      }
      uint8_t thruster_currents_lengthT = *(inbuffer + offset++);
      if(thruster_currents_lengthT > thruster_currents_length)
        this->thruster_currents = (float*)realloc(this->thruster_currents, thruster_currents_lengthT * sizeof(float));
      offset += 3;
      thruster_currents_length = thruster_currents_lengthT;
      for( uint8_t i = 0; i < thruster_currents_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_thruster_currents));
        memcpy( &(this->thruster_currents[i]), &(this->st_thruster_currents), sizeof(float));
      }
      uint8_t thruster_rpms_lengthT = *(inbuffer + offset++);
      if(thruster_rpms_lengthT > thruster_rpms_length)
        this->thruster_rpms = (float*)realloc(this->thruster_rpms, thruster_rpms_lengthT * sizeof(float));
      offset += 3;
      thruster_rpms_length = thruster_rpms_lengthT;
      for( uint8_t i = 0; i < thruster_rpms_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_thruster_rpms));
        memcpy( &(this->thruster_rpms[i]), &(this->st_thruster_rpms), sizeof(float));
      }
      uint8_t thruster_controller_temperatures_lengthT = *(inbuffer + offset++);
      if(thruster_controller_temperatures_lengthT > thruster_controller_temperatures_length)
        this->thruster_controller_temperatures = (float*)realloc(this->thruster_controller_temperatures, thruster_controller_temperatures_lengthT * sizeof(float));
      offset += 3;
      thruster_controller_temperatures_length = thruster_controller_temperatures_lengthT;
      for( uint8_t i = 0; i < thruster_controller_temperatures_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_thruster_controller_temperatures));
        memcpy( &(this->thruster_controller_temperatures[i]), &(this->st_thruster_controller_temperatures), sizeof(float));
      }
      uint8_t thruster_output_powers_lengthT = *(inbuffer + offset++);
      if(thruster_output_powers_lengthT > thruster_output_powers_length)
        this->thruster_output_powers = (float*)realloc(this->thruster_output_powers, thruster_output_powers_lengthT * sizeof(float));
      offset += 3;
      thruster_output_powers_length = thruster_output_powers_lengthT;
      for( uint8_t i = 0; i < thruster_output_powers_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_thruster_output_powers));
        memcpy( &(this->thruster_output_powers[i]), &(this->st_thruster_output_powers), sizeof(float));
      }
      uint8_t thruster_warnings_lengthT = *(inbuffer + offset++);
      if(thruster_warnings_lengthT > thruster_warnings_length)
        this->thruster_warnings = (char**)realloc(this->thruster_warnings, thruster_warnings_lengthT * sizeof(char*));
      offset += 3;
      thruster_warnings_length = thruster_warnings_lengthT;
      for( uint8_t i = 0; i < thruster_warnings_length; i++){
      uint32_t length_st_thruster_warnings;
      memcpy(&length_st_thruster_warnings, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_thruster_warnings; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_thruster_warnings-1]=0;
      this->st_thruster_warnings = (char *)(inbuffer + offset-1);
      offset += length_st_thruster_warnings;
        memcpy( &(this->thruster_warnings[i]), &(this->st_thruster_warnings), sizeof(char*));
      }
      uint8_t thruster_errors_lengthT = *(inbuffer + offset++);
      if(thruster_errors_lengthT > thruster_errors_length)
        this->thruster_errors = (char**)realloc(this->thruster_errors, thruster_errors_lengthT * sizeof(char*));
      offset += 3;
      thruster_errors_length = thruster_errors_lengthT;
      for( uint8_t i = 0; i < thruster_errors_length; i++){
      uint32_t length_st_thruster_errors;
      memcpy(&length_st_thruster_errors, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_thruster_errors; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_thruster_errors-1]=0;
      this->st_thruster_errors = (char *)(inbuffer + offset-1);
      offset += length_st_thruster_errors;
        memcpy( &(this->thruster_errors[i]), &(this->st_thruster_errors), sizeof(char*));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->total_ms_in_driver));
      uint8_t setpoints_lengthT = *(inbuffer + offset++);
      if(setpoints_lengthT > setpoints_length)
        this->setpoints = (float*)realloc(this->setpoints, setpoints_lengthT * sizeof(float));
      offset += 3;
      setpoints_length = setpoints_lengthT;
      for( uint8_t i = 0; i < setpoints_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_setpoints));
        memcpy( &(this->setpoints[i]), &(this->st_setpoints), sizeof(float));
      }
      uint8_t processed_setpoints_lengthT = *(inbuffer + offset++);
      if(processed_setpoints_lengthT > processed_setpoints_length)
        this->processed_setpoints = (float*)realloc(this->processed_setpoints, processed_setpoints_lengthT * sizeof(float));
      offset += 3;
      processed_setpoints_length = processed_setpoints_lengthT;
      for( uint8_t i = 0; i < processed_setpoints_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_processed_setpoints));
        memcpy( &(this->processed_setpoints[i]), &(this->st_processed_setpoints), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "cola2_control/ThrustersInfo"; };
    const char * getMD5(){ return "e9a9f06dc0d57886bf76e6b4975c4485"; };

  };

}
#endif