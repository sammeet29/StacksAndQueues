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
    CHECK(m_stack.push(10));
    UNSIGNED_LONGS_EQUAL(1, m_stack.size());
}

TEST(Stack, pop_expected)
{
    CHECK(m_stack.push(20));
    UNSIGNED_LONGS_EQUAL(1, m_stack.size());
    LONGS_EQUAL(20, m_stack.pop());
    UNSIGNED_LONGS_EQUAL(0, m_stack.size());
}

TEST(Stack, pop_when_stack_empty)
{
    CHECK(m_stack.is_empty());
    LONGS_EQUAL(-1, m_stack.pop());
}

TEST(Stack, peek_expected)
{
    CHECK(m_stack.push(20));
    UNSIGNED_LONGS_EQUAL(1, m_stack.size());
    LONGS_EQUAL(20, m_stack.peek());
    UNSIGNED_LONGS_EQUAL(1, m_stack.size());
}

TEST(Stack, peek_when_stack_empty)
{
    CHECK(m_stack.is_empty());
    LONGS_EQUAL(-1, m_stack.peek());
}

TEST(Stack, is_empty_expected)
{
    CHECK(m_stack.is_empty());
}

TEST(Stack, is_full_expected)
{
    for(int i = 0; i < STACK_SIZE; i++ )
    {
        CHECK(m_stack.push(i* 10));
        CHECK_FALSE(m_stack.is_empty());
    }

    CHECK_FALSE(m_stack.push(25));
    CHECK(m_stack.is_full());
}
