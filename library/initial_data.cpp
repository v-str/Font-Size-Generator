#include <initial_data.h>

#include <stdexcept>

void InitialData::SetInitialWidgetWidth(int initial_widget_width) {
  initial_widget_width_ = ReturnZeroIfInputValutNegative(initial_widget_width);
}

void InitialData::SetInitialWidgetHeight(int initial_widget_height) {
  initial_widget_height_ =
      ReturnZeroIfInputValutNegative(initial_widget_height);
}

void InitialData::SetInitialFontPixelSize(int initial_font_pixel_size) {
  initial_font_pixel_size_ =
      ReturnZeroIfInputValutNegative(initial_font_pixel_size);
}

void InitialData::SetFontScaleMultiplier(double font_scale_multiplier) {
  font_scale_multiplier_ =
      ReturnZeroIfMultiplierNegative(font_scale_multiplier);
}

int InitialData::InitialWidgetWidth() const { return initial_widget_width_; }

int InitialData::InitialWidgetHeight() const { return initial_widget_height_; }

int InitialData::InitialFontPixelSize() const {
  return initial_font_pixel_size_;
}

double InitialData::FontScaleMultiplier() const {
  return font_scale_multiplier_;
}

int InitialData::ReturnZeroIfInputValutNegative(int input_value) const {
  return input_value < 0 ? 0 : input_value;
}

double InitialData::ReturnZeroIfMultiplierNegative(
    double font_scale_multiplier) const {
  return font_scale_multiplier < 0.0 ? 0.0 : font_scale_multiplier;
}
