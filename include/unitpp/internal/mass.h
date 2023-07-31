#pragma once

#include <cstdint>
#include <ratio>

#include "unitpp/internal/unit.h"

namespace unitpp {

template <typename rep_, typename period_ = std::ratio<1>>
struct mass : public unitpp::unit<rep_, period_> {
  UNITPP_BASIC_MEM_FUNCS(mass);
};

UNITPP_BASIC_FUNCS(mass);

}  // namespace unitpp