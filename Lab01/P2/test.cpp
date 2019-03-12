#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"

#include "ListInt.h"

TEST_CASE("Constructors with no parameters", "[ctors]"){

  ListInt a;

  REQUIRE(a.size() == 0);
  REQUIRE(a.toStr() == "{}");

}

TEST_CASE("Copy Constructor", "[copy_ctor]"){

  ListInt a;
  a.pushBack(1);
  a.pushBack(2);
  a.pushBack(3);
  a.pushBack(4);

  ListInt b = a;


  REQUIRE(b.size() == 4);
  REQUIRE(b.toStr() == "{1, 2, 3, 4}");

}

TEST_CASE("pushBack(int e)", "[pushBack]"){
  ListInt a;
  SECTION("Case 1"){
    a.pushBack(42);
    REQUIRE(a.size() == 1);
    REQUIRE(a.toStr() == "{42}");
  }

  SECTION("Case 2"){
    a.pushBack(1);
    a.pushBack(2);
    a.pushBack(3);
    a.pushBack(4);
    a.pushBack(5);
    REQUIRE(a.size() == 5);
    REQUIRE(a.toStr() == "{1, 2, 3, 4, 5}");
  }
}

TEST_CASE("pushFront(int e)", "[pushFront]"){
  ListInt a;
  SECTION("Case 1"){
    a.pushFront(42);
    REQUIRE(a.size() == 1);
    REQUIRE(a.toStr() == "{42}");
  }

  SECTION("Case 2"){
    a.pushFront(1);
    a.pushFront(2);
    a.pushFront(3);
    a.pushFront(4);
    a.pushFront(5);
    REQUIRE(a.size() == 5);
    REQUIRE(a.toStr() == "{5, 4, 3, 2, 1}");
  }
}

TEST_CASE("popBack()", "[popBack]"){

  ListInt a;

  SECTION("Case 1"){
      a.pushBack(1);
      a.pushBack(2);
      a.pushBack(3);
      REQUIRE(a.toStr() == "{1, 2, 3}");
      a.popBack();
      REQUIRE(a.size() == 2);
      REQUIRE(a.toStr() == "{1, 2}");
  }

}

TEST_CASE("popFront()", "[popFront]"){

  ListInt a;

  SECTION("Case 1"){
      a.pushBack(1);
      a.pushBack(2);
      a.pushBack(3);
      REQUIRE(a.toStr() == "{1, 2, 3}");
      a.popFront();
      REQUIRE(a.size() == 2);
      REQUIRE(a.toStr() == "{2, 3}");
  }

}

TEST_CASE("Iterators", "[Iterators]"){
  ListInt a;

  SECTION("Case 1"){
    a.pushBack(42);
    a.pushBack(43);
    auto it = a.begin();

    REQUIRE(*it == 42);
    it++;
    REQUIRE(*it == 43);
    it--;
    REQUIRE(*it == 42);
  }
}

TEST_CASE("Reverse Iterators", "[RIterators]"){
  ListInt a;

  SECTION("Case 1"){
    a.pushBack(42);
    a.pushBack(43);
    auto it = a.rbegin();

    REQUIRE(*it == 43);
    it++;
    REQUIRE(*it == 42);
    it--;
    REQUIRE(*it == 43);
  }
}

TEST_CASE("Insert with Iterator", "[insert_with_iterator]"){
  ListInt a;

  SECTION("Case 1"){
    a.insert(a.end(), 12);
    REQUIRE(a.size() == 1);
    REQUIRE(a.toStr() == "{12}");
  }

}

TEST_CASE("Erase with Iterator", "[erase_with_iterator]"){
  ListInt a;

  SECTION("Case 1"){
    a.pushBack(1);
    a.pushBack(2);
    REQUIRE(a.toStr() == "{1, 2}");
    a.erase(a.begin());
    REQUIRE(a.size() == 1);
    REQUIRE(a.toStr() == "{2}");
  }

}

TEST_CASE("Clear", "[clear]"){

  ListInt a;
  a.pushBack(1);
  a.pushBack(2);
  a.pushBack(3);
  a.pushBack(4);
  a.pushBack(5);
  a.pushBack(6);
  a.clear();
  REQUIRE(a.size() == 0);
  REQUIRE(a.toStr() == "{}");

}

TEST_CASE("Assignment operator", "[assignment]"){

  ListInt a;
  a.pushBack(1);
  a.pushBack(2);
  a.pushBack(3);
  a.pushBack(4);

  ListInt b;
  b.pushBack(12);
  b = a;


  REQUIRE(b.size() == 4);
  REQUIRE(b.toStr() == "{1, 2, 3, 4}");

}
