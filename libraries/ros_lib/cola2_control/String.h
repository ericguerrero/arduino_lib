#ifndef _ROS_SERVICE_String_h
#define _ROS_SERVICE_String_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cola2_control
{

static const char STRING[] = "cola2_control/String";

  class StringRequest : public ros::Msg
  {
    public:
      const char* mystring;

    StringRequest():
      mystring("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_mystring = strlen(this->mystring);
      memcpy(outbuffer + offset, &length_mystring, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->mystring, length_mystring);
      offset += length_mystring;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_mystring;
      memcpy(&length_mystring, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mystring; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mystring-1]=0;
      this->mystring = (char *)(inbuffer + offset-1);
      offset += length_mystring;
     return offset;
    }

    const char * getType(){ return STRING; };
    const char * getMD5(){ return "e8054fff057e825e73968032a7c26bc8"; };

  };

  class StringResponse : public ros::Msg
  {
    public:

    StringResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return STRING; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class String {
    public:
    typedef StringRequest Request;
    typedef StringResponse Response;
  };

}
#endif
