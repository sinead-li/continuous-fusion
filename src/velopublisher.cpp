#include "kittireader.hpp"
#include "ros/ros.h"
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "kittivelo");
    ros::NodeHandle nh;
    ros::Publisher publisher = nh.advertise<pcl::PointCloud<pcl::PointXYZI>>("/velodyne/points", 1);

    std::string globPattern = std::string(argv[1]) + "velodyne_points/data/*.bin";
    std::vector<cv::String> fpaths = KittiReader::globFilesHelper(globPattern);

    pcl::PointCloud<pcl::PointXYZI> cloud;
    ros::Rate loop_rate(1);
    int count = 0;
    while (ros::ok())
    {
        cloud = KittiReader::getPointcloud(fpaths[count]);
        cloud.header.frame_id = "kitti_frame";

        ROS_INFO("Publishing pointcloud.");
        publisher.publish(cloud);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
        if (count == fpaths.size())
        {
            count = 0;
        }
    }
    return 0;
}
