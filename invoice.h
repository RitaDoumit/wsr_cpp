#ifndef INVOICE_H
#define INVOICE_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstddef>
#include <vector>
#include "dressdata.h"
using namespace std;
extern const char FNAME[20];
extern vector<DressData> dresses;
extern DressData d;
bool inStore(int code)
{
        bool found = false;
        for (auto it : dresses)
        {
                if (it.DressCode == code)
                {
                        found = true;
                        break;
                }
        }
        return found;
}

void invoice()
{
        string Rentaldate; // entered by user
        int deposit;
        char Cname[51];
        char Cnb[51];
        int DCode;

        char inFileDate[51];
        int nb;
        char inFileName[51];
        char inFileNb[51];
        bool found;
        bool available = true;
        cout << " \n\nWSR Invoice \n \n";
        cout << "Enter Date: ";
        cin.ignore();
        getline(cin, Rentaldate);

        cout << "\nEnter dress's CODE:";
        cin >> DCode;
        found = inStore(DCode);

        if (found == false)
        {
                cout << "Dress doesn't exist..\n";
        }

        if (found == true)
        {
                for (auto it : dresses)
                {
                        if (it.DressCode == DCode)
                        {

                                fstream s;
                                s.open("rdates.txt", ios::in);

                                while (!s.eof())
                                {
                                        s >> nb;
                                        if (nb == it.DressCode)
                                        {
                                                s >> inFileDate >> inFileName >> inFileNb;

                                                if (inFileDate == Rentaldate)
                                                {
                                                        available = false;
                                                }
                                        }
                                }

                                s.close();

                                if (available == false)

                                {
                                        cout << "Dress is not available on that date! \n";
                                }

                                else if (available == true)
                                {

                                        cout << endl;
                                        cout << "Customer's Name: ";
                                        cin >> Cname;
                                        cin.ignore();
                                        cout << endl;
                                        cout << "Customer's Number: ";
                                        cin >> Cnb;

                                        cout << endl;

                                        s.open("rdates.txt", ios::app);

                                        s << it.DressCode << " " << Rentaldate << " " << Cname << " " << Cnb << endl;
                                        ;
                                        s.close();

                                        cout << "INVOICE \n";
                                        cout << "Dress CODE: " << it.DressCode << endl;
                                        cout << "Dress Color: " << it.DressColor << endl;
                                        cout << "Dress Size: " << it.DressSize << endl;
                                        cout << "Dress Designer: " << it.DressDesigner << endl;
                                        cout << "Net Rental Price: " << it.RentalPrice << endl;
                                        deposit = it.RentalPrice * 0.2;
                                        cout << "Deposit paid: " << deposit << endl;
                                        cout << "Remaining amount: " << it.RentalPrice - deposit;
                                }
                        }
                }
        }
}

#endif