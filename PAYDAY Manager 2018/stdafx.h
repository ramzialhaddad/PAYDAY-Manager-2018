// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <thread>
#include <fstream>
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm> 
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <ctime>

#pragma comment(lib, "Winmm.lib")

#define sleep this_thread::sleep_for
#define pause cin.ignore();
#define clear system("cls");
#define elip cout << "."; sleep(0.1s); cout << "."; sleep(0.1s); cout << "."; sleep(0.1s); cout << "."; sleep(0.1s);
#define lelip cout << "."; sleep(1s); cout << "."; sleep(1s); cout << "."; sleep(1s); cout << "."; sleep(1s);
#define endl cout << endl;
#define input cout << "> ";
#define cls system("cls");