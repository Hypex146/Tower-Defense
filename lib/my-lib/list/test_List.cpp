#include "List.h"
#include "gtest/gtest.h"

TEST(Constructors, ZeroParams_0) {
    List<int> list;
}

TEST(Constructors, Assignment_0) {
    List<int> list;
    list.insert(1, 0);
    list.insert(0, 0);
    list.insert(2, 2);
    List<int> list2(list);
    list.remove(0);
    list.remove(0);
    EXPECT_EQ(list2.take(0), 0);
    EXPECT_EQ(list2.take(1), 1);
    EXPECT_EQ(list2.take(2), 2);
}

TEST(Operators, Assignment_0) {
    List<int> list;
    list.insert(1, 0);
    list.insert(0, 0);
    list.insert(2, 2);
    List<int> list2;
    list2 = list;
    list.remove(0);
    list.remove(0);
    EXPECT_EQ(list2.take(0), 0);
    EXPECT_EQ(list2.take(1), 1);
    EXPECT_EQ(list2.take(2), 2);
}

TEST(Methods, Insert_0) {
    List<int> list;
    list.insert(1, 0);
    list.insert(0, 0);
    list.insert(2, 2);
    EXPECT_EQ(list.take(0), 0);
    EXPECT_EQ(list.take(1), 1);
    EXPECT_EQ(list.take(2), 2);
    list.insert(3, 1);
    EXPECT_EQ(list.take(1), 3);
    list.insert(4, 0);
    EXPECT_EQ(list.take(4), 2);
    list.insert(5, 999);
    EXPECT_EQ(list.take(5), 5);
}

TEST(Methods, Remove_0) {
    List<int> list;
    list.insert(1, 0);
    list.insert(0, 0);
    list.insert(2, 2);
    list.remove(1);
    EXPECT_EQ(list.take(0), 0);
    EXPECT_EQ(list.take(1), 2);
}

TEST(Methods, Take_0) {
    List<int> list;
    list.insert(1, 0);
    list.insert(0, 0);
    list.insert(2, 2);
    EXPECT_EQ(list.take(0), 0);
    EXPECT_EQ(list.take(1), 1);
    EXPECT_EQ(list.take(999), 2);
}

TEST(Methods, TakePtr_0) {
    List<int> list;
    list.insert(1, 0);
    list.insert(0, 0);
    list.insert(2, 2);
    *list.takePtr(1) = 5;
    EXPECT_EQ(list.take(1), 5);
}

TEST(Methods, Swap_0) {
    List<int> list;
    list.insert(1, 0);
    list.insert(0, 0);
    list.insert(2, 2);
    list.swap(0, 2);
    EXPECT_EQ(list.take(0), 2);
    EXPECT_EQ(list.take(1), 1);
    EXPECT_EQ(list.take(2), 0);
}

TEST(Methods, GetValueCount_0) {
    List<int> list;
    list.insert(1, 0);
    list.insert(0, 0);
    list.insert(2, 2);
    list.insert(3, 0);
    list.insert(1, 0);
    EXPECT_EQ(list.getValueCount(0), 1);
    EXPECT_EQ(list.getValueCount(1), 2);
    EXPECT_EQ(list.getValueCount(555), 0);
}

TEST(Methods, getValueIndex_0) {
    List<int> list;
    list.insert(1, 0);
    list.insert(0, 0);
    list.insert(2, 2);
    list.insert(3, 0);
    list.insert(1, 0);
    EXPECT_EQ(list.getValueIndex(0), 2);
    EXPECT_EQ(list.getValueIndex(1), 0);
}

TEST(Methods, GetLen_0) {
    List<int> list;
    list.insert(1, 0);
    list.insert(0, 0);
    list.insert(2, 2);
    list.insert(3, 0);
    list.insert(1, 0);
    EXPECT_EQ(list.getLen(), 5);
}
