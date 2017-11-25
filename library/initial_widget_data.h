#ifndef INITIAL_DATA_H
#define INITIAL_DATA_H

#include <string>

#include <QFont>

struct InitialWidgetData {
  static void SetFontScaleMultiplier(double font_scale_multiplier);
  static void SetInitialWidgetWidth(int initial_widget_width);
  static void SetInitialWidgetHeight(int initial_widget_height);
  static void SetInitialWidgetFont(const QFont& font);

  static double FontScaleMultiplier();
  static int InitialWidgetWidth();
  static int InitialWidgetHeight();
  static QFont InitialWidgetFont();

 private:
  static bool IsValueNegative(double value);
  static bool IsValueNegative(int value);

  static double font_scale_multiplier_;
  static int initial_widget_width_;
  static int initial_widget_height_;
  static QFont initial_widget_font_;

  static std::string error_text_;
};

#endif  // INITIAL_DATA_H
