cmake_minimum_required(VERSION 2.8.3)

project(${pkg_name})
# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED COMPONENTS
  rqt_gui
  rqt_gui_cpp
${dependencies_1}
)

catkin_python_setup()

catkin_package(
)

include_directories(
  $${catkin_INCLUDE_DIRS}
)

install(PROGRAMS
  scripts/${pkg_name}
  DESTINATION $${CATKIN_PACKAGE_BIN_DESTINATION}
)
