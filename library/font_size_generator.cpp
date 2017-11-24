#include <font_size_generator.h>

#include <stdexcept>

#include <initial_widget_data.h>

FontSizeGenerator::FontSizeGenerator(double font_scale_multiplier,
                                     const QWidget& widget) {
  try {
    InitialWidgetData::SetFontScaleMultiplier(font_scale_multiplier);
    InitialWidgetData::SetInitialWidgetWidth(widget.width());
    InitialWidgetData::SetInitialWidgetHeight(widget.height());
    InitialWidgetData::SetInitialFontPixelSize(widget.font().pixelSize());
  } catch (const std::exception& initial_data_setting_error) {
    throw std::logic_error(initial_data_setting_error.what());
  }
}

void FontSizeGenerator::GenerateFontSize(QWidget* widget) {
  if (widget == nullptr) {
    throw std::logic_error("Null pointer passed as parameter");
  }
}
