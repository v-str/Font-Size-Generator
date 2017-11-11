#include <initial_data.h>

void InitialData::SetInitialWidgetWidth(int initial_widget_width) {}

int InitialData::InitialWidgetWidth() const { return initial_widget_width_; }

bool InitialData::IsInputValuePositive(int input_value) const {
  return input_value > 0;
}
