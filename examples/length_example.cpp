
#include <unitpp/units/imperial/length.h>
#include <unitpp/units/si/length.h>

#include <iostream>

using namespace unitpp;

int main() {
  auto distance_km = si::kilometres(12);

  std::cout << "i have " << distance_km.count() << " km to work\n";

  auto distance_m = cast_length<si::metres>(distance_km);
  std::cout << "which is " << distance_m.count() << " m\n";

  auto distance_mi = cast_length<imperial::miles>(distance_km);
  std::cout << "or " << distance_mi.count() << " mi\n";
  return 0;
}
