#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

const int No_of_items = 7;
const string Categories[No_of_items] = { "Case", "RAM", "Hard Disk", "Solid State Drive", "Second Hard Disk Drive", "Optical Drive", "Operating System" };
const string itemCode[No_of_items] = { "A", "B", "C", "D", "E", "F", "G" };
const string Description[No_of_items][3] =
{
	{"A1 Compact", "A2 Tower"},
	{"B1 8GB", "B2 16GB", "B3 32GB"},
	{"C1 1 TB HDD", "C2 2 TB HDD", "C3 4 TB HDD"},
	 {"D1 240 GB SSD", "D2 480 GB SSD"},
	{"E1 1 TB HDD", "E2 2 TB HDD", "E3 4 TB HDD"},
	{"F1 DVD/Blu-Ray Player", "F2 DVD/Blu-Ray Re-writer"},
	{"G1 Standard Version", "G2 Professional Version"}
};

double price[No_of_items][3] =
{
	{75.00, 150.00},
	{79.99, 149.99, 299.99},
	{49.99, 89.99, 129.99},
	{59.99, 119.99},
	{49.99, 89.99, 129.99},
	{50.00, 100.00},
	{100.00, 175.00}
};

void Display(int category)
{
	cout << "Availble items " << Categories[category] << endl;
	for (int h = 0; h < 3; h++)
	{
		cout << h << Description[category][h] << " ($" << price[category][h] << ")" << endl;

	}

}

int main()
{

	vector <int> selecteditem(No_of_items, 0);
	double totalprice = 200; // as given the simple price is 200
	int additionItem = 0;
	double discount = 0.0, savedamnt;

	cout << "Welcome to Online Computer Store." << endl;

	for (int j = 0; j < 7; j++)
	{
		Display(j);
		int choice;

		do
		{
			cout << "Enter the item code you want or (-1) to skip the item: ";
			cin >> choice;

			if (choice >= 0 && choice < 3)
			{
				selecteditem[j] = choice;
				totalprice += price[j][choice];
				additionItem++;
			}

			else if (choice != -1)
			{
				cout << "Item do not exit." << endl;
			}
		} while (choice < -1 || choice >= 7);

	}

	if (additionItem == 1)
	{
		discount = 0.05;
	}

	else if (additionItem >= 2)
	{
		discount = 0.10;
	}

	savedamnt = totalprice * discount;
	totalprice -= savedamnt;



	cout << "You have selected the following item" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << Description[i][selecteditem[i]] << " ($" << price[i][selecteditem[i]] << ")\n";
	}

	cout << "Total Price: $" << totalprice + savedamnt << endl;
	cout << "You have saved: $" << savedamnt << endl;
	cout << "Gross Total: $ " << totalprice << endl;
}