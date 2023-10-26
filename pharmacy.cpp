/* FOREGROUND */
#ifndef COLORS
#define COLORS
#define RST "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST
#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST
#endif
/* COLORS */

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

void menu();
class secure
{
	protected:
    string userName, password; //hide admin name

	public:

    //virtual void menu(){}

    secure()
    {
        cout << FRED("\n\n\n\n\n\n\t\t\t\tPHARMACY MANAGEMENT SYSTEM");
        cout << FGRN("\n\n---> Manage and perform various operations related to medicines in a pharmacy as well as manage customer sales and generating bills <---")<<endl;
        //system("color 0B"); //change terminal color
        cout << FYEL("\n\n\n\n\t\t  Enter Your Name to Continue as an Admin : ");
        cin >> userName;
        cout << FYEL("\n\t\t  Enter the password of the Admin : ");
        cin >> password;

        system("CLS");
        if(userName == "yogita" && password == "hello")
        {
        	menu();
		}
		else
		{
			cout<<"\n\n\t----> Wrong Username or Password! Enter again <----"<<endl;
		}
    }

    ~secure(){} //destructor
};

struct medical
{
    char name[20];
    float cost;
    int quantity;
};

medical pharm;
vector<medical> medics;
vector<medical> medics2;
vector<medical> medics3;
vector<medical> medics4;
vector<medical> medics5;
vector<medical> medics6;
vector<medical> medics7;
vector<medical> medics8;

class pharmacy
{
    protected:
    int ch2, i, j, found, quan;
    float total_cost = 0;
    string nm, name_search;

    public:

    virtual void text()
    {
        cout<<"This is the pharmacy class"<<endl;
    }

};

class capsule : public pharmacy
{
    public:

    void text()
    {
        cout<<"Capsules data here"<<endl;
    }

    void get_c()
    {
        do
        {
            cout<<"\nEnter name of the capsule : ";
            cin>>pharm.name;
            cout<<"Enter cost of "<<pharm.name<<" capsule : ";
            cin>>pharm.cost;
            cout<<"Enter the quantity : ";
            cin>>pharm.quantity;

            medics.push_back(pharm);
            /*
            cout<<medics[0].name;
       		cout<<medics[0].cost;
        	cout<<medics[0].quantity;
            */
            cout<<"\nEnter 1 to continue and 0 to stop adding : ";
            cin>>ch2;
        }while(ch2!=0 and ch2==1);
    }

    void save_file(const vector<medical> &medics, const string &Medical)
	{
		ofstream out("D:/Medical.txt");
	   	if(!out)
	   	{
	   		cerr<<" File not found : "<<Medical<<endl;
		}
		for(i=0; i<medics.size(); i++)
		{
			out<<i+1<<". Name : "<<medics[i].name<<endl;
	        out<<" Cost : "<<medics[i].cost<<endl;
	        out<<" Quantity : "<<medics[i].quantity<<endl;
		}
		out.close();
		cout<<" Medicines Saved to File "<<Medical<<endl;
	}

    void display_c()
    {
        for(i=0; i<medics.size(); i++)
        {
            cout<<i+1<<". Name of capsule is : "<<medics[i].name<<endl;
            cout<<" Cost of capsule is : "<<medics[i].cost<<endl;
            cout<<" Quantity of capsule is : "<<medics[i].quantity<<endl;
        }
    }

    void search_c()
    {
        cout<<"Enter name of the capsule you want to search : "<<endl;
        cin>>nm;
        found = 0;
        for(i=0; i<medics.size(); i++)
        {
            if(nm == medics[i].name)
            {
            	found = 1;
                cout<<i+1<<". Name of capsule is : "<<medics[i].name<<endl;
                cout<<" Cost of capsule is : "<<medics[i].cost<<endl;
                cout<<" Quantity of capsule is : "<<medics[i].quantity<<endl;
            }
        }
        if(found == 0)
        {
        	cout<<"Medicine not found!";
		}
    }

    void update_c()
    {
        cout << "Enter name of the capsule to be updated: ";
        cin >> nm;
        found = 0;
        for (i = 0; i < medics.size(); i++)
        {
            if (nm == medics[i].name)
            {
                found = 1;
                cout << "Enter the updated name: "<<endl;
                cin >> medics[i].name;
                cout << "Enter updated cost: "<<endl;
                cin >> medics[i].cost;
                cout << "Enter updated quantity: "<<endl;
                cin >> medics[i].quantity;
                cout << "Medicine updated successfully." << endl;
            }
        }

        if (found == 0)
        {
            cout << "Medicine not found!" << endl;
        }
    }

    void delete_c()
    {
        cout<<"Enter name of the capsule you want to delete : "<<endl;
        cin>>nm;
        found = 0;
        for(i=0; i<medics.size(); i++)
        {
            if(nm == medics[i].name)
            {
            	found = 1;
                medics.erase(medics.begin()+i);
                cout<<"Deleted "<<medics[i].name<<endl;
            }
        }
        if(found == 0)
        {
        	cout<<"Medicine not found"<<endl;
		}
    }

    void cust_c()
    {
    	found = 0;
    	cout<<"\nAvailable Capsules are : "<<endl;
    	display_c();
        do
        {
            cout<<"Enter name of the capsule customer wants to buy : "<<endl;
            cin>>pharm.name;
            name_search = pharm.name;
            for(i=0; i<medics.size(); i++)
	        {
	            if(name_search == medics[i].name)
	            {
	            	found = 1;
	                //cout<<"The cost of "<<medics[i].name<<" capsule is "<<medics[i].cost<<endl;
	                cout<<"The cost of capsule is : "<<medics[i].cost<<endl;;
	                pharm.cost = medics[i].cost;
            		cout<<"Enter the quantity customer wants : "<<endl;
            		cin>>pharm.quantity;
            		quan = pharm.quantity;
            		if(quan > medics[i].quantity)
            		{
            			cout<<"The quantity of medicine is not available! Customer can buy less quantity for now. \nEnter if customer agrees : "<<endl;
            			cin>>pharm.quantity;
					}
	            }
	        }
            if(found == 0)
			{
				cout<<"Medicine not available!"<<endl;
			}

            medics5.push_back(pharm);
            cout<<"Enter 1 to continue or 0 to stop adding: "<<endl;
            cin>>ch2;
        }while(ch2!=0 and ch2==1);
    }
};

class tablet : public pharmacy
{
    public:

    void text()
    {
        cout<<"Tablets data here"<<endl;
    }

    void get_t()
    {
        do
        {
            cout<<"Enter name of the tablet : "<<endl;
            cin>>pharm.name;
            cout<<"Enter cost of "<<pharm.name<<" tablet : "<<endl;
            cin>>pharm.cost;
            cout<<"Enter the quantity : "<<endl;
            cin>>pharm.quantity;

            medics2.push_back(pharm);
            cout<<"Enter 1 to continue and 0 to stop adding : "<<endl;
            cin>>ch2;
        }while(ch2!=0 and ch2==1);
    }

    void display_t()
    {
        for(i=0; i<medics2.size(); i++)
        {
            cout<<i+1<<". Name of capsule is : "<<medics2[i].name<<endl;
            cout<<" Cost of capsule is : "<<medics2[i].cost<<endl;
            cout<<" Quantity of capsule is : "<<medics2[i].quantity<<endl;
        }
    }

    void search_t()
    {
        cout<<"Enter name of the tablet you want to search : "<<endl;
        cin>>nm;
        found = 0;
        for(i=0; i<medics2.size(); i++)
        {
            if(nm == medics2[i].name)
            {
            	found = 1;
                cout<<i+1<<". Name of tablet is : "<<medics2[i].name<<endl;
                cout<<" Cost of tablet is : "<<medics2[i].cost<<endl;
                cout<<" Quantity of tablet is : "<<medics2[i].quantity<<endl;
            }
        }
        if(found == 0)
        {
        	cout<<"Medicine not found!"<<endl;
		}
    }

    void update_t()
    {
        cout << "Enter name of the tablet to be updated: "<<endl;
        cin >> nm;
    	found = 0;
        for (i = 0; i < medics2.size(); i++)
        {
            if (nm == medics2[i].name)
            {
                found = 1;
                cout << "Enter the updated name: "<<endl;
                cin >> medics2[i].name;
                cout << "Enter updated cost: "<<endl;
                cin >> medics2[i].cost;
                cout << "Enter updated quantity: "<<endl;
                cin >> medics2[i].quantity;
                cout << "Medicine updated successfully." << endl;
            }
        }
        if (found == 0)
        {
            cout << "Medicine not found!" << endl;
        }
    }

    void delete_t()
    {
        cout<<"Enter name of the tablet to delete : "<<endl;
        cin>>nm;
        for(i=0; i<medics2.size(); i++)
        {
            if(nm == medics2[i].name)
            {
                found = 1;
                medics.erase(medics2.begin()+i);
                cout<<"Deleted "<<medics2[i].name<<endl;
            }
        }
        if(found == 0)
        {
            cout << "Medicine not found!" << endl;
        }
    }

    void cust_t()
    {
    	cout<<"\nAvailable Tablets are : "<<endl;
    	display_t();
        do
        {
            cout<<"Enter name of the tablet customer wants to buy : "<<endl;
            cin>>pharm.name;
            name_search = pharm.name;
            for(i=0; i<medics2.size(); i++)
	        {
	            if(name_search == medics2[i].name)
	            {
	            	found = 1;
	                cout<<"The cost of "<<name_search<<" tablet is "<<medics2[i].cost<<endl;
	                pharm.cost = medics2[i].cost;
            		cout<<"Enter the quantity customer wants : "<<endl;
            		cin>>pharm.quantity;
            		quan = pharm.quantity;
            		if(quan > medics2[i].quantity)
            		{
            			cout<<"The quantity of medicine is not available! Customer can buy less quantity for now. \nEnter if customer agrees : "<<endl;
            			cin>>pharm.quantity;
					}
	            }
	        }
            if(found == 0)
			{
				cout<<"Medicine not available!"<<endl;
			}

            medics6.push_back(pharm);
            cout<<"Enter 1 to continue or 0 to stop adding: "<<endl;
            cin>>ch2;
        }while(ch2!=0 and ch2==1);
    }
};

class liquid : public pharmacy
{
    public:
    /*void text()
    {
        cout<<"Liquids data here"<<endl;
    }*/

    void get_l()
    {
        do
        {
            cout<<"Enter name of the liquid : "<<endl;
            cin>>pharm.name;
            cout<<"Enter cost of "<<pharm.name<<" liquid : "<<endl;
            cin>>pharm.cost;
            cout<<"Enter the quantity : "<<endl;
            cin>>pharm.quantity;

            medics3.push_back(pharm);
            cout<<"Enter 1 to continue and 0 to stop adding : "<<endl;
            cin>>ch2;
        }while(ch2!=0 and ch2==1);
    }

    void display_l()
    {
        for(i=0; i<medics3.size(); i++)
        {
            cout<<i+1<<". Name of liquid is : "<<medics3[i].name<<endl;
            cout<<" Cost of liquid is : "<<medics3[i].cost<<endl;
            cout<<" Quantity of liquid is : "<<medics3[i].quantity<<endl;
        }
    }

    void search_l()
    {
        cout<<"Enter name of the liquid you want to search : "<<endl;
        cin>>nm;
        for(i=0; i<medics3.size(); i++)
        {
            if(nm == medics3[i].name)
            {
                found = 1;
                cout<<i+1<<". Name of liquid is : "<<medics3[i].name<<endl;
                cout<<" Cost of liquid is : "<<medics3[i].cost<<endl;
                cout<<" Quantity of liquid is : "<<medics3[i].quantity<<endl;
            }
        }
        if(found == 0)
        {
            cout << "Medicine not found!" << endl;
        }
    }

    void update_l()
    {
        cout<<"Enter name of the liquid to be updated: "<<endl;
        cin>>nm;
        for(i = 0; i < medics3.size(); i++)
        {
            if(nm == medics3[i].name)
            {
                found = 1;
                cout<<"Enter the updated name: "<<endl;
                cin>>medics3[i].name;
                cout<<"Enter updated cost: "<<endl;
                cin>>medics3[i].cost;
                cout<<"Enter updated quantity: "<<endl;
                cin>>medics3[i].quantity;
                cout<<"Medicine updated successfully." << endl;
            }
        }
        if (found == 0)
        {
            cout << "Medicine not found!" << endl;
        }
    }

    void delete_l()
    {
        cout<<"Enter name of the liquid to delete : "<<endl;
        cin>>nm;
        for(i=0; i<medics3.size(); i++)
        {
            if(nm == medics3[i].name)
            {
            	found = 1;
                medics3.erase(medics3.begin()+i);
                cout<<"Deleted "<<medics3[i].name<<endl;
            }
        }
        if(found == 0)
        {
        	cout<<"Medicine not found! "<<endl;
		}
    }

    void cust_l()
    {
    	cout<<"\nAvailable Liquids are : "<<endl;
    	display_l();
        do
        {
            cout<<"Enter name of the liquid customer wants to buy : "<<endl;
            cin>>pharm.name;
            name_search = pharm.name;
            for(int i=0; i<medics3.size(); i++)
	        {
	            if(name_search == medics3[i].name)
	            {
	            	found = 1;
	                cout<<"The cost of "<<name_search<<" liquid is "<<medics3[i].cost<<endl;
	                pharm.cost = medics3[i].cost;
            		cout<<"Enter the quantity customer wants : "<<endl;
            		cin>>pharm.quantity;
            		quan = pharm.quantity;
            		if(quan > medics3[i].quantity)
            		{
            			cout<<"The quantity of medicine is not available! Customer can buy less quantity for now. \nEnter if customer agrees : "<<endl;
            			cin>>pharm.quantity;
					}
	            }
	        }
            if(found == 0)
			{
				cout<<"Medicine not available!"<<endl;
			}

            medics7.push_back(pharm);
            cout<<"Enter 1 to continue or 0 to stop adding: "<<endl;
            cin>>ch2;
        }while(ch2!=0 and ch2==1);
    }
};

class ayurvedic : public pharmacy
{
    public:

    void get_a()
    {
        do
        {
            cout<<"Enter name of the ayurveda : "<<endl;
            cin>>pharm.name;
            cout<<"Enter cost of "<<pharm.name<<" ayurveda : "<<endl;
            cin>>pharm.cost;
            cout<<"Enter the quantity : "<<endl;
            cin>>pharm.quantity;

            medics4.push_back(pharm);
            cout<<"Enter 1 to continue or 0 to stop adding : "<<endl;
            cin>>ch2;
        }while(ch2!=0 and ch2==1);
    }

    void display_a()
    {
        for(i=0; i<medics4.size(); i++)
        {
            cout<<i+1<<". Name of ayurveda is : "<<medics4[i].name<<endl;
            cout<<" Cost of ayurveda is : "<<medics4[i].cost<<endl;
            cout<<" Quantity of ayurveda is : "<<medics4[i].quantity<<endl;
        }
    }

    void search_a()
    {
        cout<<"Enter name of the ayurveda you want to search : "<<endl;
        cin>>nm;
        for(int i=0; i<medics4.size(); i++)
        {
            if(nm == medics4[i].name)
            {
                found = 1;
                cout<<i+1<<". Name of ayurveda is : "<<medics4[i].name<<endl;
                cout<<" Cost of ayurveda is : "<<medics4[i].cost<<endl;
                cout<<" Quantity of ayurveda is : "<<medics4[i].quantity<<endl;
            }
        }
        if(found == 0)
        {
            cout<<"Medicine not found !"<<endl;
        }
    }

    void update_a()
    {
        cout << "Enter name of the aurvedic medicine to be updated: "<<endl;
        cin >> nm;
        for (i = 0; i < medics4.size(); i++)
        {
            if (nm == medics4[i].name)
            {
                found = 1;
                cout << "Enter the updated name: "<<endl;
                cin >> medics4[i].name;
                cout << "Enter updated cost: "<<endl;
                cin >> medics4[i].cost;
                cout << "Enter updated quantity: "<<endl;
                cin >> medics4[i].quantity;
                cout << "Medicine updated successfully." << endl;
            }
        }
        if (found == 0)
        {
            cout << "Medicine not found !" << endl;
        }
    }

    void delete_a()
    {
        cout<<"Enter name of the ayurveda to delete : "<<endl;
        cin>>nm;
        for(i=0; i<medics4.size(); i++)
        {
            if(nm == medics4[i].name)
            {
            	found = 1;
                medics4.erase(medics4.begin()+i);
                cout<<"Deleted "<<medics4[i].name<<endl;
            }
        }
        if(found == 0)
        {
        	cout<<"Medicine not found !"<<endl;
		}
    }

    void cust_a()
    {
    	cout<<"\nAvailable Ayurveda are : "<<endl;
    	display_a();
        do
        {
            cout<<"Enter name of the ayurveda customer wants to buy : "<<endl;
            cin>>pharm.name;
            name_search = pharm.name;
            for(int i=0; i<medics4.size(); i++)
	        {
	            if(name_search == medics4[i].name)
	            {
	            	found = 1;
	                cout<<"The cost of "<<name_search<<" ayurveda is "<<medics4[i].cost<<endl;
	                pharm.cost = medics4[i].cost;
            		cout<<"Enter the quantity customer wants : "<<endl;
            		cin>>pharm.quantity;
            		quan = pharm.quantity;
            		if(quan > medics4[i].quantity)
            		{
            			cout<<"The quantity of medicine is not available! Customer can buy less quantity for now. \nEnter if customer agrees : "<<endl;
            			cin>>pharm.quantity;
					}
	            }
	        }
            if(found == 0)
			{
				cout<<"Medicine not available !"<<endl;
			}

            medics8.push_back(pharm);
            cout<<"Enter 1 to continue or 0 to stop adding: "<<endl;
            cin>>ch2;
        }while(ch2!=0 and ch2==1);
    }
};

class generate_bill : public pharmacy
{
    public:
    void bill()
	{
	    cout << FYEL("\n---------------------------------------------------------------------");
        cout << FRED("\n                           INVOICE                           	     ");
        cout << FYEL("\n---------------------------------------------------------------------")<<endl;

	    cout << left << setw(6) << "Item";
	    cout << left << setw(20) << "Name";
	    cout << left << setw(15) << "Cost";
	    cout << left << setw(15) << "Quantity";
	    cout << left << setw(15) << "Total Cost" << endl;

	    for ( i = 0; i < medics5.size(); i++)
	    {
	        cout << left << setw(6) << i + 1;
	        cout << left << setw(20) << medics5[i].name;
	        cout << left << setw(15) << medics5[i].cost;
	        cout << left << setw(15) << medics5[i].quantity;
	        float item_cost = medics5[i].cost * medics5[i].quantity;
	        cout << left << setw(15) << item_cost << endl;
	        total_cost += item_cost;
	    }

	    for ( j = 0; j < medics6.size(); j++)
	    {
	        cout << left << setw(6) << i + 1;
	        cout << left << setw(20) << medics6[j].name;
	        cout << left << setw(15) << medics6[j].cost;
	        cout << left << setw(15) << medics6[j].quantity;
	        float item_cost = medics6[j].cost * medics6[j].quantity;
	        cout << left << setw(15) << item_cost << endl;
	        total_cost += item_cost;
	    }

	    for ( j = 0; j < medics7.size(); j++)
	    {
	        cout << left << setw(6) << i + 1;
	        cout << left << setw(20) << medics7[j].name;
	        cout << left << setw(15) << medics7[j].cost;
	        cout << left << setw(15) << medics7[j].quantity;
	        float item_cost = medics7[j].cost * medics7[j].quantity;
	        cout << left << setw(15) << item_cost << endl;
	        total_cost += item_cost;
	    }

	    for ( j = 0; j < medics8.size(); j++)
	    {
	        cout << left << setw(6) << i + 1;
	        cout << left << setw(20) << medics8[j].name;
	        cout << left << setw(15) << medics8[j].cost;
	        cout << left << setw(15) << medics8[j].quantity;
	        float item_cost = medics8[j].cost * medics8[j].quantity;
	        cout << left << setw(15) << item_cost << endl;
	        total_cost += item_cost;
	    }

	    cout << "Total Cost Payable : " << total_cost << endl;
	}

};

void menu()
{
	int choice, type;
    do
    {
        cout<<FBLU("\n--------------------------------------------------------------------");
    	cout<<FYEL("\n\t\t\tPHARMACY STORE");
    	cout<<FBLU("\n--------------------------------------------------------------------")<<endl;
        cout<< left << setw(8) << "1.Input data of medicines"<<endl;
        cout<< left << setw(8) << "2.Display data of medicines"<<endl;
        cout<< left << setw(8) << "3.Search medicines"<<endl;
        cout<< left << setw(8) << "4.Update medicines"<<endl;
        cout<< left << setw(8) << "5.Delete medicines"<<endl;
        cout<< left << setw(8) << "6.Save medicines to file"<<endl;
        cout<< left << setw(8) << "7.Enter customer sell"<<endl;
        cout<< left << setw(8) << "8.Generate Bill"<<endl;
        cout<< left << setw(8) << "9.Exit"<<endl;
        cout<< left << setw(8) << "Enter your choice : "<<endl;
        cin>>choice;

        pharmacy *p ,*p1,o1;
        capsule o2;
        tablet o3;
        p = &o2;
        p1 = &o3;
        p->text();
        p1->text();

        capsule c;
        tablet t;
        liquid l;
        ayurvedic a;
        generate_bill g;

        switch(choice)
        {
            char ch1;
            case 1: //Get data
            		system("CLS");
                    do{
                        cout<<FGRN("\nEnter the type of medicine : ")<<endl;
                        cout<<FRED("1.Capsule\n2.Tablet\n3.Liquid\n4.Ayurvedic")<<endl;
                        cout<<FMAG("Enter your choice : ");
                        cin>>type;
                        switch(type)
                        {
                            case 1: c.get_c();
                                    break;
                            case 2: t.get_t();
                                    break;
                            case 3: l.get_l();
                                    break;
                            case 4: a.get_a();
                                    break;
                            default:
                                    cout<<"Invalid Choice! Please enter again"<<endl;
                        }
                        cout<<"\nDo you want to add more medicines?(y/n) : "<<endl;
                        cin>>ch1;
                    }while(ch1=='y'||ch1=='Y');
                    break;

            case 2: //display
            		system("CLS");
                    do{
                        cout<<FGRN("Enter the type of medicine : ")<<endl;
                        cout<<FRED("1.Capsule\n2.Tablet\n3.Liquid\n4.Ayurvedic")<<endl;
                        cout<<FMAG("Enter your choice : ");
                        cin>>type;
                        switch(type)
                        {
                            case 1: c.display_c();
                                    break;
                            case 2: t.display_t();
                                    break;
                            case 3: l.display_l();
                                    break;
                            case 4: a.display_a();
                                    break;
                            default:
                                    cout<<"Invalid Choice! Please enter again";
                        }
                        cout<<"\nDo you want to display more medicines?(y/n) : ";
                        cin>>ch1;
                    }while(ch1=='y'||ch1=='Y');
                    break;

            case 3: //search
            		system("CLS");
                    do{
                        cout<<FGRN("Enter the type of medicine : ")<<endl;
                        cout<<FRED("1.Capsule\n2.Tablet\n3.Liquid\n4.Ayurvedic")<<endl;
                        cout<<FMAG("Enter your choice : ");
                        cin>>type;
                        switch(type)
                        {
                            case 1: c.search_c();
                                    break;
                            case 2: t.search_t();
                                    break;
                            case 3: l.search_l();
                                    break;
                            case 4: a.search_a();
                                    break;
                            default:
                                    cout<<"Invalid Choice! Please enter again"<<endl;
                        }
                        cout<<"\nDo you want to search more medicines?(y/n) : "<<endl;
                        cin>>ch1;
                    }while(ch1=='y'||ch1=='Y');
                    break;

            case 4: //update
            		system("CLS");
                    do{
                        cout<<FGRN("Enter the type of medicine : ")<<endl;
                        cout<<FRED("1.Capsule\n2.Tablet\n3.Liquid\n4.Ayurvedic")<<endl;
                        cout<<FMAG("Enter your choice : ");
                        cin>>type;
                        switch(type)
                        {
                            case 1: c.update_c();
                                    break;
                            case 2: t.update_t();
                                    break;
                            case 3: l.update_l();
                                    break;
                            case 4: a.update_a();
                                    break;
                            default:
                                    cout<<"Invalid Choice! Please enter again"<<endl;
                        }
                        cout<<"\nDo you want to update more medicines?(y/n) : "<<endl;
                        cin>>ch1;
                    }while(ch1=='y'||ch1=='Y');
                    break;

            case 5: //delete
            		system("CLS");
                    do{
                        cout<<FGRN("Enter the type of medicine : ")<<endl;
                        cout<<FRED("1.Capsule\n2.Tablet\n3.Liquid\n4.Ayurvedic")<<endl;
                        cout<<FMAG("Enter your choice : ");
                        cin>>type;
                        switch(type)
                        {
                            case 1: c.delete_c();
                                    break;
                            case 2: t.delete_t();
                                    break;
                            case 3: l.delete_l();
                                    break;
                            case 4: a.delete_a();
                                    break;
                            default:
                                    cout<<"Invalid Choice! Please enter again"<<endl;
                        }
                        cout<<"\nDo you want to delete more medicines?(y/n) : "<<endl;
                        cin>>ch1;
                    }while(ch1=='y'||ch1=='Y');
                    break;

            case 6: //save to file
                    system("CLS");
                    c.save_file(medics, "D:/Medical.txt");
                    break;

            case 7: //customer sell
            		system("CLS");
                    do{
                        cout<<FGRN("Enter the type of medicine : ")<<endl;
                        cout<<FRED("1.Capsule\n2.Tablet\n3.Liquid\n4.Ayurvedic")<<endl;
                        cout<<FMAG("Enter your choice : ");
                        cin>>type;
                        switch(type)
                        {
                            case 1: c.cust_c();
                                    break;
                            case 2: t.cust_t();
                                    break;
                            case 3: l.cust_l();
                                    break;
                            case 4: a.cust_a();
                                    break;
                            default:
                                    cout<<"Invalid Choice! Please enter again"<<endl;
                        }
                        cout<<"\nDo customer wants to buy more medicines?(y/n) : ";
                        cin>>ch1;
                    }while(ch1=='y'||ch1=='Y');
                    break;

            case 8: //billing system
            		system("CLS");
                    g.bill();
                    break;

            case 9: cout<<FRED(BOLD("-----> VISIT AGAIN <-----"))<<endl;
                    exit(0);

            default: cout<<"Invalid Choice! Please enter again!"<<endl;
        }
    }while(choice!=9);
}

int main()
{
	secure obj;
    return 0;
}
