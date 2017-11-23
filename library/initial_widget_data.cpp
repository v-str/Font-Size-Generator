#include <initial_widget_data.h>

#include <stdexcept>

double InitialWidgetData::font_scale_multiplier_ = 0.0;
int InitialWidgetData::initial_widget_width_ = 0;
int InitialWidgetData::initial_widget_height_ = 0;

void InitialWidgetData::SetInitialWidgetWidth(int initial_widget_width) {
  if (IsValueNegative(initial_widget_width)) {
    throw std::logic_error("negative value passed as parameter");
  }
  initial_widget_width_ = initial_widget_width;
}

void InitialWidgetData::SetInitialWidgetHeight(int initial_widget_height) {
  if (IsValueNegative(initial_widget_height)) {
    throw std::logic_error("negative value passed as parameter");
  }
  initial_widget_height_ = initial_widget_height;
}

void InitialWidgetData::SetInitialFontPixelSize(int initial_font_pixel_size) {
  if (IsValueNegative(initial_font_pixel_size)) {
    throw std::logic_error("Negative parameter");
  }
  initial_font_pixel_size_ = initial_font_pixel_size;
}

void InitialWidgetData::SetFontScaleMultiplier(double font_scale_multiplier) {
  if (IsValueNegative(font_scale_multiplier)) {
    throw std::logic_error("negative value passed as parameter");
  }
  font_scale_multiplier_ = font_scale_multiplier;
}

int InitialWidgetData::InitialWidgetWidth() const {
  return initial_widget_width_;
}

int InitialWidgetData::InitialWidgetHeight() const {
  return initial_widget_height_;
}

int InitialWidgetData::InitialFontPixelSize() const {
  return initial_font_pixel_size_;
}

double InitialWidgetData::FontScaleMultiplier() const {
  return font_scale_multiplier_;
}

int InitialWidgetData::ReturnZeroIfInputValutNegative(int input_value) const {
  return input_value < 0 ? 0 : input_value;
}

double InitialWidgetData::ReturnZeroIfMultiplierNegative(
    double font_scale_multiplier) const {
  return font_scale_multiplier < 0.0 ? 0.0 : font_scale_multiplier;
}

bool InitialWidgetData::IsValueNegative(double value) { return value < 0.0; }

bool InitialWidgetData::IsValueNegative(int value) { return value < 0; }
