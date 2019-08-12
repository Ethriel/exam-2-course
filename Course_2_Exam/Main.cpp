#include"Header.h"

int main()
{
	srand(time(0));

	// MAP
	/*
	map<int, string> cities =
	{
		{33000, "Rivne"},
		{86400, "Mykolaiv"},
		{31001, "Lviv"}
	};

	for (auto elem : cities)
	{
		cout << elem.first << " " << elem.second << endl;
	}

	cout << cities[33000] << endl;

	cities[33000] = "Dubno";
	cout << cities[33001] << endl;
	*/

	// MULTIMAP
	/*
	multimap<int, string> cities =
	{
		{33000, "Rivne"},
		{86400, "Mykolaiv"},
		{31001, "Lviv"},
		{33000, "Rivne"},
		{86400, "Mykolaiv"},
		{31001, "Lviv"}
	};

	for (auto elem : cities)
		cout << elem.first << " " << elem.second << endl;

	LINE;

	for (auto it = cities.rbegin(); it != cities.rend(); ++it)
		cout << it->first << " " << it->second << endl;

	LINE;

	auto temp = cities.find(86400);
	
	if (temp != cities.end())
	{
		cout << temp->second << endl;
	}
	*/


	GasStation gs;
	gs.fillStation();

	while (true)
	{
		checkUser(gs);
	}

	system("pause");
}