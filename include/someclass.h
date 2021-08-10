#ifndef SOMECLASS_H
#define SOMECLASS_H

#include <string>

class SomeClass{
    public:
    std::string getSomeString(){
        return std::string("working");
    }
};

class MyClass {

  int x;
  std::string y;
public:
  MyClass(int x, std::string y)
    : x(x)
    , y(y)
  {}

  void incrementX() {
    ++x;
  }

  int getX() const { return x; }
  void setX(int x_) { x = x_; }

  static std::string getStringFromInstance(const MyClass& instance) {
    return instance.y;
  }

  void setStr(std::string str) { y  = str; }
  std::string getStr()const { return y; }


};

#endif