#include <font_size_calculator.h>

int FontSizeCalculator::CalculateCurrentFontSize(
    const QSize& current_widget_size,
    const InitialWidgetData& initial_widget_data) {
  initial_widget_data_ = initial_widget_data;

  if (IsCurrentSizeLessThenInitial(current_widget_size)) {
    return initial_widget_data_.InitialWidgetFont().pixelSize();
  }

  CalculateDeltaSize(current_widget_size);

  if (delta_size_.width() >= delta_size_.height()) {
    CalculateIncrementBasedOnWidth();
  } else {
    CalculateIncrementBasedOnHeight();
  }

  return GetFontSize();
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

bool FontSizeCalculator::IsCurrentSizeLessThenInitial(
    const QSize& current_widget_size) {
  return current_widget_size.width() <
         initial_widget_data_.InitialWidgetWidth();
}

int FontSizeCalculator::GetFontSize() {
  return initial_widget_data_.InitialWidgetFont().pixelSize() + font_increment_;
}
