#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <bitsett/bitsett.h>
#include <iostream>
#include <sstream>

TEST_CASE_TEMPLATE("testing BitsetT", type, int8_t, int16_t, int32_t, int64_t,
    uint8_t, uint16_t, uint32_t, uint64_t) {
    CHECK(BitsetT<type>() == BitsetT<type>(0));
    CHECK(BitsetT<type>() != BitsetT<type>(1));
    CHECK_THROWS(BitsetT<type>(-3));
    CHECK(BitsetT<type>(10) == BitsetT<type>(10, 0));
    CHECK_THROWS(BitsetT<type>(0) &= BitsetT<type>(1));
    CHECK_THROWS(BitsetT<type>(0) |= BitsetT<type>(1));
    CHECK_THROWS(BitsetT<type>(0) ^= BitsetT<type>(1));
    CHECK_THROWS(BitsetT<type>(3)[-1]);
    CHECK_THROWS(BitsetT<type>(3)[3]);
    BitsetT<type> b(24, 0);
    {
        BitsetT<type> a(24, 1);
        b = a;
    }

    CHECK(b == BitsetT<type>(24, 1));
    {
        b = b;
    }
    CHECK(b == BitsetT<type>(24, 1));

    BitsetT<type> a(24, 1);
    std::stringstream sstream("");
    sstream << a;
    CHECK(sstream.str() == std::string("111111111111111111111111"));

    a >>= 5;
    BitsetT<type> d("000001111111111111111111");
    CHECK(a == d);

    CHECK(~a == BitsetT<type>("111110000000000000000000"));
    a <<= 2;

    CHECK(~a == BitsetT<type>("111000000000000000000011"));

    BitsetT<type> c(13, 0);
    CHECK(~c == BitsetT<type>("1111111111111"));

    bool bool_buff = a[22];
    CHECK_FALSE(bool_buff);


    a[22] = true;
    CHECK(a == BitsetT<type>("010111111111111111111100"));

    bool_buff = a[17];
    CHECK(bool_buff);
    a[17] = false;
    CHECK(a == BitsetT<type>("010111011111111111111100"));

    /*
    BitsetT<type> re = BitsetT<type>("010111011111111111111100");
    re.resize(15);
    std::cout << re << "\n";
    re.resize(30);
    std::cout << re << "\n";
    re.resize(35, true);
    std::cout << re << "\n";
    */
}