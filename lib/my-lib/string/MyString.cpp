#define STD_LIBS_INCLUDE
#define MY_LIBS_INCLUDE

#include "AllHeaders.h"
#include "MyString.h"


MyString::MyString() {
    string_ = new char[1];
    string_[0] = '\0';
}

MyString::MyString(const char *string) {
    if (string == nullptr) {
        string_ = new char[1];
        string_[0] = '\0';
        return;
    }
    int str_size = 0;
    char current_char = string[0];
    while (current_char != '\0') {
        current_char = string[++str_size];
    }
    string_ = new char[str_size + 1];
    for (int i = 0; i < str_size; i++) {
        string_[i] = string[i];
    }
    string_[str_size] = '\0';
}

MyString::MyString(const MyString &object) {
    string_ = object.getCopyArr();
}

MyString::MyString(MyString &&object) noexcept {
    string_ = object.string_;
    object.string_ = nullptr;
}

MyString::~MyString() {
    delete[] string_;
}

int MyString::getLength() const {
    int str_size = 0;
    char current_char = string_[0];
    while (current_char != '\0') {
        current_char = string_[++str_size];
    }
    return str_size;
}

char *MyString::getCopyArr() const {
    int len = getLength();
    char *copy = new char[len + 1];
    for (int i = 0; i < len; i++) {
        copy[i] = string_[i];
    }
    copy[len] = '\0';
    return copy;
}

void MyString::clear() {
    delete[] string_;
    string_ = new char[1];
    string_[0] = '\0';
}

int MyString::getLengthOtherString(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void MyString::extendSize(int new_size) {
    char *new_string = new char[new_size + 1];
    int current_size = getLength();
    int loop_count;
    if (current_size >= new_size) { loop_count = new_size; }
    else { loop_count = current_size; }
    for (int i = 0; i < loop_count; i++) {
        new_string[i] = string_[i];
    }
    new_string[loop_count] = '\0';
    delete[] string_;
    string_ = new_string;
}

void MyString::extend(const char *str) {
    int to_add = MyString::getLengthOtherString(str);
    int previous_size = getLength();
    extendSize(to_add + previous_size);
    int new_size = previous_size + to_add;
    for (int i = previous_size; i < new_size; i++) {
        string_[i] = str[i - previous_size];
    }
    string_[new_size] = '\0';
}

void MyString::extend(const MyString &str) {
    int to_add = str.getLength();
    int previous_size = getLength();
    extendSize(to_add + previous_size);
    int new_size = previous_size + to_add;
    for (int i = previous_size; i < new_size; i++) {
        string_[i] = str.string_[i - previous_size];
    }
    string_[new_size] = '\0';
}

char MyString::getCasePair(char a) {
    char pair = a;
    if (a >= 65 && a <= 90) {
        pair = (char) ((int) (a) + 32);
    } else if (a >= 97 && a <= 122) {
        pair = (char) ((int) (a) - 32);
    }
    return pair;
}

bool MyString::contain(const char *str, bool case_sensitive) const {
    char original;
    char pair;
    int i = 0;
    while (string_[i] != '\0') {
        original = str[0];
        pair = original;
        if (!case_sensitive) { pair = MyString::getCasePair(original); }
        if (string_[i] == pair || string_[i] == original) {
            int j = i;
            int k = 0;
            while (string_[j] != '\0' && str[k] != '\0') {
                original = str[k];
                pair = original;
                if (!case_sensitive) { pair = MyString::getCasePair(original); }
                if (string_[j] == original || string_[j] == pair) {
                    j++;
                    k++;
                } else { break; }
            }
            if (str[k] == '\0') { return true; }
        }
        i++;
    }
    return false;
}

bool MyString::begin(const char *str, bool case_sensitive) const {
    int str_size = MyString::getLengthOtherString(str);
    if (str_size == 0) { return false; }
    int size = getLength();
    if (size < str_size) { return false; }
    char original;
    char pair;
    for (int i = 0; i < str_size; i++) {
        original = str[i];
        pair = original;
        if (!case_sensitive) { pair = MyString::getCasePair(original); }
        if (string_[i] != original && string_[i] != pair) { return false; }
    }
    return true;
}

bool MyString::end(const char *str, bool case_sensitive) const {
    int str_size = MyString::getLengthOtherString(str);
    if (str_size == 0) { return false; }
    int size = getLength();
    if (size < str_size) { return false; }
    char original;
    char pair;
    int offset = size - str_size;
    for (int i = 0; i < str_size; i++) {
        original = str[i];
        pair = original;
        if (!case_sensitive) { pair = MyString::getCasePair(original); }
        if (string_[i + offset] != original && string_[i + offset] != pair) { return false; }
    }
    return true;
}

bool MyString::equal(const MyString &str) const {
    int size = getLength();
    int other_size = str.getLength();
    if (size != other_size) { return false; }
    for (int i = 0; i < size; i++) {
        if (string_[i] != str.string_[i]) { return false; }
    }
    return true;
}

bool MyString::equal(const char *str) const {
    int size = getLength();
    int other_size = MyString::getLengthOtherString(str);
    if (size != other_size) { return false; }
    for (int i = 0; i < size; i++) {
        if (string_[i] != str[i]) { return false; }
    }
    return true;
}

char MyString::getByIndex(int index) const {
    if (getLength() <= index) { throw std::runtime_error("Out of range"); }
    return string_[index];
}

MyString MyString::getSection(int start, int end) const {
    if (start > end || end >= getLength() || start < 0) { throw std::invalid_argument("Bad argument!"); }
    int new_len = end - start + 1;
    char new_str[new_len + 1];
    int j = 0;
    for (int i = start; i <= end; i++) {
        new_str[j] = string_[i];
        j++;
    }
    new_str[new_len] = '\0';
    MyString new_string(new_str);
    return new_string;
}

void MyString::cut(int start, int end) {
    *this = getSection(start, end);
}

int MyString::toInt() const {
    if (getLength() == 0) { throw std::runtime_error("Cannot be cast to int"); }
    int res = 0;
    bool negative = false;
    if (string_[0] == '-') { negative = true; }
    for (int i = 0; i < getLength(); i++) {
        if (i == 0 && negative) { continue; }
        if (string_[i] < '0' || string_[i] > '9') { throw std::runtime_error("Cannot be cast to int"); }
        res *= 10;
        res += string_[i] - '0';
    }
    if (negative) { res *= -1; }
    return res;
}

double MyString::toDouble() const {
    if (getLength() == 0) { throw std::runtime_error("Cannot be cast to double"); }
    int fractional = 0;
    double res = 0;
    bool negative = false;
    if (string_[0] == '-') { negative = true; }
    for (int i = 0; i < getLength(); i++) {
        if (i == 0 && negative) { continue; }
        if ((string_[i] < '0' || string_[i] > '9') && string_[i] != '.') {
            throw std::runtime_error("Cannot be cast to int");
        }
        if (string_[i] == '.') {
            if (fractional == 0) {
                fractional++;
                continue;
            } else { throw std::runtime_error("Cannot be cast to int"); }
        }
        double number = string_[i] - '0';
        for (int j = 0; j < fractional; j++) {
            number /= 10;
        }
        if (fractional == 0) { res *= 10; }
        else { fractional++; }
        res += number;
    }
    if (negative) { res /= -1; }
    return res;
}

bool MyString::toBool() const {
    MyString str_false("false");
    if (*this == str_false) { return false; }
    MyString str_true("true");
    if (*this == str_true) { return true; }
    throw std::runtime_error("Cannot be cast to bool");
}

char MyString::operator[](int index) const {
    return getByIndex(index);
}

MyString::operator bool() const {
    if (getLength() > 0) { return true; }
    return false;
}

MyString MyString::operator()(int start, int end) const {
    return getSection(start, end);
}

MyString &MyString::operator=(const MyString &object) {
    if (this == &object) { return *this; }
    delete[] string_;
    string_ = object.getCopyArr();
    return *this;
}

MyString &MyString::operator=(MyString &&object) noexcept {
    if (this == &object) { return *this; }
    delete[] string_;
    string_ = object.string_;
    object.string_ = nullptr;
    return *this;
}

MyString &MyString::operator=(const char *string) {
    clear();
    extend(string);
    return *this;
}

MyString &MyString::operator+=(const MyString &str) {
    extend(str);
    return *this;
}

MyString &MyString::operator+=(const char *str) {
    extend(str);
    return *this;
}

MyString operator+(const MyString &str1, const MyString &str2) {
    MyString str(str1);
    str.extend(str2);
    return str;
}

MyString operator+(const MyString &str1, const char *str2) {
    MyString str(str1);
    str.extend(str2);
    return str;
}

MyString operator+(const char *str1, const MyString &str2) {
    MyString str(str1);
    str.extend(str2);
    return str;
}

bool operator==(const MyString &str1, const MyString &str2) {
    return str1.equal(str2);
}

bool operator==(const MyString &str1, const char *str2) {
    return str1.equal(str2);
}

bool operator==(const char *str1, const MyString &str2) {
    return str2.equal(str1);
}

bool operator!=(const MyString &str1, const MyString &str2) {
    return !str1.equal(str2);
}

bool operator!=(const MyString &str1, const char *str2) {
    return !str1.equal(str2);
}

bool operator!=(const char *str1, const MyString &str2) {
    return !str2.equal(str1);
}

std::ostream &operator<<(std::ostream &stream, const MyString &object) {
    stream << object.string_;
    return stream;
}

std::istream &operator>>(std::istream &stream, MyString &object) {
    char buf[6] = {0};
    object.clear();
    do {
        stream.get(buf, 6, '\n');
        object.extend(buf);
    } while (stream.gcount() != 0);
    stream.clear();
    stream.ignore();
    return stream;
}

void MyString::changeChar(int index, char new_char) {
    if (index >= getLength() || index < 0) { throw std::invalid_argument("Bad index"); }
    string_[index] = new_char;
}

MyString *MyString::splitIntoWords(int &count_words) const {
    int i = 0;
    bool previous_is_word = false;
    count_words = 0;
    while (string_[i] != '\0') {
        char current_char = string_[i];
        if (current_char != ' ' && !previous_is_word) {
            count_words++;
            previous_is_word = true;
        }
        if (current_char == ' ') { previous_is_word = false; }
        i++;
    }
    auto *res = new MyString[count_words];
    i = 0;
    int start = 0;
    int end = 0;
    previous_is_word = false;
    int splitted = 0;
    while (string_[i] != '\0') {
        if (!previous_is_word && string_[i] != ' ') {
            start = i;
            previous_is_word = true;
        }
        if (previous_is_word && string_[i] == ' ') {
            end = i - 1;
            res[splitted] = getSection(start, end);
            splitted++;
            previous_is_word = false;
        }
        i++;
    }
    if (previous_is_word) { res[splitted] = getSection(start, i - 1); }
    return res;
}
