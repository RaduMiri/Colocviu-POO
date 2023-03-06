#include "Bug.h"
#include <iostream>
using namespace std;

Bug :: Bug():WorkItem()
{
    this->bug_impact = 0;
    this->start_date_work_bug = "";
}
Bug :: Bug(int bug_impact, string start_date_work_bug, string date_created, string area, string status, int time_commitment, Programmer programmer_assigned)
: WorkItem( date_created,  area,  status,  time_commitment,  programmer_assigned)
{
    this->bug_impact = bug_impact;
    this->start_date_work_bug = start_date_work_bug;
}
Bug :: Bug(const Bug& ob) : WorkItem(ob)
{
    this->bug_impact = ob.bug_impact;
    this->start_date_work_bug = ob.start_date_work_bug;
}
Bug& Bug:: operator=(const Bug& ob)
{
    if(this!=&ob)
    {
        WorkItem :: operator = (ob);
        this->bug_impact = ob.bug_impact;
        this->start_date_work_bug = ob.start_date_work_bug;
    }
    return *this;
}
istream& Bug :: read(istream& in)
{
    cout<<"Bug";
    WorkItem :: read(in);
    cout<<"Bug impact: ";
    in>>bug_impact;
    cout<<"Started date of working on the bug: ";
    in>>start_date_work_bug;
    return in;
}
ostream& Bug :: write(ostream& out)
{
    out<<"\nBug ";
    WorkItem::write(out);
    out<<", with a bug impact of "<<bug_impact<<", and started being worked on since "<<start_date_work_bug<<"\n";
    return out;
}
float Bug::cost_to_solve(){return bug_impact*10 + time_commitment*5;}
