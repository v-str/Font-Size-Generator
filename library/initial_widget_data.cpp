#include <initial_widget_data.h>

#include <stdexcept>

double InitialWidgetData::font_scale_multiplier_ = 0.0;
int InitialWidgetData::initial_widget_width_ = 0;
int InitialWidgetData::initial_widget_height_ = 0;
int InitialWidgetData::initial_font_pixel_size_ = 0;
std::string InitialWidgetData::error_text_ =
    "negative value passed as parameter";

void InitialWidgetData::SetInitialWidgetWidth(int initial_widget_width) {
  if (IsValueNegative(initial_widget_width)) {
    throw std::logic_error(error_text_);
  }
  initial_widget_width_ = initial_widget_width;
}

void InitialWidgetData::SetInitialWidgetHeight(int initial_widget_height) {
  if (IsValueNegative(initial_widget_height)) {
    throw std::logic_error(error_text_);
  }
  initial_widget_height_ = initial_widget_height;
}

void InitialWidgetData::SetInitialFontPixelSize(int initial_font_pixel_size) {
  if (IsValueNegative(initial_font_pixel_size)) {
    throw std::logic_error(error_text_);
  }
  initial_font_pixel_size_ = initial_font_pixel_size;
}

void InitialWidgetData::SetFontScaleMultiplier(double font_scale_multiplier) {
  if (IsValueNegative(font_scale_multiplier)) {
    throw std::logic_error(error_text_);
  }
  font_scale_multiplier_ = font_scale_multiplier;
}

bool InitialWidgetData::IsValueNegative(double value) { return value < 0.0; }

bool InitialWidgetData::IsValueNegative(int value) { return value < 0; }
