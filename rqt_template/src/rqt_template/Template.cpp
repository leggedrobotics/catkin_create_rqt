#include "${pkg_name}/${class_name}.h"

#include <pluginlib/class_list_macros.h>

namespace ${namespace} {

${class_name}::${class_name}()
    : rqt_gui_cpp::Plugin()
    , widget_(0) {

  setObjectName("${class_name}");
}

void ${class_name}::initPlugin(qt_gui_cpp::PluginContext& context) {
  widget_ = new QWidget();
  ui_.setupUi(widget_);
  if (context.serialNumber() > 1) {
    widget_->setWindowTitle(widget_->windowTitle() +
        " (" + QString::number(context.serialNumber()) + ")");
  }
  context.addWidget(widget_);
}

void ${class_name}::shutdownPlugin() {
}

void ${class_name}::saveSettings(qt_gui_cpp::Settings& plugin_settings,
                                 qt_gui_cpp::Settings& instance_settings) const {
}

void ${class_name}::restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
                                    const qt_gui_cpp::Settings& instance_settings) {
}

} // namespace

PLUGINLIB_EXPORT_CLASS(${namespace}::${class_name}, rqt_gui_cpp::Plugin)
