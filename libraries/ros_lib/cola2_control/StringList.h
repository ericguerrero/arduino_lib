#ifndef _ROS_SERVICE_StringList_h
#define _ROS_SERVICE_StringList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cola2_control
{

static const char STRINGLIST[] = "cola2_control/StringList";

  class StringListRequest : public ros::Msg
  {
    public:
      uint8_t mystring_length;
      char* st_mystring;
      char* * mystring;

    StringListRequest():
      mystring_length(0), mystring(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = mystring_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < mystring_length; i++){
      uint32_t length_mystringi = strlen(this->mystring[i]);
      memcpy(outbuffer + offset, &length_mystringi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->mystring[i], length_mystringi);
      offset += length_mystringi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t mystring_lengthT = *(inbuffer + offset++);
      if(mystring_lengthT > mystring_length)
        this->mystring = (char**)realloc(this->mystring, mystring_lengthT * sizeof(char*));
      offset += 3;
      mystring_length = mystring_lengthT;
      for( uint8_t i = 0; i < mystring_length; i++){
      uint32_t length_st_mystring;
      memcpy(&length_st_mystring, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_mystring; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_mystring-1]=0;
      this->st_mystring = (char *)(inbuffer + offset-1);
      offset += length_st_mystring;
        memcpy( &(this->mystring[i]), &(this->st_mystring), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return STRINGLIST; };
    const char * getMD5(){ return "e355a1fd8cee5ff5ab94e6c3484bea94"; };

  };

  class StringListResponse : public ros::Msg
  {
    public:
      bool flag;

    StringListResponse():
      flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_flag;
      u_flag.real = this->flag;
      *(outbuffer + offset + 0) = (u_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_flag;
      u_flag.base = 0;
      u_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->flag = u_flag.real;
      offset += sizeof(this->flag);
     return offset;
    }

    const char * getType(){ return STRINGLIST; };
    const char * getMD5(){ return "24842bc754e0f5cc982338eca1269251"; };

  };

  class StringList {
    public:
    typedef StringListRequest Request;
    typedef StringListResponse Response;
  };

}
#endif
