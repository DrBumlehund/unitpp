#pragma once

#include <cstdint>
#include <ratio>

#include "unitpp/unit.h"

namespace unitpp {

template <typename rep_, typename period_ = std::ratio<1>>
using mass = unitpp::unit<rep_, period_>;

template <typename tp_>
struct __is_mass : std::false_type {};

template <typename rep_, typename period_>
struct __is_mass<mass<rep_, period_>> : std::true_type {};

template <typename _Tp>
using __enable_if_is_mass =
    typename std::enable_if<__is_mass<_Tp>::value, _Tp>::type;

template <typename to_mass_, typename rep_, typename period_>
constexpr __enable_if_is_mass<to_mass_> mass_cast(
    const mass<rep_, period_>& m_) {
  return unit_cast<to_mass_>(m_);
}

namespace si {
using picograms = mass<int64_t, std::pico>;
using nanograms = mass<int64_t, std::nano>;
using micrograms = mass<int64_t, std::micro>;
using milligrams = mass<int64_t, std::milli>;
using grams = mass<int64_t>;
using hectograms = mass<int64_t, std::hecto>;
using kilograms = mass<int64_t, std::kilo>;
using megagrams = mass<int64_t, std::mega>;
using tonnes = megagrams;
}  // namespace si

namespace imperial {
using pounds = mass<double, std::ratio<45359237, 100000>>;
}  // namespace imperial

}  // namespace unitpp