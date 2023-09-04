//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P12.h"
#include <iostream>
using namespace std;

static void question_12_1() {
  cache<int, 10> c;
  c = {1, 2, 3, 4, 10};
  c.push(11);
  c.push(15);
  std::cout << c << std::endl;
}

static void question_12_2() {
  cache<int, 10> c;
  c = {1, 2, 3, 4, 10};
  c.push(11);
  c.push(15);
  c.pop(); // retira el ultimo 15
  c.pop(); // retira el ultimo 11
  c.pop(); // retira el ultimo 10
  c.pop(); // retira el ultimo 4
  std::cout << c << std::endl;
  c.pop(); // retira el ultimo 3
  c.pop(); // retira el ultimo 2
  c.pop(); // retira el ultimo 1
  c.pop(); // Si esta vacio no retira ningun valor
  c.pop(); // Si esta vacio no retira ningun valor
  std::cout << boolalpha << c.empty() << std::endl;

}

static void question_12_3() {
  cache<int, 10> c;
  c = {1, 2, 3, 4, 10};
  c.clear();
  std::cout << std::boolalpha << c.empty() << std::endl;
}

static void question_12_4() {
  cache<std::string, 3> c;
  c.push("apple");
  c.push("banana");
  c.push("orange");
  c.push("lemon");    // Se elimina apple del cache
  c.push("grape");    // Se elimina banana del cache

  std::cout << c << std::endl; // grape lemon orange
}

TEST_CASE("Question #12_1") {
    execute_test("test_12_1.in", question_12_1);
}

TEST_CASE("Question #12_2") {
    execute_test("test_12_2.in", question_12_2);
}

TEST_CASE("Question #12_3") {
    execute_test("test_12_3.in", question_12_3);
}

TEST_CASE("Question #12_4") {
    execute_test("test_12_4.in", question_12_4);
}