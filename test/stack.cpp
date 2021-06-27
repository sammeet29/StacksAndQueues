#include "stack.h"
#include <stdlib.h>
#include <limits>

bool Stack::push(int const value)
{
    if(m_top == m_size)
    {
        return false;
    }

    m_array[m_top] = value;
    m_top++;
    return true;
}

int Stack::peek()
{
    if(m_top == 0)
    {
        return -1;
    }
    return m_array[m_top - 1];
}

int Stack::pop()
{
    if(m_top == 0)
    {
        return -1;
    }
    m_top--;
    int rtn_value = m_array[m_top];
    return rtn_value;
}

void Stack::clear()
{
    m_top = 0;
}

bool Stack::is_empty()
{
    return (m_top == 0);
}

bool Stack::is_full()
{
    return (m_top == m_size);
}
