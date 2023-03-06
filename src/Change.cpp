#include "Change.h"

Change :: Change():WorkItem()
{
    this->description = "";
    this->launch_date = "";
}
Change :: Change(string description, string launch_date, string date_created, string area, string status, int time_commitment, Programmer programmer_assigned)
: WorkItem( date_created,  area,  status,  time_commitment,  programmer_assigned)
{
    this->description = description;
    this->launch_date = launch_date;
}
Change :: Change(const Change& ob) : WorkItem(ob)
{
    this->description = ob.description;
    this->launch_date = ob.launch_date;
}
Change& Change:: operator=(const Change& ob)
{
    if(this!=&ob)
    {
        WorkItem :: operator = (ob);
        this->description = ob.description;
        this->launch_date = ob.launch_date;
    }
    return *this;
}
istream& Change :: read(istream& in)
{
    cout<<"Change";
    WorkItem :: read(in);
    cout<<"Description: ";
    in>>description;
    cout<<"Launch date: ";
    in>>launch_date;
    return in;
}
ostream& Change :: write(ostream& out)
{
    out<<"\nChange ";
    WorkItem::write(out);
    out<<", "<<description<<", and launched at "<<launch_date<<"\n";
    return out;
}
float Change::cost_to_solve(){return time_commitment*18.4;}
