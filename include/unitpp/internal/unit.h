#pragma once

#include <limits>
#include <ratio>
#include <type_traits>

namespace unitpp {

//
// forward declarations
//
template <typename rep_, typename period_ = std::ratio<1>>
struct unit;

}  // namespace unitpp

template <typename _CT, typename period1_, typename period2_, typename = void>
struct __unit_wrapper_common_type {};

template <typename _CT, typename period1_, typename period2_>
struct __unit_wrapper_common_type<_CT, period1_, period2_,
                                  std::__void_t<typename _CT::type>> {
 private:
  using __gcd_num = std::__static_gcd<period1_::num, period2_::num>;
  using __gcd_den = std::__static_gcd<period1_::den, period2_::den>;
  using __cr = typename _CT::type;
  using __r = std::ratio<__gcd_num::value,
                         (period1_::den / __gcd_den::value) * period2_::den>;

 public:
  using type = unitpp::unit<__cr, typename __r::type>;
};

namespace std {

/// Specialization of common_type for unitpp::unit types.
template <typename rep1_, typename period1_, typename rep2_, typename period2_>
struct common_type<unitpp::unit<rep1_, period1_>, unitpp::unit<rep2_, period2_>>
    : __unit_wrapper_common_type<common_type<rep1_, rep2_>,
                                 typename period1_::type,
                                 typename period2_::type> {};

/// Specialization of common_type for two identical unitpp::unit types.
template <typename rep_, typename period_>
struct common_type<unitpp::unit<rep_, period_>, unitpp::unit<rep_, period_>> {
  using type =
      unitpp::unit<typename common_type<rep_>::type, typename period_::type>;
};

/// Specialization of common_type for one unitpp::unit type.
template <typename rep_, typename period_>
struct common_type<unitpp::unit<rep_, period_>> {
  using type =
      unitpp::unit<typename common_type<rep_>::type, typename period_::type>;
};

}  // namespace std

namespace unitpp {

template <typename to_unit_, typename _CF, typename _CR, bool _NumIsOne = false,
          bool _DenIsOne = false>
struct __unit_cast_impl {
  template <typename rep_, typename period_>
  static constexpr to_unit_ __cast(const unit<rep_, period_>& __d) {
    typedef typename to_unit_::rep __to_rep;
    return to_unit_(static_cast<__to_rep>(static_cast<_CR>(__d.count()) *
                                          static_cast<_CR>(_CF::num) /
                                          static_cast<_CR>(_CF::den)));
  }
};

template <typename to_unit_, typename _CF, typename _CR>
struct __unit_cast_impl<to_unit_, _CF, _CR, true, true> {
  template <typename rep_, typename period_>
  static constexpr to_unit_ __cast(const unit<rep_, period_>& __d) {
    typedef typename to_unit_::rep __to_rep;
    return to_unit_(static_cast<__to_rep>(__d.count()));
  }
};

template <typename to_unit_, typename _CF, typename _CR>
struct __unit_cast_impl<to_unit_, _CF, _CR, true, false> {
  template <typename rep_, typename period_>
  static constexpr to_unit_ __cast(const unit<rep_, period_>& __d) {
    typedef typename to_unit_::rep __to_rep;
    return to_unit_(static_cast<__to_rep>(static_cast<_CR>(__d.count()) /
                                          static_cast<_CR>(_CF::den)));
  }
};

template <typename to_unit_, typename _CF, typename _CR>
struct __unit_cast_impl<to_unit_, _CF, _CR, false, true> {
  template <typename rep_, typename period_>
  static constexpr to_unit_ __cast(const unit<rep_, period_>& __d) {
    typedef typename to_unit_::rep __to_rep;
    return to_unit_(static_cast<__to_rep>(static_cast<_CR>(__d.count()) *
                                          static_cast<_CR>(_CF::num)));
  }
};

template <typename _Tp>
struct __is_unit : std::false_type {};

template <typename rep_, typename period_>
struct __is_unit<unit<rep_, period_>> : std::true_type {};

template <typename _Tp>
using __enable_if_is_unit =
    typename std::enable_if<__is_unit<_Tp>::value, _Tp>::type;

template <typename _Tp>
using __disable_if_is_unit =
    typename std::enable_if<!__is_unit<_Tp>::value, _Tp>::type;

/// unit_cast
template <typename to_unit_, typename rep_, typename period_>
constexpr __enable_if_is_unit<to_unit_> unit_cast(
    const unit<rep_, period_>& __d) {
  typedef typename to_unit_::period __to_period;
  typedef typename to_unit_::rep __to_rep;
  typedef std::ratio_divide<period_, __to_period> __cf;
  typedef typename std::common_type<__to_rep, rep_, intmax_t>::type __cr;
  typedef __unit_cast_impl<to_unit_, __cf, __cr, __cf::num == 1, __cf::den == 1>
      __dc;
  return __dc::__cast(__d);
}

/// treat_as_floating_point
template <typename rep_>
struct treat_as_floating_point : std::is_floating_point<rep_> {};

//
// unit_values
//
template <typename rep_>
struct unit_values {
  static constexpr rep_ zero() noexcept { return rep_(0); }
  static constexpr rep_ max() noexcept {
    return std::numeric_limits<rep_>::max();
  }
  static constexpr rep_ min() noexcept {
    return std::numeric_limits<rep_>::lowest();
  }
};

//
// is_ratio static check
//
template <typename tp_>
struct is_ratio : std::false_type {};

template <intmax_t num_, intmax_t den_>
struct is_ratio<std::ratio<num_, den_>> : std::true_type {};

//
// unit wrapper
//
template <typename rep_, typename period_>
struct unit {
 private:
  template <typename rep2_>
  using __is_float = treat_as_floating_point<rep2_>;

  template <typename r1_, typename r2_,
            intmax_t __gcd1 = _S_gcd(r1_::num, r2_::num),
            intmax_t __gcd2 = _S_gcd(r1_::den, r2_::den)>
  using __divide = std::ratio<(r1_::num / __gcd1) * (r2_::den / __gcd2),
                              (r1_::den / __gcd2) * (r2_::num / __gcd1)>;

  // period2_ is an exact multiple of period_
  template <typename period2_>
  using __is_harmonic =
      std::__bool_constant<__divide<period2_, period_>::den == 1>;

 public:
  using rep = rep_;
  using period = typename period_::type;

  static_assert(is_ratio<period_>::value,
                "period must be a specialization of ratio");
  static_assert(period_::num > 0, "period must be positive");

  constexpr unit() = default;
  constexpr unit(const unit&) = default;

  template <typename rep2_,
            typename = std::_Require<
                std::is_convertible<const rep2_&, rep>,
                std::__or_<__is_float<rep>, std::__not_<__is_float<rep2_>>>>>
  constexpr explicit unit(const rep2_& __rep) : r_(static_cast<rep>(__rep)) {}

  template <typename rep2_, typename period2_,
            typename = std::_Require<
                std::is_convertible<const rep2_&, rep>,
                std::__or_<__is_float<rep>,
                           std::__and_<__is_harmonic<period2_>,
                                       std::__not_<__is_float<rep2_>>>>>>
  constexpr unit(const unit<rep2_, period2_>& u_)
      : r_(unit_cast<unit>(u_).count()) {}

  ~unit() = default;
  unit& operator=(const unit&) = default;

  constexpr rep count() const { return r_; }

  constexpr unit<typename std::common_type<rep>::type, period> operator+()
      const {
    return unit<typename std::common_type<rep>::type, period>(r_);
  }

  constexpr unit<typename std::common_type<rep>::type, period> operator-()
      const {
    return unit<typename std::common_type<rep>::type, period>(-r_);
  }

  constexpr unit& operator++() {
    ++r_;
    return *this;
  }

  constexpr unit operator++(int) { return unit(r_++); }

  constexpr unit& operator--() {
    --r_;
    return *this;
  }

  constexpr unit operator--(int) { return unit(r_--); }

  constexpr unit& operator+=(const unit& u_) {
    r_ += u_.count();
    return *this;
  }

  constexpr unit& operator-=(const unit& u_) {
    r_ -= u_.count();
    return *this;
  }

  constexpr unit& operator*=(const rep& rhs_) {
    r_ *= rhs_;
    return *this;
  }

  constexpr unit& operator/=(const rep& rhs_) {
    r_ /= rhs_;
    return *this;
  }

  static constexpr unit zero() noexcept {
    return unit(unit_values<rep>::zero());
  }

  static constexpr unit min() noexcept { return unit(unit_values<rep>::min()); }

  static constexpr unit max() noexcept { return unit(unit_values<rep>::max()); }

 private:
  rep r_;
};

#define UNITPP_BASIC_MEM_FUNCS(unit_name)                         \
  using unit_t = unitpp::unit<rep_, period_>;                     \
  template <typename rep2_, typename period2_>                    \
  constexpr unit_name(const unitpp::unit<rep2_, period2_>& u_)    \
      : unitpp::unit<rep_, period_>::unit(u_) {}                  \
                                                                  \
  template <typename rep2_, typename period2_>                    \
  unit_name& operator=(const unitpp::unit<rep2_, period2_>& u_) { \
    unitpp::unit<rep_, period_>::operator=(u_);                   \
    return *this;                                                 \
  }                                                               \
  using unitpp::unit<rep_, period_>::unit;                        \
  using unitpp::unit<rep_, period_>::operator=;                   \
  using unitpp::unit<rep_, period_>::operator++;                  \
  using unitpp::unit<rep_, period_>::operator--;                  \
  using unitpp::unit<rep_, period_>::operator+=;                  \
  using unitpp::unit<rep_, period_>::operator-=;                  \
  using unitpp::unit<rep_, period_>::operator*=;                  \
  using unitpp::unit<rep_, period_>::operator/=;

#define UNITPP_BASIC_FUNCS(unit_name)                                    \
  template <typename tp_>                                                \
  struct __is_##unit_name : std::false_type {};                          \
                                                                         \
  template <typename rep_, typename period_>                             \
  struct __is_##unit_name<unit_name<rep_, period_>> : std::true_type {}; \
                                                                         \
  template <typename _Tp>                                                \
  using __enable_if_is_##unit_name =                                     \
      typename std::enable_if<__is_##unit_name<_Tp>::value, _Tp>::type;  \
                                                                         \
  template <typename to_unit_, typename rep_, typename period_>          \
  constexpr __enable_if_is_##unit_name<to_unit_> cast_##unit_name(       \
      const unit_name<rep_, period_>& m_) {                              \
    return unit_cast<typename to_unit_::unit_t>(m_);                     \
  }

}  // namespace unitpp