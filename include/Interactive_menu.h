#ifndef INTERACTIVE_MENU_H
#define INTERACTIVE_MENU_H
#include <vector>
#include "WorkItem.h"
#include "Bug.h"
#include "Change.h"
#include <typeinfo>
#include "Progammer.h"
using namespace std;


class Interactive_menu //singletone interactive menu
{
    static Interactive_menu* ob;
    int menu_counter;
    Interactive_menu(){menu_counter = 0;}
    vector<WorkItem*> workitems_list;
    vector<Programmer> programmers_list;
public:
    static Interactive_menu* get_instance()
    {
        if(!ob)
            ob = new Interactive_menu;
        return ob;
    }
    void menu();
    int menu_try_catch(int x, int (&options)[10]);
    template <class T>
    void register_workitem();
};
#endif // INTERACTIVE_MENU_H
