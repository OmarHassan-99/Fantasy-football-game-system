#pragma once
#include <iostream>
using namespace std;

class HighlightsOfTheMatch {
protected:

	string name; // the name of the footballer
	string contributes;// the type of contribution (goals ,assists ,clean sheets) goal 3 & assist 2
	string violation; // the type of violence action (red cards,yellow cards)

public:
	void setName(string name);
	void setContributions(string contributors);
	void setViolation(string violation);
	string getName();
	string getContributions();
	string getViolation();
};

//add all the 22 players in this class to know whos players scored goals and who didn't using contributes attribute  
