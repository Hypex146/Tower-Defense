#define MY_LIBS_INCLUDE
#define STD_LIBS_INCLUDE
#include "AllHeaders.h"
#include "gtest/gtest.h"

TEST(Constructors, ZeroParams_0) {
    Graph<int> graph;
}

TEST(Methods, AddVertex_0) {
    Graph<int> graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    EXPECT_EQ(graph.hasVertex(0), true);
    EXPECT_EQ(graph.hasVertex(1), true);
    EXPECT_EQ(graph.hasVertex(2), true);
    EXPECT_EQ(graph.hasVertex(3), false);
}

TEST(Methods, AddEdge_0) {
    Graph<int> graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    EXPECT_EQ(graph.hasEdge(0, 1), true);
    EXPECT_EQ(graph.hasEdge(0, 2), true);
    EXPECT_EQ(graph.hasEdge(1, 2), false);
}

TEST(Methods, GetVertexPtr_0) {
    Graph<int> graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    EXPECT_EQ(graph.getVertexPtrById(0)->id_, 0);
    EXPECT_EQ(graph.getVertexPtrById(1)->id_, 1);
    EXPECT_EQ(graph.getVertexPtrById(2)->id_, 2);
}

TEST(Methods, RmVertex_0) {
    Graph<int> graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.rmVertex(0);
    EXPECT_EQ(graph.hasVertex(0), false);
    EXPECT_EQ(graph.hasVertex(1), true);
    EXPECT_EQ(graph.hasVertex(2), true);
    EXPECT_EQ(graph.hasVertex(3), false);
    EXPECT_EQ(graph.hasEdge(1, 2), false);
}

TEST(Methods, RmEdge_0) {
    Graph<int> graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.rmEdge(0, 1);
    EXPECT_EQ(graph.hasEdge(0, 1), false);
    EXPECT_EQ(graph.hasEdge(0, 2), true);
    EXPECT_EQ(graph.hasEdge(1, 2), false);
}

TEST(Methods, HasWay_0) {
    Graph<int> graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    EXPECT_EQ(graph.hasWay(0, 0), true);
    EXPECT_EQ(graph.hasWay(0, 1), true);
    EXPECT_EQ(graph.hasWay(0, 2), true);
    EXPECT_EQ(graph.hasWay(2, 1), true);
    EXPECT_EQ(graph.hasWay(2, 3), false);
}

TEST(Methods, GetWay_0) {
    Graph<int> graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);
    graph.addEdge(0, 3);
    graph.addEdge(3, 1);
    graph.addEdge(1, 4);
    graph.addEdge(0, 4);
    graph.addEdge(4, 2);
    List<int> list1 = graph.getWay(0, 2);
    EXPECT_EQ(list1.take(0), 5);
    EXPECT_EQ(list1.take(1), 1);
    EXPECT_EQ(list1.take(2), 3);
    List<int> list2 = graph.getWay(0, 1);
    EXPECT_EQ(list2.take(0), 5);
    EXPECT_EQ(list2.take(1), 1);
    EXPECT_EQ(list2.take(2), 4);
    List<int> list3 = graph.getWay(0, 5);
    EXPECT_EQ(list3.getLen(), 0);
    List<int> list4 = graph.getWay(0, 3);
    EXPECT_EQ(list4.take(0), 5);
    EXPECT_EQ(list4.take(1), 2);
}

TEST(Methods, GetNextStep_0) {
    Graph<int> graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);
    graph.addEdge(0, 3);
    graph.addEdge(3, 1);
    graph.addEdge(1, 4);
    graph.addEdge(0, 4);
    graph.addEdge(4, 2);
    EXPECT_EQ(graph.getNextStep(0, 3), 2);
    EXPECT_EQ(graph.getNextStep(1, 2), 1);
    EXPECT_EQ(graph.getNextStep(0, 1), 1);
    EXPECT_EQ(graph.getNextStep(0, 0), -1);
    List<int> list = graph.getWay(0, 0);
    list.print();
}
