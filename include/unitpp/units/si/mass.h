#pragma once

#include "unitpp/internal/mass.h"

namespace unitpp {
namespace si {
// source https://en.wikipedia.org/wiki/Kilogram#SI_multiples
    
using attograms  = mass<double, std::atto>;
using femtograms = mass<double, std::femto>;
using picograms  = mass<double, std::pico>;
using nanograms  = mass<double, std::nano>;
using micrograms = mass<double, std::micro>;
using milligrams = mass<double, std::milli>;
using centigrams = mass<double, std::centi>;
using decigrams  = mass<double, std::deci>;
using grams      = mass<double>;
using decagrams  = mass<double, std::deca>;
using hectograms = mass<double, std::hecto>;
using kilograms  = mass<double, std::kilo>;
using megagrams  = mass<double, std::mega>;
using gigagrams  = mass<double, std::giga>;
using teragrams  = mass<double, std::tera>;
using petagrams  = mass<double, std::peta>;
using exagrams   = mass<double, std::exa>;

using tonnes     = megagrams;
using megatonnes = gigagrams;
}  // namespace si
}  // namespace unitpp
