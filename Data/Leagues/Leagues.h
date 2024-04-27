#include <iostream>
#include <unordered_map>
#include <string>
#include"Teams.h"
#include <vector>
#include <map>
using namespace std;

class League {
private:
	string name;
	map <string, Teams> teams;

public:
	League();


	void displayTeams();

	void updatePoints(vector <Teams>allteams, list<Game> allgames);

	void displayPointTable(vector <Teams> teamlist);

	//sorting function to sort the map of team by points.
	map<string, Teams> getTeams();
};