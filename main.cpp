#include "invoice.h"
#include "dresses.h"
#include "dressdata.h"
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;

vector<DressData> dresses;
const char FNAME[20]="inventory.dat";
fstream newData;
DressData d;

int main() {

int choice=0;

newData.open(FNAME,ios::in ); // create new file in reading mode

  if(newData.fail()){

newData.open(FNAME,ios::out); // create file in writting mode
cout<<"No data is available. Add dresses to the inventory!\n \n Add Dresses:\n \n";
addDress();
newData.close();
newData.clear();
}
while(newData>>d.DressCode>>d.DressDesigner>>d.DressSupplier>>d.SupplierNb>>d.DressColor>>d.DressSize>>d.RentalPrice>>d.RetailPrice)
{
  dresses.push_back(d);
}

	while (choice !=3)
	{
        cout<<"\n    Rent A Dress \n";
        cout<<"\t Main Menu \n \n";
        cout<<"1. Create Invoice \n";
        cout<<"2. Dresses\n";
        cout<<"3. Exit\n";

  cout<<"Enter your choice: ";
  cin>>choice;

//validate input
while(choice<1 || choice>3)
{
    cout<<"Enter a valid choice:";
    cin>>choice;
}
switch (choice){

case 1:
invoice();
break;
case 2:
Select();
break;
case 3:
break;
			}

}

   return 0;

   }
