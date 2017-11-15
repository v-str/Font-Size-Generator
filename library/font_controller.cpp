#include <font_controller.h>

#include <QWidget>

void FontController::SetInitialWidgetMeasurements(double font_scale_multiplier,
                                                  const QWidget& widget) {
  initial_data_.SetInitialWidgetWidth(widget.width());
  initial_data_.SetInitialWidgetHeight(widget.height());
  initial_data_.SetInitialFontPixelSize(widget.font().pixelSize());
  initial_data_.SetFontScaleMultiplier(font_scale_multiplier);
  widget_font_ = widget.font();
}

void FontController::ControllFontSize(QWidget* widget) {}
