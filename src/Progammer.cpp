#include "Progammer.h"

int Programmer:: counter_programmer = 100;
Programmer :: Programmer():id_programmer(counter_programmer++)
{
    this->programmer_name = "";
    this->programmer_type = "";
    this->programmer_experience = 0;
}
Programmer :: Programmer(string programmer_name, string programmer_type, int programmer_experience)
:id_programmer(counter_programmer++)
{
    this->programmer_name = programmer_name;
    this->programmer_type = programmer_type;
    this->programmer_experience = programmer_experience;
}
Programmer :: Programmer(const Programmer& ob):id_programmer(counter_programmer++)
{
    this->programmer_name = ob.programmer_name;
    this->programmer_type = ob.programmer_type;
    this->programmer_experience = ob.programmer_experience;
}
Programmer& Programmer :: operator =(const Programmer& ob)
{
    if(this!=&ob)
    {
        this->programmer_name = ob.programmer_name;
        this->programmer_type = ob.programmer_type;
        this->programmer_experience = ob.programmer_experience;
    }
    return *this;
}
istream& Programmer :: read(istream& in)
{
    cout<<"Programmer\nName: ";
    in>>programmer_name;
    cout<<"Type: ";
    in>>programmer_type;
    cout<<"Experience: ";
    bool programmer_experience_flag = 1;
    while(programmer_experience_flag)
    {
        in>>programmer_experience;
        try
        {
            if(programmer_experience)
                programmer_experience_flag = 0;
            else
                throw(programmer_experience);
        }
        catch(...)
        {
            bool error_message_flag = 1;
            if(error_message_flag)
            {
                cout<<"Experience must be a number\n";
                error_message_flag = 0;

            }
            cin.clear();
            cin.ignore();
        }
    }
    return in;
}
ostream& Programmer :: write(ostream& out)
{
    out<<"\nProgrammer named "<<programmer_name<<", working in "<<programmer_type<<", with "<<programmer_experience<<" year(s) of experience.";
    return out;
}
istream& operator>>(istream& in, Programmer& ob){return ob.read(in);}
ostream& operator <<(ostream& out, Programmer& ob){return ob.write(out);}
