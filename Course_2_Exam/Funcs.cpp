#include"Header.h"

void checkUser(GasStation& gs)
{
	system("cls");
	int choice = 0, choiceA = 0;
	string name, password;
	cout << "Hello! Do you want to register? (1) yes, (2) no, (3) exit\n";
	cin >> choice;
	while (!cin.good())
	{
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
	{
		gs.registerUser();
		menuUser(gs);
		break;
	}
	case 2:
	{
		cout << "Are you Admin? (1) yes, (2) no\n";
		cin >> choiceA;
		while (!cin.good())
		{
			cin >> choiceA;
		}
		switch (choiceA)
		{
		case 1:
		{
			cout << "Enter name:\n";
			cin >> name;
			while (name != gs.getAdminName())
			{
				cout << "Wrong username. Enter again\n";
				cin >> name;
			}
			cout << "Enter password\n";
			cin >> password;
			while (password != gs.getAdminPassword())
			{
				cout << "Wrong password. Enter again\n";
				cin >> password;
			}
			menuAdmin(gs);
			break;
		}
		case 2:
		{
			cout << "Bye then!\n";
			break;

		}
		default:
		{
			cout << "Bye!\n";
			break;
		}
		}
		break;
	}
	case 3:
	{
		exit(0);
	}
	default:
	{

		break;
	}
	}
}

void menuAdmin(GasStation & gs)
{
	int choice = 0;
	while (choice != 11)
	{
		system("cls");
		cout << "Hi, Admin. What do you want to do?\n";
		cout << "(1) Show all fuel\n";
		cout << "(2) Add new fuel\n";
		cout << "(3) Refill fuel\n";
		cout << "(4) Set new price\n";
		cout << "(5) Show all cash\n";
		cout << "(6) Show coffee cash\n";
		cout << "(7) Show fuel cash\n";
		cout << "(8) Show sold fuel stats\n";
		cout << "(9) Refill coffee machine\n";
		cout << "(10) Get all cash\n";
		cout << "(11) Exit\n";
		cin >> choice;
		while (!cin.good())
		{
			cout << "Wrong, try again\n";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
		{
			gs.printFuel();
			system("pause");
			break;
		}
		case 2:
		{
			gs.addNewFuel();
			break;
		}
		case 3:
		{
			gs.refillFuel();
			break;
		}
		case 4:
		{
			gs.changePrice();
			break;
		}
		case 5:
		{
			gs.printCash();
			system("pause");
			break;
		}
		case 6:
		{
			gs.printCashCoffee();
			system("pause");
			break;
		}
		case 7:
		{
			gs.printCashFuel();
			system("pause");
			break;
		}
		case 8:
		{
			gs.printStats();
			system("pause");
			break;
		}
		case 9:
		{
			gs.refillCoffee();
			break;
		}
		case 10:
		{
			gs.takeCash();
			system("pause");
			break;
		}
		case 11:
		{
			cout << "Bye!\n";
			system("pause");
			break;
		}
		default:
		{
			break;
		}
		}
	}
	
}

void menuUser(GasStation & gs)
{
	int choice = 0;
	while (choice != 3)
	{
		cout << "Welcome, what do you want to do?\n";
		cout << "(1) Buy fuel\n";
		cout << "(2) Buy coffee\n";
		cout << "(3) Exit\n";
		cin >> choice;
		while (!cin.good())
		{
			cout << "Wrong, try again\n";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
		{
			gs.buyFuel();
			break;
		}
		case 2:
		{
			gs.buyCoffee();
			break;
		}
		case 3:
		{
			cout << "Bye!\n";
			system("pause");
			break;
		}
		}
	}
}
