#ifndef _ROS_auv_msgs_InterventionSpec_h
#define _ROS_auv_msgs_InterventionSpec_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auv_msgs/ImageFeature.h"
#include "sensor_msgs/RegionOfInterest.h"
#include "auv_msgs/InterventionTaskSpec.h"

namespace auv_msgs
{

  class InterventionSpec : public ros::Msg
  {
    public:
      const char* view_image_id;
      uint8_t view_feature_length;
      auv_msgs::ImageFeature st_view_feature;
      auv_msgs::ImageFeature * view_feature;
      sensor_msgs::RegionOfInterest roi;
      float roi_rotation;
      uint8_t object_feature_length;
      auv_msgs::ImageFeature st_object_feature;
      auv_msgs::ImageFeature * object_feature;
      uint8_t task_spec_length;
      auv_msgs::InterventionTaskSpec st_task_spec;
      auv_msgs::InterventionTaskSpec * task_spec;

    InterventionSpec():
      view_image_id(""),
      view_feature_length(0), view_feature(NULL),
      roi(),
      roi_rotation(0),
      object_feature_length(0), object_feature(NULL),
      task_spec_length(0), task_spec(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_view_image_id = strlen(this->view_image_id);
      memcpy(outbuffer + offset, &length_view_image_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->view_image_id, length_view_image_id);
      offset += length_view_image_id;
      *(outbuffer + offset++) = view_feature_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < view_feature_length; i++){
      offset += this->view_feature[i].serialize(outbuffer + offset);
      }
      offset += this->roi.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_roi_rotation;
      u_roi_rotation.real = this->roi_rotation;
      *(outbuffer + offset + 0) = (u_roi_rotation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roi_rotation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roi_rotation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roi_rotation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roi_rotation);
      *(outbuffer + offset++) = object_feature_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < object_feature_length; i++){
      offset += this->object_feature[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = task_spec_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < task_spec_length; i++){
      offset += this->task_spec[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_view_image_id;
      memcpy(&length_view_image_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_view_image_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_view_image_id-1]=0;
      this->view_image_id = (char *)(inbuffer + offset-1);
      offset += length_view_image_id;
      uint8_t view_feature_lengthT = *(inbuffer + offset++);
      if(view_feature_lengthT > view_feature_length)
        this->view_feature = (auv_msgs::ImageFeature*)realloc(this->view_feature, view_feature_lengthT * sizeof(auv_msgs::ImageFeature));
      offset += 3;
      view_feature_length = view_feature_lengthT;
      for( uint8_t i = 0; i < view_feature_length; i++){
      offset += this->st_view_feature.deserialize(inbuffer + offset);
        memcpy( &(this->view_feature[i]), &(this->st_view_feature), sizeof(auv_msgs::ImageFeature));
      }
      offset += this->roi.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_roi_rotation;
      u_roi_rotation.base = 0;
      u_roi_rotation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roi_rotation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roi_rotation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roi_rotation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roi_rotation = u_roi_rotation.real;
      offset += sizeof(this->roi_rotation);
      uint8_t object_feature_lengthT = *(inbuffer + offset++);
      if(object_feature_lengthT > object_feature_length)
        this->object_feature = (auv_msgs::ImageFeature*)realloc(this->object_feature, object_feature_lengthT * sizeof(auv_msgs::ImageFeature));
      offset += 3;
      object_feature_length = object_feature_lengthT;
      for( uint8_t i = 0; i < object_feature_length; i++){
      offset += this->st_object_feature.deserialize(inbuffer + offset);
        memcpy( &(this->object_feature[i]), &(this->st_object_feature), sizeof(auv_msgs::ImageFeature));
      }
      uint8_t task_spec_lengthT = *(inbuffer + offset++);
      if(task_spec_lengthT > task_spec_length)
        this->task_spec = (auv_msgs::InterventionTaskSpec*)realloc(this->task_spec, task_spec_lengthT * sizeof(auv_msgs::InterventionTaskSpec));
      offset += 3;
      task_spec_length = task_spec_lengthT;
      for( uint8_t i = 0; i < task_spec_length; i++){
      offset += this->st_task_spec.deserialize(inbuffer + offset);
        memcpy( &(this->task_spec[i]), &(this->st_task_spec), sizeof(auv_msgs::InterventionTaskSpec));
      }
     return offset;
    }

    const char * getType(){ return "auv_msgs/InterventionSpec"; };
    const char * getMD5(){ return "551d8bffe5fd065b782745dfc1f4fd3b"; };

  };

}
#endif