#include "CppUTest/TestHarness.h"

#include "stack.h"
#include <array>

TEST_GROUP(Stack)
{
    static constexpr int STACK_SIZE {10};
    std::array<int, STACK_SIZE> m_buffer {};
    Stack m_stack = Stack(m_buffer.size(), m_buffer.data());
    void setup()
    {
        UNSIGNED_LONGS_EQUAL(0U, m_stack.size());
    }

    void teardown()
    {
        m_stack.clear();
        UNSIGNED_LONGS_EQUAL(0U, m_stack.size());
    }
};

TEST(Stack, push_expected)
{
    m_stack.push(10);
    UNSIGNED_LONGS_EQUAL(1, m_stack.size());
}

TEST(Stack, pop_expected)
{
    LONGS_EQUAL(0, m_stack.pop());
}

TEST(Stack, peek_expected)
{
    LONGS_EQUAL(0, m_stack.peek());
}
