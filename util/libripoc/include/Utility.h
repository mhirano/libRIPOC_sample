//
// Created by Masahiro Hirano <masahiro.dll@gmail.com>
//

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <time.h>
#include <iostream>
#include <vector>
#include <numeric> 
#include <opencv2/opencv.hpp>

#define PI 3.14159265358979323846

namespace Util
{
	inline double timespec2second (timespec& startTime, timespec& endTime){
		if (endTime.tv_nsec < startTime.tv_nsec) {
			return endTime.tv_sec - startTime.tv_sec - 1 + (endTime.tv_nsec + 1.0e+9 - startTime.tv_nsec)/1.0e9;
		} else {
			return endTime.tv_sec - startTime.tv_sec + (endTime.tv_nsec - startTime.tv_nsec)/1.0e9;
		}
	}
    
    inline double degree2rad (double degree){
		return degree / 180.0 * PI;
    }
	
	inline double rad2degree (double rad) {
        return rad * 180.0 / PI;
    }
	
	inline bool includes(int min, int max, int value){
			return min <= value && value <= max;
	}
	
	inline cv::Point2d cartesian(cv::Point2d cvCoord){
		return cv::Point2d(cvCoord.x, -cvCoord.y);
	}

	inline double average(std::vector<double> vec){
		return std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
	}
	
};

#endif
