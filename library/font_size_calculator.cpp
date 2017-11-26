#include <font_size_calculator.h>

int FontSizeCalculator::CalculateCurrentFontSize(
    const QSize& current_widget_size,
    const InitialWidgetData& initial_widget_data) {
  initial_widget_data_ = initial_widget_data;

  CalculateDeltaSize(current_widget_size);

  if (delta_size_.width() >= delta_size_.height()) {
    CalculateIncrementBasedOnWidth();
  } else {
    CalculateIncrementBasedOnHeight();
  }

  CalculateFontSize();

  return current_font_size_;
}

void FontSizeCalculator::CalculateDeltaSize(const QSize& current_widget_size) {
  delta_size_.setWidth(current_widget_size.width() -
                       initial_widget_data_.InitialWidgetWidth());
  delta_size_.setHeight(current_widget_size.height() -
                        initial_widget_data_.InitialWidgetHeight());
}

void FontSizeCalculator::CalculateIncrementBasedOnWidth() {
  font_increment_ = initial_widget_data_.FontScaleMultiplier() *
                    (delta_size_.width() /
                     initial_widget_data_.InitialWidgetFont().pixelSize());
}

void FontSizeCalculator::CalculateIncrementBasedOnHeight() {
  font_increment_ = initial_widget_data_.FontScaleMultiplier() *
                    (delta_size_.height() /
                     initial_widget_data_.InitialWidgetFont().pixelSize());
}

void FontSizeCalculator::CalculateFontSize() {
  current_font_size_ =
      initial_widget_data_.InitialWidgetFont().pixelSize() + font_increment_;
}
