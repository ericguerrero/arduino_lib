#ifndef _ROS_SERVICE_SetGPS_h
#define _ROS_SERVICE_SetGPS_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cola2_navigation
{

static const char SETGPS[] = "cola2_navigation/SetGPS";

  class SetGPSRequest : public ros::Msg
  {
    public:
      const char* place;

    SetGPSRequest():
      place("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_place = strlen(this->place);
      memcpy(outbuffer + offset, &length_place, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->place, length_place);
      offset += length_place;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_place;
      memcpy(&length_place, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_place; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_place-1]=0;
      this->place = (char *)(inbuffer + offset-1);
      offset += length_place;
     return offset;
    }

    const char * getType(){ return SETGPS; };
    const char * getMD5(){ return "1b9cfee4aec177f2fc73f9506b6022dd"; };

  };

  class SetGPSResponse : public ros::Msg
  {
    public:
      const char* success;

    SetGPSResponse():
      success("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_success = strlen(this->success);
      memcpy(outbuffer + offset, &length_success, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->success, length_success);
      offset += length_success;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_success;
      memcpy(&length_success, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_success; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_success-1]=0;
      this->success = (char *)(inbuffer + offset-1);
      offset += length_success;
     return offset;
    }

    const char * getType(){ return SETGPS; };
    const char * getMD5(){ return "6563811f75f3715f19a981f2cc0a3560"; };

  };

  class SetGPS {
    public:
    typedef SetGPSRequest Request;
    typedef SetGPSResponse Response;
  };

}
#endif
