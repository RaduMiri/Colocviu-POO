#include <iostream>
#include <vector>
#include <typeinfo>
#include "Progammer.h"
#include "IO.h"
#include "WorkItem.h"
#include "Bug.h"
#include "Change.h"
#include "Interactive_menu.h"

using namespace std;

int main()
{
//    Bug b;
//    cout<<typeid(b).name();
//    cout<<typeid(&b).name();
//    Change c;
//    cout<<typeid(&c).name();
//    if(string(typeid(&c).name())==P6Change)
//        cout<<"TRUE";
//    Change *c1;
//    c1 = new Change;
//    cout<<typeid(*c1).name();
    Interactive_menu* menu;
    menu = menu->get_instance();
    menu->menu();
    return 0;
}
