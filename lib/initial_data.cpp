#include <initial_data.h>

#include <stdexcept>

void InitialData::SetInitialWidgetWidth(int initial_widget_width) {
  initial_widget_width_ = CheckOnNegativeValue(initial_widget_width);
}

void InitialData::SetInitialWidgetHeight(int initial_widget_height) {
  initial_widget_height_ = CheckOnNegativeValue(initial_widget_height);
}

void InitialData::SetInitialFontPixelSize(int initial_font_pixel_size) {
  initial_font_pixel_size_ = CheckOnNegativeValue(initial_font_pixel_size);
}

int InitialData::InitialWidgetWidth() const { return initial_widget_width_; }

int InitialData::CheckOnNegativeValue(int input_value) {
  if (input_value <= 0) {
    throw std::logic_error("The widget sides size should be greater than 0");
  }
  return input_value;
}
