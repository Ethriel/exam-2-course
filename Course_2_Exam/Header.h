#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<time.h>
#include<vector>
#include<exception>
#include<fstream>
#include<algorithm>
#include<functional>
#include<map>
#define LINE cout << "____________________\n"

using namespace std;

class User
{
public:
	User();
	User(string name, string password);
	~User();

	void setName(string name);
	void setPassword(string password);
	void setUser(string name, string password);
	string getName() const;
	string getPassword() const;
	void printUser() const;

private:
	string name;
	string password;
};

class Fuel
{
public:
	Fuel();
	Fuel(string name, double quan, double price);
	~Fuel();
	void setName(string name);
	void setQuan(double quan);
	void setPrice(double price);
	void setSum(double sum);
	void setFuel(string name, double quan, double price, double sum);
	string getName() const;
	double getQuan() const;
	double getPrice() const;
	double getSum() const;
	void printFuel() const;
	void printStats() const;

private:
	string name;
	double quan;
	double price;
	double sum;
};



class GasStation
{
public:
	GasStation();
	GasStation(string name, string password);
	~GasStation();
	void registerUser();
	void showUser() const;
	void showAdmin() const;
	int getCoffeeCount() const;
	void setCoffeeCount(int num);
	void printFuel() const;
	void fillStation();
	void buyFuel();
	void buyCoffee();
	void takeCash();
	void takeCashCoffee();
	void takeCashFuel();
	void addNewFuel();
	void printCash() const;
	void printCashCoffee() const;
	void printCashFuel() const;
	void printStats() const;
	void checkFuel(string name, double quan, double sum);
	void refillFuel();
	void changePrice();
	void refillCoffee();
	string getAdminName() const;
	string getAdminPassword() const;

private:
	User user;
	User admin;
	vector<Fuel> fuel;
	vector<Fuel> soldFuel;
	int coffee;
	double cash;
	double cashCoffee;
	double cashFuel;
	double coffeePrice;
	int soldCoffee;
};

void checkUser(GasStation& gs);
void menuAdmin(GasStation& gs);
void menuUser(GasStation& gs);
