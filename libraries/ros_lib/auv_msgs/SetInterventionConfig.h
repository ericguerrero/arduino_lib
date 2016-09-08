#ifndef _ROS_SERVICE_SetInterventionConfig_h
#define _ROS_SERVICE_SetInterventionConfig_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auv_msgs/InterventionSpec.h"

namespace auv_msgs
{

static const char SETINTERVENTIONCONFIG[] = "auv_msgs/SetInterventionConfig";

  class SetInterventionConfigRequest : public ros::Msg
  {
    public:
      auv_msgs::InterventionSpec spec;

    SetInterventionConfigRequest():
      spec()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->spec.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->spec.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETINTERVENTIONCONFIG; };
    const char * getMD5(){ return "b13d4b27c94a0810ff073cf60fb978c0"; };

  };

  class SetInterventionConfigResponse : public ros::Msg
  {
    public:
      bool ok;
      int32_t error_num;
      const char* error_string;
      enum { ERROR_BAD_PARAM =  1 };
      enum { ERROR_SERVICE_RUNNING =  2 };
      enum { ERROR_OTHER =  -1 };

    SetInterventionConfigResponse():
      ok(0),
      error_num(0),
      error_string("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
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
      uint32_t length_error_string = strlen(this->error_string);
      memcpy(outbuffer + offset, &length_error_string, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_string, length_error_string);
      offset += length_error_string;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
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
      uint32_t length_error_string;
      memcpy(&length_error_string, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_string; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_string-1]=0;
      this->error_string = (char *)(inbuffer + offset-1);
      offset += length_error_string;
     return offset;
    }

    const char * getType(){ return SETINTERVENTIONCONFIG; };
    const char * getMD5(){ return "8a34db9e4c5ab50b1c2a620d4f14366c"; };

  };

  class SetInterventionConfig {
    public:
    typedef SetInterventionConfigRequest Request;
    typedef SetInterventionConfigResponse Response;
  };

}
#endif
