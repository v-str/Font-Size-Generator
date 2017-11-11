#ifndef INITIAL_DATA_H
#define INITIAL_DATA_H

class InitialData {
 public:
  void SetInitialWidgetWidth(int initial_widget_width);

  int InitialWidgetWidth() const;

 private:
  bool IsInputValuePositive(int input_value) const;

  int initial_widget_width_ = 0;
  int initial_widget_height_ = 0;
  int initial_font_pixel_size_ = 0;
  double font_scale_multiplier_ = 1.0;
};

#endif  // INITIAL_DATA_H
