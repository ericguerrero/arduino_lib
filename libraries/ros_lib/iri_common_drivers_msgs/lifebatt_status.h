#ifndef _ROS_iri_common_drivers_msgs_lifebatt_status_h
#define _ROS_iri_common_drivers_msgs_lifebatt_status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iri_common_drivers_msgs
{

  class lifebatt_status : public ros::Msg
  {
    public:
      float voltage;
      float temperature;
      uint8_t status;
      float input_current;
      float output_current;
      float remaining_capacity;
      float time_to_charged;
      float time_to_discharged;

    lifebatt_status():
      voltage(0),
      temperature(0),
      status(0),
      input_current(0),
      output_current(0),
      remaining_capacity(0),
      time_to_charged(0),
      time_to_discharged(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->voltage);
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      offset += serializeAvrFloat64(outbuffer + offset, this->input_current);
      offset += serializeAvrFloat64(outbuffer + offset, this->output_current);
      offset += serializeAvrFloat64(outbuffer + offset, this->remaining_capacity);
      offset += serializeAvrFloat64(outbuffer + offset, this->time_to_charged);
      offset += serializeAvrFloat64(outbuffer + offset, this->time_to_discharged);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->voltage));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temperature));
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->input_current));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->output_current));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->remaining_capacity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time_to_charged));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time_to_discharged));
     return offset;
    }

    const char * getType(){ return "iri_common_drivers_msgs/lifebatt_status"; };
    const char * getMD5(){ return "9cc10a535f6582725be65cc15269919b"; };

  };

}
#endif