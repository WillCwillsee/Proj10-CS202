#ifndef NodeStack_hpp
#define NodeStack_hpp
#include <NodeStack/Node.hpp>
#include <cstdlib>

template <typename T>
class NodeStack{
    friend std::ostream & operator<<(std::ostream & os,
                                     const NodeStack<T> & nodeQueue);
public:
    NodeStack();
    NodeStack(size_t count, const T & value);
    NodeStack(const NodeStack<T> & other);
   /*~NodeStack();
    NodeStack & operator= (const NodeStack<T> & rhs);*/
    T & top();
    const T & top() const;
    void push(const T & value);
    void pop();
    size_t size() const;
    bool empty() const;
    bool full() const;
    /*void clear();
    void serialize(std::ostream & os) const;*/
private:
    Node<T> * m_top;
};


//NodeStack Initialization
/*template <typename T>
std::ostream & operator<<(std::ostream & os, const NodeStack<T> & nodeQueue)
{
   // nodeQueue.serialize(os);
    return os;
}*/

template <typename T>
NodeStack<T>::NodeStack() : m_top(nullptr)
{
    
}

template <typename T>
NodeStack<T>::NodeStack(size_t size, const T & value) : m_top(nullptr)
{
    for ( int i = 0; i < size; i++)
    {
        Node<T>* temp = new Node<T>;
        temp->m_data = value;
        temp->m_next = m_top;
        m_top=temp;
        m_top->m_next = nullptr;
        delete temp;
    }
}

template <typename T>
NodeStack<T>::NodeStack(const NodeStack<T> & other)
{
    while(other.m_top->m_next!= nullptr)
    {
        Node<T>* temp = new Node<T>;
        temp->m_data = other.m_top->m_data;
        temp->m_next = other.m_top->m_next;
        m_top = temp->m_next;;
    }
}


/*template <typename T>
NodeStack<T>::~NodeStack(){
    
}
template <typename T>
NodeStack<T> & NodeStack<T>::operator= (const NodeStack<T> & rhs)
{
    Node<T>* temp1 = new Node<T>;
    Node<T>* temp2 = new Node<T>;
    temp1->m_next = rhs.m_top->m_next;
    temp2 = this->m_top;
    this->m_top = rhs.m_top;
    this->m_top->m_data = rhs.m_top->m_data;
    while(temp1->m_next!= nullptr){
        temp1->m_next = temp1->m_next->m_next;
        temp2 = temp2->m_next;
        
    }
    return *this;
}*/
template <typename T>
T & NodeStack<T>::top()
{
    return m_top->m_data;
}

template <typename T>
const T & NodeStack<T>::top() const
{
    return m_top->m_data;
}

template <typename T>
void NodeStack<T>::push(const T & value)
{
    Node<T> * temp = new Node<T>;
    temp->m_data=value;
    temp->m_next=nullptr;
    //make newnode as top/head
    m_top=temp;
}

template <typename T>
void NodeStack<T>::pop()
{
    m_top = m_top->m_next;
}

template <typename T>
size_t NodeStack<T>::size() const
{
    Node<T> * temp = new Node<T>;
    temp = m_top;
    size_t i = 1;
    while(temp!=nullptr){
        temp = temp->m_next;
        i++;
    }
    return i;
}

template <typename T>
bool NodeStack<T>::empty() const
{
    if(m_top == nullptr) return 1;
    else return 0;
}

template <typename T>
bool NodeStack<T>::full() const
{
    return 0;
}
/* void clear();
 void serialize(std::ostream & os) const;
 */

#endif /* NodeStack_hpp */
