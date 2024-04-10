#include<iostream>
#include<fstream>
using namespace std;

#define SIZE 99
int Num = 0;       //the number of Users in the system 

class User
{
private:
	std::string Name;
	std::string Email;
	std::string PassWord;
public:
	void Login();
	void Register();
	void read();
	void save();
}us;

User user[SIZE];

void User::read()
{
	Num = 0;
	ifstream ifile;
	ifile.open("User.txt", ios::in);

	if (!ifile.is_open())
	{
		return;
	}
	
	for (int i = 0; i < SIZE && !ifile.eof(); i++)
	{
		ifile >> user[i].Email;
		ifile >> user[i].Name;
		ifile >> user[i].PassWord;
		Num++;
	}
	ifile.close();
}

void User::save()
{
	ofstream ofile;
	ofile.open("user.txt", ios::out);

	if (!ofile.is_open())
	{
		return;
	}

	for (int i = 0; i < Num; i++)
	{
		ofile << user[i].Email << endl;
		ofile << user[i].Name << endl;
		ofile << user[i].PassWord << endl;
	}
	ofile.close();
}

void User::Register()
{
	us.read();
	std::string Name;
	std::string Email;
	std::string PassWord1;
	std::string PassWord2;

	for (int i = Num; i < SIZE; i++)
	{
	here:
		cout << "Input Your Name: \n";
		cin >> Name;
		cout << "Input Your Email: \n";
		cin >> Email;
		for (int i = 0; i < Num; i++)
		{
			if (Email == user[i].Email)
			{
				cout << "The Email Address has been used£¡\n" << endl;
				goto here;
			}
		}
		user[i].Email = Email;
		user[i].Name = Name;
	there:
		cout << "Input Your PassWord: \n";
		cin >> PassWord1;
		user[i].PassWord = PassWord1;
		cout << "Input Your PassWord again : \n";
		cin >> PassWord2;
		if (PassWord2 != user[i].PassWord)
		{
			cout << "The two PassWord are different" << endl;
			goto there;
		}
		else
		{
			Num++;
			cout << "Register sucessfully. \n" << endl;
			us.save();
		}
		break;
	}
}

void User::Login()
{
	us.read();
	std::string Email;
	std::string PassWord;
	int Flag = 0;
	here:
		cout << "Input Your Email: " << endl;
		cin >> PassWord;
		cout << "Input Your PassWord: " << endl;
		cin >> Email;
		for (int i = 0; i < Num; i++)
		{
			if (Email == user[i].Email && PassWord == user[i].PassWord)
			{
				Flag++;
			}
		}
		if (Flag == 0)
		{
			cout << "Wrong Email OR Wrong PassWord" << endl;
			goto here;
		}
		else
		{
			cout << "Login sucessfully." << endl;
		}
}