#include <iostream>
#include <fstream>
#include "Configurator.h"

int main() {
    MyString src("test.txt");
    MyString tgt("test1.yml");
    Configurator::copyFile(src, tgt);
    return 0;
}
