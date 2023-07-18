#pragma once


#include "unitpp/internal/length.h"

namespace unitpp {
namespace si {
    
using attometres  = length<double, std::atto>;
using femtometres = length<double, std::femto>;
using picometres  = length<double, std::pico>;
using nanometres  = length<double, std::nano>;
using micrometres = length<double, std::micro>;
using millimetres = length<double, std::milli>;
using centimetres = length<double, std::centi>;
using decimetres  = length<double, std::deci>;
using metres      = length<double>;
using decametres  = length<double, std::deca>;
using hectometres = length<double, std::hecto>;
using kilometres  = length<double, std::kilo>;
using megametres  = length<double, std::mega>;
using gigametres  = length<double, std::giga>;
using terametres  = length<double, std::tera>;
using petametres  = length<double, std::peta>;
using exametres   = length<double, std::exa>;

}  // namespace si
}  // namespace unitpp
