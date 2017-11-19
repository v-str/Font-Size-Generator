#ifndef INITIAL_DATA_H
#define INITIAL_DATA_H

class InitialData {
 public:
  void SetInitialWidgetWidth(int initial_widget_width);
  void SetInitialWidgetHeight(int initial_widget_height);
  void SetInitialFontPixelSize(int initial_font_pixel_size);

  void SetFontScaleMultiplier(double font_scale_multiplier);

  int InitialWidgetWidth() const;
  int InitialWidgetHeight() const;
  int InitialFontPixelSize() const;
  double FontScaleMultiplier() const;

 private:
  int ReturnZeroIfInputValutNegative(int input_value) const;
  double ReturnZeroIfMultiplierNegative(double font_scale_multiplier) const;

  int initial_widget_width_ = 0;
  int initial_widget_height_ = 0;
  int initial_font_pixel_size_ = 0;
  double font_scale_multiplier_ = 1.0;
};

#endif  // INITIAL_DATA_H
