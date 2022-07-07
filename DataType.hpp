

#ifndef DATATYPE_H_
#define DATATYPE_H_
#include <cstdlib>
#include <iostream>

class DataType{
    
    friend std::ostream & operator<<(std::ostream & os, const DataType & dataType);
    friend std::istream & operator>>(std::istream & is, DataType & dataType);
    
public:
    DataType();
    DataType(int intVal, double doubleVal);
    DataType(const DataType & other);
    
    bool operator==(const DataType & rhs) const;
    DataType & operator= (const DataType & rhs);
    
    const int & intVal() const;
    int & intVal();
    const double & doubleVal() const;
    double & doubleVal();
    int m_intVal;
    double m_doubleVal;
};

#endif //DATATYPE_H_
