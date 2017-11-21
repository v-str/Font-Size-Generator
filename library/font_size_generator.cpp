#include <font_size_generator.h>

FontSizeGenerator::FontSizeGenerator(int initial_widget_font_pixel_size,
                                     double font_scale_coefficient,
                                     const QSize& initial_widget_size) {}

int FontSizeGenerator::GenerateCurrentFontSize(
    const QSize& current_widget_size) const {
  return 25;
}
