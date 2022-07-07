
#ifndef ArrayStack_hpp
#define ArrayStack_hpp
#include <DataType/DataType.hpp>
#include <cstdlib>

const size_t ARRAY_CAPACITY = 1000;

template <typename T>

class ArrayStack{
   friend std::ostream & operator<<(std::ostream & os, const ArrayStack<T> & arrayStack);
    
public:
    ArrayStack();
    ArrayStack(size_t count, const T & value);
    ArrayStack(const ArrayStack<T> & other);
    ~ArrayStack();
    ArrayStack & operator= (const ArrayStack<T> & rhs);
    T & top();
    const T & top() const;
    void push(const T & value);
    void pop();
    size_t size() const;
    bool empty() const;
    bool full() const;
    void clear();
    void serialize(std::ostream & os) const;
    
private:
    T m_container[ARRAY_CAPACITY];
    size_t m_top;

};

template <typename T>
ArrayStack<T>::ArrayStack() : m_top(0)
{
    
}

template <typename T>
ArrayStack<T>::ArrayStack(size_t count, const T & value) : m_top()
{
    T m_container[count+1];
    /*for(int i = 0; i < ARRAY_CAPACITY; i++){
     T m_container[i](value.m_intVal, value.m_doubleVal);
     }*/
    for(int i = 0; i < count+1; i++){
        m_top +=1;
        m_container[i].m_intVal = value.m_intVal;
        m_container[i].m_doubleVal = value.m_doubleVal;
    }
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> & other) : m_top(other.m_top)
{
    for(int i = 0; i < m_top; i++){
        m_container[i].m_intVal = other.m_container[i].m_intVal;
        m_container[i].m_doubleVal = other.m_container[i].m_doubleVal;
    }
}

template <typename T>
ArrayStack<T>::~ArrayStack()
{
    for(int i = 0; i < m_top; i++){
        this->pop();
    }
}

template <typename T>
ArrayStack<T> & ArrayStack<T>::operator=(const ArrayStack<T> & rhs)
{
    this->m_top = rhs.m_top;
    for(int i = 0; i < rhs.m_top; i++){
        this->m_container[i].m_intVal = rhs.m_container[i].m_intVal;
        this->m_container[i].m_doubleVal = rhs.m_container[i].m_doubleVal;
    }
    return *this;
}

template <typename T>
T & ArrayStack<T>::top()
{
    return m_container[m_top-1];
}

template <typename T>
const T & ArrayStack<T>::top() const
{
    return m_container[m_top-1];
}

template <typename T>
void ArrayStack<T>::push(const T & value)
{
    m_container[m_top].m_intVal = value.m_intVal;
    m_container[m_top].m_doubleVal = value.m_doubleVal;
    m_top = m_top+1;
}

template <typename T>
void ArrayStack<T>::pop()
{
    m_container[m_top].m_intVal = 0;
    m_container[m_top].m_doubleVal = 0;
    m_top -= 1;
}


template <typename T>
size_t ArrayStack<T>::size() const
{
    return m_top-1;
}

template <typename T>
bool ArrayStack<T>::empty() const
{
    if(m_top == 0) return 1;
    else return 0;
}

template <typename T>
bool ArrayStack<T>::full() const
{
    if(m_top == ARRAY_CAPACITY) return 1;
    else return 0;
}

template <typename T>
void ArrayStack<T>::clear()
{
    for (int i = 0; i < m_top; i++)
    {
        m_container[i].m_intVal = 0;
        m_container[i].m_doubleVal = 0;
    }
    m_top = 0;
}

template <typename T>
std::ostream & operator<<(std::ostream & os, const ArrayStack<T> & arrayStack)
{
    arrayStack.serialize(os);
    return os;
}

template <typename T>
void ArrayStack<T>::serialize(std::ostream & os) const
{
    os << "Stack size: " << m_top-1 << std::endl << std::endl << std::endl;
    for (int i = m_top; i < m_top; i++)
    {
        os << "Element " << i << std::endl << "Int Value: " << m_container[i].m_intVal << std::endl << "Double Value: " << m_container[i].m_doubleVal << std::endl;
    }
}

#endif /* ArrayStack_hpp */
