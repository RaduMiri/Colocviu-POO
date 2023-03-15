#include <iostream>
#include <vector>
#include <typeinfo>
#include <limits>
#include "Progammer.h"
#include "IO.h"
#include "WorkItem.h"
#include "Bug.h"
#include "Change.h"
#include "Interactive_menu.h"

using namespace std;

int main()
{
    Interactive_menu* menu;
    menu = menu->get_instance();
    menu->menu();
    return 0;
}
