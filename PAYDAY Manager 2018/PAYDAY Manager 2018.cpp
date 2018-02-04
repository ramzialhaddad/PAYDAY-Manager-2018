// PAYDAY Manager 2018.cpp : Defines the entry point for the console application.
// save file format no spaces: Username(string), Balance(int), Budget(int), SuspicionLevel(int), Loyalty(int),
// Reputation(int), Risk(int), Heister1(string), Heister2(string), Heister3(string), Heister4(string)

#include "stdafx.h"


/*       ____   _ __   ______    _ __   __
|  _ \ / \\ \ / /  _ \  / \\ \ / /
| |_) / _ \\ V /| | | |/ _ \\ V /
|  __/ ___ \| | | |_| / ___ \| |
__  __|_| /_/  _\_\_| |____/_/___\_\_|_ ____
|  \/  |  / \  | \ | |  / \  / ___| ____|  _ \
| |\/| | / _ \ |  \| | / _ \| |  _|  _| | |_) |
| |  | |/ ___ \| |\  |/ ___ \ |_| | |___|  _ <
|_|  |_/_/  _\_\_| \_/_/_ _\_\____|_____|_| \_\
|___ \ / _ \/ |___  |
__) | | | | |  / /
/ __/| |_| | | / /
|_____|\___/|_|/_/          */

using namespace std;

//This is the crime.net things

int option;
int loudOrStealth;
//misc variables
int b = 11;
int w = 15;
int r = 12;
int y = 14;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Function to generate random 50 50 outcomes
int randomGenerator() {
	srand(time(0));
	return rand() % 2;
}

// Function that handles bad points for loyalty
int badPoint(std::vector <int> saveFileLoyalty, int searchedIndex, unsigned int amount) {

	saveFileLoyalty[searchedIndex] -= amount;
	return saveFileLoyalty[searchedIndex];
}

// Function that handles good points for loyalty
int goodPoint(std::vector <int> saveFileLoyalty, int searchedIndex, unsigned int amount) {

	saveFileLoyalty[searchedIndex] += amount;
	return saveFileLoyalty[searchedIndex];
}

// This is to add a fancy touch to printing text to the console
void type(const string& message, unsigned int timeBetweenEachLetter) {
	// after it got the string and the int then we need to itterate it until the message has completely printed
	for (const char c : message) {
		cout << c;
		Sleep(timeBetweenEachLetter);
	}
}

// This is the lose function, it always repeats the statment
void lose() {
	for (;;) {
		cls;
		sleep(2s);
		type("Your Payday Gang lost faith in you, they all went to custody and police found you and now you are in jail", 100);
		sleep(2s);
		pause;
	}
}

std::vector <int> typingGame(string text, std::vector <int> saveFileLoyalty, int searchedIndex) {
	string thisVariableDoesNotReallyMatterTooMuch;
	system("cls");
	SetConsoleTextAttribute(hConsole, y);
	cout << text << "\n";
	SetConsoleTextAttribute(hConsole, w);
	input;
	cin >> thisVariableDoesNotReallyMatterTooMuch;
	if (thisVariableDoesNotReallyMatterTooMuch != text) {
		if (saveFileLoyalty[searchedIndex] > 0) {
			saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
		}
	}
	else {
		saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
	}

	return saveFileLoyalty;
} // End of function


// This is the First World Bank Heist
void fwb(std::vector <string> saveFileUsername, std::vector <int> saveFileBalance, std::vector <int> saveFileBudget, std::vector <int> saveFileSuspicion, std::vector <int> saveFileLoyalty, std::vector <int> saveFileReputation, std::vector <int> saveFileRisk, int searchedIndex) {
	type("Loading", 30);
	lelip;
	endl;

	type("You send the Payday Gang to the bank...\n", 30);
	sleep(1s);

	type("They worry about the plan going south, they request you to either go loud or stealth\n", 30);
	
	type("Type 1 for loud and 0 for stealth\n", 30);
	input;
	cin >> loudOrStealth;

	cout << "You chose " << loudOrStealth;
	endl;

	switch (loudOrStealth){
	case 0:
		// The user tried to pick stealth, lets check weather he can or cannot go depending on their suspicion level
		// this is to check wheather their risk or suspicion is over 40, if so then they are too high to go stealth
		if (saveFileRisk[searchedIndex] >= 40 || saveFileSuspicion[searchedIndex] >= 40) {
			type("Your Risk or Suspicion Level is too high, the cops were called and the heist is now loud\n", 30);
			sleep(1s);

			type("Your Gang reached the Bank with cops alerted and launching an assult soon!\n", 30);
			lelip;
			system("cls");
			type("Quick! Type this!\n", 30);
			sleep(1s);
		}

		else {
			// The suspicion level is low enough for stealth to be viable
			type("Your risk or suspicion is low enough to go stealth", 30);
			sleep(1s);
		}
		break;

	case 1:
		// If the user chose Loud
		string thisVariableDoesNotReallyMatterTooMuch;
		system("cls");
		PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC);
		cout << "Your Gang reached the Bank with cops alerted and launching an assult soon!\n";
		lelip;
		endl;
		type("They arrive at the Bank and shoot the visible security guards and gather up hostages", 40);
		sleep(2s);
		system("cls");
		cout << "Quick! Type this!\n";
		sleep(0.1s);

		int beforeValue = saveFileLoyalty[searchedIndex];
		
		SetConsoleTextAttribute(hConsole, y);
		cout << "Guys!\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "Guys!"){
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "find\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "find") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "the\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "the") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "bank\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "bank") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "manager\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "manager") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "and\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "and") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "get\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "get") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "his\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "his") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "keycard.\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "keycard.") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "The\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "The") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "drill\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "drill") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "and\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "and") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "thermite\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "thermite") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "is\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "is") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "in\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "in") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "the\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "the") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "server\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "server") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "room.\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "room.") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		sleep(1s);
		type("Calculating result, please wait", 40);
		lelip;
		endl;
		sleep(2s);

		int calculatedResult = saveFileLoyalty[searchedIndex] - beforeValue;
		type("You got a total of " + to_string(calculatedResult) + " loyal points!", 30);
		sleep(2s);
		endl;
		system("cls");

		type("They search for the Bank Manager", 30);
		lelip;
		endl;
		sleep(2s);
		type("They found the Bank Manager, should they kill him or take him as a hostage?", 40);
		sleep(2s);
		endl;
		SetConsoleTextAttribute(hConsole, r);
		type("-kill +2 Risk\n", 30);
		SetConsoleTextAttribute(hConsole, b);
		type("-hostage -1 Risk\n", 30);
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;

		if (thisVariableDoesNotReallyMatterTooMuch == "kill" || thisVariableDoesNotReallyMatterTooMuch == "Kill" || thisVariableDoesNotReallyMatterTooMuch == "k") {
			SetConsoleTextAttribute(hConsole, r);
			type("Risk increased by 2", 40);
			SetConsoleTextAttribute(hConsole, w);
			sleep(1s);
			endl;
			saveFileRisk[searchedIndex] += 2;
			type("The gang brutally shot the Bank Manager and took the keycard", 30);
			sleep(2s);
		}
		else if (thisVariableDoesNotReallyMatterTooMuch == "hostage" || thisVariableDoesNotReallyMatterTooMuch == "Hostage" || thisVariableDoesNotReallyMatterTooMuch == "h") {
			SetConsoleTextAttribute(hConsole, b);
			type("Risk decreased by 1", 30);
			SetConsoleTextAttribute(hConsole, w);
			sleep(1s);
			endl;
			saveFileRisk[searchedIndex] -= 1;
			type("The gang ties the bank manager up and hide him in a corner", 30);
			endl;
			sleep(2s);
		}
		cls;
		sleep(2s);
		type("The gang searches the bank for the server room", 30);
		elip;
		endl;
		type("They find the server room and pick up the drill and thermite", 30);
		sleep(2s);
		endl;
		// random chance of thermite not being taken
		if (int(randomGenerator) == 1) {
			type("They forgot to take the other canister of thermite", 30);
			type("Type This!", 30);
			sleep(2s);

			// the typing thing

			int beforeVlaue = saveFileLoyalty[searchedIndex];

			system("cls");
			SetConsoleTextAttribute(hConsole, y);
			cout << "Guys\n";
			SetConsoleTextAttribute(hConsole, w);
			input;
			cin >> thisVariableDoesNotReallyMatterTooMuch;
			if (thisVariableDoesNotReallyMatterTooMuch != "Guys") {
				if (saveFileLoyalty[searchedIndex] > 0) {
					saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
				}
			}
			else {
				saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
			}

			system("cls");
			SetConsoleTextAttribute(hConsole, y);
			cout << "you\n";
			SetConsoleTextAttribute(hConsole, w);
			input;
			cin >> thisVariableDoesNotReallyMatterTooMuch;
			if (thisVariableDoesNotReallyMatterTooMuch != "you") {
				if (saveFileLoyalty[searchedIndex] > 0) {
					saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
				}
			}
			else {
				saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
			}

			system("cls");
			SetConsoleTextAttribute(hConsole, y);
			cout << "forgot\n";
			SetConsoleTextAttribute(hConsole, w);
			input;
			cin >> thisVariableDoesNotReallyMatterTooMuch;
			if (thisVariableDoesNotReallyMatterTooMuch != "forgot") {
				if (saveFileLoyalty[searchedIndex] > 0) {
					saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
				}
			}
			else {
				saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
			}

			system("cls");
			SetConsoleTextAttribute(hConsole, y);
			cout << "the\n";
			SetConsoleTextAttribute(hConsole, w);
			input;
			cin >> thisVariableDoesNotReallyMatterTooMuch;
			if (thisVariableDoesNotReallyMatterTooMuch != "the") {
				if (saveFileLoyalty[searchedIndex] > 0) {
					saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
				}
			}
			else {
				saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
			}

			system("cls");
			SetConsoleTextAttribute(hConsole, y);
			cout << "other\n";
			SetConsoleTextAttribute(hConsole, w);
			input;
			cin >> thisVariableDoesNotReallyMatterTooMuch;
			if (thisVariableDoesNotReallyMatterTooMuch != "other") {
				if (saveFileLoyalty[searchedIndex] > 0) {
					saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
				}
			}
			else {
				saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
			}

			system("cls");
			SetConsoleTextAttribute(hConsole, y);
			cout << "can\n";
			SetConsoleTextAttribute(hConsole, w);
			input;
			cin >> thisVariableDoesNotReallyMatterTooMuch;
			if (thisVariableDoesNotReallyMatterTooMuch != "can") {
				if (saveFileLoyalty[searchedIndex] > 0) {
					saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
				}
			}
			else {
				saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
			}

			system("cls");
			SetConsoleTextAttribute(hConsole, y);
			cout << "of\n";
			SetConsoleTextAttribute(hConsole, w);
			input;
			cin >> thisVariableDoesNotReallyMatterTooMuch;
			if (thisVariableDoesNotReallyMatterTooMuch != "of") {
				if (saveFileLoyalty[searchedIndex] > 0) {
					saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
				}
			}
			else {
				saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
			}

			system("cls");
			SetConsoleTextAttribute(hConsole, y);
			cout << "thermite\n";
			SetConsoleTextAttribute(hConsole, w);
			input;
			cin >> thisVariableDoesNotReallyMatterTooMuch;
			if (thisVariableDoesNotReallyMatterTooMuch != "thermite") {
				if (saveFileLoyalty[searchedIndex] > 0) {
					saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
				}
			}
			else {
				saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
			}
			sleep(2s);

			system("cls");
			sleep(1s);
			type("Calculating result, please wait", 40);
			lelip;
			endl;
			sleep(2s);

			int calculatedResult = saveFileLoyalty[searchedIndex] - beforeValue;
			type("You got a total of " + to_string(calculatedResult) + " loyal points!", 30);
			sleep(2s);
			endl;
			system("cls");
			
		} // End random encounter

		type("The gang makes their way to the entrance of the vault area", 40);
		lelip;
		endl;
		sleep(2s);
		type("They place the thermal drill and start drilling", 40);
		lelip;
		endl;
		sleep(2s);
		type("Quick! Type this!", 40);
		sleep(2s);
		system("cls");

		int beforeVlaue = saveFileLoyalty[searchedIndex];

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "Guys\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "Guys") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "you\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "you") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "need\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "need") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "to\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "to") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "hook\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "hook") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "me\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "me") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "up\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "up") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "to\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "to") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "one\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "one") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}
		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "of\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "of") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "the\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "the") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "terminals\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "terminals") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "to\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "to") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "open\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "open") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "the\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "the") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "magnetic\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "magnetic") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "seal\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "seal") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "of\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "of") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "the\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "the") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}

		system("cls");
		SetConsoleTextAttribute(hConsole, y);
		cout << "door.\n";
		SetConsoleTextAttribute(hConsole, w);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;
		if (thisVariableDoesNotReallyMatterTooMuch != "door.") {
			if (saveFileLoyalty[searchedIndex] > 0) {
				saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, 1);
			}
		}
		else {
			saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, 1);
		}
		sleep(2s);

		system("cls");
		sleep(1s);
		type("Calculating result, please wait", 40);
		lelip;
		endl;
		sleep(1s);

		calculatedResult = saveFileLoyalty[searchedIndex] - beforeValue;
		type("You got a total of " + to_string(calculatedResult) + " loyal points!", 30);
		sleep(1s);
		endl;
		system("cls");




		system("PAUSE");
		break; // end of case
	} // End of switch statment

	cout << "HEY THERE MAN !";
	endl;
	pause;
} // End of Function

//menu for heists
void heistoptions(std::vector <string> saveFileUsername, std::vector <int> saveFileBalance, std::vector <int> saveFileBudget, std::vector <int> saveFileSuspicion, std::vector <int> saveFileLoyalty, std::vector <int> saveFileReputation, std::vector <int> saveFileRisk, int searchedIndex)
{
heistoptions:
	cout << "1. First World Bank\n";
	cin >> option;
	switch (option) {
	case 1:
		system("cls");
		fwb(saveFileUsername, saveFileBalance, saveFileBudget, saveFileSuspicion, saveFileLoyalty, saveFileReputation, saveFileRisk, searchedIndex);
		break;
	
	default:
		cout << "Sorry, didn't quite get that!\n";
		system("PAUSE");
		goto heistoptions;
	}
}

//crime.net
void crimenet(std::vector <string> saveFileUsername, std::vector <int> saveFileBalance, std::vector <int> saveFileBudget, std::vector <int> saveFileSuspicion, std::vector <int> saveFileLoyalty, std::vector <int> saveFileReputation, std::vector <int> saveFileRisk, int searchedIndex, std::vector <string> saveFileHeister1, std::vector <string> saveFileHeister2, std::vector <string> saveFileHeister3, std::vector <string> saveFileHeister4)
{
	string message;
crimenet:
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	type("Welcome to ", 150);
	SetConsoleTextAttribute(hConsole, b);
	type("Crime.net\n", 60);
	SetConsoleTextAttribute(hConsole, w);
	sleep(2s);
	cout << "What would you like to do?\n";
	cout << "1. Plan a heist\n";
	cout << "2. Change the crew\n";
	cout << "3. Budget\n";
	cin >> option;

	switch (option) {
	case 1:
		cout << "What heist would you like to do?\n";
		heistoptions(saveFileUsername, saveFileBalance, saveFileBudget, saveFileSuspicion, saveFileLoyalty, saveFileReputation, saveFileRisk, searchedIndex); //calling the menu function
		break;
	case 2:
		cout << "Which heisters do you want to change?\n";
		cout << "Your current heisters are:\n";
		system("PAUSE");
		break;

	case 3:
		cls;
		message = string("Your budget is ") + to_string(saveFileBudget[searchedIndex]);
		type(message, 40);
		endl;
		system("PAUSE");
		break;

	default:
		cls;
		cout << "Sorry, didn't get that!\n";
		Sleep(1);
		goto crimenet;
	}

	goto crimenet;
}



// Here below is the stats() function, the functions needs reuqired vectors and variables in specific order to display
// the correct stats. The vector contains all the data of that category and the varible is the index of it.
int stats(std::vector <string> saveFileUsername, std::vector <int> saveFileBalance, std::vector <int> saveFileBudget, std::vector <int> saveFileSuspicion, std::vector <int> saveFileLoyalty, std::vector <int> saveFileReputation, std::vector <int> saveFileRisk, int searchedIndex, std::vector <string> saveFileHeister1, std::vector <string> saveFileHeister2, std::vector <string> saveFileHeister3, std::vector <string> saveFileHeister4) {
	system("cls");
	cout << "Stats:" << "\n";
	Sleep(300);

	string message = "Username: " + saveFileUsername[searchedIndex];
	type(message, 30);
	endl;
	Sleep(100);

	message = string("Balance: ") + to_string(saveFileBalance[searchedIndex]);
	type(message, 30);
	endl;
	Sleep(100);

	message = string("Budget: ") + to_string(saveFileBudget[searchedIndex]);
	type(message, 30);
	endl;
	Sleep(100);

	message = string("Suspicion Level: ") + to_string(saveFileSuspicion[searchedIndex]);
	type(message, 30);
	endl;
	Sleep(100);

	message = string("Loyalty: ") + to_string(saveFileLoyalty[searchedIndex]);
	type(message, 30);
	endl;
	Sleep(100);

	message = string("Reputation: ") + to_string(saveFileReputation[searchedIndex]);
	type(message, 30);
	endl;
	Sleep(100);

	message = string("Risk: ") + to_string(saveFileRisk[searchedIndex]);
	type(message, 30);
	endl;
	Sleep(100);

	message = "Preferred Heister 1: " + saveFileHeister1[searchedIndex];
	type(message, 30);
	endl;
	Sleep(100);

	message = "Preferred Heister 2: " + saveFileHeister2[searchedIndex];
	type(message, 30);
	endl;
	Sleep(100);

	message = "Preferred Heister 3: " + saveFileHeister3[searchedIndex];
	type(message, 30);
	endl;
	Sleep(100);

	message = "Preferred Heister 4: " + saveFileHeister4[searchedIndex];
	type(message, 30);
	endl;
	Sleep(2000);

	system("PAUSE");

	return 0;
}

// finally, the main function
int main()
{
	// These variables help with searching the inputted username in the vector saveFileUsername
	int lengthOfVectors = 0;
	int searchedIndex = 0;
	bool valueFound;

	// this is to initilize inSaveFile as the saveFile.csv
	ifstream inSaveFile("saveFile.csv");

	// lets now make some variables the 2 below are just for the dump nothing more
	string value;

	// These variables are use consistenly throughout the game
	std::vector <string> saveFileUsername;
	std::vector <int> saveFileBalance;
	std::vector <int> saveFileBudget;
	std::vector <int> saveFileSuspicion;
	std::vector <int> saveFileLoyalty;
	std::vector <int> saveFileReputation;
	std::vector <int> saveFileRisk;
	std::vector <string> saveFileHeister1;
	std::vector <string> saveFileHeister2;
	std::vector <string> saveFileHeister3;
	std::vector <string> saveFileHeister4;


	// This dumps all data from the save file to individual vectors that we can use and change as we please
	while (inSaveFile.good()) {
		// For username
		getline(inSaveFile, value, ',');
		cout << string(value);
		endl;
		saveFileUsername.push_back(string(value));

		// For Balance
		getline(inSaveFile, value, ',');
		cout << string(value);
		endl;
		saveFileBalance.push_back(int(stoi(value)));

		// For Budget
		getline(inSaveFile, value, ',');
		cout << string(value);
		endl;
		saveFileBudget.push_back(int(stoi(value)));

		// For Suspicion Level
		getline(inSaveFile, value, ',');
		cout << string(value);
		endl;
		saveFileSuspicion.push_back(int(stoi(value)));

		// For Loyalty
		getline(inSaveFile, value, ',');
		cout << string(value);
		endl;
		saveFileLoyalty.push_back(int(stoi(value)));

		// For Reputation
		getline(inSaveFile, value, ',');
		cout << string(value);
		endl;
		saveFileReputation.push_back(int(stoi(value)));

		// For Risk
		getline(inSaveFile, value, ',');
		cout << string(value);
		endl;
		saveFileRisk.push_back(int(stoi(value)));

		//For the 4 heisters
		getline(inSaveFile, value, ',');
		cout << string(value);
		endl;
		saveFileHeister1.push_back(string(value));

		getline(inSaveFile, value, ',');
		cout << string(value);
		endl;
		saveFileHeister2.push_back(string(value));

		getline(inSaveFile, value, ',');
		cout << string(value);
		endl;
		saveFileHeister3.push_back(string(value));

		getline(inSaveFile, value, ',');
		cout << string(value);
		endl;
		saveFileHeister4.push_back(string(value));

		//so we can know how long the vectors are, useful for calculations and verification methods
		lengthOfVectors += 1;
	}

	// declaring some variables
	string username;

	int option;

	string intro = { "LLogging in..." };
	string user = { "b41n" };
	string pass = { "bainistheman1978" };
	int i = 0;
	int u = 0;
	int p = 0;

	//lets set the colour of the console to look pretty
	system("color 0f");
	SetConsoleTitle(L"PAYDAY Manager 2018");

	//Printing the text with colour
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int r = 12;
	int b = 11;
	int w = 15;
	cout << "PAYDAY: ";
	SetConsoleTextAttribute(hConsole, r);
	cout << "Manager 2018";
	endl;
	SetConsoleTextAttribute(hConsole, w);

	system("PAUSE");
	system("cls");

	// a GoTo Loop thing so we can always refer back to it
mainmenu:
	system("cls");
	cout << "1. Play\n";
	cout << "2. Stats\n";
	cout << "3. Credits\n";
	cout << "4. Exit\n";
	cin >> option;
	system("cls");
	// A Switch Case
	switch (option)
	{
	case 1:
		SetConsoleTextAttribute(hConsole, b);
		cout << "Crime.net\n";
		SetConsoleTextAttribute(hConsole, w);
		cout << "Please login.\n";

		cout << "Username: ";
		cin >> username;
		endl;

		// lets now find this username in the saveFileUsername vector then we can assign a index to it
		valueFound = false;

		for (i = -1; (i < lengthOfVectors) && !valueFound;) {
			cout << i;
			endl;
			saveFileUsername[i];
			if (username == saveFileUsername[i]) {
				searchedIndex = i;
				valueFound = true;
			}
			++i;
		}

		if (valueFound) {
			sleep(1s);
			cout << "Password: ";
			sleep(0.5s);
			while (pass[p] != '\0')
			{
				cout << pass[p];
				Sleep(70);
				p++;
			}
			sleep(1s);
			system("cls");

			while (intro[i] != '\0')
			{
				cout << intro[i];
				Sleep(30);
				i++;
			}
			endl;
			sleep(1s);
			cout << "Found  " << username << " in database";
			elip;
			endl;
			cout << "Welcome, " << username << ".\n";

			system("PAUSE");
			
			// This user seems legit lets log him in to crimenet, hopefully he didn't just take one of the usernames in the "SUPER SECURE" CSV file xD
			crimenet(saveFileUsername, saveFileBalance, saveFileBudget, saveFileSuspicion, saveFileLoyalty, saveFileReputation, saveFileRisk, searchedIndex, saveFileHeister1, saveFileHeister2, saveFileHeister3, saveFileHeister4);
		}
		else {
			sleep(1s);
			cout << "ERROR - No Such Username Exists";
			endl;
			Sleep(500);
			cout << "To make an account you must 'hack' the game :^)";
			endl;
			sleep(2s);

		}

		break;
	case 2:
		// Lets call our C++ file called stats.cpp and pass the required variables and vectors
		stats(saveFileUsername, saveFileBalance, saveFileBudget, saveFileSuspicion, saveFileLoyalty, saveFileReputation, saveFileRisk, searchedIndex, saveFileHeister1, saveFileHeister2, saveFileHeister3, saveFileHeister4);
		break;

	case 3:
		type("Programming - Ramzi Al Haddad", 30);
		endl;
		system("PAUSE");
		break;

	case 4:
		exit(0);

	default:
		cout << "Sorry didn't quite get that!";
		endl;
		Sleep(1500);
		break;
	}
	goto mainmenu;
}