#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
class retailer;
class item_menu;

class retailer
{
protected:
    string ridname;
    string rpass;

public:
    retailer()
    {
    }
    void reg();
    void check();
    void admin();
    void alogin();
    void home();
    friend void adminmenu(item_menu i, retailer r);
};
class item_menu : public retailer
{
    string itemname;
    string itemprice;
    int qty;
    int item_no = 0;

public:
    void add();
    void view();
    void edit();
    void sales();
    friend void adminmenu(item_menu i, retailer r);
    item_menu()
    {
    }
};
void item_menu::add()
{
    string name;
    string pass;

    cout << endl
         << "\t\t\t\t\t\t\t\t\tADD Admin to DB" << endl;
    cout << "\t\tEnter Name:";
    cin >> name;
    cout << "\t\tEnter password:";
    cin >> pass;
    fflush(stdin);
    fstream f;
    f.open("admin.dat", ios::in | ios::app | ios::binary);
    f << name << " " << pass << endl;
    f.close();
}
void item_menu::edit()
{
    fstream f;
    f.open("item.dat", ios::in | ios::app | ios::binary);
    cout << "item no.:" << item_no << endl;
    cout << "\t\t\t\t\t\tEnter item name:";
    cin >> itemname;
    cout << "\t\t\t\t\t\tEnter itemprice (/kg):";
    cin >> itemprice;
    cout << "enter Quantity:";
    cin >> qty;
    f << itemname << " " << itemprice << " " << qty << " " << item_no << endl;
    item_no++;
    fflush(stdin);
    f.close();
}

void item_menu::sales()
{
}
void item_menu::view()
{
    fstream f;
    f.open("item.dat", ios::in | ios::binary);
    cout << "\t\t\t item name"
         << "   "
         << "\t\t item price"
         << " "
         << "\t\tQty" << endl;
    while (!f.eof())
    {

        f >> itemname >> itemprice >> qty;
        cout << "\t\t\t" << itemname << "   "
             << "\t\t" << itemprice << " "
             << "\t\t" << qty << endl;
        
    }
    f.close();
}

void adminmenu(item_menu i, retailer r)
{

    int choice = 0;
    cout << endl
         << "\t\t\t\t\t\t\t\t\tADMIN ----MENU" << endl;
    cout << "\t\t\t\t\t\t\t1.To ADD Admin " << endl;
    cout
        << "\t\t\t\t\t\t\t2.To Edit item list " << endl;
    cout
        << "\t\t\t\t\t\t\t3.To View List" << endl;
    cout
        << "\t\t\t\t\t\t\t4.To View Sales" << endl;
    cout
        << "\t\t\t\t\t\t\t5.To Exit to home" << endl;
    cout << "ENter choice:";
    cin >> choice;
    switch (choice)
    {

    case 1:
        i.add();
        break;

    case 2:
        i.edit();
        break;
    case 3:
        i.view();
        break;
    case 4:
        i.sales();
        break;
    case 5:
        r.home();
        break;
    default:
        cout << "ENter correcrt option:" << endl;
        adminmenu(i, r);
        break;
    }
}

void retailer::alogin()
{
    int flag = 0;

    // cin.ignore(1, '\n');
    cout << "\t\t\t\t\t\t\t\t\tADMIN ----login Page" << endl;
    string id;
    string pass;
    cout << "Enter Id and password:" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t\tId:->";
    cin >> id;

    cout << "\t\t\t\t\t\t\t\t\tPassword:";
    // cin.ignore(1, '\n');
    char ch;
    ch = getch();
    while (ch != 13)
    {
        // // if (ch == '\b')
        // // {

        // //     cout << "\b \b";
        // //     pass.push_back(ch);
        // // }
        //  if (ch=='\b') {
        //     cout << "\b \b"; //to delete wrong character that user input

        // }
        // else  if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        // {ch = getch();
        // cout << "*";
        // pass.push_back(ch);}
        //     fflush(stdin);

        ch = getch();
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            // store the ch to the pass
            cout << '*';
            pass.push_back(ch);
        }
        if (ch == '\b')
        {
            cout << "\b \b"; // to delete wrong character that user input
            pass.pop_back();
        }

        if (ch == '\r')
        { // r is Enter or 13 charecter code (enter)
            ch = 13;
        }
    }

    fflush(stdin);

    fstream f;
    int i = 0;
    f.open("admin.dat", ios::in | ios::binary);
    retailer r[10];
    f >> r[i].ridname >> r[i].rpass;

    // if (r[i].ridname == id && r[i].rpass == pass)
    // {cout<<"hello";
    //     system("cls");
    //     flag = 1;
    //     cout << "\t\t\t\t\t\tLogged In!!" << endl
    //          << endl;
    // }
    while (!f.eof())
    {

        if (r[i].ridname == id && r[i].rpass == pass)
        {
            system("cls");
            flag = 1;
            cout << "\t\t\t\t\t\tLogged In!!" << endl
                 << endl;

            cout << "welcome Admin"
                 << " " << r[i].ridname << " " << endl
                 << endl;
            item_menu I;
            adminmenu(I, r[i]);
        }
        i++;
        f >> r[i].ridname >> r[i].rpass;
    }

    f.close();
    if (flag == 0)
    {
        cout << endl
             << "wrong id or password" << endl;
        alogin();
    }
}

void retailer::admin()
{
    int t;
    cout << endl;
    cout << "\t\t\t\t\t\t*******************************************************************************************\t\t\t\t\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t\t\t\t\tADMIN PAGE" << endl;
    cout << " 1. ADMIN LOGIN:::::" << endl;
    cout << " 2. Home:::::" << endl;
    cout << "choice:";
    cin >> t;
    if (t == 1)
        alogin();
    else if (t == 2)
        home();
    else
    {
        cout << "Wrong choice" << endl;
        admin();
    }
}

void retailer::home()
{
    retailer r;
    cout << endl;
    int t = 0;
    cout << "\t\t\t\t\t\t*******************************************************************************************\t\t\t\t\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t\t\t\t\tWELCOME TO ONLINE RETAIL STORE" << endl;
    cout << endl
         << endl
         << "\t\t\t\t\t\t\t\t--->1 Admin Page" << endl;
    cout << endl
         << "\t\t\t\t\t\t\t\t--->2 Shopping" << endl
         << endl;

    cout << "\t\t\t\t\t\t*******************************************************************************************\t\t\t\t\t\t\t\t\t" << endl;
    cout << "choice::";
    cin >> t;
    if (t == 1)
    {
        r.admin();
    }
    if (t == 2)
    {
        //   shopping();
    }
    //    cin.ignore(1,’\n’
}

int main()
{
    retailer r;
    system("cls");

    r.home();

    return 0;
}