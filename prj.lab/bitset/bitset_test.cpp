#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <bitset/bitset.h>
#include <iostream>
#include <sstream>

TEST_CASE("testing Bitset") {
    CHECK(Bitset(10) == Bitset(10, 0));
    CHECK_THROWS(Bitset(0) &= Bitset(1));
    CHECK_THROWS(Bitset(0) |= Bitset(2));
    CHECK_THROWS(Bitset(0) ^= Bitset(1));
    CHECK_THROWS(Bitset(3)[-1]);
    CHECK_THROWS(Bitset(3)[3]);
    Bitset b(24, 0);
    {
        Bitset a(24, 1);
        b = a;
    }

    CHECK(b == Bitset(24, 1));
    {
        b = b;
    }
    CHECK(b == Bitset(24, 1));

    Bitset a(24, 1);
    std::stringstream sstream("");
    sstream << a;
    CHECK(sstream.str() == std::string("111111111111111111111111"));

    a >>= 5;
    Bitset d("000001111111111111111111");
    CHECK(a == d);

    CHECK(~a == Bitset("111110000000000000000000"));
    a <<= 2;

    CHECK(~a == Bitset("111000000000000000000011"));

    Bitset c(13, 0);
    CHECK(~c == Bitset("1111111111111"));

    bool bool_buff = a[22];
    CHECK_FALSE(bool_buff);


    a[22] = true;
    CHECK(a == Bitset("010111111111111111111100"));

    bool_buff = a[17];
    CHECK(bool_buff);
    a[17] = false;
    CHECK(a == Bitset("010111011111111111111100"));


    Bitset re = Bitset("010111011111111111111100");
    re.resize(15);
    std::cout << re << "\n";
    re.resize(30);
    std::cout << re << "\n";
}
