#ifndef MAIN_H
# define MAIN_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <opencv2/opencv.hpp>


std::vector<cv::String> getFilepaths(std::string pattern);
std::vector<cv::Mat> getImages(std::vector<cv::String> fpaths);
std::vector<cv::Vec4f> getPointcloud(cv::String fpath);
std::vector<std::vector<cv::Vec4f>> getPointclouds(std::vector<cv::String> fpaths);

#endif