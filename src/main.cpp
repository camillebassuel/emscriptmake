#include <iostream>
#include <cstring>
#include <string>
#include <someclass.h>
#include <emscripten/bind.h>

using namespace emscripten;


static MyClass mc(122,"hello");

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

int incrementX() {
    mc.incrementX();
    return mc.getX();
}


EMSCRIPTEN_BINDINGS(my_module) {
    function("lerp", &lerp);
    function("incrementX", &incrementX);
}

// Binding code
EMSCRIPTEN_BINDINGS(my_class_example) {
  class_<MyClass>("MyClass")
    .constructor<int, std::string>()
    .function("incrementX", &MyClass::incrementX)
    .property("x", &MyClass::getX, &MyClass::setX)
    .property("str", &MyClass::getStr, &MyClass::setStr)
    .class_function("getStringFromInstance", &MyClass::getStringFromInstance)
    ;
}