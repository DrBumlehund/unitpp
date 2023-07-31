
#include <unitpp/units/mass.h>

#include <iostream>

using namespace unitpp;

int main() {
  auto potato_weight = si::kilograms(1);

  std::cout << "got " << potato_weight.count() << " kg potatoes\n";

  auto potato_weight_gr = cast_mass<si::grams>(potato_weight);
  std::cout << "which is " << potato_weight_gr.count() << " gr\n";

  auto potato_weight_lbs = cast_mass<imperial::pounds>(potato_weight);
  std::cout << "or " << potato_weight_lbs.count() << " lbs\n";
  return 0;
}
