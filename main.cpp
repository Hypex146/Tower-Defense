#include <iostream>
#include <fstream>
#include "Configurator.h"

int main() {
    Configurator cfg("new_test.yml");
    MyString str1;
    str1 = cfg.getString(MyString("key1"));
    std::cout << str1 << std::endl;
    int a = cfg.getInt(MyString("key2"));
    std::cout << a << std::endl;
    double b = cfg.getDouble(MyString("key3"));
    std::cout << b << std::endl;
    bool c = cfg.getBool(MyString("key4"));
    std::cout << c << std::endl;
    cfg.setInt(MyString("NewKey5"), 777, false);
    cfg.setDouble(MyString("NewKey6"), 0.25, false);
    cfg.setBool(MyString("NewKey7"), false, false);
    MyString string("NewString");
    cfg.setString(MyString("NewKey8"), string, false);
    return 0;
}
