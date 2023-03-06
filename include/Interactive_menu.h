#ifndef INTERACTIVE_MENU_H
#define INTERACTIVE_MENU_H

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
};
#endif // INTERACTIVE_MENU_H
