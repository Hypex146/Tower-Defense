#ifndef TOWER_DEFENSE_MYSTRING_H
#define TOWER_DEFENSE_MYSTRING_H

class MyString {
private:
    // указатель на строку
    char *string_;

    // изменить размер выделенной памяти под строку
    void extendSize(int new_size);

    // получить длину внешней строки
    static int getLengthOtherString(const char *str);

    // получить пару по регистру для переданного символа (Капс/не капс) (А/а и т.п.)
    static char getCasePair(char a);

public:

    // создаёт пустую строку
    MyString();

    // создаёт строку на основе переданной
    explicit MyString(const char *string);

    // конструктор копирования
    MyString(const MyString &object);

    // конструктор перемещения
    MyString(MyString &&object) noexcept;

    // диструктор
    ~MyString();

    void changeChar(int index, char new_char);

    // получить длину строки
    int getLength() const;

    // получит копию строки
    char *getCopyArr() const;

    // сделать строку пустой
    void clear();

    // расширить строку, дабовив к ней переданную строку
    void extend(const char *str);

    // расширить строку, дабовив к ней переданную строку
    void extend(const MyString &str);

    // есть ли в нашей строке переданная
    bool contain(const char *str, bool case_sensitive = true) const;

    // начинается ли наша строка с переданной
    bool begin(const char *str, bool case_sensitive = true) const;

    // заканчивается ли наша строка на переданную
    bool end(const char *str, bool case_sensitive = true) const;

    // равны ли строки
    bool equal(const MyString &str) const;

    // равны ли строки
    bool equal(const char *str) const;

    char getByIndex(int index) const;

    MyString getSection(int start, int end) const;

    void cut(int start, int end);

    int toInt() const;

    double toDouble() const;

    bool toBool() const;

    char operator[](int index) const;

    explicit operator bool() const;

    MyString operator()(int start, int end) const;

    // оператор копирования
    MyString &operator=(const MyString &object);

    // оператор перемещения
    MyString &operator=(MyString &&object) noexcept;

    // оператор копирования строки
    MyString &operator=(const char *string);

    // оператор прибавления
    MyString &operator+=(const MyString &str);

    // оператор прибавления
    MyString &operator+=(const char *str);

    // оператор сложения
    friend MyString operator+(const MyString &str1, const MyString &str2);

    // оператор сложения
    friend MyString operator+(const MyString &str1, const char *str2);

    // оператор сложения
    friend MyString operator+(const char *str1, const MyString &str2);

    // оператор проверки на равенство
    friend bool operator==(const MyString &str1, const MyString &str2);

    // оператор проверки на равенство
    friend bool operator==(const MyString &str1, const char *str2);

    // оператор проверки на равенство
    friend bool operator==(const char *str1, const MyString &str2);

    // оператор проверки на неравенство
    friend bool operator!=(const MyString &str1, const MyString &str2);

    // оператор проверки на неравенство
    friend bool operator!=(const MyString &str1, const char *str2);

    // оператор проверки на неравенство
    friend bool operator!=(const char *str1, const MyString &str2);

    // оператор вывода
    friend std::ostream &operator<<(std::ostream &stream, const MyString &object);

    // оператор ввода
    friend std::istream &operator>>(std::istream &stream, MyString &object);

    MyString *splitIntoWords(int &count_words) const;
};

MyString operator+(const MyString &str1, const MyString &str2);

MyString operator+(const MyString &str1, const char *str2);

bool operator==(const MyString &str1, const MyString &str2);

bool operator==(const MyString &str1, const char *str2);

bool operator==(const char *str1, const MyString &str2);

bool operator!=(const MyString &str1, const MyString &str2);

bool operator!=(const MyString &str1, const char *str2);

bool operator!=(const char *str1, const MyString &str2);

std::ostream &operator<<(std::ostream &stream, const MyString &object);

std::istream &operator>>(std::istream &stream, MyString &object);

#endif //TOWER_DEFENSE_MYSTRING_H
