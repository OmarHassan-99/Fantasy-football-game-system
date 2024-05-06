#include <iostream>
#include <string>
#include <conio.h>
#include "UserValidations.h"
#include "User.h"
#include "Admin.h"

using namespace std;
bool loginstat = false;

void User::homePage(unordered_map<string, User>& Users, vector <TheLeague>& leagues, list<Game>allGames)
{
	int choice;

choice:
	cout << "\n\n\n";
	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n\n";
	cout << spacing(60, ' ') << "      Welcome to Fantasy game!" << "\n\n";
	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n\n\n";
	cout << spacing(60, ' ') << "**It's time for another season of fantasy football glory!**" << "\n\n\n";
	cout << spacing(60, ' ') << "Let's start!" << endl;
	cout << spacing(60, ' '); Admin::PauseAndClear();
	cout << "\n\n\n\n\n\n";
	cout << spacing(60, ' ') << "1-Admin   2-Login   3-Sign up   4-Exit" << endl;
	cout << spacing(60, ' ') << "Enter your option" << endl;
	cout << spacing(60, ' '); cin >> choice;
	if (choice == 1)
	{
		cout << spacing(60, ' '); Admin::PauseAndClear();
		Admin::CheckAdmin(Users, leagues);
		homePage(Users, leagues, allGames);
		return;
	}
	else if (choice == 2)
	{
		toLogin(Users, leagues, allGames);
	}
	else if (choice == 3)
	{
		cout << spacing(60, ' '); Admin::PauseAndClear();
		signup(Users);
		cout << spacing(60, ' '); Admin::PauseAndClear();
		toLogin(Users, leagues, allGames);
		return;
	}
	else if (choice == 4)
	{
		system("exit");
	}
	else
	{
		cout << "Please enter a valid choice" << endl;
		goto choice;
	}
};


void User::toLogin(unordered_map<string, User>& Users, vector <TheLeague>& leagues, list<Game>allGames) {
	int count = 0;
	string user;
	string pass;
	system("cls");
	do
	{
		cout << "Log-in\n------------\n\n";
		cout << "Username: ";
		cin >> user;
		cout << "Password(Press '+' to show password): " << endl;
		pass = hidePassword(user);
		User CurrentUser = login(Users, user, pass);
		if (loginstat == true)
		{
			system("pause");
			system("cls");
			userMenu(CurrentUser, Users, leagues, allGames);
			return;
		}
		else
		{
			count++;
			cout << "Try again..\t" << count << " / 3\n";
			system("pause");
			system("cls");
		}
	} while (count != 3);
}

User User::login(unordered_map<string, User>& users, string username, string password)
{
	if (users[username].GetPassword() == password)
	{
		cout << "Login successful!" << endl;
		cout << "Welcome back boss!" << endl;
		loginstat = true;
		return users.at(username);
	}
	else
	{
		cout << "Login failed!. Please make sure of your username and password" << endl;
		loginstat = false;
		return User();
	}
};

void User::signup(unordered_map<string, User>& Users)
{
	User newUser;
	cout << "\n\n\n\n";
	cout << spacing(60, ' '); cout << "Sign up" << endl;
	UserValidations::signupinfo(&newUser, "Fullname", UserValidations::fullnameCheck, &User::SetFullName);
	UserValidations::usernameCheck(Users, newUser);
	UserValidations::signupinfo(&newUser, "Password", UserValidations::passwordCheck, &User::SetPassword);
	UserValidations::signupinfo(&newUser, "PhoneNumber", UserValidations::phoneNumberCheck, &User::SetPhoneNumber);
	UserValidations::signupinfo(&newUser, "EmailAddress", UserValidations::emailAddressCheck, &User::SetEmail);
	cout << spacing(60, ' ') << "Account created successfully!" << endl;
	Users.insert_or_assign(newUser.username, newUser);
}
void User::userMenu(User& currentUser, unordered_map<string, User>& Users, vector <TheLeague>& leagues, list<Game>allGames)
{
	int choice;
choice:
	cout << "Main Menu" << endl;
	cout << "1-Profile \n 2-Squad \n 3-Market \n 4-Play \n 5-logout" << endl;
	cout << "Enter you option..." << endl;
	cin >> choice;
	if (choice == 1)
	{
		profile(currentUser, Users);
		userMenu(currentUser, Users, leagues, allGames);
		return;
	}
	else if (choice == 2)
	{
		ShowSquad(currentUser);
		userMenu(currentUser, Users, leagues, allGames);
		return;
	}
	else if (choice == 3)
	{
		stack<string>oldUserGames = GetUserTeams(currentUser);
		Market(currentUser, leagues);
		FilteringTeams(allGames, currentUser, oldUserGames);
		userMenu(currentUser, Users, leagues, allGames);
		return;
	}
	else if (choice == 4)
	{
		play(allGames, currentUser, Users);
		userMenu(currentUser, Users, leagues, allGames);
		return;
	}
	else if (choice == 5)
	{
		currentUser.homePage(Users, leagues, allGames);
		return;
	}
	else
	{
		cout << "Please select a valid choice." << endl;
		goto choice;
	}
};
string User::hidePassword(string username)
{
	string Minput, print;
	char input;
	input = _getch();
	while (input != 13)
	{
		if (input == 8)
		{
			if (print.size() == 0)
			{
				print = "";
				Minput = "";
			}
			else
			{
				print.resize(print.size() - 1);
				cout << print;
				Minput.resize(Minput.size() - 1);
			}
		}
		else if (input == 43)
		{

			cout << Minput;
		}
		else
		{
			print.push_back('*');
			cout << print;
			Minput.push_back(input);
		}
		input = _getch();
		system("cls");
		cout << "Log-in\n------------\n\n"; // the display
		cout << "Username: ";
		cout << username << endl;
		cout << "Password(Press '+' to show password): " << endl;
	}
	cout << endl;
	return Minput;
};