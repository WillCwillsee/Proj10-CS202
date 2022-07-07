#ifndef Node_hpp
#define Node_hpp
#include <DataType/DataType.hpp>
#include <cstdlib>

template <typename> class NodeStack;
template <typename T>
class Node{
    
    friend class NodeStack<T>;
    
public:
    Node();
    Node(const T & data, Node<T> * next);
    Node(const Node<T> & other);
    T & data();
    const T & data() const;
    
private:
    Node<T> * m_next;
    T m_data;
};

template <typename T>
Node<T>::Node() : m_next(nullptr)
{
    
}

template <typename T>
Node<T>::Node(const T & data, Node<T> * next) : m_next(next), m_data(data)
{
    
}

template <typename T>
Node<T>::Node(const Node<T> & other) : m_next(other.m_next), m_data(other.m_data)
{
    
}

template <typename T>
T & Node<T>::data()
{
    return m_data;
}

template <typename T>
const T & Node<T>::data() const
{
    return m_data;
}

#endif /* Node_hpp */
