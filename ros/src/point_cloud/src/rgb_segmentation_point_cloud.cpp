//
// Created by neil on 4/1/19.
//


#include <ros/ros.h>
#include <ros/console.h>
#include "cv_bridge/cv_bridge.h"
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl_ros/transforms.h>
#include <pcl/filters/voxel_grid.h>
// opencv
#include <opencv2/opencv.hpp>
#include <chrono>


ros::Publisher pub;
tf::StampedTransform transform;
cv::Mat segmentation_image;
bool accept_frame;

void image_callback(const sensor_msgs::ImageConstPtr& msg)
{
    cv_bridge::CvImagePtr cv_ptr;
    try{
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::MONO8);
    }
    catch (cv_bridge::Exception& e){
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }
    if (accept_frame) {
        cv::Mat dst;
        cv::resize(cv_ptr->image, dst, cv::Size(1920, 1080));
        segmentation_image = dst;
    }
}

void cloud_callback (const sensor_msgs::PointCloud2ConstPtr& input){

//    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    // Create a container for the data.
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_output(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::PCLPointCloud2 pcl_pc2;
    pcl_conversions::toPCL(*input, pcl_pc2);
    pcl::fromPCLPointCloud2(pcl_pc2,*cloud_output);

//    std::cout << std::to_string(temp_cloud->width) << std::endl;
//    std::cout << std::to_string(temp_cloud->height) << std::endl;
//    std::cout << "-------" << std::endl;

    accept_frame = false;

    // std::cout << std::to_string(segmentation_image.rows * segmentation_image.cols) << std::endl;

    for(int i = 0; i < segmentation_image.rows; i+=2) {

        for (int j = 0; j < segmentation_image.cols; j += 2) {

            if (segmentation_image.data[i * segmentation_image.cols + j] == 255) {

                cloud_output->points[i * segmentation_image.cols + j].r = 0;
                cloud_output->points[i * segmentation_image.cols + j].g = 255;
                cloud_output->points[i * segmentation_image.cols + j].b = 0;
            }
        }
    }

    accept_frame = true;

    sensor_msgs::PointCloud2 cloud_publish;
    pcl::toROSMsg(*cloud_output,cloud_publish);
    cloud_publish.header = input->header;

    pub.publish(cloud_publish);

//    // timing test
//    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
//    std::cout << "time" << std::endl;
//    std::cout << std::to_string(duration) << std::endl;
}

int main (int argc, char** argv) {

    // Initialize ROS
    ROS_INFO("Node started");

    ros::init(argc, argv, "rgb_segmentation_point_cloud");
    ros::NodeHandle nh;

    // Create a ROS subscriber for the input point cloud
    ros::Subscriber sub = nh.subscribe("/zed/point_cloud/cloud_registered", 3, cloud_callback);
    ros::Subscriber sub_img = nh.subscribe("/segmentation/output/road", 3, image_callback);

    pub = nh.advertise<sensor_msgs::PointCloud2> ("/point_cloud/ground_segmentation", 3);

    ros::spin();
    return 0;

}