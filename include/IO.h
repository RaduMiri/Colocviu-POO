#ifndef IO_H
#define IO_H
#include <iostream>
using namespace std;

class IO
{
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) = 0;
};

#endif // IO_H
