#include <font_size_generator.h>

#include <stdexcept>

#include <initial_widget_data.h>

FontSizeGenerator::FontSizeGenerator(double font_scale_multiplier,
                                     const QWidget& widget) {
  InitialWidgetData::SetFontScaleMultiplier(font_scale_multiplier);
  InitialWidgetData::SetInitialWidgetWidth(widget.width());
  InitialWidgetData::SetInitialWidgetHeight(widget.height());
  InitialWidgetData::SetInitialWidgetFont(widget.font());
}

void FontSizeGenerator::GenerateFontSize(QWidget* widget) {
  if (widget == nullptr) {
    throw std::logic_error("Null pointer passed as parameter");
  } else {
    CaptureWidgetParameters(*widget);
  }

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
  generated_font_ = InitialWidgetData::InitialWidgetFont();
  widget->setFont(generated_font_);
}

bool FontSizeGenerator::IsWidgetSidesSizeEqualInitial() const {
  return currect_widget_geometry_.width() ==
             InitialWidgetData::InitialWidgetWidth() ||
         currect_widget_geometry_.height() ==
             InitialWidgetData::InitialWidgetHeight();
}
