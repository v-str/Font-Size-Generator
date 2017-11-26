﻿#ifndef FONT_SIZE_CALCULATOR_H
#define FONT_SIZE_CALCULATOR_H

#include <QSize>

#include <initial_widget_data.h>

class FontSizeCalculator {
 public:
  int CalculateCurrentFontSize(const QSize& current_widget_size,
                               const InitialWidgetData& initial_widget_data);

 private:
  void CalculateDeltaSize(const QSize& current_widget_size);
  void CalculateIncrementBasedOnWidth();
  void CalculateIncrementBasedOnHeight();

  bool IsCurrentSizeLessThenInitial(const QSize& current_widget_size);

  int GetFontSize();

  QSize delta_size_;
  InitialWidgetData initial_widget_data_;

  double font_increment_ = 0.0;
  int current_font_size_ = 0;
};

#endif  // FONT_SIZE_CALCULATOR_H