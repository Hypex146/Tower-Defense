#ifndef TOWER_DEFENSE_CONFIGURATOR_H
#define TOWER_DEFENSE_CONFIGURATOR_H

#include <iostream>
#include <fstream>
#include "MyString.h"

class Configurator {
private:
    // Поток ввода/вывода для файла.
    std::fstream file_stream_;

    // Имя файла + путь (this is the way).
    MyString file_path_;

    bool addNewLineIfNeed();

    template<typename T>
    void rewrite(const MyString &key, const T value) {
        MyString path_to_tmp("tmp_file.txt");
        if (!isExistByPath(path_to_tmp)) { createFileByPath(path_to_tmp); }
        clearFile(path_to_tmp);
        copyFile(file_path_, path_to_tmp);
        clearFile(file_path_);
        std::fstream tmp_file;
        tmp_file.open("tmp_file.txt");
        char *file_name = file_path_.getCopyArr();
        file_stream_.open(file_name);
        delete[] file_name;
        MyString string;
        do {
            tmp_file >> string;
            if (string == "") { continue; }
            MyString current_key;
            MyString current_value;
            splitKeyAndValue(string, current_key, current_value);
            if (current_key == key) {
                file_stream_ << key << ": " << value << std::endl;
            } else {
                file_stream_ << string << std::endl;
            }
        } while (string);
        file_stream_.close();
        tmp_file.close();
    }

public:
    explicit Configurator(const char *file_path);

    explicit Configurator(const MyString &file_path);

    bool isExist();

    static bool isExistByPath(const MyString &file_path);

    void createFile();

    static void createFileByPath(const MyString &file_path);

    bool isOpen();

    static MyString rmTrash(const MyString &string);

    MyString getValue(const MyString &key);

    char *getCopyOfFileName() const;

    static void splitKeyAndValue(const MyString &string, MyString &key, MyString &value);

    int getInt(const MyString &key);

    double getDouble(const MyString &key);

    bool getBool(const MyString &key);

    MyString getString(const MyString &key);

    bool hasKey(const MyString &key);

    void setInt(const MyString &key, int value, bool rewrite = false);

    void setDouble(const MyString &key, double value, bool rewrite = false);

    void setBool(const MyString &key, bool value, bool rewrite = false);

    void setString(const MyString &key, MyString &value, bool rewrite = false);

    static void copyFile(const MyString &path_to_src, const MyString &path_to_tgt);

    static void clearFile(const MyString &path_to_file);

};


#endif //TOWER_DEFENSE_CONFIGURATOR_H
