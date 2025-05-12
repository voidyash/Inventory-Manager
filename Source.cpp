#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<iostream>


// class dept contains main function to perform add, perform, add, update, view, and delete operations
class dept
{
public:
	// control panel function is called which displays the option available to the user
	void control_panel();
	void add_item();
	void display_item();
	void check_item();
	void update_item();
	void delete_item();
};

// control panel
void dept::control_panel()
{
	// using the colour combination of 0A
	system("Color 0A");
	system("cls");
	std::cout << "************************************************" << std::endl;
	std::cout << "\n\t\t\tSTORE'S INVENTORY MANAGEMENT SYSTEM" << std::endl;
	std::cout << "\n\t\t\tCONTROL PANEL:- " << std::endl;
	std::cout << "************************************************" << std::endl;

	std::cout << "\n\n 1) ADD NEW ITEM. " << std::endl;
	
	std::cout << " 2) DISPLAY ITEMS." << std::endl;
	std::cout << " 3) CHECK SPECIFIC ITEMS." << std::endl;

	std::cout << " 4) UPDATE ITEM. " << std::endl;
	
	std::cout << " 5) DELETE ITEM. " << std::endl;
	std::cout << " 6) EXIT. " << std::endl;
}

// ADD ITEM
void dept::add_item()
{
	system("cls");

	// using the colour combination of 0A
	system("Color 0A");
	std::fstream file;
	int no_item, item_id;
	std::string itm_name;
	std::string c_name;

	std::cout << "\n\n\t\t\t ADD NEW ITEM:- " << std::endl;
	std::cout << "=================================================" << std::endl;
	std::cout << "Item Code:- " << std::endl;
	std::cin >> item_id;
	std::cout << "=================================================" << std::endl;
	std::cout << "\n\n\t\t\t Item Name:- " << std::endl;
	std::cin >> itm_name;
	std::cout << "\n\t\t\t Company Name:- " << std::endl;
	std::cin >> c_name;
	std::cout << "\n\n\t\t\t Number of items:- " << std::endl;
	std::cin >> no_item;

	file.open("item.txt", std::ios::out | std::ios::app);
	file << " " << item_id << " " << itm_name << " " << c_name << " " << no_item << std::endl;
	std::cout << "========================================================================" << std::endl;

	file.close();
}

// display item
void dept::display_item()
{
	system("cls");

	system("Color 0A");
	std::fstream file;
	int no_item, item_code;
	std::string itm_name;
	std::string c_name;
	file.open("item.txt", std::ios::in);
	if (!file)
	{
		std::cout << "File opening error!" << std::endl;
	}
	else
	{
		std::cout << "========================================================" << std::endl;
		std::cout << " Item Code          Item           Company         Number of item" << std::endl;
		std::cout << "========================================================" << std::endl;
		file >> item_code >> itm_name >> c_name >> no_item;
		while (!file.eof())
		{
			std::cout << "   " << item_code << "           " << itm_name << "           " << c_name << "\t          " << no_item << std::endl;;
			file >> item_code >> itm_name >> c_name >> no_item;
		}
		std::cout << "=======================================================" << std::endl;
		file.close();
	}
}

// check specific item
void dept::check_item()
{
	system("cls");

	system("Color 0A");
	std::fstream file;
	int count = 0;
	int no_item, item_code;
	std::string itm_name, c_name;

	std::cout << "\n\n\t\t\t\t CHECK SPECIFIC PRODUCTS" << std::endl;
	std::cout << "======================================================" << std::endl;

	file.open("item.txt", std::ios::in);
	if (!file)
	{
		std::cout << "File Opening Error!" << std::endl;
	}
	else
	{
		int it_code;
		std::cout << "\n\n Item Code:- " << std::endl;
		std::cin >> it_code;
		std::cout << "==================================================" << std::endl;


		file >> item_code >> itm_name >> c_name >> no_item;

		while (!file.eof())
		{
			if (it_code == item_code)
			{
				system("cls");
				std::cout << "\n\n\t\t\t\t CHECK SPECIFIC PRODUCT!!! " << std::endl;
				std::cout << "\n\n Item code:- " << item_code << std::endl;
				std::cout << "\n Item Name:- " << itm_name << std::endl;
				std::cout << "\n Company Name:- " << c_name << std::endl;
				std::cout << "\n Number of items:- " << no_item << std::endl;
				count++;
				break;
			}
			file >> item_code >> itm_name >> c_name >> no_item;
		}
		file.close();
		if (count == 0)
		{
			std::cout << "Item not found!!!" << std::endl;
		}
	}
}

// update item
void dept::update_item()
{
	system("cls");

	system("Color 0A");
	std::fstream file, file1;
	int no_copy, no_co, count = 0;
	std::string itm_name, b_na, a_name, a_na, newitm_idd, newitm_id;

	std::cout << "\n\n\t\t\t\t UPDATE ITEM RECORD" << std::endl;
	std::cout << "====================================================================" << std::endl;

	file1.open("book1.txt", std::ios::app | std::ios::out);
	file.open("item.txt", std::ios::in);

	if (!file)
	{
		std::cout << "File Opening Error!" << std::endl;
	}
	else
	{
		std::cout << "\n\n Item Code:" << std::endl;
		std::cin >> newitm_id;
		std::cout << "\n--------------------------------------------------------" << std::endl;

		file >> newitm_id >> itm_name >> a_name >> no_copy;

		while (!file.eof())
		{
			if (newitm_id == newitm_idd)
			{
				system("cls");

				std::cout << "\n\n\t\t\t\t Update Book Record:" << std::endl;
				std::cout << "\n New item name: " << std::endl;
				std::cin >> b_na;

				std::cout << "\n\n\t\t\t\t Company Name: " << std::endl;
				std::cin >> a_na;

				std::cout << "\n\n\t\t\t\t Number of items: " << std::endl;
				std::cin >> no_co;

				file1 << " " << newitm_id << " " << b_na << " " << a_na << " " << no_co << std::endl;
				count++;
			}

			else
			{
				file1 << " " << newitm_idd << " " << itm_name << " " << a_name << " " << no_copy << std::endl;
			}
			file >> newitm_idd >> itm_name >> a_name >> no_copy;
		}
		if (count == 0)
		{
			std::cout << "\n\n Item code not found. " << std::endl;
		}
	}

	file.close();
	file1.close();

	remove("item.txt");
	rename("book1.txt", "item.txt");
}

// delete item
void dept::delete_item()
{
	system("cls");

	system("Color 0A");
	std::fstream file, file1;
	int no_copy, count = 0;

	std::string newitm_id, newitm_idd, itm_name, a_name;

	std::cout << "\n\n\t\t\t\t Delete Item Record: " << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

	file1.open("book1.txt", std::ios::app | std::ios::out);
	file.open("item.txt", std::ios::in);

	if (!file)
	{
		std::cout << "\n\n File Opening Error!" << std::endl;
	}
	else
	{
		std::cout << "\n\n Item Code: " << std::endl;
		std::cin >> newitm_id;

		std::cout << "---------------------------------------------------------------------------------" << std::endl;
		
		file >> newitm_id >> itm_name >> a_name >> no_copy;

		while (!file.eof())
		{
			if (newitm_id == newitm_idd)
			{
				system("cls");
				std::cout << "\n\n\t\t\t\t Delete item record" << std::endl;
				std::cout << "\n\n One Item is Deleted Successfully......" << std::endl;
				count++;
			}
			else
			{
				file1 << " " << newitm_idd << " " << itm_name << " " << a_name << " " << no_copy << std::endl;
			}
			file >> newitm_id >> itm_name >> a_name >> no_copy;
		}
		if (count == 0)
		{
			std::cout << "\n\n Book ID not found!" << std::endl;
		}
	}
	file.close();
	file1.close();

	remove("item.txt");
	rename("temp.txt", "item.txt");
}

int main()
{
	dept d;

p:
	d.control_panel();
	int choice;

	char x;
	std::cout << "\n\n YOUR CHOICE:- " << std::endl;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		do
		{
			d.add_item();
			std::cout << "Do you want to add another item? (y/n)" << std::endl;
			std::cin >> x;
		} while (x == 'y');
		break;
	case 2:
		d.display_item();
		break;
	case 3:
		d.check_item();
		break;
	case 4:
		d.update_item();
		break;
	case 5:
		d.delete_item();
		break;
	case 6: 
		exit(0);
		break;
	default:
		std::cout << "\n\n Invalid value...... Please try again later!!" << std::endl;
		break;
	}
	std::cout << std::endl;
	_getch();

	goto p;
}