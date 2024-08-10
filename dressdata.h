#ifndef DRESSINFO_H
#define DRESSINFO_H
#include <vector>
#include <string>
using namespace std;
struct DressData
		{
			int DressCode;
			double RentalPrice;
			double RetailPrice;
			char DressSize[51];
			char DressColor[51];
			char DressDesigner[51];
			char DressSupplier[51];
			char SupplierNb[51];
			
		};
		#endif