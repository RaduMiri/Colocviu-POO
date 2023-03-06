#include "Interactive_menu.h"
#include <vector>
#include "WorkItem.h"
#include "Bug.h"
#include "Change.h"
#include <typeinfo>
#include "Progammer.h"
Interactive_menu* Interactive_menu::ob = 0;
void Interactive_menu::menu()
{
    vector<WorkItem*> workitems_list;
    vector<Programmer> programmers_list;
    int main_menu_flag = 1, op1;
    while(main_menu_flag == 1)
    {
        cout<<"Main menu, press:\n1 for work item options\n2 for programmer options\n3 to exit\n"<<"\n";
        cin>>op1;
        switch(op1)
        {
            case 1:
                {
                    int op2, menu_workitem_flag = 1;
                    while(menu_workitem_flag == 1)
                    {
                        if(programmers_list.size()<1)
                        {
                            cout<<"\nCaution! There are no programmers registered so no programmers can be assigned";
                        }
                        cout<<"\n1 for registering a bug\n2 for registering a change\n3 for deleting a bug\n";
                        cout<<"4 for deleting a change\n5 for showing all bugs\n6 for showing all changes\n";
                        cout<<"7 for showing all work items\n9 for returning to the main menu\n"<<"\n";
                        cin>>op2;
                        switch(op2)
                        {
                        case 1:
                            {
                                Bug *temp;
                                temp = new Bug;
                                cin>>*temp;
                                cout<<"\n";
                                workitems_list.push_back(temp);

                                break;
                            }
                        case 2:
                            {
                                Change *temp;
                                temp = new Change;
                                cin>>*temp;
                                if(programmers_list.size()<1)
                                {
                                    cout<<"No programmer was assigned\n";
                                }
                                else
                                    {
                                        bool programmer_assignment_flag = 1;
                                        while(programmer_assignment_flag == 1)
                                        {
                                            bool programmer_assigned_flag = 0;
                                            cout<<"Assign a programmer by name: ";
                                            string name;
                                            cin>>name;
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
                                            }
                                        }
                                    }
                                workitems_list.push_back(temp);
                                break;
                            }
                        case 3:
                            {
                                vector <int> positions;
                                for (int i=0;i<workitems_list.size();i++)
                                {
                                    if(string(typeid(*workitems_list[i]).name())=="3Bug")
                                        {
                                            cout<<"Position "<<i<<*workitems_list[i];
                                            positions.push_back(i);
                                        }
                                }
                                if(positions.size()>0)
                                {
                                    int op3, bug_deletion_flag = 0;
                                    cout<<"\nChoose the position of a bug to delete\n";
                                    cin>>op3;
                                    for (auto it= positions.begin(); it != positions.end();it++)
                                        {
                                            if(*it==op3)
                                            {
                                                auto p1 = workitems_list.begin();
                                                advance(p1,*it);
                                                workitems_list.erase(p1);
                                                bug_deletion_flag = 1;
                                            }
                                        }
                                    if(bug_deletion_flag == 0)
                                    {
                                        cout<<"There was no such bug found\n";
                                    }
                                }
                                else
                                    cout<<"\nThere are no bugs listed\n";
                                positions.clear();
                                break;
                            }
                        case 4:
                            {
                                vector <int> positions;
                                for (int i=0;i<workitems_list.size();i++)
                                {
                                    if(string(typeid(*workitems_list[i]).name())=="6Change")
                                        {
                                            cout<<"Position "<<i<<*workitems_list[i];
                                            positions.push_back(i);
                                        }
                                }
                                if(positions.size()>0)
                                {
                                    int op3, change_deletion_flag = 0;
                                    cout<<"\nChoose the position of a change to delete\n";
                                    cin>>op3;
                                    for (auto it= positions.begin(); it != positions.end();it++)
                                        {
                                            if(*it==op3)
                                            {
                                                auto p1 = workitems_list.begin();
                                                advance(p1,*it);
                                                workitems_list.erase(p1);
                                                cout<<"Deleted\n";
                                                change_deletion_flag = 1;
                                            }

                                        }
                                    if(change_deletion_flag == 0)
                                    {
                                        cout<<"There was no such change found\n";
                                    }
                                }
                                else
                                    cout<<"\nThere are no changes listed\n";
                                positions.clear();
                                break;
                            }
                        case 5:
                            {
                                if(workitems_list.size()>0)
                                {
                                    for (int i=0;i<workitems_list.size();i++)
                                    {
                                        if(string(typeid(*workitems_list[i]).name())=="3Bug")
                                            {
                                                cout<<*workitems_list[i];
                                            }
                                    }
                                }
                                else
                                    cout<<"\nThere are no bugs\n";
                                break;
                            }
                        case 6:
                            {
                                if(workitems_list.size()>0)
                                {
                                    for (int i=0;i<workitems_list.size();i++)
                                    {
                                        if(string(typeid(*workitems_list[i]).name())=="6Change")
                                            {
                                                cout<<*workitems_list[i];
                                            }
                                    }
                                }
                                else
                                    cout<<"\nThere are no changes\n";
                                break;
                            }
                        case 7:
                            {
                                if(workitems_list.size()>0)
                                {
                                    for (int i=0;i<workitems_list.size();i++)
                                    {
                                        cout<<*workitems_list[i];
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
            case 2:
                {
                    int op2, menu_programmer = 1;
                    while(menu_programmer == 1)
                    {
                        cout<<"\n1 for registering a programmer\n2 for deleting a programmer\n3 for viewing all programmers\n9 for returning to the main menu\n";
                        cout<<"\n";
                        cin>>op2;
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
