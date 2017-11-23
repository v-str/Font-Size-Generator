#ifndef INITIAL_DATA_H
#define INITIAL_DATA_H

struct InitialWidgetData {
  static void SetInitialWidgetWidth(int initial_widget_width);
  static void SetInitialWidgetHeight(int initial_widget_height);
  void SetInitialFontPixelSize(int initial_font_pixel_size);

  static void SetFontScaleMultiplier(double font_scale_multiplier);

  int InitialWidgetWidth() const;
  int InitialWidgetHeight() const;
  int InitialFontPixelSize() const;
  double FontScaleMultiplier() const;

 private:
  int ReturnZeroIfInputValutNegative(int input_value) const;
  double ReturnZeroIfMultiplierNegative(double font_scale_multiplier) const;

  static bool IsValueNegative(double value);
  static bool IsValueNegative(int value);

  static int initial_widget_width_;
  static int initial_widget_height_;
  int initial_font_pixel_size_ = -1;
  static double font_scale_multiplier_;
};

#endif  // INITIAL_DATA_H
