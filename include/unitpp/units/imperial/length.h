#pragma once

#include "unitpp/internal/length.h"

namespace unitpp {
namespace imperial {
// source: https://en.wikipedia.org/wiki/Imperial_units#Length

using twips = length<double, std::ratio<176389, 10000000000>>;
using thous = length<double, std::ratio<254, 10000000>>;
using barleycorns = length<double, std::ratio<84667, 10000000>>;
using inches = length<double, std::ratio<254, 10000>>;
using hands = length<double, std::ratio<1016, 10000>>;
using feet = length<double, std::ratio<3048, 10000>>;
using yards = length<double, std::ratio<9144, 10000>>;
using chains = length<double, std::ratio<201168, 10000>>;
using furlongs = length<double, std::ratio<201168, 1000>>;
using miles = length<double, std::ratio<1609344, 1000>>;
using leagues = length<double, std::ratio<4828032, 1000>>;

}  // namespace imperial
}  // namespace unitpp
