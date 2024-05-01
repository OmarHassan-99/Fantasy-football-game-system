#pragma once
#include <iostream>
#include <vector>
#include "list"
#include "queue"
#include "User.h"
#include "unordered_map"
#include "Teams.h"
#include"Leagues.h"
using namespace std;
class Admin
{
protected:




public:
	bool CheckAdmin();
	void AdminMenu(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League*/);

	//users
	void AboutUsers(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League*/);
	void DisplayAllUsers(unordered_map<string, User>& Users);
	void ShowAndEditUser(unordered_map<string, User>& Users);
	void ViewProfile(unordered_map<string, User>& Users, User CurrentUser);
	void EditProfile(unordered_map<string, User>& Users, User CurrentUser);
	void UserSquadAndPlayers(unordered_map<string, User>& Users);
	void DeleteUser(unordered_map<string, User>& Users);
	void Deletion(unordered_map<string, User>& Users, User DeletedUser);

	//teams


	//leagues

	void PauseAndClear();
};