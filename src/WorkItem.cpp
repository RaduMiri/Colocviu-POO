#include "WorkItem.h"

int WorkItem :: counter_workitem = 1000;
WorkItem :: WorkItem():id_workitem(counter_workitem++)
{
    this->date_created = "";
    this->area = "";
    this->status = "";
    this->time_commitment = 0;
    this->programmer_assigned = Programmer();
}
WorkItem :: WorkItem(string date_created, string area, string status, int time_commitment, Programmer programmer_assigned)
:id_workitem(counter_workitem++)
{
    this->date_created = date_created;
    this->area = area;
    this->status = status;
    this->time_commitment = time_commitment;
    this->programmer_assigned = programmer_assigned;
}
WorkItem :: WorkItem(const WorkItem& ob):id_workitem(counter_workitem++)
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
    cout<<"Time commitment: ";
    in>>time_commitment;
    //cout<<"No programmer assigned\n";
    return in;
}
ostream& WorkItem :: write(ostream& out)
{
    if(programmer_assigned.get_name()!="")
        out<<"created at "<<date_created<<", in the area of "<<area<<", with the status of "<<status<<", a time commitment of "<<time_commitment<<", programmed by "<<programmer_assigned.get_name();
    else
        out<<"created at "<<date_created<<", in the area of "<<area<<", with the status of "<<status<<", a time commitment of "<<time_commitment<<" with no programmer assigned";
    return out;
}
istream& operator>>(istream& in, WorkItem& ob){return ob.read(in);}
ostream& operator <<(ostream& out, WorkItem& ob){return ob.write(out);}

