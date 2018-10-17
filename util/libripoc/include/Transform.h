//
// Created by Masahiro Hirano <masahiro.dll@gmail.com>
//

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <iostream>

#include <opencv2/opencv.hpp>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include "Utility.h"

// Wrapper of Affine2d for ease of use
// Assume Cartesian coordinate

// angle : in radian

struct Transform2d{
    /**
     * Variables
     */

    Eigen::Affine2d transform2d;

    /**
     * Methods
     */
    Transform2d(){ };

    // copy constructor
    Transform2d(const Transform2d &trans) : transform2d(trans.transform2d) { }; 
    
    // initialize by affine matrix
    Transform2d(Eigen::Affine2d transform2d_): transform2d(transform2d_){ };
    
    // angle is in rad.
    Transform2d(cv::Point2d shift_, double angle_, double scale_=1){
        Eigen::Rotation2Dd rotation(angle_);
        Eigen::Translation2d translation(shift_.x, shift_.y);
//        Eigen::DiagonalMatrix<double, 2> scaling(scale_, scale_);
//        transform2d = scaling * translation * rotation;
        transform2d = translation * rotation;
    }

    double angle() const {
        Eigen::Rotation2Dd rotate2d(transform2d.rotation());
        return rotate2d.angle();
    }

    void setAngle(const double angle_){
        Eigen::Rotation2Dd rotation(angle_);
        Eigen::Translation2d translation(transform2d.translation());
        transform2d = translation * rotation;
    }

    cv::Point2d shift() const {
        Eigen::Translation2d shift2d(transform2d.translation());
        return cv::Point2d(shift2d.x(), shift2d.y());
    }

    void setShift(const cv::Point2d shift_){
        Eigen::Rotation2Dd rotation(transform2d.rotation());
        Eigen::Translation2d translation(Eigen::Vector2d(shift_.x, shift_.y));
        transform2d = translation * rotation;
    }

    void setShiftX(const double x_){
        Eigen::Rotation2Dd rotation(transform2d.rotation());
        Eigen::Translation2d currentShift2d(transform2d.translation());

        Eigen::Translation2d translation(Eigen::Vector2d(x_, currentShift2d.y()));
        transform2d = translation * rotation;
    }

    void setShiftY(const double y_){
        Eigen::Rotation2Dd rotation(transform2d.rotation());
        Eigen::Translation2d currentShift2d(transform2d.translation());

        Eigen::Translation2d translation(Eigen::Vector2d(currentShift2d.x(), y_));
        transform2d = translation * rotation;
    }

    friend std::ostream& operator<< (std::ostream &out, const Transform2d &tgt){
        out << "[" << tgt.shift().x << ", " << tgt.shift().y << ", "
            << tgt.angle() << "[rad](" << Util::rad2degree(tgt.angle()) << "[deg])]";
        return out;
    }

    void inverse(){
        this->transform2d = transform2d.inverse(Eigen::Isometry);
    }
    
    std::string formatted(){
        std::ostringstream ost;
        ost << this->shift().x << "," << this->shift().y << "," << this->angle() << std::endl; 
        return ost.str();
    }
    

    Transform2d operator*(const Transform2d &t){
        return Transform2d(this->transform2d * t.transform2d);
    }

    cv::Point2d operator*(const cv::Point2d &p){
        Eigen::Vector2d mul = this->transform2d * Eigen::Vector2d(p.x, p.y);
        return cv::Point2d(mul[0], mul[1]); // cv::Point2d(mul.x(), mul.y())
    }
};

#endif //TRANSFORM_H
