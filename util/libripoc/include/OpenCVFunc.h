//
// Created by Masahiro Hirano <masahiro.dll@gmail.com>
//

#ifndef ACCEL_OPENCVFUNC_H
#define ACCEL_OPENCVFUNC_H

#include <opencv2/opencv.hpp>

/*
 * Functions adapted from OpenCV
 * Some functions on OpenCV are only available from inside
 * Therefore copy and paste necessary codes here
 * copied at May 30, 2018.
 * Copyright belongs to OpenCV contributors.
 */

class OpenCVFunc {
public:
    static void magSpectrums(cv::InputArray _src, cv::OutputArray _dst);
    static void divSpectrums(cv::InputArray _srcA, cv::InputArray _srcB,
                             cv::OutputArray _dst, int flags, bool conjB);
    static void fftShift(cv::InputOutputArray _out);
    static cv::Point2d weightedCentroid(cv::InputArray _src,
                                    cv::Point peakLocation,
                                    cv::Size weightBoxSize,
                                    double *response);
};


#endif //ACCEL_OPENCVFUNC_H