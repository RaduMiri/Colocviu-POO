#ifndef WORKITEM_H
#define WORKITEM_H
#include "IO.h"
#include "Progammer.h"
using namespace std;


class WorkItem: public IO
{
protected:
    string date_created, area, status;
    //area of work for workitem, Factory, Finance, etc
    //Status: InProgress, Open, Closed
    int time_commitment; //number of days it took to solve
    const int workitem_id;
    static int counter_workitem;
    Programmer programmer_assigned;
public:
    WorkItem();
    WorkItem(string date_created, string area, string status, int time_commitment, Programmer programmer_assigned);
    WorkItem(const WorkItem& ob);
    WorkItem& operator =(const WorkItem& ob);

    istream& read(istream& in);
    ostream& write(ostream& out) ;
    friend istream& operator >>(istream& in, WorkItem& ob);
    friend ostream& operator <<(ostream& out, WorkItem& ob);


    int int_input(int x, istream &in, string message);
    const int get_workitem_id(){return workitem_id;}
    Programmer get_programmer_assigned(){return programmer_assigned;}
    void set_programmer(Programmer p){programmer_assigned = p;}
    float cost_to_solve(){return 0;}

    ~WorkItem(){}
};
#endif // WORKITEM_H
