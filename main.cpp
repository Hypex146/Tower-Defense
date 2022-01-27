#include <iostream>
#include <fstream>

#define ALL_INCLUDE
#include "AllHeaders.h"

int main() {
    auto *td = new TowerDefense();
    td->initModulesDefault();
    auto *ui = new ConsoleRenderer(td);
    ui->runUI();
    delete ui;
    td->deleteAllModules();
    delete td;
    std::cout << "Bye!" << std::endl;
    return 0;
}
