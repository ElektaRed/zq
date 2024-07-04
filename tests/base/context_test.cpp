#include <doctest/doctest.h>
#include <zq/zq.hpp>

SCENARIO("We compile and run the tests") {
  GIVEN("a zq context") {
    auto context = zq::mk_context();

    WHEN("running the tests") {
      THEN("we should see the tests pass") {
        CHECK(context);
      }
    }
  }
}

SCENARIO("Using a native ZeroMQ context") {
  GIVEN("a native zmq context") {
    auto z_ctx = zmq_ctx_new();
    REQUIRE(z_ctx != nullptr);

    WHEN("Creating a zq context from the native") {
      auto context = zq::mk_context(z_ctx);
      THEN("we should have a valid zq context") {
        CHECK(context);
      }
    }

    WHEN("Creating a zq context from an invalid native context") {
      auto context = zq::mk_context(nullptr);
      THEN("we should not have a valid zq context") {
        CHECK(!context);
      }
    }
  }
}
