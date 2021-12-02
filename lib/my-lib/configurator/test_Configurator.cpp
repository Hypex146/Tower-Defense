#include "gtest/gtest.h"
#include "Configurator.h"

#define FIRST_TIME false
#define FILE_TEST1_EXISTS true

TEST(Constructors, CharParam_0) {
    Configurator cfg("test.yml");
    char *file_name = cfg.getCopyOfFileName();
    EXPECT_STREQ(file_name, "test.yml");
    delete[] file_name;
}

TEST(Constructors, CharParam_1) {
    Configurator cfg("");
    char *file_name = cfg.getCopyOfFileName();
    EXPECT_STREQ(file_name, "");
    delete[] file_name;
}

TEST(Constructors, MyStringParam_0) {
    MyString str("test.yml");
    Configurator cfg(str);
    char *file_name = cfg.getCopyOfFileName();
    EXPECT_STREQ(file_name, "test.yml");
    delete[] file_name;
}

TEST(Constructors, MyStringParam_1) {
    MyString str("");
    Configurator cfg(str);
    char *file_name = cfg.getCopyOfFileName();
    EXPECT_STREQ(file_name, "");
    delete[] file_name;
}

TEST(Methods, GetInt_0) {
    Configurator cfg("test.yml");
    MyString key("key3");
    EXPECT_EQ(cfg.getInt(key), 123456);
}

TEST(Methods, GetInt_1) {
    Configurator cfg("test.yml");
    MyString key("key4");
    EXPECT_EQ(cfg.getInt(key), 97854);
}

TEST(Methods, GetInt_2) {
    Configurator cfg("test.yml");
    MyString key("key5");
    EXPECT_EQ(cfg.getInt(key), -1254);
}

TEST(Methods, GetInt_3) {
    Configurator cfg("test.yml");
    MyString key("key11");
    EXPECT_EQ(cfg.getInt(key), 1545);
}

TEST(Methods, GetInt_4) {
    Configurator cfg("test.yml");
    MyString key("key1");
    EXPECT_THROW(cfg.getInt(key), std::runtime_error);
}

TEST(Methods, GetInt_5) {
    Configurator cfg("tst.yml");
    MyString key("key3");
    EXPECT_THROW(cfg.getInt(key), std::runtime_error);
}

TEST(Methods, GetDouble_0) {
    Configurator cfg("test.yml");
    MyString key("key7");
    EXPECT_NEAR(cfg.getDouble(key), 7.1548, 0.00001);
}

TEST(Methods, GetDouble_1) {
    Configurator cfg("test.yml");
    MyString key("key12");
    EXPECT_EQ(cfg.getDouble(key), 0.5);
}

TEST(Methods, GetDouble_2) {
    Configurator cfg("test.yml");
    MyString key("key8");
    EXPECT_NEAR(cfg.getDouble(key), -0.45875, 0.00001);
}

TEST(Methods, GetDouble_3) {
    Configurator cfg("test.yml");
    MyString key("key1");
    EXPECT_THROW(cfg.getDouble(key), std::runtime_error);
}

TEST(Methods, GetDouble_4) {
    Configurator cfg("tst.yml");
    MyString key("key8");
    EXPECT_THROW(cfg.getDouble(key), std::runtime_error);
}

TEST(Methods, GetBool_0) {
    Configurator cfg("test.yml");
    MyString key("key13");
    EXPECT_EQ(cfg.getBool(key), true);
}

TEST(Methods, GetBool_1) {
    Configurator cfg("test.yml");
    MyString key("key14");
    EXPECT_EQ(cfg.getBool(key), false);
}

TEST(Methods, GetBool_2) {
    Configurator cfg("test.yml");
    MyString key("key15");
    EXPECT_EQ(cfg.getBool(key), true);
}

TEST(Methods, GetBool_3) {
    Configurator cfg("tst.yml");
    MyString key("key15");
    EXPECT_THROW(cfg.getBool(key), std::runtime_error);
}

TEST(Methods, GetBool_4) {
    Configurator cfg("test.yml");
    MyString key("key16");
    EXPECT_THROW(cfg.getBool(key), std::runtime_error);
}

TEST(Methods, GetString_0) {
    Configurator cfg("test.yml");
    MyString key("key2");
    MyString string = cfg.getString(key);
    EXPECT_EQ(string == "second", true);
}

TEST(Methods, GetString_1) {
    Configurator cfg("test.yml");
    MyString key("key1");
    MyString string = cfg.getString(key);
    EXPECT_EQ(string == "first", true);
}

TEST(Methods, GetString_2) {
    Configurator cfg("test.yml");
    MyString key("key9");
    MyString string = cfg.getString(key);
    EXPECT_EQ(string == "qwerty", true);
}

TEST(Methods, GetString_3) {
    Configurator cfg("test.yml");
    MyString key("key10");
    MyString string = cfg.getString(key);
    EXPECT_EQ(string == "  fjridkd", true);
}

TEST(Methods, GetString_4) {
    Configurator cfg("test.yml");
    MyString key("key17");
    MyString string = cfg.getString(key);
    EXPECT_EQ(string == "string", true);
}

TEST(Methods, GetString_5) {
    Configurator cfg("test.yml");
    MyString key("key6");
    EXPECT_THROW(cfg.getString(key), std::runtime_error);
}

TEST(Methods, GetString_6) {
    Configurator cfg("test.yml");
    MyString key("keeeeey6");
    EXPECT_THROW(cfg.getString(key), std::invalid_argument);
}

TEST(Methods, GetString_7) {
    Configurator cfg("test.yml");
    MyString key("key18");
    MyString string = cfg.getString(key);
    EXPECT_EQ(string == "", true);
}

TEST(Methods, GetString_8) {
    Configurator cfg("test.yml");
    MyString key("key9");
    MyString string = cfg.getString(key);
    EXPECT_EQ(string == "qweerty", false);
}

TEST(Methods, IsExist_0) {
    Configurator cfg("test.yml");
    EXPECT_EQ(cfg.isExist(), true);
}

TEST(Methods, IsExist_1) {
    Configurator cfg("test.yl");
    EXPECT_EQ(cfg.isExist(), false);
}

TEST(Methods, HasKey_0) {
    Configurator cfg("test.yml");
    MyString key("key1");
    EXPECT_EQ(cfg.hasKey(key), true);
}

TEST(Methods, HasKey_1) {
    Configurator cfg("test.yml");
    MyString key("key7");
    EXPECT_EQ(cfg.hasKey(key), true);
}

TEST(Methods, HasKey_2) {
    Configurator cfg("test.yml");
    MyString key("key18");
    EXPECT_EQ(cfg.hasKey(key), true);
}

TEST(Methods, HasKey_3) {
    Configurator cfg("test.yml");
    MyString key("keeeey7");
    EXPECT_EQ(cfg.hasKey(key), false);
}

TEST(Methods, HasKey_4) {
    Configurator cfg("test.yl");
    MyString key("key18");
    EXPECT_THROW(cfg.hasKey(key), std::runtime_error);
}

TEST(Methods, SetInt_0) {
    Configurator cfg("test.yml");
    MyString key("MyKey1");
    if (FIRST_TIME) {
        cfg.setInt(key, 777);
        EXPECT_EQ(cfg.getInt(key), 777);
    } else {
        EXPECT_THROW(cfg.setInt(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetInt_1) {
    Configurator cfg("test.yml");
    MyString key("MyKey2");
    if (FIRST_TIME) {
        cfg.setInt(key, 123);
        EXPECT_EQ(cfg.getInt(key), 123);
    } else {
        EXPECT_THROW(cfg.setInt(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetInt_2) {
    Configurator cfg("test.yml");
    MyString key("MyKey3");
    if (FIRST_TIME) {
        cfg.setInt(key, -54);
        EXPECT_EQ(cfg.getInt(key), -54);
    } else {
        EXPECT_THROW(cfg.setInt(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetInt_3) {
    Configurator cfg("test.yl");
    MyString key("MyKeyERROR");
    EXPECT_THROW(cfg.setInt(key, -54), std::runtime_error);
}

TEST(Methods, SetInt_4) {
    MyString for_clear("tmp_file.txt");
    Configurator::clearFile(for_clear);
    Configurator cfg("test.yml");
    MyString key("MyKeyR0");
    cfg.setInt(key, 777, true);
    EXPECT_EQ(cfg.getInt(key), 777);
    cfg.setInt(key, 999, true);
    EXPECT_EQ(cfg.getInt(key), 999);
}

TEST(Methods, SetDouble_0) {
    Configurator cfg("test.yml");
    MyString key("MyKey4");
    if (FIRST_TIME) {
        cfg.setDouble(key, 1);
        EXPECT_EQ(cfg.getDouble(key), 1);
    } else {
        EXPECT_THROW(cfg.setDouble(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetDouble_1) {
    Configurator cfg("test.yml");
    MyString key("MyKey5");
    if (FIRST_TIME) {
        cfg.setDouble(key, 5.25);
        EXPECT_EQ(cfg.getDouble(key), 5.25);
    } else {
        EXPECT_THROW(cfg.setDouble(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetDouble_2) {
    Configurator cfg("test.yml");
    MyString key("MyKey6");
    if (FIRST_TIME) {
        cfg.setDouble(key, -125.2);
        EXPECT_EQ(cfg.getDouble(key), -125.2);
    } else {
        EXPECT_THROW(cfg.setDouble(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetDouble_3) {
    Configurator cfg("test.yl");
    MyString key("MyKeyERROR");
    EXPECT_THROW(cfg.setDouble(key, -54), std::runtime_error);
}

TEST(Methods, SetDouble_4) {
    Configurator cfg("test.yml");
    MyString key("MyKeyR1");
    cfg.setDouble(key, 1, true);
    EXPECT_EQ(cfg.getDouble(key), 1);
    cfg.setDouble(key, -125.2, true);
    EXPECT_EQ(cfg.getDouble(key), -125.2);
}

TEST(Methods, SetBool_0) {
    Configurator cfg("test.yml");
    MyString key("MyKey7");
    if (FIRST_TIME) {
        cfg.setBool(key, true);
        EXPECT_EQ(cfg.getBool(key), true);
    } else {
        EXPECT_THROW(cfg.setDouble(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetBool_1) {
    Configurator cfg("test.yml");
    MyString key("MyKey8");
    if (FIRST_TIME) {
        cfg.setBool(key, false);
        EXPECT_EQ(cfg.getBool(key), false);
    } else {
        EXPECT_THROW(cfg.setDouble(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetBool_2) {
    Configurator cfg("test.yml");
    MyString key("MyKey9");
    if (FIRST_TIME) {
        cfg.setBool(key, true);
        EXPECT_EQ(cfg.getBool(key), true);
    } else {
        EXPECT_THROW(cfg.setDouble(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetBool_3) {
    Configurator cfg("test.yl");
    MyString key("MyKeyERROR");
    EXPECT_THROW(cfg.setBool(key, true), std::runtime_error);
}

TEST(Methods, SetBool_4) {
    Configurator cfg("test.yml");
    MyString key("MyKeyR2");
    cfg.setBool(key, true, true);
    EXPECT_EQ(cfg.getBool(key), true);
    cfg.setBool(key, false, true);
    EXPECT_EQ(cfg.getBool(key), false);
}

TEST(Methods, SetString_0) {
    Configurator cfg("test.yml");
    MyString key("MyKey10");
    MyString string("Hello!");
    if (FIRST_TIME) {
        cfg.setString(key, string);
        EXPECT_EQ(cfg.getString(key) == "Hello!", true);
    } else {
        EXPECT_THROW(cfg.setDouble(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetString_1) {
    Configurator cfg("test.yml");
    MyString key("MyKey11");
    MyString string("Hello, World!");
    if (FIRST_TIME) {
        cfg.setString(key, string);
        EXPECT_EQ(cfg.getString(key) == "Hello, World!", true);
    } else {
        EXPECT_THROW(cfg.setDouble(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetString_2) {
    Configurator cfg("test.yml");
    MyString key("MyKey12");
    MyString string("");
    if (FIRST_TIME) {
        cfg.setString(key, string);
        EXPECT_EQ(cfg.getString(key) == "", true);
    } else {
        EXPECT_THROW(cfg.setDouble(key, 777);, std::invalid_argument);
    }
}

TEST(Methods, SetString_3) {
    Configurator cfg("test.yl");
    MyString key("MyKeyERROR");
    MyString string("");
    EXPECT_THROW(cfg.setString(key, string), std::runtime_error);
}

TEST(Methods, SetString_4) {
    Configurator cfg("test.yml");
    MyString key("MyKeyR3");
    MyString string("Hello, World!");
    cfg.setString(key, string, true);
    EXPECT_EQ(cfg.getString(key) == "Hello, World!", true);
    string = "Hello!";
    cfg.setString(key, string, true);
    EXPECT_EQ(cfg.getString(key) == "Hello!", true);
}

TEST(Methods, CreateFile_0) {
    Configurator cfg("test1.yml");
    if (FILE_TEST1_EXISTS) {
        EXPECT_THROW(cfg.createFile(), std::runtime_error);
    } else {
        EXPECT_EQ(cfg.isExist(), false);
        cfg.createFile();
        EXPECT_EQ(cfg.isExist(), true);
        EXPECT_THROW(cfg.createFile(), std::runtime_error);
    }
}

TEST(Methods, SplitKeyAndValue_0) {
    MyString string("key1: value");
    MyString key;
    MyString value;
    Configurator::splitKeyAndValue(string, key, value);
    EXPECT_EQ(key == "key1", true);
    EXPECT_EQ(value == "value", true);
}

TEST(Methods, SplitKeyAndValue_1) {
    MyString string("key1:value");
    MyString key;
    MyString value;
    Configurator::splitKeyAndValue(string, key, value);
    EXPECT_EQ(key == "key1", true);
    EXPECT_EQ(value == "value", true);
}

TEST(Methods, SplitKeyAndValue_2) {
    MyString string("key1:       value     ");
    MyString key;
    MyString value;
    Configurator::splitKeyAndValue(string, key, value);
    EXPECT_EQ(key == "key1", true);
    EXPECT_EQ(value == "value", true);
}

TEST(Methods, SplitKeyAndValue_3) {
    MyString string("key1:");
    MyString key;
    MyString value;
    Configurator::splitKeyAndValue(string, key, value);
    EXPECT_EQ(key == "key1", true);
    EXPECT_EQ(value == "", true);
}

TEST(Methods, SplitKeyAndValue_4) {
    MyString string("key1:          ");
    MyString key;
    MyString value;
    Configurator::splitKeyAndValue(string, key, value);
    EXPECT_EQ(key == "key1", true);
    EXPECT_EQ(value == "", true);
}

TEST(Methods, SplitKeyAndValue_5) {
    MyString string(": value");
    MyString key;
    MyString value;
    EXPECT_THROW(Configurator::splitKeyAndValue(string, key, value),
                 std::invalid_argument);
}

TEST(Methods, SplitKeyAndValue_6) {
    MyString string("key1 value");
    MyString key;
    MyString value;
    EXPECT_THROW(Configurator::splitKeyAndValue(string, key, value),
                 std::invalid_argument);
}

TEST(Methods, RmTrash_0) {
    MyString string("string string");
    string = Configurator::rmTrash(string);
    EXPECT_EQ(string == "string string", true);
}

TEST(Methods, RmTrash_1) {
    MyString string("   string string   ");
    string = Configurator::rmTrash(string);
    EXPECT_EQ(string == "string string", true);
}

TEST(Methods, RmTrash_2) {
    MyString string("  string string     ");
    string = Configurator::rmTrash(string);
    EXPECT_EQ(string == "string string", true);
}

TEST(Methods, RmTrash_3) {
    MyString string(" ");
    string = Configurator::rmTrash(string);
    EXPECT_EQ(string == "", true);
}

TEST(Methods, RmTrash_4) {
    MyString string("       ");
    string = Configurator::rmTrash(string);
    EXPECT_EQ(string == "", true);
}
