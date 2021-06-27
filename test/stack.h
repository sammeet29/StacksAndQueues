#ifndef STACK_H
#define STACK_H

////////////////////////////////////////////////////////////////////////////////
/// @brief A stack that can store integer. it uses an array of integers to act
/// as an stack.
////////////////////////////////////////////////////////////////////////////////
class Stack
{
public:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Constructs a stack.
    /// 
    /// @param[in] size - Size of array.
    ////////////////////////////////////////////////////////////////////////////
    Stack(size_t size, int * buffer)
    : m_size(size)
    , m_array(buffer)
    , m_top(0U)
    {};

    /// @brief Pushes an integer value to the top of the stack.
    bool push(int const value);
    
    int pop();
    int peek();

    /// @brief Clears the stack. 
    ///
    /// @remark This doesn't delete the data, it just resets the stack pointer
    /// to the start.
    void clear();

    /// @brief Tells the amount of stack used.
    constexpr unsigned int size()
    {
        return m_top;
    }

private:
    // total size of array
    size_t const m_size;
    // Pointer to array to store the integer array 
    int * m_array;
    // top of array
    unsigned int m_top;
};

#endif // STACK_H
