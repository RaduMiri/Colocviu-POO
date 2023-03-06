#ifndef BUG_H
#define BUG_H
#include <string>
#include "WorkItem.h"
#include "Progammer.h"
using namespace std;


class Bug : public WorkItem
{
    int bug_impact; // priority to solve, from 1 to 10 - max
    string start_date_work_bug;
public:
    Bug();
    Bug(int bug_impact, string start_date_work_bug, string date_created, string area, string status, int time_commitment, Programmer programmer_assigned);
    Bug(const Bug& ob);
    Bug& operator =(const Bug& ob);

    istream& read(istream& in);
    ostream& write(ostream& out) ;
    float cost_to_solve();

    ~Bug(){}
};
#endif // BUG_H
