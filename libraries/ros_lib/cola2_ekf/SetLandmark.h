#ifndef _ROS_SERVICE_SetLandmark_h
#define _ROS_SERVICE_SetLandmark_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovariance.h"

namespace cola2_ekf
{

static const char SETLANDMARK[] = "cola2_ekf/SetLandmark";

  class SetLandmarkRequest : public ros::Msg
  {
    public:
      geometry_msgs::PoseWithCovariance landmark;
      const char* topic_name;

    SetLandmarkRequest():
      landmark(),
      topic_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->landmark.serialize(outbuffer + offset);
      uint32_t length_topic_name = strlen(this->topic_name);
      memcpy(outbuffer + offset, &length_topic_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topic_name, length_topic_name);
      offset += length_topic_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->landmark.deserialize(inbuffer + offset);
      uint32_t length_topic_name;
      memcpy(&length_topic_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic_name-1]=0;
      this->topic_name = (char *)(inbuffer + offset-1);
      offset += length_topic_name;
     return offset;
    }

    const char * getType(){ return SETLANDMARK; };
    const char * getMD5(){ return "3a728969e9be1948ad1516696bacf677"; };

  };

  class SetLandmarkResponse : public ros::Msg
  {
    public:

    SetLandmarkResponse()
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

    const char * getType(){ return SETLANDMARK; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetLandmark {
    public:
    typedef SetLandmarkRequest Request;
    typedef SetLandmarkResponse Response;
  };

}
#endif
