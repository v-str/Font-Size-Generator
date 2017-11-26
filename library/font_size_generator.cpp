#include <font_size_generator.h>

#include <stdexcept>

FontSizeGenerator::FontSizeGenerator(double font_scale_multiplier,
                                     const QWidget& widget) {
  initial_widget_data_.SetFontScaleMultiplier(font_scale_multiplier);
  initial_widget_data_.SetInitialWidgetWidth(widget.width());
  initial_widget_data_.SetInitialWidgetHeight(widget.height());
  initial_widget_data_.SetInitialWidgetFont(widget.font());
}

void FontSizeGenerator::GenerateFontSize(QWidget* widget) {
  if (!widget) {
    throw std::logic_error("Null pointer passed as parameter");
  }

  CaptureWidgetParameters(*widget);

  if (IsWidgetSidesSizeEqualInitial()) {
    AssignInitialFont(widget);
  }
}

QFont FontSizeGenerator::GetGeneratedFont() const { return generated_font_; }

void FontSizeGenerator::CaptureWidgetParameters(const QWidget& widget) {
  currect_widget_geometry_ = widget.geometry();
  generated_font_ = widget.font();
}

void FontSizeGenerator::AssignInitialFont(QWidget* widget) {
  generated_font_ = initial_widget_data_.InitialWidgetFont();
  widget->setFont(generated_font_);
}

bool FontSizeGenerator::IsWidgetSidesSizeEqualInitial() const {
  return currect_widget_geometry_.width() ==
             initial_widget_data_.InitialWidgetWidth() ||
         currect_widget_geometry_.height() ==
             initial_widget_data_.InitialWidgetHeight();
}
