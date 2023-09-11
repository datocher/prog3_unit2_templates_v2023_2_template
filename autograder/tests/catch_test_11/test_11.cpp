//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P11.h"
#include <vector>
#include <array>

static void question_11_1() {
  auto f = polynomial<int, 10, 0, 7, 2, 0, 0, 11>();
  cout << f(5);
}

static void question_11_2() {
  auto f = polynomial<double, 21.0, 3.5, 0.0, 5.0>();
  cout << f(4.5);
}

static void question_11_3() {
  auto f = polynomial<int, 0, 0, 0, 2, 0, 0, 11>();
  cout << f(4);
}

TEST_CASE("Question #11_1") {
    execute_test("test_11_1.in", question_11_1);
}

TEST_CASE("Question #11_2") {
    execute_test("test_11_2.in", question_11_2);
}

TEST_CASE("Question #11_3") {
    execute_test("test_11_3.in", question_11_3);
}
