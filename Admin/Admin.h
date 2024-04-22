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
	void AdminMenu(unordered_map<string, User>& Users, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League);

	//users
	void AboutUsers(unordered_map<string, User>& Users, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League);
	void DisplayAllUsers(unordered_map<string, User>& Users);
	void ShowAndEditUser(unordered_map<string, User>& Users);
	void UserSquadAndPlayers(unordered_map<string, User>& Users);
	void DeleteUser(unordered_map<string, User>& Users);

	//teams
	void AboutTeams(unordered_map<string, User>& Users, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League);
	void DisplayAllTeams(unordered_map<string, Teams>& Team);
	void ShowAndEditTeam(unordered_map<string, Teams>& Team);

	//leagues
	void AboutLeagues(unordered_map<string, User>& Users, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League);
	void DisplayAllLeagues(unordered_map<string, Leagues>& League);
	void ShowAndEditLeague(unordered_map<string, Leagues>& League);

	void PauseAndClear(string GoTo);
};