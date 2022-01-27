#ifndef TOWER_DEFENSE_CONSOLERENDERER_H
#define TOWER_DEFENSE_CONSOLERENDERER_H


class ConsoleRenderer {
private:
    int height_;
    int width_;
    bool is_running = false;
    TowerDefense *tower_defense_;
    MyString *clearField = nullptr;
    MyString *currentField = nullptr;

    void renderClearField() const;

    void renderCurrentField() const;

    void drawCurrentField() const;

    void drawCastleInfo() const;

    //void drawCoordinatesX() const;

    //void addCoordinatesYToCurrentField() const;

    MyString getCharByEntity(Entity *entity) const;

    MyString intToString(int a) const;

    void getCommand(MyString &command_result);

    void processCommand(const MyString &command, MyString &command_result);

    void errorInCommand(MyString &command_result);

    void commandNextStep(MyString *command_words, int count_words_in_command, MyString &command_result);

    void commandExit(MyString *command_words, int count_words_in_command, MyString &command_result);

    void commandBuildTower(MyString *command_words, int count_words_in_command, MyString &command_result);

    void commandBuildWall(MyString *command_words, int count_words_in_command, MyString &command_result);

    void commandUpgradeCastle(MyString *command_words, int count_words_in_command, MyString &command_result);

    void commandUpgradeTower(MyString *command_words, int count_words_in_command, MyString &command_result);

    void commandFixWall(MyString *command_words, int count_words_in_command, MyString &command_result);

    void commandHelp(MyString *command_words, int count_words_in_command, MyString &command_result);

public:
    explicit ConsoleRenderer(TowerDefense *tower_defense);

    ~ConsoleRenderer();

    void runUI();
};


#endif //TOWER_DEFENSE_CONSOLERENDERER_H
