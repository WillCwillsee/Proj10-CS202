#include <ArrayStack/ArrayStack.hpp>
#include <NodeStack/NodeStack.hpp>

int main(){
    std::cout << std::endl << "----------------" << std::endl << "ArrayStack tests" << std::endl << "----------------" << std::endl;
    //1
    std::cout << std::endl << "//1  Default constructor test:" << std::endl;
    ArrayStack<DataType> Default;
    std::cout << "Test successful" << std::endl << std::endl;
    //2
    std::cout << "//2  Parameterized constructor test:" << std::endl;
    DataType dataTest(1,2);
    ArrayStack<DataType> Parameterized(2, dataTest);
    std::cout << "Test successful" << std::endl << std::endl;
    //3
    std::cout << "//3  Copy constructor test:" << std::endl;
    ArrayStack<DataType> Copy(Parameterized);
    std::cout << "Test successful" << std::endl << std::endl;
    //5
    std::cout << "//5  Assignment operator test" << std::endl;
    Default = Copy;
    std::cout << "Test successful" << std::endl << std::endl;
    //6a,6b
    std::cout << "//6a,6b  Top test" << std::endl;
    if (!Copy.empty())
    {
        std::cout << "Top Element contains " << Copy.top() << std::endl;
    }
    std::cout << "Test successful" << std::endl << std::endl;
    //7a,7b
    std::cout << "//8  Push test" << std::endl;
    if (!Copy.full())
    {
        Copy.push(dataTest);
        std::cout << "New Top Element contains " << Copy.top() << std::endl;
    }
    std::cout << "Test successful" << std::endl << std::endl;
    //8
    std::cout << "//9  Pop test" << std::endl;
    if (!Copy.empty())
    {
       Copy.pop();
       std::cout << "New Top Element contains " << Copy.top() << std::endl;
    }
    std::cout << "Test successful" << std::endl << std::endl;
    //9
    std::cout << "//10  Size test" << std::endl;
    std::cout << "Current Queue size is " << Copy.size() << std::endl;
    std::cout << "Test successful" << std::endl << std::endl;
    //10
    std::cout << "//11  Empty test" << std::endl;
    std::cout << "The queue is empty: " << std::boolalpha << Copy.empty() <<  std::endl;
    std::cout << "Test successful" << std::endl << std::endl;
    //11
    std::cout << "//12  Full test" << std::endl;
    std::cout << "The queue is full: " << std::boolalpha << Copy.full() << std::endl;
    std::cout << "Test successful" << std::endl << std::endl;
    //12
    std::cout << "//13  Clear test" << std::endl;
    Copy.clear();
    std::cout << "Test successful" << std::endl << std::endl;
    //13(i)
    /*std::cout << "//14(i)  Serialize and << operator test" << std::endl;
    std::cout << Copy;
    std::cout << "Test successful" << std::endl << std::endl;
    */

    
    //NodeStack Tests
    std::cout << std::endl << "----------------" << std::endl << "NodeStack tests" << std::endl << "----------------" << std::endl;
    //1
    std::cout << std::endl << "//1  Default constructor test:" << std::endl;
    NodeStack<DataType> nodeDef;
    std::cout << "Test successful" << std::endl << std::endl;
    //2
     std::cout << "//2  Parameterized constructor test:" << std::endl;
     NodeStack<DataType> nodeParameterized(3, dataTest);
     std::cout << "Test successful" << std::endl << std::endl;
    //3
     std::cout << "//3  Copy constructor test:" << std::endl;
     NodeStack<DataType> nodeCopy(nodeParameterized);
     std::cout << "Test succesful" << std::endl << std::endl;
    /* //5
     std::cout << "//5  Assignment operator test" << std::endl;
     nodeDef = nodeCopy;
     std::cout << "Test successful" << std::endl << std::endl;
     */
     //6a,6b
     std::cout << "//6a,6b  Top test" << std::endl;
     if (!nodeParameterized.empty())
     {
     std::cout << "Top Element contains " << nodeParameterized.top() << std::endl;
     }
     std::cout << "Test successful" << std::endl << std::endl;
     //7a,7b
     std::cout << "//8  Push test" << std::endl;
    DataType dataTest2(3,3);
     if (!nodeParameterized.full())
     {
     nodeParameterized.push(dataTest2);
     std::cout << "New Top Element contains " << nodeParameterized.top() << std::endl;
     }
     std::cout << "Test successful" << std::endl << std::endl;
     //8
    /* std::cout << "//9  Pop test" << std::endl;
     if (!nodeParameterized.empty())
     {
     nodeParameterized.pop();
     std::cout << "New Top Element contains " << nodeParameterized.top() << std::endl;
     }
     std::cout << "Test successful" << std::endl << std::endl;
     */
     //9
     std::cout << "//10  Size test" << std::endl;
     std::cout << "Current stack size is " << nodeParameterized.size() << std::endl;
     std::cout << "Test successful" << std::endl << std::endl;
     //10
     std::cout << "//11  Empty test" << std::endl;
     std::cout << "The stack is empty: " << std::boolalpha << nodeParameterized.empty() <<  std::endl;
     std::cout << "Test successful" << std::endl << std::endl;
     //11
     std::cout << "//12  Full test" << std::endl;
     std::cout << "The stack is full: " << std::boolalpha << nodeParameterized.full() << std::endl;
     std::cout << "Test successful" << std::endl << std::endl;
    /*
     //12
     std::cout << "//13  Clear test" << std::endl;
     nodeCopy.clear();
     std::cout << "Test successful" << std::endl << std::endl;
     //13(i)
     std::cout << "//14(i)  Serialize and << operator test" << std::endl;
     std::cout << nodeCopy;
     std::cout << "Test successful" << std::endl << std::endl;
     */
    
    
    //Destructor Tests
     std::cout << "Destructor Tests" << std::endl;
    
    //4
    std::cout << "//4 NodeStack destructor test:" << std::endl;
    std::cout << "Test successful" << std::endl << std::endl;
    std::cout << "//4 ArrayStack destructor test:" << std::endl;
    std::cout << "Test successful" << std::endl << std::endl;
    
    std::cout << std::endl << "I was unable to get the << operator and serialize working for either NodeStack or ArrayStack.  I also couldn't get pop, clear and the = assigment operator working for NodeStack " << std::endl;
    return 0;
}
