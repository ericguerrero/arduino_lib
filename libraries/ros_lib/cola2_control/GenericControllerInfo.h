#ifndef _ROS_cola2_control_GenericControllerInfo_h
#define _ROS_cola2_control_GenericControllerInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cola2_control
{

  class GenericControllerInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float setpoint;
      float sensed;
      uint8_t nodes_length;
      char* st_nodes;
      char* * nodes;
      uint8_t node_values_length;
      float st_node_values;
      float * node_values;
      float output;
      float saturated_output;

    GenericControllerInfo():
      header(),
      setpoint(0),
      sensed(0),
      nodes_length(0), nodes(NULL),
      node_values_length(0), node_values(NULL),
      output(0),
      saturated_output(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint);
      offset += serializeAvrFloat64(outbuffer + offset, this->sensed);
      *(outbuffer + offset++) = nodes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < nodes_length; i++){
      uint32_t length_nodesi = strlen(this->nodes[i]);
      memcpy(outbuffer + offset, &length_nodesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->nodes[i], length_nodesi);
      offset += length_nodesi;
      }
      *(outbuffer + offset++) = node_values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < node_values_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->node_values[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->output);
      offset += serializeAvrFloat64(outbuffer + offset, this->saturated_output);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sensed));
      uint8_t nodes_lengthT = *(inbuffer + offset++);
      if(nodes_lengthT > nodes_length)
        this->nodes = (char**)realloc(this->nodes, nodes_lengthT * sizeof(char*));
      offset += 3;
      nodes_length = nodes_lengthT;
      for( uint8_t i = 0; i < nodes_length; i++){
      uint32_t length_st_nodes;
      memcpy(&length_st_nodes, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_nodes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_nodes-1]=0;
      this->st_nodes = (char *)(inbuffer + offset-1);
      offset += length_st_nodes;
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(char*));
      }
      uint8_t node_values_lengthT = *(inbuffer + offset++);
      if(node_values_lengthT > node_values_length)
        this->node_values = (float*)realloc(this->node_values, node_values_lengthT * sizeof(float));
      offset += 3;
      node_values_length = node_values_lengthT;
      for( uint8_t i = 0; i < node_values_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_node_values));
        memcpy( &(this->node_values[i]), &(this->st_node_values), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->output));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->saturated_output));
     return offset;
    }

    const char * getType(){ return "cola2_control/GenericControllerInfo"; };
    const char * getMD5(){ return "7df293306350256ffc89decea647d435"; };

  };

}
#endif