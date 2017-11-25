#ifndef FONT_SIZE_GENERATOR_H
#define FONT_SIZE_GENERATOR_H

#include <QFont>
#include <QRect>
#include <QWidget>

class FontSizeGenerator {
 public:
  FontSizeGenerator(double font_scale_multiplier, const QWidget& widget);

  void GenerateFontSize(QWidget* widget);

  QFont GetGeneratedFont() const;

 private:
  void CaptureWidgetParameters(const QWidget& widget);

  void AssignInitialFont(QWidget* widget);

  bool IsWidgetSidesSizeEqualInitial() const;

  QRect currect_widget_geometry_;
  QFont generated_font_;
};

#endif  // FONT_SIZE_GENERATOR_H
