#pragma once

#include "unitpp/internal/length.h"

namespace unitpp {
namespace imperial {
// source: https://en.wikipedia.org/wiki/Imperial_units#Length

using hand = length<double, std::ratio<1016, 10000>>;
using feet = length<double, std::ratio<3048, 10000>>;
using yards = length<double, std::ratio<9144, 10000>>;
using miles = length<double, std::ratio<1609344, 1000>>;

}  // namespace imperial
}  // namespace unitpp
