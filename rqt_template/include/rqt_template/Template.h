#pragma once

#include <rqt_gui_cpp/plugin.h>
#include <${pkg_name}/ui_${file_name}.h>

#include <ros/ros.h>

#include <QWidget>
#include <QObject>

namespace ${namespace} {

class ${class_name}
    : public rqt_gui_cpp::Plugin {

  Q_OBJECT

public:
  /**
   * @brief $class_name
   */
  ${class_name}();

  /**
   * @brief initPlugin
   * @param context
   */
  virtual void initPlugin(qt_gui_cpp::PluginContext& context);

  /**
   * @brief shutdownPlugin
   */
  virtual void shutdownPlugin();

  /**
   * @brief saveSettings
   * @param plugin_settings
   * @param instance_settings
   */
  virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings,
                            qt_gui_cpp::Settings& instance_settings) const;

  /**
   * @brief restoreSettings
   * @param plugin_settings
   * @param instance_settings
   */
  virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
                               const qt_gui_cpp::Settings& instance_settings);

protected slots:

protected:
  Ui::${class_name}Widget ui_;
  QWidget* widget_;
  ros::NodeHandle nh_;
};

} // namespace
