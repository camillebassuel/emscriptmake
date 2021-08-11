#include <iostream>
#include <cstring>
#include <string>
#include <someclass.h>
#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}


EMSCRIPTEN_BINDINGS(my_module) {
    function("lerp", &lerp);
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

struct Point2f {
    float x;
    float y;
};

struct PersonRecord {
    std::string name;
    int age;
};

// Array fields are treated as if they were std::array<type,size>
struct ArrayInStruct {
        int field[2];
};

PersonRecord findPersonAtLocation(Point2f){
    return PersonRecord{ "default personn" , 101 };
}

EMSCRIPTEN_BINDINGS(my_value_example) 
{
    value_array<Point2f>("Point2f")
        .element(&Point2f::x)
        .element(&Point2f::y)
        ;

    value_object<PersonRecord>("PersonRecord")
        .field("name", &PersonRecord::name)
        .field("age", &PersonRecord::age)
        ;

    value_object<ArrayInStruct>("ArrayInStruct")
            .field("field", &ArrayInStruct::field) // Need to register the array type
            ;

    // Register std::array<int, 2> because ArrayInStruct::field is interpreted as such
    value_array<std::array<int, 2>>("array_int_2")
            .element(emscripten::index<0>())
            .element(emscripten::index<1>())
            ;

    function("findPersonAtLocation", &findPersonAtLocation);
}





std::vector<int> returnVectorData () {
  std::vector<int> v(10, 1);
  return v;
}

std::map<int, std::string> returnMapData () {
  std::map<int, std::string> m;
  m.insert(std::pair<int, std::string>(10, "This is a string."));
  return m;
}

EMSCRIPTEN_BINDINGS(module) {
  function("returnVectorData", &returnVectorData);
  function("returnMapData", &returnMapData);

  // register bindings for std::vector<int> and std::map<int, std::string>.
  register_vector<int>("vector<int>");
  register_map<int, std::string>("map<int, string>");
}