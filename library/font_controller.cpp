#include <font_controller.h>

#include <stdexcept>

#include <QWidget>

void FontController::SetInitialParameters(double font_scale_multiplier,
                                          const QWidget& widget) {
  try {
    initial_data_.SetFontScaleMultiplier(font_scale_multiplier);
    initial_data_.SetInitialWidgetWidth(widget.width());
    initial_data_.SetInitialWidgetHeight(widget.height());
  } catch (const std::exception&) {
    throw std::logic_error("incorrect initial widget parameters");
  }
}

void FontController::ControllFontSize(QWidget* widget) {}
