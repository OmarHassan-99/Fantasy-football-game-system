#pragma once
#include <fileManpulation.h>

string readFileData(string filename) {
	string currentDir = "Data/Files/";
	filename = currentDir + filename;
	ifstream file(filename);
	string file_data;

	if (file.is_open()) {
		// Use stringstream to efficiently read file into string
		stringstream ss;
		ss << file.rdbuf();
		file_data = ss.str();
	}
	else
		cout << "Error: Could not open file" << endl;
	file.close();
	return file_data;
}
vector<string> splitByRegex(string data, string reg) {
	vector<string> parts;
	regex re(reg);
	sregex_token_iterator iter(data.begin(), data.end(), re, -1);
	sregex_token_iterator end;

	while (iter != end) {
		parts.push_back(*iter);
		++iter;
	}

	return parts;
}

list<Game> fileManipulation::getGamesData() {
	string filename = "gameData.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s+----\s+)";
	vector<string> parts = splitByRegex(file_data, regex);

	regex = R"(\n)";

	return parseGames(parts, regex);
}
map<string, Teams> fileManipulation::getTeamsData() {
	string filename = "teamsData.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s+----\s+)";
	vector<string> parts = splitByRegex(file_data, regex);
	//cout << parts[0] << endl << parts[1] << endl;
	regex = R"(\n)";
	return parseTeams(parts, regex);
}
string fileManipulation::parseGameStatistics(vector<string> gameLines) {
	string parsedStatistics;
	string statisticsNames[] = {
		"Shots on goal",
		"Shots",
		"Possession %",
		"Fouls",
		"Offsides",
		"Corner kicks",
		"Saves"
	};
	for (int i = 6; i < 13; i++) {
		parsedStatistics.append(statisticsNames[i - 6] + ": " + gameLines[i]);
		if (i != 12)
			parsedStatistics.append(", ");
	}
	return parsedStatistics;
}
/*
 * 'parseGames' function should return all Games in the gameData.txt
 */
list<Game> fileManipulation::parseGames(vector<string> parts, string regex) {
	list<Game> parsedGames;

	for (size_t i = 1; i < parts.size(); ++i) {
		vector<string> gameLines = splitByRegex(parts[i], regex);

		parsedGames.push_back(
			parseGame(gameLines)
		);
	}

	return parsedGames;
}
/*
 * 'parseTeams' function should return all Teams in the teamsData.txt
 */
map<string, Teams> fileManipulation::parseTeams(vector<string> parts, string regex) {
	map<string, Teams> parsedTeams;

	for (size_t i = 1; i < parts.size(); ++i) {
		vector<string> teamLines = splitByRegex(parts[i], regex);

		parsedTeams.insert(
			make_pair(teamLines[0], parseTeam(teamLines))
		);
	}

	return parsedTeams;
}

Teams fileManipulation::parseTeam(vector<string> teamLines) {
	string name = teamLines[0];
	int points = stoi(teamLines[1], nullptr);
	int wins = stoi(teamLines[2], nullptr);
	int losses = stoi(teamLines[3], nullptr);
	int draws = stoi(teamLines[4], nullptr);

	return Teams(name, points, wins, losses, draws);
}
Game fileManipulation::parseGame(vector<string> gameLines) {
	int gameID = stoi(gameLines[0], nullptr);
	string winnerTeam = gameLines[3];
	string score = gameLines[4];
	string gameStatistics = parseGameStatistics(gameLines);
	string manOfTheMatch = gameLines[13];
	string gameDate = gameLines[14];

	return Game(gameID, winnerTeam, score, gameStatistics, manOfTheMatch, gameDate);
}