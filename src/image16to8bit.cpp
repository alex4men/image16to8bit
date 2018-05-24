#include "image16to8bit/image16to8bit.h"


namespace image16to8bit
{


void Converter::onInit()
{
    nodelet_topic_tools::NodeletLazy::onInit();

    NODELET_INFO("Initializing 16-8bit converter nodelet...");


    pub_info_ = advertise<sensor_msgs::CameraInfo>(*pnh_, "camera_info", 1);
    pub_image_ = advertise<sensor_msgs::Image>(*pnh_, "image", 1);

    onInitPostProcess();
}

void Converter::subscribe()
{
  sub_info_ = nh_->subscribe("camera_info", 1, &Converter::infoCb, this);
  sub_image_ = nh_->subscribe("image", 1, &Converter::imageCb, this);
}

void Converter::unsubscribe()
{
  sub_info_.shutdown();
  sub_image_.shutdown();
}

void Converter::infoCb(const sensor_msgs::CameraInfoConstPtr& info_msg)
{
    pub_info_.publish(*info_msg);
}

void Converter::imageCb(const sensor_msgs::ImageConstPtr& image_msg)
{
    cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(image_msg, image_msg->encoding);

    int height = image_msg->height;
    int width = image_msg->width;

    cv::Mat img8(height, width, CV_8UC1);
    cv_ptr->image.convertTo(img8, CV_8UC1);
    cv_ptr->image = img8;

    cv_ptr->encoding = sensor_msgs::image_encodings::MONO8;

    pub_image_.publish(cv_ptr->toImageMsg());
}


}  //namespace image16to8bit


#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(image16to8bit::Converter, nodelet::Nodelet)
