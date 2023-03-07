#ifndef INTERACTIVE_MENU_H
#define INTERACTIVE_MENU_H
#include <stddef.h>
using namespace std;


class Interactive_menu //singletone interactive menu
{
    static Interactive_menu* ob;
    int menu_counter;
    Interactive_menu(){menu_counter = 0;}
public:
    static Interactive_menu* get_instance()
    {
        if(!ob)
            ob = new Interactive_menu;
        return ob;
    }
    void menu();
    int menu_try_catch(int x, int (&options)[10]);
};
#endif // INTERACTIVE_MENU_H
