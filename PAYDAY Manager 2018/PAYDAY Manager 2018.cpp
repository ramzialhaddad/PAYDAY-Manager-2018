// PAYDAY Manager 2018.cpp : Defines the entry point for the console application.
// save file format no spaces: Username(string), Balance(int), Budget(int), SuspicionLevel(int), Loyalty(int),
// Reputation(int), Risk(int), Heister1(string), Heister2(string), Heister3(string), Heister4(string)

/*

	TODO:

	- Add functions for colours of console
	- Add more content
	- Possibly remove cls; and replace with function that actually prints out the Press any key to continue . . .

*/

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
int blue = 11;
int white = 15;
int red = 12;
int yellow = 14;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
std::vector <string> actions;

// This is a funtion to easily change the text colour of the console/terminal/cmd
int changeToColour(int colour){
	SetConsoleTextAttribute(hConsole, colour);
}

// Function to generate random outcomes
int randomGenerator(int amount) {
	srand(time(NULL));
	int randomNumber = rand() % amount;
	return randomNumber;
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
	} // End of for loop
} // End of function

void checkStats(std::vector <int> saveFileLoyalty, std::vector <int> saveFileRisk, std::vector <int> saveFileSuspicion, int searchedIndex) {
	if (saveFileLoyalty[searchedIndex] < 0) {
		// Their Loyalty is too low, they have lost
		type("Your Loyalty is too low, you have lost.", 20);
		sleep(2s);
		lose();
	} if (saveFileRisk[searchedIndex] >= 30) {
		// Their Risk is too high, they have lost
		type("Your Risk is too high, you have lost.", 20);
		sleep(2s);
		lose();
	} if (saveFileSuspicion[searchedIndex] >= 30) {
		// Their Suspicion is too high, they have lost
		type("Your Suspicion is too high, you have lost.", 20);
		sleep(2s);
		lose();
	}
} // End of function

// This function takes care of the typing aspect of the 
int typingGame(string text, std::vector <int> saveFileLoyalty, int searchedIndex, int amount) {
	string thisVariableDoesNotReallyMatterTooMuch;
	cls;
	SetConsoleTextAttribute(hConsole, yellow);
	type(text, 10);
	SetConsoleTextAttribute(hConsole, white);
	cout << "\n";
	input;
	cin.ignore();
	getline(cin, thisVariableDoesNotReallyMatterTooMuch);
	if (thisVariableDoesNotReallyMatterTooMuch != text) {
		if (saveFileLoyalty[searchedIndex] > 0) {
			saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, amount);
		}
	}
	else {
		saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, amount);
	}
	cout << thisVariableDoesNotReallyMatterTooMuch;
	endl;
	sleep(3s);
	return saveFileLoyalty[searchedIndex];
} // End of function

int typingGameNoIgnore(string text, std::vector <int> saveFileLoyalty, int searchedIndex, int amount) {
	string thisVariableDoesNotReallyMatterTooMuch;
	cls;
	SetConsoleTextAttribute(hConsole, yellow);
	type(text, 20);
	SetConsoleTextAttribute(hConsole, white);
	cout << "\n";
	input;
	getline(cin, thisVariableDoesNotReallyMatterTooMuch);
	if (thisVariableDoesNotReallyMatterTooMuch != text) {
		if (saveFileLoyalty[searchedIndex] > 0) {
			saveFileLoyalty[searchedIndex] = badPoint(saveFileLoyalty, searchedIndex, amount);
		}
	}
	else {
		saveFileLoyalty[searchedIndex] = goodPoint(saveFileLoyalty, searchedIndex, amount);
	}
	cout << thisVariableDoesNotReallyMatterTooMuch;
	endl;
	sleep(3s);
	return saveFileLoyalty[searchedIndex];
} // End of function

// Define searchArray and stolen from my own code
//https://github.com/ramzialhaddadtm/PracticalCplusplusAndPythonTutorial/blob/master/Banking%20Program/C%2B%2B/Banking%20Program.cpp
int searchArray(int ArrayPassed[], int whatYouNeedToBeSearched, int length) {
	//Define some variables
	int i = 0;
	int searchedIndex = 0;
	bool valueFound;

	for (i = -1; (i < length) && !valueFound;) {
		//Just for debugging/demonstration purposes
		//cout << i << endl;
		ArrayPassed[i];

		if (whatYouNeedToBeSearched == ArrayPassed[i]) {
			searchedIndex = i;
			valueFound = true;
		}
		i++;
	}

	if (valueFound) {
		return searchedIndex;
	}
	else {
		return -1;
	}
}


// This is the First World Bank Heist
// fwb also includes loud and stealth pathways
void fwb(std::vector <string> saveFileUsername, std::vector <int> saveFileBalance, std::vector <int> saveFileBudget, std::vector <int> saveFileSuspicion, std::vector <int> saveFileLoyalty, std::vector <int> saveFileReputation, std::vector <int> saveFileRisk, int searchedIndex, std::vector <string> saveFileHeister1, std::vector <string> saveFileHeister2, std::vector <string> saveFileHeister3, std::vector <string> saveFileHeister4) {
	// This records all the significant events during the heist, to be used in extra 
	//events and also to be used in calculations for if an event should be harder or easier on the player
	vector <string> events;


	// This is an array that records all the remaining downs of each Heister
	// The members in the array are cooresponding to the heister 1, 2, 3, 4
	int heisterDowns[4] = { 3, 3, 3, 3 };
	
	cls;;

	type("You send the Payday Gang to the bank...\n", 30);
	sleep(1s);

	type("They worry about the plan going south, they request you to either go loud or stealth\n", 30);
	
	type("Type 1 for loud and 0 for stealth\n", 30);
	input;
	cin >> loudOrStealth;
	endl;

	switch (loudOrStealth){
	case 0:
		// The user tried to pick stealth, lets check weather he can or cannot go depending on their suspicion level
		// this is to check wheather their risk or suspicion is over 40, if so then they are too high to go stealth
		if (saveFileRisk[searchedIndex] >= 40 || saveFileSuspicion[searchedIndex] >= 40) {
			type("Your Risk or Suspicion Level is too high, the cops were called and the heist is now loud\n", 30);
			sleep(1s);

			type("Your Gang reached the Bank with cops alerted and launching an assault soon!\n", 30);
			lelip;
			cls;
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
		checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);
		string thisVariableDoesNotReallyMatterTooMuch;
		actions.push_back("loud");
		cls;
		PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC);
		// ~ 1
		cout << "Your Gang reached the Bank with cops alerted and launching an assault soon!\n";
		lelip;
		endl;
		type("They arrive at the Bank and shoot the visible security guards and gather up hostages", 40);
		sleep(2s);
		cls;
		cout << "Quick! Type this!\n";
		sleep(1s);

		int beforeValue = saveFileLoyalty[searchedIndex];
		
		// ~ 2
		saveFileLoyalty[searchedIndex] = typingGame("Guys! find the bank manager and get his keycard. The drill and thermite is in the server room.", saveFileLoyalty, searchedIndex, 1);

		cls;
		sleep(1s);
		
		int calculatedResult = saveFileLoyalty[searchedIndex] - beforeValue;
		type("You got a total of " + to_string(calculatedResult) + " loyal points!", 30);
		sleep(2s);
		endl;
		cls;
		checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);

		type("They search for the Bank Manager", 30);
		lelip;
		endl;
		sleep(2s);
		ab:
		cls;
		type("They found the Bank Manager, should they kill him or take him as a hostage?", 40);
		sleep(2s);
		endl;
		SetConsoleTextAttribute(hConsole, red);
		type("-kill +2 Risk\n", 30);
		SetConsoleTextAttribute(hConsole, blue);
		type("-hostage -1 Risk\n", 30);
		SetConsoleTextAttribute(hConsole, white);
		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;

		// ~ 2.1
		if (thisVariableDoesNotReallyMatterTooMuch == "kill" || thisVariableDoesNotReallyMatterTooMuch == "Kill" || thisVariableDoesNotReallyMatterTooMuch == "k") {
			SetConsoleTextAttribute(hConsole, red);
			type("Risk increased by 2", 40);
			SetConsoleTextAttribute(hConsole, white);
			sleep(1s);
			endl;
			saveFileRisk[searchedIndex] += 2;
			type("The gang brutally shot the Bank Manager and took the keycard", 30);
			sleep(2s);
			actions.push_back("kill");
			checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);
		}
		else if (thisVariableDoesNotReallyMatterTooMuch == "hostage" || thisVariableDoesNotReallyMatterTooMuch == "Hostage" || thisVariableDoesNotReallyMatterTooMuch == "h") {
			SetConsoleTextAttribute(hConsole, blue);
			type("Risk decreased by 1", 30);
			SetConsoleTextAttribute(hConsole, white);
			sleep(1s);
			endl;
			saveFileRisk[searchedIndex] -= 1;
			type("The gang ties the bank manager up and hide him in a corner", 30);
			endl;
			sleep(2s);
			actions.push_back("hostage");
			checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);
		}
		else {
			goto ab;
		}
		// ~ 3
		checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);
		cls;
		sleep(2s);
		type("The gang searches the bank for the server room", 30);
		elip;
		endl;
		type("They find the server room and pick up the drill and thermite", 30);
		sleep(2s);
		endl;

		meme:
		// random chance of thermite not being taken
		// ~ 3.1
		if (randomGenerator(2)) {
			type("They forgot to take the other canister of thermite", 30);
			endl;
			sleep(2s);
			type("Quick! Type This!", 30);
			sleep(1s);

			int beforeVlaue = saveFileLoyalty[searchedIndex];

			// the typing thing
			saveFileLoyalty[searchedIndex] = typingGame("Guys! you forgot the other canister of thermite go grab it!", saveFileLoyalty, searchedIndex, 1);

			cls;
			sleep(1s);

			int calculatedResult = saveFileLoyalty[searchedIndex] - beforeValue;
			type("You got a total of " + to_string(calculatedResult) + " loyal points!", 30);
			sleep(2s);
			endl;
			cls;
			checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);
			
		} // End random encounter

		// ~ 4
		type("The gang makes their way to the entrance of the vault area", 40);
		lelip;
		endl;
		sleep(2s);
		type("They place the thermal drill and start drilling", 40); // ~ 4.1
		lelip;
		endl;
		sleep(2s);
		type("Quick! Type this!", 40);
		sleep(2s);
		cls;

		int beforeVlaue = saveFileLoyalty[searchedIndex];
		// ~ 5
		saveFileLoyalty[searchedIndex] = typingGameNoIgnore("Guys! you need to hook me up to one of the terminals to open the magnetic seal.", saveFileLoyalty, searchedIndex, 1);

		cls;
		sleep(1s);

		calculatedResult = saveFileLoyalty[searchedIndex] - beforeValue;
		type("You got a total of " + to_string(calculatedResult) + " loyal points!", 30);
		sleep(1s);
		endl;
		cls;
		checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);

		abc:
		cls;

		type("The gang makes their way through the barage of cops to the computer terminal", 40);
		sleep(2s);
		elip;
		endl;

		type("They find the computer terminal and download your RAT", 40);
		elip;
		sleep(1.5s);
		endl;

		// ~ 5.1
		type("Which hack do you want to use?\n", 40);
		SetConsoleTextAttribute(hConsole, red);
		type("-short +2 Risk\n", 30);
		SetConsoleTextAttribute(hConsole, blue);
		type("-long -1 Risk\n", 30);
		SetConsoleTextAttribute(hConsole, white);

		input;
		cin >> thisVariableDoesNotReallyMatterTooMuch;

		beforeVlaue = saveFileLoyalty[searchedIndex];
		int uselessIntVar = 0;
		if (thisVariableDoesNotReallyMatterTooMuch == "short") {
			// Shorter hack but more traceable
			//  higher suspicion as a result
			actions.push_back("short");
			type("You chose the less time consuming hack but as a consequence your risk increased", 30);
			sleep(2s);
			endl;
			saveFileRisk[searchedIndex] += 2;
			checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);
			type("Quick Type This!", 30);
			sleep(1.5s);
			// Now there is a short minigame that the user types lines of code

			uselessIntVar += typingGame("struct group_info init_groups = { .usage = ATOMIC_INIT(2) };", saveFileLoyalty, searchedIndex, 1);
			cout << uselessIntVar;
			endl;
			uselessIntVar += typingGameNoIgnore("ssh bain@firstworldbank bainistheman1978", saveFileLoyalty, searchedIndex, 1);
			cout << uselessIntVar;
			endl;
			uselessIntVar += typingGameNoIgnore("upload 5267.py -firstworldbank", saveFileLoyalty, searchedIndex, 1);
			cout << uselessIntVar;
			endl;
			uselessIntVar += typingGameNoIgnore("sudo python 5267.py", saveFileLoyalty, searchedIndex, 1);
			cout << uselessIntVar;
			endl;

			saveFileLoyalty[searchedIndex] = int((uselessIntVar / 6));

			cls;
			sleep(1s);

			calculatedResult = saveFileLoyalty[searchedIndex] - beforeValue;
			type("You got a total of " + to_string(calculatedResult) + " loyal points!", 30);
			cout << calculatedResult;
			endl;
			cout << uselessIntVar;
			endl;
			sleep(3s);
			endl;
			cls;
			checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);

		}
		else if (thisVariableDoesNotReallyMatterTooMuch == "long") {
			// Longer less traceable hack
			// less suspicion as a result
			actions.push_back("long");
			type("You chose the longer hack, as a result your risk decreased", 30);
			sleep(2s);
			endl;
			saveFileRisk[searchedIndex] -= 1;
			checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);
			type("Quick Type This!", 30);
			sleep(1.5s);

			// Now there is a longer minigame that the user types lines of code
			
			uselessIntVar += typingGameNoIgnore("struct group_info init_groups = { .usage = ATOMIC_INIT(2) };", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("struct group_info *groups_alloc(int gidsetsize){", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("struct group_info *group_info;", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("int nblocks;", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("int i;", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("nblocks = (gidsetsize + NGROUPS_PER_BLOCK - 1)/ NGROUPS_PER_BLOCK;", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("nblocks = nblocks ?:1;", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("group_info = kmalloc(sizeof(*group_info) + nblocks*sizeof(gid_t *), GFP_USER;", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("getLogFileName(std::string logType){", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("switch(this -> currentSubFilters[i]){", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("void decode_ethernet(const unsigned char*);", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("#include <sys/socket.h>", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("#include <fstream>", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("ifstream netMetasploitrEthnet = '0.sh'", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("ssh bain@firstworldbank bainistheman1978", saveFileLoyalty, searchedIndex, 1);
			uselessIntVar += typingGameNoIgnore("./0.sh", saveFileLoyalty, searchedIndex, 1);

			saveFileLoyalty[searchedIndex] = int((uselessIntVar / 5));

			cls;
			sleep(1s);

			calculatedResult = saveFileLoyalty[searchedIndex] - beforeValue;
			type("You got a total of " + to_string(calculatedResult) + " loyal points!", 30);
			sleep(1s);
			endl;
			cls;
			checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);
			
		}
		else {
			goto abc;
		}

		clear;
		type("Your hack has been uploaded", 40);
		lelip;
		endl;
		sleep(3s);
		cls;
		// ~ 6
		type("The cops have paused your progress!", 40);
		sleep(2s);
		endl;
		type("The gang rush to the computer and proceed to enable your hack \n", 40);
		sleep(2s);
		endl;

		// ~ 6.1
		// Generate a random down and continue the detour
		if (randomGenerator(2)) {
			uselessIntVar = randomGenerator(4);

			if (uselessIntVar == 0) {
				type(saveFileHeister1[searchedIndex], 40);
				type(" got downed!", 40);
				endl;
				// Continue
			}
			else if (uselessIntVar == 1) {
				type(saveFileHeister2[searchedIndex], 40);
				type(" got downed!", 40);
				endl;
				// Continue
			}
			else if (uselessIntVar == 2) {
				type(saveFileHeister3[searchedIndex], 40);
				type(" got downed!", 40);
				endl;
				// Continue
			}
			else if (uselessIntVar == 3) {
				type(saveFileHeister4[searchedIndex], 40);
				type(" got downed!", 40);
				endl;
				// Continue
			} // End of random stop

			cls;
			sleep(2s);

			type("The Gang reaches the computer and attempt to reconnect to your VPS", 40);
			lelip;
			endl;

			// Random Encounter
			type(to_string(saveFileSuspicion[searchedIndex]),  40);
			pause;
			if ((0.25 + saveFileSuspicion[searchedIndex] / 30)) {
				int beforeValue = saveFileLoyalty[searchedIndex];
				cls;
				type("The Cops are Tracking You!!!", 40);
				endl;
				sleep(1s);
				
				uselessIntVar = 0;

				uselessIntVar += typingGameNoIgnore("sudo ./openvpn", saveFileLoyalty, searchedIndex, 1);
				uselessIntVar += typingGameNoIgnore("i = switchIPDNS ` ` `  0.0.0.0, 127.0.0.1", saveFileLoyalty, searchedIndex, 1);
				uselessIntVar += typingGameNoIgnore("i.save('/')", saveFileLoyalty, searchedIndex, 1);
				uselessIntVar += typingGameNoIgnore("exit", saveFileLoyalty, searchedIndex, 1);
				uselessIntVar += typingGameNoIgnore("exec openvpn -config -i.cfg", saveFileLoyalty, searchedIndex, 1);
				uselessIntVar += typingGameNoIgnore("sudo ./cleanup", saveFileLoyalty, searchedIndex, 1);

				saveFileLoyalty[searchedIndex] = int((uselessIntVar / 2));

				cls;
				sleep(1s);

				calculatedResult = saveFileLoyalty[searchedIndex] - beforeValue;
				type("You got a total of " + to_string(calculatedResult) + " loyal points!", 30);
				sleep(1s);
				endl;
				cls;
				checkStats(saveFileLoyalty, saveFileRisk, saveFileSuspicion, searchedIndex);

			} // End of Random Encounter


			//Either open new port (long, lower risk)
			//Use same port (short, higher risk)

		}

		PlaySound(TEXT("music.wav"), NULL, SND_APPLICATION);
		type("End of the line buddy", 50);
		pause;
		break; // end of case

	} // End of switch statment

	cout << "HEY THERE MAN !";
	endl;
	pause;
} // End of Function

//menu for heists
void heistoptions(std::vector <string> saveFileUsername, std::vector <int> saveFileBalance, std::vector <int> saveFileBudget, std::vector <int> saveFileSuspicion, std::vector <int> saveFileLoyalty, std::vector <int> saveFileReputation, std::vector <int> saveFileRisk, int searchedIndex, std::vector <string> saveFileHeister1, std::vector <string> saveFileHeister2, std::vector <string> saveFileHeister3, std::vector <string> saveFileHeister4)
{
heistoptions:
	cout << "1. First World Bank\n";
	cin >> option;
	switch (option) {
	case 1:
		cls;
		fwb(saveFileUsername, saveFileBalance, saveFileBudget, saveFileSuspicion, saveFileLoyalty, saveFileReputation, saveFileRisk, searchedIndex, saveFileHeister1, saveFileHeister2, saveFileHeister3, saveFileHeister4);
		break;
	
	default:
		cout << "Sorry, didn't quite get that!\n";
		pause;
		goto heistoptions;
	}
}

//crime.net
void crimenet(std::vector <string> saveFileUsername, std::vector <int> saveFileBalance, std::vector <int> saveFileBudget, std::vector <int> saveFileSuspicion, std::vector <int> saveFileLoyalty, std::vector <int> saveFileReputation, std::vector <int> saveFileRisk, int searchedIndex, std::vector <string> saveFileHeister1, std::vector <string> saveFileHeister2, std::vector <string> saveFileHeister3, std::vector <string> saveFileHeister4)
{
	string message;
crimenet:
	cls;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	type("Welcome to ", 150);
	SetConsoleTextAttribute(hConsole, blue);
	type("Crime.net\n", 60);
	SetConsoleTextAttribute(hConsole, white);
	sleep(2s);
	cout << "What would you like to do?\n";
	cout << "1. Plan a heist\n";
	cout << "2. Change the crew\n";
	cout << "3. Budget\n";
	cin >> option;

	switch (option) {
	case 1:
		cout << "What heist would you like to do?\n";
		heistoptions(saveFileUsername, saveFileBalance, saveFileBudget, saveFileSuspicion, saveFileLoyalty, saveFileReputation, saveFileRisk, searchedIndex, saveFileHeister1, saveFileHeister2, saveFileHeister3, saveFileHeister4); //calling the menu function
		break;
	case 2:
		cout << "Which heisters do you want to change?\n";
		cout << "Your current heisters are:\n";
		pause;
		break;

	case 3:
		cls;
		message = string("Your budget is ") + to_string(saveFileBudget[searchedIndex]);
		type(message, 40);
		endl;
		pause;
		break;

	default:
		cls;
		cout << "Sorry, didn't get that!\n";
		pause;
		goto crimenet;
	}

	goto crimenet;
}



// Here below is the stats() function, the functions needs reuqired vectors and variables in specific order to display
// the correct stats. The vector contains all the data of that category and the varible is the index of it.
int stats(std::vector <string> saveFileUsername, std::vector <int> saveFileBalance, std::vector <int> saveFileBudget, std::vector <int> saveFileSuspicion, std::vector <int> saveFileLoyalty, std::vector <int> saveFileReputation, std::vector <int> saveFileRisk, int searchedIndex, std::vector <string> saveFileHeister1, std::vector <string> saveFileHeister2, std::vector <string> saveFileHeister3, std::vector <string> saveFileHeister4) {
	cls;
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

	pause;

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
	SetConsoleTextAttribute(hConsole, red);
	cout << "Manager 2018";
	endl;
	SetConsoleTextAttribute(hConsole, white);

	pause;
	cls;

	// a GoTo Loop thing so we can always refer back to it
mainmenu:
	cls;
	cout << "1. Play\n";
	cout << "2. Stats\n";
	cout << "3. Credits\n";
	cout << "4. Exit\n";
	cin >> option;
	cls;
	// A Switch Case
	switch (option)
	{
	case 1:
		SetConsoleTextAttribute(hConsole, blue);
		cout << "Crime.net\n";
		SetConsoleTextAttribute(hConsole, white);
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
			cls;

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

			pause;
			
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
		// Lets call our stats function and pass in the required arguements
		stats(saveFileUsername, saveFileBalance, saveFileBudget, saveFileSuspicion, saveFileLoyalty, saveFileReputation, saveFileRisk, searchedIndex, saveFileHeister1, saveFileHeister2, saveFileHeister3, saveFileHeister4);
		break;

	case 3:
		// credits
		type("Programming - Ramzi Al Haddad", 30);
		endl;
		pause;
		break;

	case 4:
		// exit the program
		exit(0);

	default:
		cout << "Sorry didn't quite get that!";
		endl;
		Sleep(1500);
		break;
	}
	goto mainmenu;
}