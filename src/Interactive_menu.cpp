#include "Interactive_menu.h"

Interactive_menu* Interactive_menu::ob {};
int Interactive_menu::menu_try_catch(int x, int (&options)[10])
{
    bool try_catch_flag = 1;
    while(try_catch_flag)
    {
        cin>>x;
        try
        {
            if(x)
            {
                for(int i=0;i<10;i++)
                {
                    if(x==options[i])
                    {
                        try_catch_flag = 0;
                        delete[] &options;
                        return x;
                    }
                }
                throw(x);
            }
            else
                throw(x);
        }
        catch(...)
        {
            cout<<"Option invalid, try another option\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // first argument says ignore everything, second argument says stop at end of the line aka \n
        }
    }
}
template <class T>
void Interactive_menu::register_workitem()
{
    T *temp;
    temp = new T;
    cin>>*temp;
    if(programmers_list.size()<1)
        cout<<"No programmer was assigned\n";
    else
        {
            bool programmer_assignment_flag = 1;
            while(programmer_assignment_flag == 1)
            {
                bool programmer_assigned_flag = 0;
                cout<<"Assign a programmer by name: ";
                string name;
                cin>>name;
                if(name == "")
                    cout<<"No programmer was assigned\n";
                else
                {
                    for(int i = 0;i<programmers_list.size();i++)
                    {
                        if(programmers_list[i].get_name()==name)
                        {
                            (*temp).set_programmer(programmers_list[i]);
                            cout<<"Programmer set\n";
                            programmer_assigned_flag = 1;
                            programmer_assignment_flag = 0;
                        }
                    }
                    if(programmer_assigned_flag == 0)
                    {
                        cout<<"No such programmer was found to be assigned\nTo cancel assignment press 0, to insert another name press 1\n";
                        cin>>programmer_assignment_flag;
                        if(programmer_assignment_flag == 0)
                            cout<<"No programmer was assigned\n";
                    }
                }
            }
        }
    workitems_list.push_back(temp);
}
void Interactive_menu::menu()
{
    bool main_menu_flag = 1;
    int op1;
    while(main_menu_flag == 1)
    {
        cout<<"Main menu, press:\n1 for work item options\n2 for programmer options\n3 to exit\n"<<"\n";
        int options1[10] = {1,2,3};
        op1 = menu_try_catch(op1,options1);
        switch(op1)
        {
            case 1: //workitems
                {
                    int op2, menu_workitem_flag = 1;
                    while(menu_workitem_flag)
                    {
                        if(programmers_list.size()<1)
                        {
                            cout<<"\nCaution! There are no programmers registered so no programmers can be assigned";
                        }
                        cout<<"\n1 for registering a bug\n2 for registering a change\n";
                        cout<<"3 for the selector menu\n9 to return to the main menu\n"<<"\n";
                        int options2[10] = {1,2,3,9};
                        op2 = menu_try_catch(op2, options2);
                        switch(op2)
                        {
                        case 1: //register Bug
                            {
                                register_workitem<Bug>();
                                break;
                            }
                        case 2: //register Change
                            {
                                register_workitem<Change>();
                                break;
                            }
                        case 3: //selector option, maybe use a while to return to this menu when the operation finishes
                            {
                                if(workitems_list.size()>0)
                                {
                                    cout<<"\nSelector menu:\n1 for selecting a work item\n2 for showing all work items\n";
                                    cout<<"3 for showing all bugs\n4 for showing all changes\n9 to go back\n"<<"\n";
                                    int options3[10] = {1,2,3,4,9}, op3;
                                    op3 = menu_try_catch(op3, options3);
                                    switch(op3)
                                    {
                                    case 1: //select work item through id
                                        {
                                            cout<<"\nSearch for id: ";
                                            int id;
                                            bool id_found_flag = 0; //found is true
                                            cin>>id;
                                            for(int i = 0;i<workitems_list.size();i++)
                                            {
                                                if(id == (*workitems_list[i]).get_workitem_id())
                                                {
                                                    cout<<*workitems_list[i];
                                                    cout<<"\nWhat to do with the item?\n1 for deleting the item\n2 for changing the assigned programmer\n";
                                                    cout<<"9 to go back\n";
                                                    int options4[10] = {1,2,9}, op4;
                                                    op4 = menu_try_catch(op4, options4);
                                                    switch(op4)
                                                    {
                                                    case 1: //delete work item
                                                        {
                                                            cout<<"Are you sure?(0/1): ";
                                                            bool deletion_flag;
                                                            cin>>deletion_flag;
                                                            if(deletion_flag)
                                                            {
                                                                workitems_list.erase(workitems_list.begin()+i); //genius move
                                                                cout<<"Deleted\n";
                                                            }
                                                            break;
                                                        }
                                                    case 2: //assign programmer
                                                        {
                                                            if(programmers_list.size()!=0)
                                                            {
                                                                if((*workitems_list[i]).get_programmer_assigned().get_name() == "")
                                                                    cout<<"There is no programmer assigned\n";
//                                                                 else
//                                                                    cout<<(*workitems_list[i]).get_programmer_assigned();
                                                                else
                                                                    cout<<"Programmer name: "<<(*workitems_list[i]).get_programmer_assigned().get_name()<<"\n";
                                                                bool new_programmer_assignment_flag = 1;
                                                                while(new_programmer_assignment_flag)
                                                                {
                                                                    cout<<"Choose programmer by name: ";
                                                                    string name;
                                                                    cin>>name;
                                                                    for(int j =0;i<programmers_list.size();j++)
                                                                    {
                                                                        if(programmers_list[j].get_name() == name)
                                                                        {

                                                                            (*workitems_list[i]).set_programmer(programmers_list[j]);
                                                                            cout<<"Programmer reassigned successfully";
                                                                            new_programmer_assignment_flag = 0;
                                                                            break;
                                                                        }
                                                                    }
                                                                    if(new_programmer_assignment_flag == 1)
                                                                        cout<<"There is no programmer with this name\n";
                                                                }
                                                            }
                                                            else
                                                                cout<<"There are no programmers to assign";
                                                            break;
                                                        }
                                                    case 9:
                                                        {
                                                            cout<<"\n";
                                                            break;
                                                        }
                                                    }
                                                    id_found_flag = 1;
                                                    break;

                                                }
                                            }
                                            if(id_found_flag==0)
                                                cout<<"There is no work item with this id";
                                            break;
                                        }
                                    case 2: //show all work items
                                        {
                                            if(workitems_list.size()>0)
                                            {
                                                cout<<"\nThere is a number of "<<workitems_list.size()<<" work items:\n";
                                                for (int i=0;i<workitems_list.size();i++)
                                                    cout<<*workitems_list[i];
                                            }
                                            else
                                                cout<<"\nThere are no work items\n";
                                            break;
                                        }
                                    case 3: //show bugs
                                        {
                                            if(workitems_list.size()>0)
                                            {
                                                for (int j=0;j<workitems_list.size();j++)
                                                {
                                                    if(string(typeid(*workitems_list[j]).name())=="3Bug")
                                                        {
                                                            cout<<*workitems_list[j];
                                                        }
                                                }
                                            }
                                            else
                                                cout<<"\nThere are no bugs\n";
                                            break;
                                        }
                                    case 4: //show changes
                                        {
                                            if(workitems_list.size()>0)
                                            {
                                                for (int j=0;j<workitems_list.size();j++)
                                                {
                                                    if(string(typeid(*workitems_list[j]).name())=="6Change")
                                                        {
                                                            cout<<*workitems_list[j];
                                                        }
                                                }
                                            }
                                            else
                                                cout<<"\nThere are no changes\n";
                                            break;
                                        }
                                    case 9:
                                        {
                                            cout<<"\n";
                                            break;
                                        }
                                    }
                                }
                                else
                                    cout<<"\nThere are no work items\n";
                                break;
                            }
                        case 9:
                            {
                                cout<<"\n";
                                menu_workitem_flag = 0;
                                break;
                            }
                        }
                    }
                    break;
                }
            case 2: //programmers
                {
                    int op2, menu_programmer = 1;
                    while(menu_programmer == 1)
                    {
                        cout<<"\n1 for registering a programmer\n2 for deleting a programmer\n3 for viewing all programmers\n9 for returning to the main menu\n";
                        cout<<"\n";
                        int options2[10] = {1,2,3,9};
                        op2 = menu_try_catch(op2, options2);
                        switch(op2)
                        {
                            case 1:
                                {
                                    Programmer temp;
                                    cin>>temp;
                                    programmers_list.push_back(temp);
                                    break;
                                }
                            case 2:
                                {
                                    if(programmers_list.size()>0)
                                    {
                                        int programmer_deletion_flag = 0;
                                        cout<<"Name of the programmer to be deleted: ";
                                        string name;
                                        cin>>name;
                                        for(auto it = programmers_list.begin();it!=programmers_list.end();it++)
                                        {
                                            if((*it).get_name() == name)
                                            {
                                                cout<<*it;
                                                programmers_list.erase(it);
                                                cout<<"\nDeleted\n";
                                                programmer_deletion_flag = 1;
                                                break;
                                            }
                                        }
                                        if(programmer_deletion_flag == 0)
                                        {
                                            cout<<"There was no such programmer found\n";
                                        }
                                        name = "";
                                    }
                                    else
                                        cout<<"There are no programmers listed\n";
                                    break;
                                }
                            case 3:
                                {
                                    for(int i =0;i<programmers_list.size();i++)
                                        cout<<programmers_list[i]<<"\n";
                                    break;
                                }
                            case 9:
                                {
                                    cout<<"\n";
                                    menu_programmer = 0;
                                    break;
                                }

                        }
                    }
                    break;
                }
            case 3:
                {
                    cout<<"\nGoodbye\n";
                    main_menu_flag = 0;
                    break;
                }

        }
    }
}
