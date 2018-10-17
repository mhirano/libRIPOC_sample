//
// Created by Masahiro Hirano <masahiro.dll@gmail.com>
//

#ifndef RIPOC_POC_HPP
#define RIPOC_POC_HPP

#include <iostream>
#include <opencv2/opencv.hpp>

#include "Utility.h"
#include "Transform.h"
#include "OpenCVFunc.h"

using namespace cv;
using namespace std;

/**
 * POC method enum class
 */
enum class POCMethod{
    POC = 0,
    RIPOC = 1
};

/**
 * POC option class
 * - POCMethod, number of columns, number of rows
 */
struct POCOption{
    POCOption() : pocMethod(POCMethod::RIPOC) {};
    POCOption(POCMethod method_, int cols_, int rows_)
            : pocMethod(method_), numCols(cols_), numRows(rows_) {};
    ~POCOption() {};

    POCMethod method() const { return pocMethod; }
    int cols() const { return numCols; }
    int rows() const { return numRows; }

private:
    POCMethod pocMethod;
    int numCols;
    int numRows;
};

/**
 * POC result
 */
struct POCResult{
    POCMethod method;
    
    Transform2d trans;
    
    double ripocResponse;
    double pocResponse;
    
};


/**
 * POC class
 * - calculate translation/rotation/scale from given two displaced images
 */
class POC{
public:
    POC();
    
    POC(POCOption option_);
    
    POCResult calcTrans (const Mat &prev, const Mat &curr);
    
private:
    POCOption option;

    cv::Mat hanningWindow;
    cv::Mat prev_gr, prev64f;
    cv::Mat curr_gr, curr64f;
   
    int optimalDFTSizeRow,  optimalDFTSizeCol;
    Mat prev64f_pad, curr64f_pad, paddedWin;
    
    Mat prev64f_LAS, curr64f_LAS;
    
    Mat prev_LP, curr_LP;

    void dft_logmag(cv::Mat &src, cv::Mat &mag, cv::Mat &hann);
    
    Point2d myPhaseCorr(const Mat& prev, const Mat& curr, const cv::Mat& hann);
};

#endif //RIPOC_POC_HPP
