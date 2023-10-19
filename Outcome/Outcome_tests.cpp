#define CATCH_CONFIG_MAIN
#include "../tests/catch.hpp"
#include "Outcome.hpp"

TEST_CASE( "Outcomes are computed") {

    Outcome o1 = Outcome("Red",1);
    Outcome o2 = Outcome("Red",1);
    Outcome o3 = Outcome("Black",2);

    bool eq  = bool(o1==o2);
    bool ineq = bool(o2!=o3);
    bool noteq = bool(o2==o3);

    REQUIRE(eq == true);
    REQUIRE( o1.getName() == "Red");
    REQUIRE( o1.getOdds() == 1 );
    REQUIRE( ineq == true);
    REQUIRE(noteq == false);

}
