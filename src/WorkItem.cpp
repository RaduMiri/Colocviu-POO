#include "WorkItem.h"

int WorkItem :: counter_workitem = 1000;
WorkItem :: WorkItem():workitem_id(counter_workitem++)
{
    this->date_created = "";
    this->area = "";
    this->status = "";
    this->time_commitment = 0;
    this->programmer_assigned    = Programmer();
}
WorkItem :: WorkItem(string date_created, string area, string status, int time_commitment, Programmer programmer_assigned)
:workitem_id(counter_workitem++)
{
    this->date_created = date_created;
    this->area = area;
    this->status = status;
    this->time_commitment = time_commitment;
    this->programmer_assigned = programmer_assigned;
}
WorkItem :: WorkItem(const WorkItem& ob):workitem_id(counter_workitem++)
{
    this->date_created = ob.date_created;
    this->area = ob.area;
    this->status = ob.status;
    this->time_commitment = ob.time_commitment;
    this->programmer_assigned = ob.programmer_assigned;
}
WorkItem& WorkItem :: operator =(const WorkItem& ob)
{
    if(this!=&ob)
    {
        this->date_created = ob.date_created;
        this->area = ob.area;
        this->status = ob.status;
        this->time_commitment = ob.time_commitment;
        this->programmer_assigned = ob.programmer_assigned;
    }
    return *this;
}
istream& WorkItem :: read(istream& in)
{
    cout<<"\nCreated at: ";
    in>>date_created;
    cout<<"Area: ";
    in>>area;
    cout<<"Status: ";
    in>>status;
    time_commitment = int_input(time_commitment, in, "Time commitment: ");
    return in;
}
int WorkItem::int_input(int x, istream &in, string message)
{
    bool flag_int = 1;
    while(flag_int)
    {
        try
        {
            cout<<message;
            in>>x;
            if(in)
                flag_int = 0;
            else
                throw(0);
        }
        catch(...)
        {
            cout<<"Wrong input\n";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return x;
}
ostream& WorkItem :: write(ostream& out)
{
    out<<"id:"<<get_workitem_id()<<", created at "<<date_created<<", in the area of "<<area<<", with the status of "<<status<<", a time commitment of "<<time_commitment;
    if(programmer_assigned.get_name()!="")
        out<<", programmed by "<<programmer_assigned.get_name();
    else
        out<<" with no programmer assigned";
    return out;
}
istream& operator>>(istream& in, WorkItem& ob){return ob.read(in);}
ostream& operator <<(ostream& out, WorkItem& ob){return ob.write(out);}
