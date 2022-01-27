#define ALL_INCLUDE

#include "AllHeaders.h"
#include "ConsoleRenderer.h"

ConsoleRenderer::ConsoleRenderer(TowerDefense *tower_defense) {
    tower_defense_ = tower_defense;
    if (tower_defense_->getGameMap() == nullptr) {
        throw std::runtime_error("First register an instance of the \"GameMap\" class");
    }
    width_ = tower_defense_->getGameMap()->getWidth();
    height_ = tower_defense_->getGameMap()->getHeight();
    clearField = new MyString[height_];
    currentField = new MyString[height_];
}

void ConsoleRenderer::renderClearField() const {
    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            if (tower_defense_->getGameMap()->getFieldType(x, y) == FieldType::PLAIN) {
                clearField[y] = clearField[y] + ".";
            } else if (tower_defense_->getGameMap()->getFieldType(x, y) == FieldType::MOUNTAIN) {
                clearField[y] = clearField[y] + "^";
            } else if (tower_defense_->getGameMap()->getFieldType(x, y) == FieldType::WATER) {
                clearField[y] = clearField[y] + "~";
            }
        }
    }
}

MyString ConsoleRenderer::intToString(int a) const {
    MyString res;
    bool isNegative = false;
    if (a < 0) {
        a *= -1;
        isNegative = true;
    }
    if (a == 0) { res = "0"; }
    while (a > 0) {
        char number[2];
        number[0] = a % 10 + 48;
        number[1] = '\0';
        res = number + res;
        a /= 10;
    }
    if (isNegative) { res = "-" + res; }
    return res;
}

MyString ConsoleRenderer::getCharByEntity(Entity *entity) const {
    MyString res;
    switch (entity->getType()) {
        case (EntityType::CASTLE): {
            res = "@";
            break;
        }
        case (EntityType::TOWER): {
            auto *tower = (Tower *) entity;
            res = intToString(tower->getLvl());
            break;
        }
        case (EntityType::WALL): {
            res = "#";
            break;
        }
        case (EntityType::ENEMY_LAIR): {
            res = "*";
            break;
        }
        case (EntityType::LIGHT_INFANTRY): {
            res = "l";
            break;
        }
        case (EntityType::HEAVY_INFANTRY): {
            res = "h";
            break;
        }
        case (EntityType::AVIATION): {
            res = "a";
            break;
        }
        case (EntityType::HERO_LIGHT_INFANTRY): {
            res = "L";
            break;
        }
        case (EntityType::HERO_HEAVY_INFANTRY): {
            res = "H";
            break;
        }
        case (EntityType::HERO_AVIATION): {
            res = "A";
            break;
        }
    }
    return res;
}

void ConsoleRenderer::renderCurrentField() const {
    for (int y = 0; y < height_; y++) {
        currentField[y] = clearField[y];
    }
    List<Entity *> entities = tower_defense_->getEntitiesManager()->getEntities();
    ListIterator<Entity *> iterator = entities.createIterator();
    while (iterator.hasNext()) {
        iterator.next();
        Position pos = iterator.getCurrent()->getPos();
        char entity_char = getCharByEntity(iterator.getCurrent())[0];
        currentField[pos.y_].changeChar(pos.x_, entity_char);
    }
    Position pos = tower_defense_->getEntitiesManager()->getCastle()->getPos();
    currentField[pos.y_].changeChar(pos.x_, getCharByEntity(tower_defense_->getEntitiesManager()->getCastle())[0]);
}

void ConsoleRenderer::getCommand(MyString &command_result) {
    std::cout << "Enter the command >" << std::endl;
    MyString command;
    std::cin >> command;
    processCommand(command, command_result);
}

void ConsoleRenderer::processCommand(const MyString &command, MyString &command_result) {
    int count_words_in_command;
    MyString *command_words = command.splitIntoWords(count_words_in_command);
    if (count_words_in_command == 0 || command_words[0] == "go") {
        commandNextStep(command_words, count_words_in_command, command_result);
    } else if (command_words[0] == "exit") {
        commandExit(command_words, count_words_in_command, command_result);
    } else if (command_words[0] == "build-tower") {
        commandBuildTower(command_words, count_words_in_command, command_result);
    } else if (command_words[0] == "build-wall") {
        commandBuildWall(command_words, count_words_in_command, command_result);
    } else if (command_words[0] == "upgrade-castle") {
        commandUpgradeCastle(command_words, count_words_in_command, command_result);
    } else if (command_words[0] == "upgrade-tower") {
        commandUpgradeTower(command_words, count_words_in_command, command_result);
    } else if (command_words[0] == "fix-wall") {
        commandFixWall(command_words, count_words_in_command, command_result);
    } else if (command_words[0] == "help") {
        commandHelp(command_words, count_words_in_command, command_result);
    } else { errorInCommand(command_result); }
    delete[] command_words;
}

void ConsoleRenderer::commandNextStep(MyString *command_words, int count_words_in_command, MyString &command_result) {
    if (count_words_in_command > 2) {
        errorInCommand(command_result);
        return;
    }
    if (count_words_in_command <= 1) {
        tower_defense_->moveEntities();
        renderCurrentField();
        command_result = "The entities make 1 step";
    } else {
        int count_steps;
        try {
            count_steps = command_words[1].toInt();
        } catch (const std::exception &ex) {
            count_steps = 0;
            errorInCommand(command_result);
            return;
        }
        if (count_steps < 0) { count_steps = 0; }
        for (int i = 0; i < count_steps; i++) {
            if (!tower_defense_->getEntitiesManager()->getCastle()->isAlive()) { break; }
            tower_defense_->moveEntities();
        }
        renderCurrentField();
        command_result = "The entities make ";
        command_result += intToString(count_steps);
        command_result += " steps";
    }
}

void ConsoleRenderer::errorInCommand(MyString &command_result) {
    command_result = "ERROR in command, write \"help\" for help on commands";
}

void ConsoleRenderer::drawCurrentField() const {
    system("clear");
    for (int i = 0; i < height_; i++) {
        std::cout << currentField[i] << std::endl;
    }
}

void ConsoleRenderer::drawCastleInfo() const {
    std::cout << "Castle HP: " << tower_defense_->getEntitiesManager()->getCastle()->getHP() << " | ";
    std::cout << "Castle Lvl: " << tower_defense_->getEntitiesManager()->getCastle()->getLvl() << " | ";
    std::cout << "Gold: " << tower_defense_->getEntitiesManager()->getCastle()->getGold() << " | ";
    std::cout << "Kills: " << tower_defense_->getEntitiesManager()->getCastle()->getKillsCount() << " | ";
    std::cout << "Tick: " << tower_defense_->getTick() << std::endl;
}

void ConsoleRenderer::runUI() {
    renderClearField();
    renderCurrentField();
    MyString command_result;
    is_running = true;
    while (is_running) {
        drawCurrentField();
        drawCastleInfo();
        std::cout << command_result << std::endl;
        getCommand(command_result);
        if (!tower_defense_->getEntitiesManager()->getCastle()->isAlive()) { is_running = false; }
    }
    system("clear");
    drawCurrentField();
    drawCastleInfo();
    std::cout << "You lose!" << std::endl;
    std::cout << "Enter any button for exit" << std::endl;
    std::getchar();
}

ConsoleRenderer::~ConsoleRenderer() {
    delete[] clearField;
    delete[] currentField;
}

void ConsoleRenderer::commandExit(MyString *command_words, int count_words_in_command, MyString &command_result) {
    if (count_words_in_command != 1) {
        errorInCommand(command_result);
        return;
    }
    is_running = false;
    command_result = "^_^";
}

void ConsoleRenderer::commandBuildTower(MyString *command_words, int count_words_in_command, MyString &command_result) {
    Position pos(-1, -1);
    if (count_words_in_command != 3) {
        errorInCommand(command_result);
        return;
    }
    try {
        pos.x_ = command_words[1].toInt();
        pos.y_ = command_words[2].toInt();
    }
    catch (const std::exception &ex) {
        errorInCommand(command_result);
        return;
    }
    Result result = tower_defense_->buildTower(pos);
    if (result.completed_) { renderCurrentField(); }
    command_result = result.message_;
}

void ConsoleRenderer::commandBuildWall(MyString *command_words, int count_words_in_command, MyString &command_result) {
    Position pos(-1, -1);
    if (count_words_in_command != 3) {
        errorInCommand(command_result);
        return;
    }
    try {
        pos.x_ = command_words[1].toInt();
        pos.y_ = command_words[2].toInt();
    }
    catch (const std::exception &ex) {
        errorInCommand(command_result);
        return;
    }
    Result result = tower_defense_->buildWall(pos);
    if (result.completed_) { renderCurrentField(); }
    command_result = result.message_;
}

void
ConsoleRenderer::commandUpgradeCastle(MyString *command_words, int count_words_in_command, MyString &command_result) {
    if (count_words_in_command != 1) {
        errorInCommand(command_result);
        return;
    }
    Result result = tower_defense_->castleLvlUp();
    command_result = result.message_;
}

void
ConsoleRenderer::commandUpgradeTower(MyString *command_words, int count_words_in_command, MyString &command_result) {
    Position pos(-1, -1);
    if (count_words_in_command != 3) {
        errorInCommand(command_result);
        return;
    }
    try {
        pos.x_ = command_words[1].toInt();
        pos.y_ = command_words[2].toInt();
    }
    catch (const std::exception &ex) {
        errorInCommand(command_result);
        return;
    }
    Result result = tower_defense_->towerLvlUp(pos);
    if (result.completed_) { renderCurrentField(); }
    command_result = result.message_;
}

void ConsoleRenderer::commandFixWall(MyString *command_words, int count_words_in_command, MyString &command_result) {
    Position pos(-1, -1);
    if (count_words_in_command != 3) {
        errorInCommand(command_result);
        return;
    }
    try {
        pos.x_ = command_words[1].toInt();
        pos.y_ = command_words[2].toInt();
    }
    catch (const std::exception &ex) {
        errorInCommand(command_result);
        return;
    }
    Result result = tower_defense_->fixWall(pos);
    command_result = result.message_;
}

void ConsoleRenderer::commandHelp(MyString *command_words, int count_words_in_command, MyString &command_result) {
    if (count_words_in_command != 1) {
        errorInCommand(command_result);
        return;
    }
    command_result = "Below are examples of available commands:\n";
    command_result += "help\n";
    command_result += "go <count steps>\n";
    command_result += "build-tower <x> <y>\n";
    command_result += "build-wall <x> <y>\n";
    command_result += "upgrade-castle\n";
    command_result += "upgrade-tower <x> <y>\n";
    command_result += "fix-wall <x> <y>\n";
    command_result += "exit";
}
/*
void ConsoleRenderer::addCoordinatesYToCurrentField() const {
    for (int i = 0; i < height_; i++) {
        currentField[i] += "-";
        currentField[i] += intToString(i);
    }
}

void ConsoleRenderer::drawCoordinatesX() {

}
*/

