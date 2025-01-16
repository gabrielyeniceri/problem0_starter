#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "add.hpp"

// force template expansion
template class Add<int>;

TEST_CASE("Test add", "[Add]"){

  Add<int> a;
  REQUIRE(a.call(1,2)==3);
}
TEST_CASE("Test long addition", "[Add]") {
    Add<long> a;
    long x = 100;
    long y = 200;
    REQUIRE(a.call(x, y) == 300);
}

TEST_CASE("Test double addition", "[Add]") {
    Add<double> a;
    double x = 3.0 - std::sqrt(2.0);
    double y = 4.0 + std::sqrt(2.0);
    REQUIRE(a.call(x, y) == Approx(7.0));
}

TEST_CASE("Test char addition", "[Add]") {
    Add<char> a;
    REQUIRE(a.call('2' - '0', '3' - '0') == '5' - '0');
}
TEST_CASE("Test string addition", "[Add]") {
    Add<std::string> a;
    REQUIRE(a.call("2", "3") == "23");
}
TEST_CASE("Test bool addition", "[Add]") {
    Add<bool> a;
    REQUIRE(a.call(true, true) == static_cast<bool>(true + true));  // true is treated as 1 in arithmetic
}


//the destructor remains untested because nothing explicitly verifies it
//no, operator overloading is not implemented as it uses a call instead of overloading the + operater