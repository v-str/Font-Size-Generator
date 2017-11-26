#include <font_size_calculator.h>

int FontSizeCalculator::CalculateCurrentFontSize(
    const QSize& current_widget_size,
    const InitialWidgetData& initial_widget_data) {
  initial_widget_data_ = initial_widget_data;

  CalculateDeltaSize(current_widget_size);

  if (delta_size_.width() >= delta_size_.height()) {
    // CalculateFontByBasedOnWidth
  } else {
    // CalculateFontBasedOnHeight
  }

  return current_font_size_ = 20;
}

void FontSizeCalculator::CalculateDeltaSize(const QSize& current_widget_size) {
  delta_size_.setWidth(current_widget_size.width() -
                       initial_widget_data_.InitialWidgetWidth());
  delta_size_.setHeight(current_widget_size.height() -
                        initial_widget_data_.InitialWidgetHeight());
}
