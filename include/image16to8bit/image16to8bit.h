#include <nodelet/nodelet.h>
#include <nodelet_topic_tools/nodelet_lazy.h>
#include <cv_bridge/cv_bridge.h>
#include <ros/ros.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/Image.h>

namespace image16to8bit
{


class Converter : public nodelet_topic_tools::NodeletLazy
{
    protected:
        // ROS communication
        ros::Publisher pub_image_;
        ros::Publisher pub_info_;
        ros::Subscriber sub_info_;
        ros::Subscriber sub_image_;
    
        virtual void onInit();
        virtual void subscribe();
        virtual void unsubscribe();

        void imageCb(const sensor_msgs::ImageConstPtr& image_msg);
        void infoCb(const sensor_msgs::CameraInfoConstPtr& info_msg);
};


}