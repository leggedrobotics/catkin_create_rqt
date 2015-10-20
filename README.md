# Create catkin rqt plugin package for ROS

**Author: Samuel Bachmann**

This is a very basic script to create a standard rqt plugin for ROS.
The script will generate a ready to use rqt package including .cpp, .ui and .h files.
There are some input arguments supported to customize the package a bit.

## Usage

Example call:

    ./catkin_create_rqt rqt_example std_msgs sensor_msgs -c Example -n rqt_example -f example -p /home/user/catkin_ws/src

## Supported arguments

    usage: catkin_create_rqt [-h] [-p PATH] [-c CLASS_NAME] [-n NAMESPACE]
                             [-f FILE_NAME] [-a AUTHOR] [-e EMAIL]
                             name [dependencies [dependencies ...]]


| Parameter           | Description                                          |
| ------------------- | ---------------------------------------------------- |
| [-h, --help]        | shows the help message and exits                     |
| [-p, --path]        | the path into which the package should be generated  |
| [-c, --class_name]  | rename the used class name                           |
| [-n, --namespace]   | rename the used namespace                            |
| [-f, --file_name]   | rename the file names (file_name.cpp, .h, .ui)       |
| [-a, --author]      | define author in package.xml                         |
| [-e, --email]       | define email address in package.xml                  |
