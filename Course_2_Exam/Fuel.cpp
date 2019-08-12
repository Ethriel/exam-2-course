#include"Header.h"

Fuel::Fuel():name("NONE"), quan(0.0), price(0.0), sum(0.0)
{
}

Fuel::Fuel(string name, double quan, double price):name(name), quan(quan), price(price), sum(0.0)
{
}

Fuel::~Fuel()
{
}

void Fuel::setName(string name)
{
	this->name = name;
}

void Fuel::setQuan(double quan)
{
	this->quan = quan;
}

void Fuel::setPrice(double price)
{
	this->price = price;
}

void Fuel::setSum(double sum)
{
	this->sum = sum;
}

void Fuel::setFuel(string name, double quan, double price, double sum)
{
	setName(name);
	setQuan(quan);
	setPrice(price);
	setSum(sum);
}

string Fuel::getName() const
{
	return name;
}

double Fuel::getQuan() const
{
	return quan;
}

double Fuel::getPrice() const
{
	return price;
}

double Fuel::getSum() const
{
	return sum;
}

void Fuel::printFuel() const
{
	cout << "Name: " << name << endl;
	cout << "Quantity: " << quan << " l" << endl;
	cout << "Price: " << price << "$" << endl;
	LINE;
}

void Fuel::printStats() const
{
	cout << "SOLD:\n";
	cout << "Name: " << name << endl;
	cout << "Quantity: " << quan << " l" << endl;
	cout << "Sum: " << sum << "$" << endl;
	LINE;
}
