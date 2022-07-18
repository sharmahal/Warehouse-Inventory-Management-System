#include<iostream>
#include<vector>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
#define vi vector<int>
#define pb push_back

const int INF = 1000000;
static map < string, int >data;
class purchase
{
public:
    int product_price;
    void get_product_price()
        {
        cout<<"\nProduct Price:";
        cin>>product_price;
        };
void display_product_price()
        {
        cout<<"\t\t"<<product_price<<"\t\t";
        };
};
class selling
{
public:
    int selling_price;
    void delete_product (int n)
        {
        cout<<"The product with product id- "<<n<< " is deleted from database";
        cout<<"\nPress any key to continue";
        getch();

        };
    void get_selling()
        {
        cout<<"\nSelling Price:";
        cin>>selling_price;
        };
    void display_selling()
        {
        cout<<selling_price;
        };
};
class warehouse: public selling, public purchase
{
private:
  int quantity_purchased;
  char manufacturing_date[10];
public:
  int product_id;
  char product_name[20], product_type[20];
  int return_quantity()
    {
    return quantity_purchased;
    }
  void display_warehouse ()
    {
    cout << "   "<<product_id << "\t        ";
    cout << product_name;
    cout << "\t";
    cout << product_type;
    cout << "\t";
    cout << manufacturing_date;
    cout << "\t    ";
    cout << quantity_purchased;
    }
  void get_warehouse ()
    {
    cout << "Product ID:";
    cin >> product_id;
    cin.sync ();
    cout << "\nProduct Name:";
    cin >> product_name;
    cin.sync ();
    cout << "\nProduct Type:";
    cin >> product_type;
    cin.sync ();
    cout << "\nManufacturing Date:";
    cin >> manufacturing_date;
    cin.sync ();
    cout << "\nQuantity Purchased:";
    cin >> quantity_purchased;
    data[product_name] += quantity_purchased;
    }
  void quantity_display ()
    {
    cout << "Product name\t" << "Quantity" << endl;
    for (auto it:data)
        {
        cout << it.first << "\t\t" << it.second << endl;
        }
    cout<<"\nPress any key to continue";
    }
  void mostfrequent ()
    {
    cout<<"Product Name\tQuantity\n";
    int maxp = 0;
    string product;
    for (auto it:data)
        {
        if (it.second > maxp)
            {
            maxp = it.second;
            product = it.first;
            }
        }
    cout << product << "\t\t" << maxp<<"\nPress any key to continue";
    }
};
int x = 0;
int flag = 0;



vector<pair<int,int>> wg[100050];
vi d(100050,INF);

vi dijkstra(int src)
{
    set<pair<int,int>> s;

     vi parent(10000+1,-1);

    d[src]=0;
    s.insert({0,src});
    while(!s.empty()){
        int i=s.begin()->second;
        s.erase(s.begin());
        for (auto & e:wg[i]){
            int nb=e.first;
            int w=e.second;
            if (d[i]+w<d[nb]){
                s.erase({d[nb],nb});
                d[nb]=d[i]+w;
                s.insert({d[nb],nb});
                 parent[nb]=i;
            }
        }
    }
    return parent;
}

int compare_id(warehouse obj1, warehouse obj2)
{
    return obj1.product_id<obj2.product_id;
}

map<int,string> name_of_city;
map<string,int> num_of_city;
void intialise (){

    name_of_city[1]="Delhi";
    name_of_city[2]="Rajasthan";
    name_of_city[3]="Mumbai";
    name_of_city[4]="Madhya Pradesh";
    name_of_city[5]="Kolkata";
    name_of_city[6]="Aizawl";
    num_of_city["Delhi"]=1;
    num_of_city["Rajasthan"]=2;
    num_of_city["Mumbai"]=3;
    num_of_city["Madhya Pradesh"]=4;
    num_of_city["Kolkata"]=5;
    num_of_city["Aizawl"]=6;

    wg[1].pb({2,1000});
    wg[1].pb({4,1500});
    wg[2].pb({3,3000});
    wg[4].pb({3,1500});
    wg[1].pb({5,2000});
    wg[5].pb({6,2000});

}

int main ()
{

    intialise();
    int a = 0;
    top:
    int ch = 0;
    system ("CLS");
    warehouse obj[50];
    cout <<"-----------------------------------------------------------------------------------------------------------------------\n\t\t\t\t\t\t\tMain Menu\n-----------------------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t\tPress 1 to enter data ";
    cout << "\n\t\t\t\t\t\tPress 2 to display data ";
    cout << "\n\t\t\t\t\t\tPress 3 to edit data ";
    cout << "\n\t\t\t\t\t\tPress 4 to remove data (Product sold)";
    cout << "\n\t\t\t\t\t\tPress 5 to  stock details";
    cout << "\n\t\t\t\t\t\tPress 6 to exit";
    cout <<"\n-----------------------------------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t\tEnter your choice";
    cin >> ch;
    if (ch < 1 || ch > 6)
        {
        cout <<"\n\t\t\tYou have entered wrong input. Please try again. Press any key to continue";
        getch ();
        goto top;
        }
    else
        {
        switch (ch)
            {
            case 1:
            system ("CLS");
            obj[a].get_warehouse ();
            obj[a].get_product_price();
            obj[a].get_selling ();
            a++;
            cout << "\n Press any key to continue";
            getch ();
            goto top;
            break;
            case 2:
            system ("CLS");
            if (!a)
                {
                cout <<"-----------------------------------------------------------------------------------------------------------------------\n\t\t\t\t\tNo Data Present. Press any key to continue.\n-----------------------------------------------------------------------------------------------------------------------\n";
                getch ();
                goto top;
                }
            else
                {
                sort(obj,obj+a,compare_id);
                cout <<"-----------------------------------------------------------------------------------------------------------------------\n";
                cout << "Product ID\t" << "Product Name" << "\tProduct Type\t"<< "MFG Date" <<"\tQty Purchased\t"<< "Product Price\t" << "Selling Price\n";
                cout <<"-----------------------------------------------------------------------------------------------------------------------\n";
                int x = 0;
                for (x = 0; x < a; x++)
                    {
                    obj[x].display_warehouse ();
                    obj[x].display_product_price();
                    obj[x].display_selling();
                    cout << "\n";
                    }
                cout <<"-----------------------------------------------------------------------------------------------------------------------\n\t\t\t\t\t\t\tPress any key to continue.\n-----------------------------------------------------------------------------------------------------------------------\n";
                getch ();
                goto top;
                }
            break;
            case 3:
            if (!a)
                {
                system ("CLS");
                cout <<"-----------------------------------------------------------------------------------------------------------------------\n\t\t\t\t\tNo Data Present. Press any key to continue.\n-----------------------------------------------------------------------------------------------------------------------\n";
                getch ();
                goto top;
                }
            else
                {
                system("CLS");
                cout << "Enter product ID: ";
                int pid;
                cin >> pid;
                int f=0;

                sort(obj,obj+a,compare_id);

                int low=0,high=a-1;

                while(low<high){
                    int mid=(low+high)/2;
                    if (obj[mid].product_id==pid){
                        data[obj[mid].product_name]-=obj[mid].return_quantity();
                        f = 1;
                    obj[mid].get_warehouse ();
                    obj[mid].get_product_price();
                    obj[mid].get_selling ();
                    break;
                    }
                    if (obj[mid].product_id>pid){
                        high=mid-1;
                    }
                    else {
                        low=mid+1;
                    }

                }

                if (f == 1)
                    {

                    goto top;
                    }
                else
                    {
                    cout << "No such PID exists.\nPress any key to continue";
                    getch();
                    goto top;
                    }
                }
            break;
            case 4:
            if (!a)
                {
                system ("CLS");
                cout <<"-----------------------------------------------------------------------------------------------------------------------\n\t\t\t\t\tNo Data Present. Press any key to continue.\n-----------------------------------------------------------------------------------------------------------------------\n";
                getch ();
                goto top;
                }
            else
                {
                system("CLS");
                cout << "Enter product ID: ";
                int pid;
                cin>>pid;
                int x = 0, arr[a], b[a];
                     int flag = 0;
                for (x = 0; x < a; x++)
                    {
                    arr[x] = obj[x].product_id;
                    if (arr[x] == pid)
                        {
                        flag = 1;
                        break;
                        }
                    }
                if (flag == 1)
                    {

                    for (int i = x; i < a - 1; i++)
                        {
                        obj[i] = obj[i + 1];
                        }
                    a--;
                    cout<<endl<<"Enter the delivery address:"<<endl;
                    string s;
                    cin>>s;
                    vi parent=dijkstra(1);
                    cout<<endl<<"Cheapest Route will cost "<<d[num_of_city[s]]<<endl;
                    int num=num_of_city[s];
                    stack<int> route;
                    while(1){
                        route.push(num);
                        num=parent[num];
                        if (num==1) break;
                    }
                    route.push(1);
                    cout<<"Route-"<<endl;
                    while(!route.empty()){
                        int num=route.top();
                        route.pop();
                        cout<<name_of_city[num]<<endl;
                    }
                    obj[x].delete_product(obj[x].product_id);
                    data[obj[x].product_name]-=obj[x].return_quantity();
                     getch();
                    goto top;
                    }

                else
                    {
                    cout << "No such PID exists\n Press any key to continue";
                    getch();
                    goto top;
                    }
                }
            break;
            case 6:
            system ("CLS");
            cout <<"-----------------------------------------------------------------------------------------------------------------------\n\t\t\t\t\t\tThank you for using the program\n-----------------------------------------------------------------------------------------------------------------------\n";
            break;
            case 5:
            system ("CLS");
            if (!a)
                {
                system ("CLS");
                cout <<"-----------------------------------------------------------------------------------------------------------------------\n\t\t\t\t\tNo Data Present. Press any key to continue.\n-----------------------------------------------------------------------------------------------------------------------\n";
                getch ();
                goto top;
                }
            else
                {
                top1:
                int ch = 0;
                system ("CLS");
                cout <<"-----------------------------------------------------------------------------------------------------------------------\n\t\t\t\t\t\t\tMain Menu\n-----------------------------------------------------------------------------------------------------------------------\n";
                cout << "\t\t\t\t\t\tPress 1 to enter display last entries";
                cout << "\n\t\t\t\t\t\tPress 2 to display total quantity ";
                cout<<"\n\t\t\t\t\t\tPress 3 to see most stored product";
                cout<<"\n\t\t\t\t\t\tPress 4 to go to previous menu ";
                cout<<"\n\t\t\t\t\t\tPress 5 to exit";
                cout <<"\n-----------------------------------------------------------------------------------------------------------------------\n";
                cout << "\t\t\t\t\t\tEnter your choice";
                cin >> ch;
                if(ch>=1 && ch<=5)
                    {
                    if(ch==1)
                        {
                        system("CLS");
                        int rd = 0;
                        cout << "Enter recent data: ";
                        cin >> rd;
                        if (rd > a)
                            {
                            cout <<"Not enough entries.Press any key to continue: ";
                            getch ();
                            goto top;
                            }
                        else
                            {
                            std::stack < warehouse > t;
                            int w;
                            w = rd;
                            while (rd > 0)
                            {
                            t.push (obj[a - 1]);
                            rd--;
                            a--;
                            }
                            a = a + w;
                            system ("CLS");
                            cout <<"-----------------------------------------------------------------------------------------------------------------------\n";
                            cout << "Product ID\t" << "Product Name" << "\tProduct Type\t"<< "MFG Date" <<"\tQty Purchased\t"<< "Product Price\t" << "Selling Price\n";
                            cout <<"-----------------------------------------------------------------------------------------------------------------------\n";
                            for (int z = 0; z < w; z++)
                            {
                            t.top ().display_warehouse ();
                            t.top().display_product_price();
                            t.top().display_selling();
                            cout<<"\n";
                            t.pop ();
                            }
                            cout <<"\n-----------------------------------------------------------------------------------------------------------------------\n\t\t\t\t\t\t\tPress any key to continue.\n-----------------------------------------------------------------------------------------------------------------------\n";
                            getch ();
                            goto top1;
                            }
                        }
                    if(ch==2)
                        {
                        system ("CLS");
                        obj[a].quantity_display();
                        getch();
                        goto top1;
                        }
                    if(ch==3)
                        {
                        system("CLS");
                        if(a)
                            {
                            obj[0].mostfrequent();
                            getch();
                            goto top1;
                            }
                        else
                            cout<<"No data stored";
                        }
                    if(ch==4)
                        {
                        goto top;
                        }
                    if(ch==5)
                        {
                        system ("CLS");
                        cout <<"-----------------------------------------------------------------------------------------------------------------------\n\t\t\t\t\t\tThank you for using the program\n-----------------------------------------------------------------------------------------------------------------------\n";
                        }
                }
                else
                {
                cout <<"\n\t\t\tYou have entered wrong input. Please try again. Press any key to continue";
                getch ();
                goto top1;
                }
                }
            }
        }
    }
