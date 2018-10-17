# libRIPOC_sample
## About
A simple library of RIPOC(Rotation invariant Phase Only Correlation).

Only supports Release mode for now.

Library build enviroment
- OS: Windows 10 Home
- Compiler: Visual Studio 2017 (MSVC 19.14.26433.0)
- CMake 3.11.18040201-MSVC_2
- OpenCV 3.4.3 (pre-build)
- Eigen 3.3.5

libripoc ver 1.0 is contained.

## How to run
1. Install OpenCV, Eigen  
Make sure to add path to PATH.
2. Tweak property sheets  
Visual studio's property sheets are located under *util* directory.
Edit `OpenCV.props` and `Eigen.props` reflecting your environment.
3. Build and run  
Open `libRIPOC_sample.sln` and switch to *Release*. You can now try *libRIPOC*.

## Remarks
Feel free to contact me (masahiro.dll@gmail.com) in case you face any problem.
