#include "gtest/gtest.h"
#include "Queue.h"

TEST(Constructors, ZeroParams_0) {
    Queue<int> queue;
}

TEST(Methods, Enqueue_0) {
    Queue<int> queue;
    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
}

TEST(Methods, Dequeue_0) {
    Queue<int> queue;
    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    EXPECT_EQ(queue.dequeue(), 0);
    EXPECT_EQ(queue.dequeue(), 1);
    EXPECT_EQ(queue.dequeue(), 2);
}

TEST(Methods, Empty_0) {
    Queue<int> queue;
    EXPECT_EQ(queue.empty(), true);
    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    EXPECT_EQ(queue.empty(), false);
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    EXPECT_EQ(queue.empty(), true);
}
