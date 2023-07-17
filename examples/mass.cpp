#include <unitpp/si/mass.h>

#include <iostream>

int main() {
  unitpp::si::kilograms potato_weight(2);

  std::cout << "got " << potato_weight.count() << " kg potatoes\n";

  std::cout << "which is "
            << unitpp::mass_cast<unitpp::si::grams>(potato_weight).count()
            << " grams\n";

  std::cout
      << "or "
      << unitpp::mass_cast<unitpp::imperial::pounds>(potato_weight).count()
      << " pounds\n";
  return 0;
}
