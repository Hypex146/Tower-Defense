#include "Configurator.h"

Configurator::Configurator(const char *file_path) {
    file_path_ = file_path;
}

Configurator::Configurator(const MyString &file_path) {
    file_path_ = file_path;
}

char *Configurator::getCopyOfFileName() const {
    return file_path_.getCopyArr();
}

bool Configurator::isExist() {
    bool isExist = false;
    char *file_name_chars = file_path_.getCopyArr();
    std::ifstream fin(file_name_chars);
    if (fin.is_open())
        isExist = true;
    fin.close();
    delete[] file_name_chars;
    return isExist;
}

bool Configurator::isExistByPath(const MyString &file_path) {
    bool isExist = false;
    char *file_name_chars = file_path.getCopyArr();
    std::ifstream fin(file_name_chars);
    if (fin.is_open())
        isExist = true;
    fin.close();
    delete[] file_name_chars;
    return isExist;
}

bool Configurator::isOpen() {
    return file_stream_.is_open();
}

MyString Configurator::rmTrash(const MyString &string) {
    if (!string) return string;
    MyString res;
    int start = 0;
    int end = string.getLength() - 1;
    while ((string[start] == ' ' || string[start] == '\t' || string[start] == '\r') && start < end) { start++; }
    while ((string[end] == ' ' || string[end] == '\t' || string[end] == '\r') && end > start) { end--; }
    if (start == end && (string[start] == ' ' || string[start] == '\t' || string[start] == '\r')) res = "";
    else res = string(start, end);
    return res;
}

void Configurator::splitKeyAndValue(const MyString &string, MyString &key, MyString &value) {
    int split_index = 0;
    int string_len = string.getLength();
    while (split_index < string_len && string[split_index] != ':') { split_index++; }
    if (split_index != 0 && split_index != string_len && string[split_index] == ':') {
        if (split_index + 1 == string.getLength()) {
            value = "";
            key = string(0, split_index - 1);
        } else {
            value = string(split_index + 1, string.getLength() - 1);
            value = rmTrash(value);
            key = string(0, split_index - 1);
        }
    } else {
        throw std::invalid_argument("This key does not exist");
    }
}

MyString Configurator::getValue(const MyString &key) {
    if (!isExist()) { throw std::runtime_error("File is not exist"); }
    char *file_path = file_path_.getCopyArr();
    file_stream_.open(file_path);
    delete[] file_path;
    MyString string;
    MyString value;
    MyString current_key;
    do {
        file_stream_ >> string;
        if (!string) { continue; }
        Configurator::splitKeyAndValue(string, current_key, value);
        if (current_key == key) {
            file_stream_.close();
            return value;
        }
    } while (string);
    file_stream_.close();
    throw std::invalid_argument("This key does not exist");
}

bool Configurator::hasKey(const MyString &key) {
    if (!isExist()) { throw std::runtime_error("File is not exist"); }
    char *file_path = file_path_.getCopyArr();
    file_stream_.open(file_path);
    delete[] file_path;
    MyString string;
    MyString value;
    MyString current_key;
    do {
        file_stream_ >> string;
        if (!string) { continue; }
        Configurator::splitKeyAndValue(string, current_key, value);
        if (current_key == key) {
            file_stream_.close();
            return true;
        }
    } while (string);
    file_stream_.close();
    return false;
}

int Configurator::getInt(const MyString &key) {
    MyString value = getValue(key);
    return value.toInt();
}

double Configurator::getDouble(const MyString &key) {
    MyString value = getValue(key);
    return value.toDouble();
}

bool Configurator::getBool(const MyString &key) {
    MyString value = getValue(key);
    return value.toBool();
}

MyString Configurator::getString(const MyString &key) {
    MyString value = getValue(key);
    int len = value.getLength();
    if (len >= 2) {
        if (value[0] == '"' && value[len - 1] == '"') {
            if (len > 2) { value.cut(1, len - 2); }
            else value = "";
            return value;
        }
    }
    throw std::runtime_error("Cannot be cast to string");
}

bool Configurator::addNewLineIfNeed() {
    if (!isExist()) { throw std::runtime_error("File is not exist"); }
    char *file_path = file_path_.getCopyArr();
    file_stream_.open(file_path);
    delete[] file_path;
    file_stream_.seekp(-1, std::ios_base::end);
    char a = '\n';
    file_stream_ >> a;
    if (a != '\n') {
        file_stream_ << std::endl;
        file_stream_.close();
        return true;
    }
    file_stream_.close();
    return false;
}

void Configurator::setInt(const MyString &key, int value, bool rewrite) {
    if (!isExist()) { throw std::runtime_error("File is not exist"); }
    bool has_key = hasKey(key);
    if (!rewrite && has_key) { throw std::invalid_argument("This key exists"); }
    addNewLineIfNeed();
    if (rewrite && has_key) {
        Configurator::rewrite<int>(key, value);
        return;
    }
    char *file_path = file_path_.getCopyArr();
    file_stream_.open(file_path, std::ios_base::app);
    delete[] file_path;
    file_stream_ << key << ": " << value << std::endl;
    file_stream_.close();
}

void Configurator::setDouble(const MyString &key, double value, bool rewrite) {
    if (!isExist()) { throw std::runtime_error("File is not exist"); }
    bool has_key = hasKey(key);
    if (!rewrite && has_key) { throw std::invalid_argument("This key exists"); }
    addNewLineIfNeed();
    if (rewrite && has_key) {
        Configurator::rewrite<double>(key, value);
        return;
    }
    char *file_path = file_path_.getCopyArr();
    file_stream_.open(file_path, std::ios_base::app);
    delete[] file_path;
    file_stream_ << key << ": " << value << std::endl;
    file_stream_.close();
}

void Configurator::setBool(const MyString &key, bool value, bool rewrite) {
    if (!isExist()) { throw std::runtime_error("File is not exist"); }
    bool has_key = hasKey(key);
    if (!rewrite && has_key) { throw std::invalid_argument("This key exists"); }
    addNewLineIfNeed();
    if (rewrite && has_key) {
        MyString special_value;
        if (value) { special_value = "true"; }
        else { special_value = "false"; }
        Configurator::rewrite<MyString>(key, special_value);
        return;
    }
    char *file_path = file_path_.getCopyArr();
    file_stream_.open(file_path, std::ios_base::app);
    delete[] file_path;
    if (value) { file_stream_ << key << ": " << "true" << std::endl; }
    else { file_stream_ << key << ": " << "false" << std::endl; }
    file_stream_.close();
}

void Configurator::setString(const MyString &key, MyString &value, bool rewrite) {
    if (!isExist()) { throw std::runtime_error("File is not exist"); }
    bool has_key = hasKey(key);
    if (!rewrite && has_key) { throw std::invalid_argument("This key exists"); }
    addNewLineIfNeed();
    if (rewrite && has_key) {
        MyString special_value = "\"" + value + "\"";
        Configurator::rewrite<MyString>(key, special_value);
        return;
    }
    char *file_path = file_path_.getCopyArr();
    file_stream_.open(file_path, std::ios_base::app);
    delete[] file_path;
    file_stream_ << key << ": \"" << value << "\"" << std::endl;
    file_stream_.close();
}

void Configurator::createFile() {
    if (isExist()) { throw std::runtime_error("This file already exists"); }
    char *file_name = file_path_.getCopyArr();
    std::ofstream fout;
    fout.open(file_name);
    fout.close();
    delete[] file_name;
}

void Configurator::createFileByPath(const MyString &file_path) {
    if (isExistByPath(file_path)) { throw std::runtime_error("This file already exists"); }
    char *file_name = file_path.getCopyArr();
    std::ofstream fout;
    fout.open(file_name);
    fout.close();
    delete[] file_name;
}

void Configurator::copyFile(const MyString &path_to_src, const MyString &path_to_tgt) {
    if (!isExistByPath(path_to_src)) { throw std::invalid_argument("Source file does not exist"); }
    if (!isExistByPath(path_to_tgt)) { throw std::invalid_argument("Target file does not exist"); }
    MyString string;
    char *path_to_src_char = path_to_src.getCopyArr();
    char *path_to_tgt_char = path_to_tgt.getCopyArr();
    std::fstream f_src;
    std::fstream f_tgt;
    f_src.open(path_to_src_char);
    f_tgt.open(path_to_tgt_char);
    delete[] path_to_src_char;
    delete[] path_to_tgt_char;
    do {
        f_src >> string;
        if (string == "") { continue; }
        f_tgt << string << std::endl;
    } while (string);
    f_src.close();
    f_tgt.close();
}

void Configurator::clearFile(const MyString &path_to_file) {
    char *file_name = path_to_file.getCopyArr();
    std::fstream file_stream;
    file_stream.open(file_name, std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    file_stream.close();
    delete[] file_name;
}
