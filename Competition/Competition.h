#ifndef COMPETITION_H
#define COMPETITION_H
#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include "User.h"
#include "Game.h"
#include "Teams.h"

using namespace std;

class Competition {

protected:


	const static int goalPoints = 4;
	const static int assistPoints = 2;
	const static int cleanSheetPoints = 3;
	const static int redCardDeduction = 2;
	const static int yellowCardDeduction = 1;
	const static int numOfPlayers = 22;
	const static int MOTM_Bonus = 3;

public:


	void static UpdateFootballerPoints(list<Game> &gameweek); // updating all the players in a game
	void static UpdateFootballerPrice(Footballer& player, int points);//based on points for EVERY player (even if not in user's squad)
	bool static checkPosition(string footballerPosition); // checks if the player is a goalkeeper or a defender
	void static searchTeamInMatch(unordered_map<string, Footballer> &TeamType, Game game); //for looping over the hometeam and awayteam 
	bool static IsManOfTheMatch(string currentMOTM, string playerName); //checks if the player is the MOTM
	char static priceCalculation(int points); //containing five tiers for changing the players price 



	void static updateAllUserPoints(unordered_map<string, User>& Users);
	void static ReducePoints(string footballerName, User& currentUser, string violation, string status, Teams& team, int& tempPoints);//this function used to reduce user points,balance and footballer points

	void static AddContributesPoints(string footballerName, User& currentUser, string contributes, string status, Teams& team, string footballerPosition, int& tempPoints);//this function used to update user points,balance and footballer points
	void static addPoints(string contributes, User &currentUser, string footballerName, int numPerpoints, string status, Teams& team, int& tempPoints); // goals or assits
	void static addGoalsAssistPoints(string contributes, User currentUser, string footballerName, string status, Teams& team, int& tempPoints);// add both goals and assits
	void static findPlayers(User& currentUser, string status, Teams& team);


	void showAllGameHighlights(queue<Game>Usergames, list <Game>& allGames);// show all the games that played in this week or round.


	//suspend functions

};
#endif
