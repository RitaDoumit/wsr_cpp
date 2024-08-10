#ifndef DRESSES_H
#define DRESSES_H
#include "dressdata.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
extern fstream newData;

extern const char FNAME[20];
extern fstream newData;

extern vector<DressData> dresses;
extern DressData d;

void dressinfo(int code, string color, string size, string supplier, string designer, string suppliernb, double retailPrice, double rentalPrice)
{
  cout << "\nDress CODE: " << code << endl;
  cout << "Dress Color: " << color << endl;
  cout << "Dress Size: " << size << endl;
  cout << "Dress Designer: " << designer << endl;
  cout << "Dress Supplier: " << supplier << endl;
  cout << "Supplier Number: " << suppliernb << endl;
  cout << "Retail Price: " << retailPrice << " $" << endl;
  cout << "Net Rental Price: " << rentalPrice << " $" << endl;
}

void addDress()
{

  int DressCode1;
  double RentalPrice1;
  double RetailPrice1;
  char DressSize1[30];
  char DressColor1[30];
  char DressDesigner1[30];
  char DressSupplier1[30];
  char SupplierNb1[30];

  int i = 0;
  cin.ignore();
  cout << "Enter Supplier's name:";
  cin.getline(DressSupplier1, 30);
  cout << "Enter Supplier's phone number:";
  cin.getline(SupplierNb1, 30);
  cout << "Enter dress's CODE:";
  cin >> DressCode1;
  cin.ignore();
  cout << "Enter dress's Size :";
  cin.getline(DressSize1, 30);

  cout << "Enter dress's color :";
  cin.getline(DressColor1, 30);

  cout << "Enter dress's Designer :";
  cin.getline(DressDesigner1, 30);

  cout << "Enter dress's Rental price:";
  cin >> RentalPrice1;

  cout << "Enter dress's Net Retail price:";
  cin >> RetailPrice1;

  d.DressCode = DressCode1;
  d.RentalPrice = RentalPrice1;
  d.RetailPrice = RetailPrice1;
  strcpy(d.DressSize, DressSize1);
  strcpy(d.DressColor, DressColor1);
  strcpy(d.DressDesigner, DressDesigner1);
  strcpy(d.DressSupplier, DressSupplier1);
  strcpy(d.SupplierNb, SupplierNb1);

  dresses.push_back(d);

  newData.open(FNAME);

  ofstream newData(FNAME, ios::app);

  newData << d.DressCode << "\t" << d.DressDesigner << "\t" << d.DressSupplier << "\t" << d.SupplierNb << "\t" << d.DressColor << "\t" << d.DressSize << "\t" << d.RentalPrice << "\t" << d.RetailPrice;

  cout << endl
       << " Dress was added\n ";
  newData.close();
}

void look4Dress()
{
  bool found = false;
  int i = 0;
  int searchdress;

  cout << "\nEnter code of dress:";
  cin >> searchdress;

  for (auto it : dresses)
  {
    if (it.DressCode == searchdress)
    {
      found = true;
      dressinfo(it.DressCode, it.DressColor, it.DressSize, it.DressSupplier, it.DressDesigner, it.SupplierNb, it.RetailPrice, it.RentalPrice);
      break;
    }
  }

  if (!found)
  {
    cout << "\nDress not found!" << endl;
  }
}

void removeDress()
{
  bool found = false;
  int i = 0;
  int dresscode;
  cin.ignore();
  cout << "Enter code of dress:";
  cin >> dresscode;
  char confirm;
  cin.ignore();

  int word;
  string line;
  fstream s;
  fstream o;
  s.open(FNAME);      // final file
  o.open("temp.txt"); // temp file
  for (DressData it : dresses)
  {

    if (it.DressCode == dresscode)
    {
      found = true;
    }
    else
    {
      i++;
    }

    if (found)
    {
      dressinfo(it.DressCode, it.DressColor, it.DressSize, it.DressSupplier, it.DressDesigner, it.SupplierNb, it.RetailPrice, it.RentalPrice);
      cout << "\nAre you sure you want to remove this dress? \n";
      cin >> confirm;

      if (confirm == 'Y' || confirm == 'y')
      {

        while (s >> word)
        { // reading from original file

          if (word != dresscode)
          {
            getline(s, line);

            o << word << line << "\n"; // write on temp file
          }
          else
          {
            getline(s, line);

            // move on
          }
        }

        o.seekp(0);
        s.open(FNAME, ios::trunc);
        s.close();
        s.open(FNAME, ios::out);

        while (getline(o, line))
        {
          {
            s << line << "\n";
          }
        }
        o.close();
        o.open("temp.txt", ios::out | ios::trunc); // temp file
        dresses.erase(dresses.begin() + i);

        cout << "Dress was removed!" << endl;
        break;
      }
    }

    i++;
  }

  if (!found)
  {

    cout << "Dress not found!\n \n";
  }
  o.open("temp.txt", ios::trunc);
  o.close();
}

void Select()
{
  int choice = 0;
  while (choice != 4)
  {

    cout << "\n   We Speak Runway \n";
    cout << "\t Dresses \n \n";
    cout << "1. Add Dress \n";
    cout << "2. Look for dress\n";
    cout << "3. Remove dress\n";
    cout << "4. Return to Main Menu \n\n";
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 1 || choice > 4)
    {
      cout << "Enter a valid choice:";
      cin >> choice;
    }
    switch (choice)
    {
    case 1:
      addDress();
    case 2:
      look4Dress();
      break;
    case 3:
      removeDress();
      break;
    case 4:
      cout << "Back to main menu /n";
      break;
    }
  }
}

#endif