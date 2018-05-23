#include <pluginlib/class_list_macros.h>

#include "image16to8bit/image16to8bit.h"

// watch the capitalization carefully
PLUGINLIB_EXPORT_CLASS(image16to8bit::Converter, nodelet::Nodelet)

namespace image16to8bit
{
    void Converter::onInit()
    {
        NODELET_DEBUG("Initializing nodelet...");
        ROS_INFO("Hi!");
    }
}