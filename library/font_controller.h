#ifndef FONT_CONTROLLER_H
#define FONT_CONTROLLER_H

#include <QFont>
#include <QRect>

#include <initial_data.h>

class QWidget;

class FontController {
 public:
  void SetInitialWidgetMeasurements(double font_scale_multiplier,
                                    const QWidget& widget);

 private:
  InitialData initial_data_;
  QFont widget_font_;
  QRect widget_geometry_;

  int width_font_increment_ = 0;
  int height_font_increment_ = 0;
};

#endif  // FONT_CONTROLLER_H
