#include <font_size_generator.h>

#include <stdexcept>

FontSizeGenerator::FontSizeGenerator(int initial_widget_font_pixel_size,
                                     double font_scale_coefficient,
                                     const QSize& initial_widget_size) {
  if (initial_widget_font_pixel_size < 0.0) {
    throw std::logic_error("font pixel cannot be negative");
  }
}
