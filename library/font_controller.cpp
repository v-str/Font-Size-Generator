#include <font_controller.h>

#include <stdexcept>

#include <QWidget>

void FontController::SetInitialParameters(double font_scale_multiplier,
                                          const QWidget& widget) {
  initial_data_.SetInitialWidgetWidth(widget.width());
  initial_data_.SetInitialWidgetHeight(widget.height());
  initial_data_.SetInitialFontPixelSize(widget.font().pixelSize());
  initial_data_.SetFontScaleMultiplier(font_scale_multiplier);

  if (IsInitialParametersIncorrect()) {
    throw std::logic_error("initial parameters was set incorrectly");
  }
}

void FontController::ControllFontSize(QWidget* widget) {}

bool FontController::IsInitialParametersIncorrect() const {
  if (initial_data_.FontScaleMultiplier() < 0) {
    return false;
  }

  return true;
}
