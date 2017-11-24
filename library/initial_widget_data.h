﻿#ifndef INITIAL_DATA_H
#define INITIAL_DATA_H

#include <string>

struct InitialWidgetData {
  static void SetInitialWidgetWidth(int initial_widget_width);
  static void SetInitialWidgetHeight(int initial_widget_height);
  static void SetInitialFontPixelSize(int initial_font_pixel_size);

  static void SetFontScaleMultiplier(double font_scale_multiplier);

 private:
  static bool IsValueNegative(double value);
  static bool IsValueNegative(int value);

  static int initial_widget_width_;
  static int initial_widget_height_;
  static int initial_font_pixel_size_;
  static double font_scale_multiplier_;

  static std::string error_text_;
};

#endif  // INITIAL_DATA_H
