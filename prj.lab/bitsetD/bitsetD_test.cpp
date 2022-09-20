#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <bitsetD/bitsetD.h>
#include <iostream>
#include <sstream>

TEST_CASE("testing BitsetD") {
    CHECK(BitsetD() == BitsetD(0));
    CHECK(BitsetD() != BitsetD(1));
    CHECK(BitsetD(10) == BitsetD(10, 0));
    CHECK_THROWS(BitsetD(0) &= BitsetD(1));
    CHECK_THROWS(BitsetD(0) |= BitsetD(2));
    CHECK_THROWS(BitsetD(0) ^= BitsetD(1));
    CHECK_THROWS(BitsetD(3)[-1]);
    CHECK_THROWS(BitsetD(3)[3]);
    BitsetD b(24, 0);
    {
        BitsetD a(24, 1);
        b = a;
    }

    CHECK(b == BitsetD(24, 1));
    {
        b = b;
    }
    CHECK(b == BitsetD(24, 1));

    BitsetD a(24, 1);
    std::stringstream sstream("");
    sstream << a;
    CHECK(sstream.str() == std::string("111111111111111111111111"));

    a >>= 5;
    BitsetD d("000001111111111111111111");
    CHECK(a == d);

    CHECK(~a == BitsetD("111110000000000000000000"));
    a <<= 2;

    CHECK(~a == BitsetD("111000000000000000000011"));

    BitsetD c(13, 0);
    CHECK(~c == BitsetD("1111111111111"));

    bool bool_buff = a[22];
    CHECK_FALSE(bool_buff);


    a[22] = true;
    CHECK(a == BitsetD("010111111111111111111100"));

    bool_buff = a[17];
    CHECK(bool_buff);
    a[17] = false;
    CHECK(a == BitsetD("010111011111111111111100"));


    BitsetD re = BitsetD("010111011111111111111100");
    re.resize(15);
    std::cout << re << "\n";
    re.resize(30);
    std::cout << re << "\n";
}
