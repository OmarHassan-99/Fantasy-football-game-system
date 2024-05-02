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
	void AdminMenu(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& teams, unordered_map<string, League>& leagues*/);

	//users
	void AboutUsers(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& Teams, unordered_map<string, Leagues>& League*/);
	void DisplayAllUsers(unordered_map<string, User>& Users);
	void ShowAndEditUser(unordered_map<string, User>& Users);
	void ViewProfile(unordered_map<string, User>& Users, User CurrentUser);
	void EditProfile(unordered_map<string, User>& Users, User CurrentUser);
	void UserSquadAndPlayers(unordered_map<string, User>& Users);
	void DeleteUser(unordered_map<string, User>& Users);
	void Deletion(unordered_map<string, User>& Users, User DeletedUser);


	//teams
	void displayTeamsForSpecificLeague(unordered_map<string, League> leagues);
	Footballer* getFootballerToBeUpdated(vector<League> allleagues, string teamName, string footballerName);
	void updateFootballer(Footballer* footballerToBeUpdated, vector<League> allleagues, string teamName, string footballerName);
	void DeletePlayersInTeam(string Leaguename, map <string, Teams> teams);

	//leagues
	void static DisplayAllLeagues(unordered_map<string, League> leagues);
	void UpdateLeague(void);
	void DeleteLeague(void);
	void PauseAndClear();
};