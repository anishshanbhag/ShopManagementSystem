#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
class earn{
        public:
        double profit;
        void show()
		{
		ofstream x("ooo.txt");
        if(!x)
        cout<<"PROFIT = 0 ";
        else{
        x<<profit;
        cout<<"\nTOTAL STARTING PROFIT:  "<<profit;
        x.close();
        }
        }

};
class product:public virtual earn{
public:
           int quan;
           char name[20];
           char id[20];
           double percost;
           double persell;
           double cost;
           double sell;
           void cal()
		   {
		    cost=percost*quan;
        	sell=persell*quan;
            profit=profit +(sell-cost)*365;
			}
           void file();
           void get() ;

};
void product::get()
{
 int s;
cout<<"\nnumber of products produced?\n";
cin>>s;
for(int i=0;i<s;i++)
{
  cout<<"\ninput product name: \n";
  cin>>name;
  cout<<"\ninput product id: \n";
  cin>>id;
  cout<<"\ninput percost of product: \n";
  cin>>percost;
  cout<<"\ninput persell of product: \n";
  cin>>persell;
  cout<<"\ntotal product quntity: \nb";
  cin>>quan;
  }
  cal();
  file();
}
void product::file()
{
char file[20];
strcpy(file,id);
strcat(file,".txt");
ofstream f(file);
f<< "\nproduct name: "<<name<< "\nproduct id: "<<id<<"\npercost ofproduct: " <<percost<<"\npersell of product: "<<persell<<"\nquantity: "<<quan<<"\n total cost: "<<cost<<"\nsell: "<<sell;
f.close();
}

class staff:public virtual earn{
         protected:
         double salary;
         char post[12];
         char empid[10];
         int postquan;
         void cal()
         {
		 profit=(profit-salary*postquan)*12;
         }
         void getstaff();
         void file();
};
void staff::getstaff()
{
  cout<<"\ninput salary: \n";
  cin>>salary;
  cout<<"\ninput post quantity: \n";
  cin>>postquan;
  for(int i=0;i<postquan;i++)
  {
  	cout<<"input employee name\n";
  	cin>>post;
  cout<<"\ninput employee ID\n";
  cin>>empid;
  cal();
  file();
}
}
 void staff::file()
{  char file[20];
strcpy(file,empid);
strcat(file,".txt");
ofstream f(file);
f<< "\nnumber of working employees: "<<postquan<< "\nemployee salary: "<<salary<< "\nemployee name :"<<post<<"\nemployee id: "<<empid;
f.close();
}

class amount:public staff, public product
{

 public:
    void add();
};
void amount::add()
{
 cout<<"\nINPUT FOR PRODUCT\n";
 get();
 cout<<"\nINPUT FOR EMPLOYEE\n";
 getstaff();

 ofstream x("ooo.txt");
 x<<profit;
 x.close();
}


int main()
{
  //clrscr();
  while(1)
  {
 // clrscr();
 cout<<"\t==============================\n";
	cout<<"\t     WELCOME TO THE SHOP  \n";
	cout<<" \t==============================\n\n";
	cout<<"\t* * * * * * * * * * * * * * * *\n";
  cout<<"1. Add Entries\n2. Show profit\n3. Search Product\n4. Search Employee\n5. Exit\n";
  cout<<"\nSelect your choice\n";
  int u;
  cin>>u;
if(u==1)
  {
  amount a;
  a.show();
  a.add();
}
  else if(u==2)
  {
  amount d;
  d.show();
}
  else if(u==3)
  {   //clrscr();
   char id[20];
   char c;
    cout<<"\nINPUT ID to search\n";
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    ifstream x(file);
    while(x)
    {x.get(c);
     cout<<c;
    }
    x.close();
}
   else if(u==4)
   {
   	char eid[20];
   	char d;
   	cout<<"\nINPUT employee ID to search\n";
    cin>>eid;
   	char file[20];
   	strcpy(file,eid);
   	strcat(file,".txt");
   	ifstream y(file);
   	while(y)
   	{
   	y.get(d);
   	cout<<d;
   }
   y.close();
}
  else if(u==5)
  {
  break;
}
  else cout<<"Invalid option. Please select one of the available options\n";
 }
  return 0;

}

