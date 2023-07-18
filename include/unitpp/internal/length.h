#pragma once

#include <cstdint>
#include <ratio>

#include "unitpp/internal/unit.h"

namespace unitpp {

template <typename rep_, typename period_ = std::ratio<1>>
using length = unitpp::unit<rep_, period_>;

template <typename tp_>
struct __is_length : std::false_type {};

template <typename rep_, typename period_>
struct __is_length<length<rep_, period_>> : std::true_type {};

template <typename _Tp>
using __enable_if_is_length =
    typename std::enable_if<__is_length<_Tp>::value, _Tp>::type;

template <typename to_length_, typename rep_, typename period_>
constexpr __enable_if_is_length<to_length_> length_cast(
    const length<rep_, period_>& m_) {
  return unit_cast<to_length_>(m_);
}

}  // namespace unitpp