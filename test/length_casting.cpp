
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "unitpp/units/length.h"

using namespace unitpp;
using namespace Catch;

SCENARIO("A Kilometre can be converted into various units.") {
  GIVEN("1 km") {
    auto km = si::kilometres(1);
    THEN("the count is 1") { REQUIRE(km.count() == 1); }

    WHEN("cast into metres") {
      auto metres = cast_length<si::metres>(km);
      THEN("the count is 1000") { REQUIRE(metres.count() == 1000); }
    }

    WHEN("cast into feet") {
      auto feet = cast_length<imperial::feet>(km);
      THEN("the count is aproximately 3.2808399") {
        REQUIRE(feet.count() == Approx(3280.8399));
      }
    }
  }
}

SCENARIO("imperial length units can convert correctly.") {
  GIVEN("1 twip") {
    auto twips = imperial::twips(1);
    WHEN("converted to feet") {
      auto feet = cast_length<imperial::feet>(twips);
      THEN("count is 1/17280 feet") {
        REQUIRE(feet.count() == Approx(1.0f / 17280));
      }
    }

    WHEN("converted to metres") {
      auto metres = cast_length<si::metres>(twips);
      THEN("count is 0.0000176389 m") {
        REQUIRE(metres.count() == Approx(0.0000176389));
      }
    }
  }

  GIVEN("1 thou") {
    auto thous = imperial::thous(1);
    WHEN("converted to feet") {
      auto feet = cast_length<imperial::feet>(thous);
      THEN("count is 1/12000 feet") {
        REQUIRE(feet.count() == Approx(1.0f / 12000));
      }
    }

    WHEN("converted to metres") {
      auto metres = cast_length<si::metres>(thous);
      THEN("count is 0.0000254 m") {
        REQUIRE(metres.count() == Approx(0.0000254));
      }
    }
  }

  GIVEN("1 barleycorns") {
    auto barleycorns = imperial::barleycorns(1);
    WHEN("converted to feet") {
      auto feet = cast_length<imperial::feet>(barleycorns);
      THEN("count is 1/36 feet") { REQUIRE(feet.count() == Approx(1.0f / 36)); }
    }

    WHEN("converted to metres") {
      auto metres = cast_length<si::metres>(barleycorns);
      THEN("count is 0.0084667 m") {
        REQUIRE(metres.count() == Approx(0.0084667));
      }
    }
  }

  GIVEN("1 inch") {
    auto inches = imperial::inches(1);
    WHEN("converted to feet") {
      auto feet = cast_length<imperial::feet>(inches);
      THEN("count is 1/12 feet") { REQUIRE(feet.count() == Approx(1.0f / 12)); }
    }

    WHEN("converted to metres") {
      auto metres = cast_length<si::metres>(inches);
      THEN("count is 0.0254 m") { REQUIRE(metres.count() == Approx(0.0254)); }
    }
  }

  GIVEN("1 hand") {
    auto hands = imperial::hands(1);
    WHEN("converted to feet") {
      auto feet = cast_length<imperial::feet>(hands);
      THEN("count is 1/3 feet") { REQUIRE(feet.count() == Approx(1.0f / 3)); }
    }

    WHEN("converted to metres") {
      auto metres = cast_length<si::metres>(hands);
      THEN("count is 0.1016 m") { REQUIRE(metres.count() == Approx(0.1016)); }
    }
  }

  GIVEN("1 feet") {
    auto feet = imperial::feet(1);

    WHEN("converted to metres") {
      auto metres = cast_length<si::metres>(feet);
      THEN("count is 0.3048 m") { REQUIRE(metres.count() == Approx(0.3048)); }
    }
  }

  GIVEN("1 yard") {
    auto yards = imperial::yards(1);
    WHEN("converted to feet") {
      auto feet = cast_length<imperial::feet>(yards);
      THEN("count is 3 feet") { REQUIRE(feet.count() == 3); }
    }

    WHEN("converted to metres") {
      auto metres = cast_length<si::metres>(yards);
      THEN("count is 0.9144 m") { REQUIRE(metres.count() == Approx(0.9144)); }
    }
  }

  GIVEN("1 chain") {
    auto chains = imperial::chains(1);
    WHEN("converted to feet") {
      auto feet = cast_length<imperial::feet>(chains);
      THEN("count is 66 feet") { REQUIRE(feet.count() == 66); }
    }

    WHEN("converted to metres") {
      auto metres = cast_length<si::metres>(chains);
      THEN("count is 20.1168 m") { REQUIRE(metres.count() == Approx(20.1168)); }
    }
  }

  GIVEN("1 furlong") {
    auto furlongs = imperial::furlongs(1);
    WHEN("converted to feet") {
      auto feet = cast_length<imperial::feet>(furlongs);
      THEN("count is 660 feet") { REQUIRE(feet.count() == 660); }
    }

    WHEN("converted to metres") {
      auto metres = cast_length<si::metres>(furlongs);
      THEN("count is 201.168 m") { REQUIRE(metres.count() == Approx(201.168)); }
    }
  }

  GIVEN("1 mile") {
    auto miles = imperial::miles(1);
    WHEN("converted to feet") {
      auto feet = cast_length<imperial::feet>(miles);
      THEN("count is 5280 feet") { REQUIRE(feet.count() == 5280); }
    }

    WHEN("converted to metres") {
      auto metres = cast_length<si::metres>(miles);
      THEN("count is 1609.344 m") {
        REQUIRE(metres.count() == Approx(1609.344));
      }
    }
  }

  GIVEN("1 league") {
    auto leagues = imperial::leagues(1);
    WHEN("converted to feet") {
      auto feet = cast_length<imperial::feet>(leagues);
      THEN("count is 15840 feet") { REQUIRE(feet.count() == 15840); }
    }

    WHEN("converted to metres") {
      auto metres = cast_length<si::metres>(leagues);
      THEN("count is 4828.032 m") {
        REQUIRE(metres.count() == Approx(4828.032));
      }
    }
  }
}
