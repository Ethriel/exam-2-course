#include"Header.h"
User::User():name("NONE"), password("NONE")
{
}

User::User(string name, string password):name(name), password(password)
{
}

User::~User()
{
}

void User::setName(string name)
{
	this->name = name;
}

void User::setPassword(string password)
{
	this->password = password;
}

void User::setUser(string name, string password)
{
	setName(name);
	setPassword(password);
}

string User::getName() const
{
	return name;
}

string User::getPassword() const
{
	return password;
}

void User::printUser() const
{
	cout << "Name: " << this->name << endl;
	cout << "Password: " << this->password << endl;
	LINE;
}
