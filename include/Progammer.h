#ifndef PROGAMMER_H
#define PROGAMMER_H
#include "IO.h"
using namespace std;

class Programmer: public IO
{
    const int id_programmer;
    static int counter_programmer;
    string programmer_name, programmer_type;
    int programmer_experience; //in years
public:
    Programmer();
    Programmer(string programmer_name, string programmer_type, int programmer_experience);
    Programmer(const Programmer& ob);
    Programmer& operator =(const Programmer& ob);

    istream& read(istream& in);
    ostream& write(ostream& out);
    friend istream& operator >>(istream& in, Programmer& ob);
    friend ostream& operator <<(ostream& out, Programmer& ob);
    string get_name(){return programmer_name;}

    ~Programmer(){}
};

#endif // PROGAMMER_H
