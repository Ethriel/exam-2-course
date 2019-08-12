#include"Header.h"

string fuels[3] = { "A98", "A95", "A92" };
double prices[3] = { 5.0, 4.0, 3.0 };
double quans[3] = { 100.0, 200.0, 300.0 };

GasStation::GasStation():user("NONE", "NONE"), coffee(10), cash(0.0), cashCoffee(0.0), cashFuel(0.0), coffeePrice(1.5), soldCoffee(0)
{
	admin.setUser("Admin", "1111");
}

GasStation::GasStation(string name, string password): coffee(10), cash(0.0), cashCoffee(0.0), cashFuel(0.0), coffeePrice(1.5), soldCoffee(0)
{
	admin.setUser("Admin", "1111");
	user.setUser(name, password);
}

GasStation::~GasStation()
{
}

void GasStation::registerUser()
{
	string name, password;
	cout << "Enter your name:\n";
	cin.ignore();
	getline(cin, name);
	if (name == "Admin")
	{
		cout << "You can\'t be second Admin =)\n";
		return;
	}
	
	cout << "Enter password:\n";
	cin.ignore();
	getline(cin, password);

	user.setUser(name, password);
}

void GasStation::showUser() const
{
	user.printUser();
}

void GasStation::showAdmin() const
{
	admin.printUser();
}

int GasStation::getCoffeeCount() const
{
	return this->coffee;
}

void GasStation::setCoffeeCount(int num)
{
	this->coffee = num;
}

void GasStation::printFuel() const
{
	for (int i = 0; i < fuel.size(); i++)
	{
		cout << i + 1 << " ";
		fuel[i].printFuel();
	}
}

void GasStation::fillStation()
{
	for (int i = 0; i < 3; i++)
	{
		fuel.push_back(Fuel(fuels[i], quans[i], prices[i]));
		soldFuel.push_back(Fuel(fuels[i], 0.0, 0.0));
	}
}

void GasStation::buyFuel()
{
	int type = 0, choice = 0, ch = 0;
	string name;
	double quan = 0.0, sum = 0.0, money = 0.0;
	cout << "We have such types of fuel:\n";
	printFuel();
	cout << "Enter index of fuel you want to buy:\n";
	cin >> type;
	type--;
	if (type < 0 || type>fuel.size())
	{
		cout << "Wrong number\n";
		return;
	}
	cout << "By quantity (1) or sum of money (2)?\n";
	cin >> ch;
	while (!cin.good())
	{
		cout << "Wrong, try again\n";
		cin >> ch;
	}
	switch (ch)
	{
	case 1:
	{
		cout << "Enter quantity:\n";
		cin >> quan;
		if (quan > fuel[type].getQuan())
		{
			cout << "You have entered too much!\n";
			return;
		}

		fuel[type].setQuan(fuel[type].getQuan() - quan);
		sum = fuel[type].getPrice() * quan;
		cashFuel += sum;

		name = fuel[type].getName();

		checkFuel(name, quan, sum);

		break;
	}
	case 2:
	{
		cout << "Enter money:\n";
		cin >> money;
		double quan_m = money / fuel[type].getPrice();
		if (quan_m > fuel[type].getQuan())
		{
			cout << "Gas station does not have enough fuel quantity!\n";
			return;
		}

		sum += money;
		name = fuel[type].getName();
		cashFuel += sum;
		checkFuel(name, quan_m, sum);

		break;
	}
	default:
	{
		break;
	}
	}
	
	cout << "Sum of your purchase: " << sum << "$\n";
	if (coffee > 0)
	{
		cout << "Do you want some coffee ? (1) yes, (2) no\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			buyCoffee();
			break;
		}
		case 2:
		{
			cout << "Bye then!\n";
			break;
		}
		default:
		{
			cout << "Bad choice\n";
			break;
		}
		}
	}

	cash += cashCoffee + cashFuel;
}

void GasStation::buyCoffee()
{
	if (coffee <= 0)
	{
		cout << "Sorry. No coffee left. Contact the admin to refill coffee machine\n";
		return;
	}
	cout << "Here is your coffee!\n";
	cashCoffee += coffeePrice;
	coffee--;
	soldCoffee++;
}

void GasStation::takeCash()
{
	cout << "All cash sum =  " << cash << "$\n";
	cash = 0.0;
	cashCoffee = 0.0;
	cashFuel = 0.0;
}

void GasStation::takeCashCoffee()
{
	cout << "Coffe cash sum = " << cashCoffee << "$\n";
	cashCoffee = 0.0;
	cash -= cashCoffee;
}

void GasStation::takeCashFuel()
{
	cout << "Fuel cash sum = " << cashFuel << "$\n";
	cashFuel = 0.0;
	cash -= cashFuel;
}

void GasStation::addNewFuel()
{
	int types = 0;
	string name;
	double quan = 0.0, price = 0.0;
	cout << "Enter quantity of fuel types ypu want to add:\n";
	cin >> types;
	for (int i = 0; i < types; i++)
	{
		cout << "Enter name:\n";
		cin.ignore();
		getline(cin, name);
		cout << "Enter quantity in liters:\n";
		cin >> quan;
		cout << "Enter price in $\n";
		cin >> price;
		fuel.push_back(Fuel(name, quan, price));
	}
}

void GasStation::printCash() const
{
	cout << "Cash = " << cash << "$\n";
	LINE;
}

void GasStation::printCashCoffee() const
{
	cout << "Coffee cash = " << cashCoffee << "$\n";
	LINE;
}

void GasStation::printCashFuel() const
{
	cout << "Fuel cash = " << cashFuel << "$\n";
	LINE;
}

void GasStation::printStats() const
{
	for (int i = 0; i < soldFuel.size(); i++)
		soldFuel[i].printStats();
}

void GasStation::checkFuel(string name, double quan, double sum)
{
	double setSum = 0.0;
	double setQuan = 0.0;
	for (int i = 0; i < soldFuel.size(); i++)
	{
		if (soldFuel[i].getName() == name)
		{
			setSum = soldFuel[i].getSum() + sum;
			setQuan = soldFuel[i].getQuan() + quan;
			soldFuel[i].setQuan(setQuan);
			soldFuel[i].setSum(setSum);
		}
		else
			continue;
	}
}

void GasStation::refillFuel()
{
	int type = 0;
	double quan = 0.0;
	printFuel();
	cout << "Enter index of fuel you want to refill:\n";
	cin >> type;
	type--;

	if (type < 0 || type>fuel.size())
	{
		cout << "Wrong number\n";
		return;
	}
	cout << "Enter quantity:\n";
	cin >> quan;
	fuel[type].setQuan(quan);
}

void GasStation::changePrice()
{
	int type = 0;
	double price = 0.0;
	cout << "Enter index of fuel you want to refill:\n";
	cin >> type;
	type--;

	if (type < 0 || type>fuel.size())
	{
		cout << "Wrong number\n";
		return;
	}

	cout << "Enter new price:\n";
	cin >> price;
	fuel[type].setPrice(price);
}

void GasStation::refillCoffee()
{
	int quan = 0;
	cout << "Enter quantity:\n";
	cin >> quan;
	while (!cin.good())
	{
		cout << "Wrong. Try again\n";
		cin >> quan;
	}

	coffee += quan;
}

string GasStation::getAdminName() const
{
	return admin.getName();
}

string GasStation::getAdminPassword() const
{
	return admin.getPassword();
}
