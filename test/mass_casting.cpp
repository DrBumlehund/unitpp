
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "unitpp/units/imperial/mass.h"
#include "unitpp/units/si/mass.h"

using namespace unitpp;
using namespace Catch;

SCENARIO("A Kilogram can be converted into various units.") {
  GIVEN("1 kg") {
    auto kg = si::kilograms(1);
    THEN("the count is 1") { REQUIRE(kg.count() == 1); }

    WHEN("cast into grams") {
      auto grams = cast_mass<si::grams>(kg);
      THEN("the count is 1000") { REQUIRE(grams.count() == 1000); }
    }

    WHEN("cast into pounds") {
      auto pounds = cast_mass<imperial::pounds>(kg);
      THEN("the count is aproximately 2.20462262") {
        REQUIRE(pounds.count() == Approx(2.20462262));
      }
    }
  }
}

SCENARIO("imperial units can convert correctly.") {
  GIVEN("1 grains") {
    auto gr = imperial::grains(1);
    WHEN("converted to pounds") {
      auto pounds = cast_mass<imperial::pounds>(gr);
      THEN("count is 1/7000 pounds") {
        REQUIRE(pounds.count() == Approx(1.0f / 7000));
      }
    }

    WHEN("converted to milligrams") {
      auto mg = cast_mass<si::milligrams>(gr);
      THEN("count is 64.79891 mg") { REQUIRE(mg.count() == Approx(64.79891)); }
    }
  }

  GIVEN("1 drachm") {
    auto dr = imperial::drachms(1);
    WHEN("converted to pounds") {
      auto pounds = cast_mass<imperial::pounds>(dr);
      THEN("count is 1/256 pounds") {
        REQUIRE(pounds.count() == Approx(1.0f / 256));
      }
    }

    WHEN("converted to grams") {
      auto g = cast_mass<si::grams>(dr);
      THEN("count is 1.7718451953125 g") {
        REQUIRE(g.count() == Approx(1.7718451953125));
      }
    }
  }

  GIVEN("1 ounce") {
    auto oz = imperial::ounces(1);
    WHEN("converted to pounds") {
      auto pounds = cast_mass<imperial::pounds>(oz);
      THEN("count is 1/16 pounds") {
        REQUIRE(pounds.count() == Approx(1.0f / 16));
      }
    }

    WHEN("converted to grams") {
      auto g = cast_mass<si::grams>(oz);
      THEN("count is 28.349523125 g") {
        REQUIRE(g.count() == Approx(28.349523125));
      }
    }
  }

  GIVEN("1 pound") {
    auto lbs = imperial::pounds(1);

    WHEN("converted to kilograms") {
      auto kg = cast_mass<si::kilograms>(lbs);
      THEN("count is 0.45359237 kg") {
        REQUIRE(kg.count() == Approx(0.45359237));
      }
    }
  }

  GIVEN("1 stone") {
    auto st = imperial::stones(1);
    WHEN("converted to pounds") {
      auto pounds = cast_mass<imperial::pounds>(st);
      THEN("count is 14 pounds") { REQUIRE(pounds.count() == Approx(14)); }
    }

    WHEN("converted to kilograms") {
      auto kg = cast_mass<si::kilograms>(st);
      THEN("count is 6.35029318 kg") {
        REQUIRE(kg.count() == Approx(6.35029318));
      }
    }
  }

  GIVEN("1 quarter") {
    auto qr = imperial::quarters(1);
    WHEN("converted to pounds") {
      auto pounds = cast_mass<imperial::pounds>(qr);
      THEN("count is 28 pounds") { REQUIRE(pounds.count() == Approx(28)); }
    }

    WHEN("converted to kilograms") {
      auto kg = cast_mass<si::kilograms>(qr);
      THEN("count is 12.70058636 kg") {
        REQUIRE(kg.count() == Approx(12.70058636));
      }
    }
  }

  GIVEN("1 hundredweight") {
    auto cwt = imperial::hundredweights(1);
    WHEN("converted to pounds") {
      auto pounds = cast_mass<imperial::pounds>(cwt);
      THEN("count is 112 pounds") { REQUIRE(pounds.count() == Approx(112)); }
    }

    WHEN("converted to kilograms") {
      auto kg = cast_mass<si::kilograms>(cwt);
      THEN("count is 50.80234544 kg") {
        REQUIRE(kg.count() == Approx(50.80234544));
      }
    }
  }

  GIVEN("1 ton") {
    auto t = imperial::tons(1);
    WHEN("converted to pounds") {
      auto pounds = cast_mass<imperial::pounds>(t);
      THEN("count is 2240 pounds") { REQUIRE(pounds.count() == Approx(2240)); }
    }

    WHEN("converted to kilograms") {
      auto kg = cast_mass<si::kilograms>(t);
      THEN("count is 1016.0469088 kg") {
        REQUIRE(kg.count() == Approx(1016.0469088));
      }
    }
  }

  GIVEN("1 slug") {
    auto slug = imperial::slugs(1);
    WHEN("converted to pounds") {
      auto pounds = cast_mass<imperial::pounds>(slug);
      THEN("count is 32.17404856 pounds") {
        REQUIRE(pounds.count() == Approx(32.17404856));
      }
    }

    WHEN("converted to kilograms") {
      auto kg = cast_mass<si::kilograms>(slug);
      THEN("count is 14.59390294 kg") {
        REQUIRE(kg.count() == Approx(14.59390294));
      }
    }
  }
}
