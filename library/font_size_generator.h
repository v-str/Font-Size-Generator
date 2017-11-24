#ifndef FONT_SIZE_GENERATOR_H
#define FONT_SIZE_GENERATOR_H

#include <QWidget>

class FontSizeGenerator {
 public:
  FontSizeGenerator(double font_scale_multiplier, const QWidget& widget);

  void GenerateFontSize(QWidget* widget);
};

#endif  // FONT_SIZE_GENERATOR_H
