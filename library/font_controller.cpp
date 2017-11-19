#include <font_controller.h>

#include <stdexcept>

#include <QWidget>

void FontController::SetInitialWidgetMeasurements(double font_scale_multiplier,
                                                  const QWidget& widget) {
  try {
    initial_data_.SetFontScaleMultiplier(font_scale_multiplier);
  } catch (const std::exception&) {
    throw std::logic_error("incorrect initial widget parameters");
  }
}

void FontController::ControllFontSize(QWidget* widget) {}
