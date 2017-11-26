#ifndef FONT_SIZE_CALCULATOR_H
#define FONT_SIZE_CALCULATOR_H

#include <QSize>

#include <initial_widget_data.h>

class FontSizeCalculator {
 public:
  int CalculateCurrentFontSize(const QSize& current_widget_size,
                               const InitialWidgetData& initial_widget_data);

 private:
  void CalculateDeltaSize(const QSize& current_widget_size);

  QSize delta_size_;
  InitialWidgetData initial_widget_data_;

  int current_font_size_ = 0;
};

#endif  // FONT_SIZE_CALCULATOR_H
