#ifndef CHANGE_H
#define CHANGE_H
#include "WorkItem.h"
#include "Progammer.h"
using namespace std;


class Change : public WorkItem
{
    string description, launch_date;
public:
    Change();
    Change(string description, string launch_date, string date_created, string area, string status, int time_commitment, Programmer programmer_assigned);
    Change(const Change& ob);
    Change& operator =(const Change& ob);

    istream& read(istream& in);
    ostream& write(ostream& out);
    float cost_to_solve();

    ~Change(){}
};

#endif // CHANGE_H
