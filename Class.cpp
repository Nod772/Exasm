#include"Header.h"

Drink::Drink() :name("none"), cost(0), countPortion(0)
{
}

Drink::Drink(string name, float cost) : name(name), cost(cost), countPortion(0)
{
}



string Drink::GetName()
{
	return name;
}

float Drink::GetCost()
{
	return cost;
}




Avtomat::Avtomat():Coffe(), Tea(), Slush(),water(0), sugar(0), wallet(0)
{

}


void Avtomat::AddWater()
{
	float value;
	cout << "Add water :: ";
	cin >> value;
	water += value;
}

void Avtomat::AddSugar()
{
	float value;
	cout << "\nAdd sugar :: ";
	cin >> value;
	sugar += value;
}

void Avtomat::AddPortion()
{
	int action;
	cout << "Portions::\n1.Cofee\n2.Tea\n3.Slush\n\nAction :: ";
	int tempportion = 0;
	cin >> action;
	switch (action)
	{
	case 1:
	{
		cout << "Enter portion Coffe : ";
		cin >> tempportion;
		drink[0]->AddPorion(tempportion);
		break;
	}
	case 2:
	{
		cout << "Enter portion Tea   : ";
		cin >> tempportion;
		drink[1]->AddPorion(tempportion);
		break;
	}
	case 3:
	{
		cout << "Enter portion Slush : ";
		cin >> tempportion;
		drink[2]->AddPorion(tempportion);
		break;
	}
	default:
		cout << "Error drink!!\n";
		break;
	}


}

void Avtomat::Sold()
{
	int drinks;
	cout << "Enter drink :: \n1.Coffe\n2.Tea\n3.Slush\n\nAction:: ";
	cin >> drinks;
	if (drinks <= 0 || drinks >= 4)
	{
		cout << "Error drink!!!\n";
	}
	else
	{
		cout << "If you want to put sugar enter 1, else another symbol\n";
		int action;
		cin >> action;
		if (action == 1)
		{
			int coutspoon;
			cin >> coutspoon;
			sugar -= coutspoon * 50;
		}
		drink[drinks]->Sold();
		wallet += drink[drinks]->GetCost();
	}
}

void Avtomat::ShowAvtomat()
{
	cout << "\n\tAvtomat\n\n";
	cout << "Water :: " << water / 1000 << endl;
	cout << "Sugar :: " << sugar / 1000 << endl;
	for (int i = 0; i < 3; i++)
	{
		drink[i]->printDrinkName();
	}
	cout << "\nWALLET  ::  " << wallet << " grn.\n";
}

void Avtomat::FillAvtomat()
{
	cout << "Enter Water(l) :: ";
	cin >> water;
	water *= 1000;
	cout << "Enter sugar(kg) :: ";
	cin >> sugar;
	sugar *= 1000;

	cout << "Count portion Coffe :: ";
	drink[0] = new Coffe("Coffe", 12);
	drink[0]->FillPorion();

	cout << "Count portion Tea   :: ";
	drink[1] = new Tea("Tea", 10);
	drink[1]->FillPorion();


	cout << "Count portion Slush :: ";
	drink[2] = new Slush("Slush", 15);
	drink[2]->FillPorion();
}

void Avtomat::TakeMoney(float count)
{
	if (count < wallet)
	{
		wallet -= count;
		cout << "\nOperation succeeded!!!\n";
		Sleep(1000);
	}
	else
	{
		cout << "Don`t enough money in wallet!!! \n";
	}
}



bool Regist()
{
	int user;
	int password = 1111;
	cout << "\nEnter user : \n1:Good\n2:User\n\nEnter :: ";
	cin >> user;
	if (user == 1)
	{
		int temp;
		int counts = 0;
		do
		{
			cout << "\nEnter password : ";
			cin >> temp;
			if (temp == password)
			{
				return true;
			}

			else if (temp != password)
			{
				cout << "\nError password!!!";
				Sleep(3000);
			}

			counts++;
		} while (counts != 3);

		return false;
	}
	else
	{
		return false;
	}


}

void Menu(Avtomat & avto)
{
	bool Power = true;
	do
	{

		bool users = Regist();
		

		if (users)
		{
			int actions = 0;

			do
			{
				system("pause");
				system("cls");
				cout << "\n\tWELCOME!!!\n\n\n1. Add water\n2. Add portion\n3. Add Sugar\n4. Take Money\n5.Show Avtomat\n0.Exit\n\nAction :: ";
				cin >> actions;
				switch (actions)
				{
				case 1:
				{

					avto.AddWater();
					break;
				}
				case 2:
				{
					avto.AddPortion();
					break;
				}
				case 3:
				{
					avto.AddSugar();
					break;
				}
				case 4:
				{
					int mone;
					cout << "Enter count money : ";
					cin >> mone;
					avto.TakeMoney(mone);
					break;
				}
				case 5:
				{
					avto.ShowAvtomat();
					break;
				}
				default:

					break;
				}
			} while (actions != 0);
		}
		else
		{
			bool run = true;
			do
			{
				
				cout << "Enter user : 0\nBuy drink : 1\nEnter :: ";
				cin >> run;
				if (run)
				{
					avto.Sold();
				}
				
			} while (run);
		
		}

		cout << "\nPower :: ";
		cin >> Power;

	} while (Power);

	system("cls");
	cout << "\n\t\tPOWER OFF\n\n";

}
