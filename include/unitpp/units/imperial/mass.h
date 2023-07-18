#pragma once

#include "unitpp/internal/mass.h"

namespace unitpp {
namespace imperial {
// source: https://en.wikipedia.org/wiki/Imperial_units#Mass_and_weight

using grains         = mass<double, std::ratio<6479891,             100000000>>;
using drachms        = mass<double, std::ratio<17718451953125, 10000000000000>>;
using ounces         = mass<double, std::ratio<28349523125,        1000000000>>;
using pounds         = mass<double, std::ratio<45359237,               100000>>;
using stones         = mass<double, std::ratio<635029318,              100000>>;
using quarters       = mass<double, std::ratio<1270058636,             100000>>;
using hundredweights = mass<double, std::ratio<5080234544,             100000>>;
using tons           = mass<double, std::ratio<10160469088,             10000>>;
using slugs          = mass<double, std::ratio<1459390294,             100000>>;
}  // namespace imperial
}  // namespace unitpp
