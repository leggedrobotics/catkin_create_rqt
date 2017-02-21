cmake_minimum_required(VERSION 2.8.3)

project(${pkg_name})
# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED COMPONENTS
  rqt_gui
  rqt_gui_cpp
${dependencies_1}
)

if ("$${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
  find_package(Qt5Widgets REQUIRED)
else()
  find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
  include($${QT_USE_FILE})
endif()

# Flags
SET(CMAKE_CXX_FLAGS "-std=c++11 $${CMAKE_CXX_FLAGS}")

set($${PROJECT_NAME}_SRCS
  src/$${PROJECT_NAME}/${file_name}.cpp
)

set($${PROJECT_NAME}_HDRS
  include/$${PROJECT_NAME}/${file_name}.h
)

set($${PROJECT_NAME}_UIS
  resource/${file_name}.ui
)

set(ui_INCLUDE_DIR
  "$${CATKIN_DEVEL_PREFIX}/$${CATKIN_GLOBAL_INCLUDE_DESTINATION}/$${PROJECT_NAME}"
)

set($${PROJECT_NAME}_INCLUDE_DIRECTORIES
  include
  $${ui_INCLUDE_DIR}/..
)

if(NOT EXISTS $${ui_INCLUDE_DIR})
  file(MAKE_DIRECTORY $${ui_INCLUDE_DIR})
endif()

catkin_package(
#  INCLUDE_DIRS
#    $${$${PROJECT_NAME}_INCLUDE_DIRECTORIES}
#  LIBRARIES $${PROJECT_NAME}
  CATKIN_DEPENDS
    rqt_gui
    rqt_gui_cpp
${dependencies_2}
)

if ("$${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
  qt5_wrap_cpp($${PROJECT_NAME}_MOCS $${$${PROJECT_NAME}_HDRS})
else()
  qt4_wrap_cpp($${PROJECT_NAME}_MOCS $${$${PROJECT_NAME}_HDRS})
endif()

# ensure generated header files are being created in the devel space
set(_cmake_current_binary_dir "$${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_CURRENT_BINARY_DIR $${ui_INCLUDE_DIR})
if("$${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
  qt5_wrap_ui($${PROJECT_NAME}_UIS_H $${$${PROJECT_NAME}_UIS})
else()
  qt4_wrap_ui($${PROJECT_NAME}_UIS_H $${$${PROJECT_NAME}_UIS})
endif()
set(CMAKE_CURRENT_BINARY_DIR "$${_cmake_current_binary_dir}")

include_directories($${$${PROJECT_NAME}_INCLUDE_DIRECTORIES}
  $${$${PROJECT_NAME}_INCLUDE_DIRECTORIES}
  $${catkin_INCLUDE_DIRS}
)

add_library($${PROJECT_NAME}
  $${$${PROJECT_NAME}_SRCS}
  $${$${PROJECT_NAME}_HDRS}
  $${$${PROJECT_NAME}_MOCS}
  $${$${PROJECT_NAME}_UIS_H}
)
target_link_libraries($${PROJECT_NAME}
  $${catkin_LIBRARIES}
)

if ("$${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
  target_link_libraries($${PROJECT_NAME} Qt5::Widgets)
else()
  target_link_libraries($${PROJECT_NAME} $${QT_QTCORE_LIBRARY} $${QT_QTGUI_LIBRARY})
endif()

add_dependencies($${PROJECT_NAME}
  $${catkin_EXPORTED_TARGETS}
)

find_package(class_loader)
class_loader_hide_library_symbols($${PROJECT_NAME})

install(FILES plugin.xml
  DESTINATION $${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(TARGETS $${PROJECT_NAME}
  ARCHIVE DESTINATION $${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION $${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION $${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(PROGRAMS scripts/$${PROJECT_NAME}
  DESTINATION $${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/$${PROJECT_NAME}/
  DESTINATION $${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
