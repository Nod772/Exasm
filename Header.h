#pragma once
#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;



class Drink abstract
{
public:

	Drink();
	Drink(string name, float cost);
	~Drink() {};

	string GetName();
	float GetCost();


	virtual void printDrinkName()const
	{
		cout << "\nName : " << name << "\nCost : " << cost << "\n Count portion : " << countPortion << endl;
	}

	virtual void FillPorion()
	{
		cin >> countPortion;
	}
	virtual void AddPorion(int count)
	{
		countPortion += count;
	}


	virtual void Sold()
	{
		countPortion--;
	}


protected:
	string name;
	float cost;
	int countPortion;
};

class Coffe :public Drink
{
public:
	Coffe() :Drink() {};
	Coffe(string name, float cost) :Drink(name, cost) {};
	~Coffe() {};

private:

};

class Tea :public Drink
{
public:
	Tea() :Drink() {};
	Tea(string name, float cost) :Drink(name, cost) {};
	~Tea() {};

private:

};

class Slush :public Drink
{
public:
	Slush() :Drink() {};
	Slush(string name, float cost) :Drink(name, cost) {};
	~Slush() {};

private:

};

class Avtomat :public Coffe, public Tea, public Slush
{
public:
	Avtomat();
	~Avtomat() {};

	void AddWater();
	void AddSugar();
	void AddPortion();


	void Sold();
	void ShowAvtomat();
	void FillAvtomat();

	void TakeMoney(float count);

protected:

	float water;
	float sugar;
	float wallet;
	Drink* drink[3];

};

bool Regist();
void Menu(Avtomat& avto);
