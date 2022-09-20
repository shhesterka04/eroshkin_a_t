#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <rational/rational.h>



TEST_CASE("Constructor test") {
    CHECK(Rational() == Rational(0, 1));
    CHECK(Rational(3) == Rational(3, 1));
    CHECK(Rational(6, 12) == Rational(1, 2));
    CHECK(Rational(6, -12) == Rational(-1, 2));
    CHECK(Rational(6, 12) == Rational(-1, -2));
    CHECK_THROWS(Rational(6, 0));
    CHECK_THROWS(Rational(0, 0));
    CHECK(Rational(0, 3) == Rational(0, 7));
    CHECK(Rational(1, -1) == Rational(-1, 1));
    CHECK((-Rational(3)) == Rational(-3, 1));
}

TEST_CASE("Arithmetic test 1: + and +=") {
    CHECK(+Rational(3, 2) == Rational(3, 2));
    CHECK(Rational(3, 2) + Rational (4, 3) == Rational(17, 6));
    CHECK(Rational(3, 2) + Rational(-1, 2) == Rational(1, 1));
    CHECK(Rational(17, 6) + Rational(-4, 3) == Rational(3, 2));
    CHECK(Rational(3, 2) + 1 == Rational(5, 2));
    CHECK((Rational(1, 2) += Rational(1, 4)) == Rational(3, 4));
    CHECK(Rational(3, 2) + 0 == Rational(3, 2));
    CHECK(Rational(3, 2) + Rational(0,1) == Rational(3, 2));
    CHECK(Rational(3, 2) + Rational(-1, 1) == Rational(1, 2));
    CHECK(Rational(4, 1) + Rational(2, 1) == Rational(6, 1));
    CHECK(Rational(5, 2) + Rational(-1, 2) == Rational(4, 2));
    CHECK(Rational(5, 2) + Rational(-1, 2) == Rational(2, 1));
    CHECK(Rational(5, 2) + Rational(-1, 2) == 2); 
    CHECK(Rational(2, 2) - Rational() == 1);
    CHECK(Rational(2, 2) - Rational(0) == 1);
    CHECK(Rational(2, 2) + Rational(1) == 2);
    CHECK(Rational(4, 3) - Rational(1,5) == Rational(4*5-3,15));
}
TEST_CASE("Arithmetic test 2: - and -=") {
    CHECK(-Rational(3, 2) == Rational(-3, 2));
    CHECK(-Rational(3, 2) == Rational(3, -2));
    CHECK(-Rational(3, 2) != Rational(-3, -2));
    CHECK(Rational(3, 2) == -Rational(4, 3) + Rational(17, 6));
    CHECK(Rational(3, 2) == Rational(1, 1) - Rational(-1, 2));
    CHECK(Rational(17, 6) + Rational(-4, 3) == Rational(3, 2));
    CHECK(Rational(5, 2) - 1 == Rational(3, 2));
    CHECK((Rational(3, 4) -= Rational(1, 2)) == Rational(1, 4));
    CHECK(Rational(3, 2) - 0 == Rational(3, 2));
    CHECK(Rational(3, 2) - Rational(0, 1) == Rational(3, 2));
    CHECK(Rational(3, 2) - Rational(-1, 1) == Rational(5, 2));
    CHECK(Rational(4, 1) - Rational(2, 1) == Rational(2, 1));
    CHECK(Rational(5, 2) - Rational(-1, 2) == Rational(6, 2));
    CHECK(Rational(5, 2) - Rational(-1, 2) == 3);

}

TEST_CASE("Arithmetic test 3: * and *=") {
    CHECK(Rational(3, 2) * Rational(1,1) == Rational(3,2));
    CHECK(Rational(3, 2) * -1 == Rational(3, -2));
    CHECK(Rational(3, 2) * Rational(1) == Rational(3, 2));
    CHECK(Rational(3, 2) * Rational(1, -1) == Rational(-3, 2));
    CHECK(Rational(3, 2) * Rational() == 0);
    CHECK(Rational(3, 2) * Rational() == Rational(0,5));
    CHECK(Rational(3, 2) * -Rational() == 0);
    CHECK_THROWS(Rational(3, 2) * Rational(6, 0));
    CHECK(Rational(3, 2) * Rational(2,3) == 1);
    CHECK(Rational(3, 2) * Rational(4, 16) == Rational(3,8));
    CHECK(Rational(3, 2) * Rational(8, 9) == Rational(4,3));
    CHECK(Rational(3, 2) * Rational(10, 10) == Rational(3, 2));
    CHECK(Rational(3, 2) * 4 * Rational(3, 2) == Rational(9, 1));
    CHECK((Rational(2,3) *= 4) == Rational(8, 3));
    CHECK((Rational(2, 3) *= (Rational(2, 3))) == Rational(4, 9));
    CHECK((Rational(2, 3) *= 0) == Rational());
    CHECK((Rational(2, 3) *= (Rational(3, 2))) == Rational(4, 4));
    CHECK_THROWS(Rational(2, 3) *= (Rational(3, 0)));
}

TEST_CASE("Arithmetic test 4: / and /=") {
    CHECK(Rational(3, 2) / Rational(1, 1) == Rational(3, 2));
    CHECK(Rational(3, 2) / -1 == Rational(3, -2));
    CHECK(Rational(3, 2) / Rational(1) == Rational(3, 2));
    CHECK(Rational(3, 2) / Rational(1, -1) == Rational(-3, 2));
    CHECK_THROWS(Rational(3, 2) / Rational());
    CHECK_THROWS(Rational(3, 2) / Rational(6, 0));
    CHECK(Rational(3, 2) / Rational(3, 2) == 1);
    CHECK(Rational(3, 8) / Rational(4, 16) == Rational(3, 2));
    CHECK(Rational(4, 3) / Rational(8, 9) == Rational(3, 2));
    CHECK(Rational(3, 2) / Rational(10, 10) == Rational(3, 2));
    CHECK(Rational(3, 2) / 3 / Rational(3, 2) == Rational(1, 3));
    CHECK(Rational(3, 2) / 3 == Rational(1, 2));
    CHECK((Rational(2, 3) /= 4) == Rational(1, 6));
    CHECK((Rational(2, 3) / 4) == Rational(1, 6));
    CHECK((Rational(2, 3) /= (Rational(2, 3))) == 1);
    CHECK_THROWS((Rational(2, 3) /= 0));
    CHECK((Rational(2, 3) /= (Rational(3, 2))) == Rational(4, 9));
    CHECK_THROWS(Rational(2, 3) /= (Rational(3, 0)));
    CHECK((Rational(4, 7) /= (Rational(3, 14))) == Rational(8,3));
}

TEST_CASE("operator<<(std::ostream&, const Rational&)") {
    std::stringstream stream;
    Rational q = Rational(-5, 18);
    stream << q;
    std::string str;
    stream >> str;
    REQUIRE(str == "-5/18");
    //Rational m = Rational(1, -1);
    //stream << m;
    //stream >> str;
    //REQUIRE(str == "-1/1");
}


TEST_CASE("FAIL - operator>>(std::istream&, Rational&)") {
    std::stringstream stream;
    std::vector<std::string> strs = {
        "5\\18",
        //"-5/0",
        //"0/0",
        "-5/-18",
        "abc",
        "5",
        "5 / 3",
        "5/ 4",
        "5/-3",
        "5 /3",
        "a/1"
    };
    for (const auto& str : strs) {
        CAPTURE(str);
        stream << str;
        Rational q;
        stream >> q;
        CHECK(stream.fail());
        stream.clear();
    }
}

TEST_CASE("operator<<(std::ostream&, const Rational&)") {
    std::stringstream stream;
    Rational q = Rational(-5, 18);
    stream << q;
    std::string str;
    stream >> str;
    CHECK(str == "-5/18");
}
