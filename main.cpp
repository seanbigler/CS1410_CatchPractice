#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Distance.h"

TEST_CASE("Testing development of Distance class")
{
    SECTION("Test 1) Check Default Constructor")
    {
        Distance d1;
        REQUIRE(d1.getInches() == 0);
        REQUIRE(d1.getFeet() == 0);

    }
    SECTION("Test 2) Check Constructor with Parameters")
    {
        Distance d1(2, 4.5);
        REQUIRE(d1.getFeet() == 2);
        REQUIRE(d1.getInches() == 4.5);
    }
    SECTION("Test 3) Operator Overload '+' <obj> + <obj>")
    {
        Distance d1(3, 4.5);
        Distance d2(4, 2.1);
        Distance d3, d4;
        d3 = d1 + d2;
        REQUIRE(d3.getFeet() == 7);
        // Use Approx() with floating points
        REQUIRE(d3.getInches() == Approx(6.6));
        d4 = d3 + d3;
        REQUIRE(d4.getFeet() == 15);
        REQUIRE(d4.getInches() == Approx(1.2));
    }
    SECTION("Test 4) Operator Overload '+' <obj> + <const>")
    {
        Distance d1(3, 4.5);
        Distance d3;

        d3 = d1 + 5;
        REQUIRE(d3.getFeet() == 8);
        REQUIRE(d3.getInches() == Approx(4.5));
    }
    SECTION("Test 5) Operator Overload '+' <const> + <obj>")
    {
        Distance d1(3, 4.5);
        Distance d3;

        d3 = 5 + d1;
        REQUIRE(d3.getFeet() == 8);
        REQUIRE(d3.getInches() == Approx(4.5));
    }
}