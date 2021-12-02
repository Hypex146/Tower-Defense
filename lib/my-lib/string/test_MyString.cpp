#include "gtest/gtest.h"
#include "MyString.h"

MyString moveTest() {
    MyString str("Hello, World!");
    return str;
}

TEST(Constructors, ZeroParams_0) {
    MyString str;
    char *copyStr = str.getCopyArr();
    EXPECT_STREQ("", copyStr);
    delete[] copyStr;
}

TEST(Constructors, OneParams_0) {
    MyString str("1234567890");
    char *copyStr = str.getCopyArr();
    EXPECT_STREQ("1234567890", copyStr);
    delete[] copyStr;
}

TEST(Constructors, OneParams_1) {
    MyString str("");
    char *copyStr = str.getCopyArr();
    EXPECT_STREQ("", copyStr);
    delete[] copyStr;
}

TEST(Constructors, OneParams_2) {
    MyString str("Hello, World!");
    char *copyStr = str.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Constructors, Copy_0) {
    MyString str1("Hello, World!");
    MyString str2(str1);
    str1.clear();
    char *copyStr = str2.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Constructors, Copy_1) {
    MyString str1("");
    MyString str2(str1);
    str1.clear();
    char *copyStr = str2.getCopyArr();
    EXPECT_STREQ("", copyStr);
    delete[] copyStr;
}

TEST(Constructors, Move_0) {
    MyString str1(moveTest());
    str1.clear();
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("", copyStr);
    delete[] copyStr;
}

TEST(Operators, AssignmentCopy_0) {
    MyString str1("Hello, World!");
    MyString str2;
    str2 = str1;
    str1.clear();
    char *copyStr = str2.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, AssignmentCopy_1) {
    MyString str1("Hello, World!");
    MyString str2("TestTEST");
    str2 = str1;
    str1.clear();
    char *copyStr = str2.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, AssignmentCopy_2) {
    MyString str1("");
    MyString str2("TestTEST");
    str2 = str1;
    str1.clear();
    char *copyStr = str2.getCopyArr();
    EXPECT_STREQ("", copyStr);
    delete[] copyStr;
}

TEST(Operators, AssignmentMove_0) {
    MyString str1;
    str1 = moveTest();
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, AssignmentMove_1) {
    MyString str1("");
    str1 = moveTest();
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, AssignmentMove_2) {
    MyString str1("TestTEST");
    str1 = moveTest();
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, AssignmentChars_0) {
    MyString str1;
    str1 = "Hello, World!";
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, AssignmentChars_1) {
    MyString str1("");
    str1 = "Hello, World!";
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, AssignmentChars_2) {
    MyString str1("TestTest");
    str1 = "Hello, World!";
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, AssignmentChars_3) {
    MyString str1("TestTest");
    str1 = "";
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummObj_0) {
    MyString str1("Hello,");
    MyString str2(" World!");
    MyString str3 = str1 + str2;
    char *copyStr = str3.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummObj_1) {
    MyString str1("Hello, World!");
    MyString str2("");
    MyString str3 = str1 + str2;
    char *copyStr = str3.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummObj_2) {
    MyString str1("");
    MyString str2("Hello, World!");
    MyString str3 = str1 + str2;
    char *copyStr = str3.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummChar_0) {
    MyString str1("Hello,");
    MyString str2 = str1 + " World!";
    char *copyStr = str2.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummChar_1) {
    MyString str1("Hello, World!");
    MyString str2 = str1 + "";
    char *copyStr = str2.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummChar_2) {
    MyString str1("");
    MyString str2 = str1 + "Hello, World!";
    char *copyStr = str2.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummChar_3) {
    MyString str1("Hello,");
    MyString str2 = " World!" + str1;
    char *copyStr = str2.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummSelfObj_0) {
    MyString str1("Hello,");
    MyString str2(" World!");
    str1 += str2;
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummSelfObj_1) {
    MyString str1("");
    MyString str2("Hello, World!");
    str1 += str2;
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummSelfObj_2) {
    MyString str1("Hello, World!");
    MyString str2("");
    str1 += str2;
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummSelfChar_0) {
    MyString str1("Hello,");
    str1 += " World!";
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummSelfChar_1) {
    MyString str1("Hello, World!");
    str1 += "";
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, SummSelfChar_2) {
    MyString str1("");
    str1 += "Hello, World!";
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Operators, Equal_0) {
    MyString str1("Hello, World!");
    MyString str2("Hello, World!");
    EXPECT_EQ(str1 == str2, true);
}

TEST(Operators, Equal_1) {
    MyString str1("");
    MyString str2("");
    EXPECT_EQ(str1 == str2, true);
}

TEST(Operators, Equal_2) {
    MyString str1("Hello, World!");
    EXPECT_EQ(str1 == "Hello, World!", true);
}

TEST(Operators, Equal_3) {
    MyString str1("");
    EXPECT_EQ(str1 == "", true);
}

TEST(Operators, Equal_4) {
    MyString str1("");
    EXPECT_EQ(str1 == "1", false);
}

TEST(Operators, Equal_5) {
    MyString str1("Hello, World!");
    EXPECT_EQ(str1 == "", false);
}

TEST(Operators, Equal_6) {
    MyString str1("Hello, World!");
    MyString str2("");
    EXPECT_EQ(str1 == str2, false);
}

TEST(Operators, NotEqual_0) {
    MyString str1("Hello, World!");
    MyString str2("Hello, World!");
    EXPECT_EQ(str1 != str2, false);
}

TEST(Operators, NotEqual_1) {
    MyString str1("");
    MyString str2("");
    EXPECT_EQ(str1 != str2, false);
}

TEST(Operators, NotEqual_2) {
    MyString str1("Hello, World!");
    EXPECT_EQ(str1 != "Hello, World!", false);
}

TEST(Operators, NotEqual_3) {
    MyString str1("");
    EXPECT_EQ(str1 != "", false);
}

TEST(Operators, NotEqual_4) {
    MyString str1("");
    EXPECT_EQ(str1 != "1", true);
}

TEST(Operators, NotEqual_5) {
    MyString str1("Hello, World!");
    EXPECT_EQ(str1 != "", true);
}

TEST(Operators, NotEqual_6) {
    MyString str1("Hello, World!");
    MyString str2("");
    EXPECT_EQ(str1 != str2, true);
}

TEST(Operators, GetChar_0) {
    MyString str1("Hello, World!");
    EXPECT_EQ(str1[0], 'H');
}

TEST(Operators, GetChar_1) {
    MyString str1("Hello, World!");
    EXPECT_EQ(str1[0], 'H');
}

TEST(Operators, GetChar_2) {
    MyString str1("Hello, World!");
    EXPECT_EQ(str1[6], ' ');
}

TEST(Operators, GetChar_3) {
    MyString str1("Hello, World!");
    EXPECT_THROW(str1[13], std::runtime_error);
}

TEST(Operators, Bool_0) {
    MyString str("Hello, World!");
    bool res;
    if (str) { res = true; }
    else { res = false; }
    EXPECT_EQ(res, true);
}

TEST(Operators, Bool_1) {
    MyString str("");
    bool res;
    if (str) { res = true; }
    else { res = false; }
    EXPECT_EQ(res, false);
}

TEST(Operators, Cut_0) {
    MyString str1("Hello, World!");
    MyString str2("W");
    str1 = str1(7, 7);
    bool res = str2 == str1;
    EXPECT_EQ(res, true);
}

TEST(Operators, Cut_1) {
    MyString str("Hello, World!");
    EXPECT_THROW(str(6, 5), std::invalid_argument);
}


TEST(Methods, GetLength_0) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.getLength(), 13);
}

TEST(Methods, GetLength_1) {
    MyString str(" ");
    EXPECT_EQ(str.getLength(), 1);
}

TEST(Methods, GetLength_2) {
    MyString str("");
    EXPECT_EQ(str.getLength(), 0);
}

TEST(Methods, GetLength_3) {
    MyString str;
    EXPECT_EQ(str.getLength(), 0);
}

TEST(Methods, Clear_0) {
    MyString str("Hello, World!");
    str.clear();
    EXPECT_EQ(str.getLength(), 0);
}

TEST(Methods, Clear_1) {
    MyString str("");
    str.clear();
    EXPECT_EQ(str.getLength(), 0);
}

TEST(Methods, Clear_2) {
    MyString str;
    str.clear();
    EXPECT_EQ(str.getLength(), 0);
}

TEST(Methods, Equal_0) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.equal("Hello, World!"), true);
}

TEST(Methods, Equal_1) {
    MyString str("");
    EXPECT_EQ(str.equal(""), true);
}

TEST(Methods, Equal_2) {
    MyString str1("Hello, World!");
    MyString str2("Hello, World!");
    EXPECT_EQ(str1.equal(str2), true);
}

TEST(Methods, Equal_3) {
    MyString str1("");
    MyString str2("");
    EXPECT_EQ(str1.equal(str2), true);
}

TEST(Methods, ExtendChar_0) {
    MyString str("Hello");
    str.extend(", World!");
    char *copyStr = str.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Methods, ExtendChar_1) {
    MyString str("");
    str.extend("Hello, World!");
    char *copyStr = str.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Methods, ExtendChar_2) {
    MyString str("Hello, World!");
    str.extend("");
    char *copyStr = str.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Methods, ExtendObj_0) {
    MyString str1("Hello");
    MyString str2(", World!");
    str1.extend(str2);
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Methods, ExtendObj_1) {
    MyString str1("");
    MyString str2("Hello, World!");
    str1.extend(str2);
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Methods, ExtendObj_2) {
    MyString str1("Hello, World!");
    MyString str2("");
    str1.extend(str2);
    char *copyStr = str1.getCopyArr();
    EXPECT_STREQ("Hello, World!", copyStr);
    delete[] copyStr;
}

TEST(Methods, Contain_0) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.contain("Hello"), true);
}

TEST(Methods, Contain_1) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.contain(""), false);
}

TEST(Methods, Contain_2) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.contain(" "), true);
}

TEST(Methods, Contain_3) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.contain(", "), true);
}

TEST(Methods, Contain_4) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.contain("!"), true);
}

TEST(Methods, Contain_5) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.contain("l!"), false);
}

TEST(Methods, Contain_6) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.contain("HelLO, World!", false), true);
}

TEST(Methods, Contain_7) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.contain("HelLO, World!"), false);
}

TEST(Methods, Contain_8) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.contain("hELL", false), true);
}

TEST(Methods, Begin_0) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.begin("Hello, World!"), true);
}

TEST(Methods, Begin_1) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.begin("Hello, "), true);
}

TEST(Methods, Begin_2) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.begin("He"), true);
}

TEST(Methods, Begin_3) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.begin(""), false);
}

TEST(Methods, Begin_4) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.begin(" "), false);
}

TEST(Methods, Begin_5) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.begin("HeLlo,"), false);
}

TEST(Methods, Begin_6) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.begin("HeLlo,", false), true);
}

TEST(Methods, Begin_7) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.begin("HeLlo, wOrLd!", false), true);
}

TEST(Methods, Begin_8) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.begin("ello, Wor"), false);
}

TEST(Methods, Begin_9) {
    MyString str("");
    EXPECT_EQ(str.begin(""), false);
}

TEST(Methods, End_0) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.end("Hello, World!"), true);
}

TEST(Methods, End_1) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.end("World!"), true);
}

TEST(Methods, End_2) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.end("!"), true);
}

TEST(Methods, End_3) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.end("Worl"), false);
}

TEST(Methods, End_4) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.end("HelLo, World!"), false);
}

TEST(Methods, End_5) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.end(""), false);
}

TEST(Methods, End_6) {
    MyString str("");
    EXPECT_EQ(str.end(""), false);
}

TEST(Methods, End_7) {
    MyString str("Hello, World!");
    EXPECT_EQ(str.end("HelLo, woRlD!", false), true);
}

TEST(Methods, ToInt_0) {
    MyString str("123456789");
    EXPECT_EQ(str.toInt(), 123456789);
}

TEST(Methods, ToInt_1) {
    MyString str("-123456789");
    EXPECT_EQ(str.toInt(), -123456789);
}

TEST(Methods, ToInt_2) {
    MyString str("0");
    EXPECT_EQ(str.toInt(), 0);
}

TEST(Methods, ToInt_3) {
    MyString str("");
    EXPECT_THROW(str.toInt(), std::runtime_error);
}

TEST(Methods, ToInt_4) {
    MyString str("4713g576");
    EXPECT_THROW(str.toInt(), std::runtime_error);
}

TEST(Methods, ToInt_5) {
    MyString str("12-3456789");
    EXPECT_THROW(str.toInt(), std::runtime_error);
}

TEST(Methods, ToInt_6) {
    MyString str("-");
    EXPECT_EQ(str.toInt(), 0);
}

TEST(Methods, ToDouble_0) {
    MyString str("2.75");
    EXPECT_EQ(str.toDouble(), 2.75);
}

TEST(Methods, ToDouble_1) {
    MyString str("-2.75");
    EXPECT_EQ(str.toDouble(), -2.75);
}

TEST(Methods, ToDouble_2) {
    MyString str("123.456789");
    EXPECT_EQ(str.toDouble(), 123.456789);
}

TEST(Methods, ToDouble_3) {
    MyString str("-123.456789");
    EXPECT_EQ(str.toDouble(), -123.456789);
}

TEST(Methods, ToDouble_4) {
    MyString str("0.123");
    EXPECT_NEAR(str.toDouble(), 0.123, 0.0001);
}

TEST(Methods, ToDouble_5) {
    MyString str("-0.123");
    EXPECT_NEAR(str.toDouble(), -0.123, 0.0001);
}

TEST(Methods, ToDouble_6) {
    MyString str("0");
    EXPECT_EQ(str.toDouble(), 0);
}

TEST(Methods, ToDouble_7) {
    MyString str("-0");
    EXPECT_EQ(str.toDouble(), 0);
}

TEST(Methods, ToDouble_8) {
    MyString str(".123");
    EXPECT_NEAR(str.toDouble(), 0.123, 0.0001);
}

TEST(Methods, ToDouble_9) {
    MyString str("123.45g6");
    EXPECT_THROW(str.toDouble(), std::runtime_error);
}

TEST(Methods, ToDouble_10) {
    MyString str("123.45g6");
    EXPECT_THROW(str.toDouble(), std::runtime_error);
}

TEST(Methods, ToDouble_11) {
    MyString str("-123.4-56");
    EXPECT_THROW(str.toDouble(), std::runtime_error);
}

TEST(Methods, ToBool_0) {
    MyString str("true");
    EXPECT_EQ(str.toBool(), true);
}

TEST(Methods, ToBool_1) {
    MyString str("false");
    EXPECT_EQ(str.toBool(), false);
}

TEST(Methods, ToBool_2) {
    MyString str("TrueFalse");
    EXPECT_THROW(str.toDouble(), std::runtime_error);
}

TEST(Methods, GetSection_0) {
    MyString str("Hello, World!");
    bool res = str == str.getSection(0, 12);
    EXPECT_EQ(res, true);
}

TEST(Methods, GetSection_1) {
    MyString str("Hello, World!");
    EXPECT_THROW(str.getSection(0, 13), std::invalid_argument);
}

TEST(Methods, GetSection_2) {
    MyString str("Hello, World!");
    EXPECT_THROW(str.getSection(-1, 5), std::invalid_argument);
}

TEST(Methods, GetSection_3) {
    MyString str("Hello, World!");
    EXPECT_THROW(str.getSection(6, 5), std::invalid_argument);
}

TEST(Methods, GetSection_4) {
    MyString str1("Hello, World!");
    MyString str2("o, Wo");
    bool res = str2 == str1.getSection(4, 8);
    EXPECT_EQ(res, true);
}

TEST(Methods, GetSection_5) {
    MyString str1("Hello, World!");
    MyString str2("W");
    bool res = str2 == str1.getSection(7, 7);
    EXPECT_EQ(res, true);
}

TEST(Methods, GetSection_6) {
    MyString str1("Hello, World!");
    MyString str2("o");
    bool res = str2 == str1.getSection(7, 7);
    EXPECT_EQ(res, false);
}

TEST(Methods, Cut_0) {
    MyString str1("Hello, World!");
    MyString str2("W");
    str1.cut(7, 7);
    bool res = str2 == str1;
    EXPECT_EQ(res, true);
}

TEST(Methods, Cut_1) {
    MyString str("Hello, World!");
    EXPECT_THROW(str.cut(6, 5), std::invalid_argument);
}
