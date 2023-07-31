#pragma once

#include <cstdint>
#include <ratio>

#include "unitpp/internal/unit.h"

namespace unitpp {

template <typename rep_, typename period_ = std::ratio<1>>
struct length : public unitpp::unit<rep_, period_> {
  UNITPP_BASIC_MEM_FUNCS(length);
};

UNITPP_BASIC_FUNCS(length);

}  // namespace unitpp