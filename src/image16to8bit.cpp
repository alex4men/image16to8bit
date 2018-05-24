#include "image16to8bit/image16to8bit.h"


namespace image16to8bit
{


void Converter::onInit()
{
    nodelet_topic_tools::NodeletLazy::onInit();

    NODELET_INFO("Initializing nodelet...");
    ROS_INFO("Hi!");


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

    // sensor_msgs::CameraInfo dst_info_msg = *info_msg;

  // double scale_y;
  // double scale_x;
  // if (config.use_scale)
  // {
  //   scale_y = config.scale_height;
  //   scale_x = config.scale_width;
  //   dst_info_msg.height = static_cast<int>(info_msg->height * config.scale_height);
  //   dst_info_msg.width = static_cast<int>(info_msg->width * config.scale_width);
  // }
  // else
  // {
  //   scale_y = static_cast<double>(config.height) / info_msg->height;
  //   scale_x = static_cast<double>(config.width) / info_msg->width;
  //   dst_info_msg.height = config.height;
  //   dst_info_msg.width = config.width;
  // }

  // dst_info_msg.K[0] = dst_info_msg.K[0] * scale_x;  // fx
  // dst_info_msg.K[2] = dst_info_msg.K[2] * scale_x;  // cx
  // dst_info_msg.K[4] = dst_info_msg.K[4] * scale_y;  // fy
  // dst_info_msg.K[5] = dst_info_msg.K[5] * scale_y;  // cy

  // dst_info_msg.P[0] = dst_info_msg.P[0] * scale_x;  // fx
  // dst_info_msg.P[2] = dst_info_msg.P[2] * scale_x;  // cx
  // dst_info_msg.P[3] = dst_info_msg.P[3] * scale_x;  // T
  // dst_info_msg.P[5] = dst_info_msg.P[5] * scale_y;  // fy
  // dst_info_msg.P[6] = dst_info_msg.P[6] * scale_y;  // cy

    pub_info_.publish(*info_msg);
}

void Converter::imageCb(const sensor_msgs::ImageConstPtr& image_msg)
{

    // cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(image_msg);
    // cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(image_msg, sensor_msgs::image_encodings::TYPE_16UC1);

    
  // if (config.use_scale)
  // {
  //   cv::resize(cv_ptr->image, cv_ptr->image, cv::Size(0, 0),
  //              config.scale_width, config.scale_height, config.interpolation);
  // }
  // else
  // {
    // int height = image_msg->height;
    // int width = image_msg->width;

  //   cv::resize(cv_ptr->image, cv_ptr->image, cv::Size(width, height), 0, 0, config.interpolation);
  // }

  // pub_image_.publish(cv_ptr->toImageMsg());
    // cv_bridge::CvImagePtr cv_ptr;
 //    cv_ptr = cv_bridge::toCvCopy(image_msgg);  
    // cv::Mat img8(height, width, CV_8UC1);
    // cv_ptr->image.convertTo(img8, CV_8UC1);

    pub_image_.publish(*image_msg);
}


}  //namespace image16to8bit


#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(image16to8bit::Converter, nodelet::Nodelet)
