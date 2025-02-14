#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void startgame() {
	int numbertoguess, usernumber= -1, attemp = 1;
	srand(time(0));
	numbertoguess = (rand() % 100) + 1;
	while (usernumber != numbertoguess) {
		cout << "Attemp number: " << attemp << endl;
		cout << "Enter your guess: ";
		cin >> usernumber;
		if (usernumber == numbertoguess) {
			cout << "You Win!" << endl;
			cout << "your number of attemps is: " << attemp << endl;
		}
		else if (usernumber < numbertoguess) {
			cout << "The number entered is smaller than the number to guess. Try Again" << endl;
		}
		else {
			cout << "The number entered is bigger than the number to guess. Try Again" << endl;
		}
		attemp++;
	}
}
int main()
{
	string start,restart="";
	cout << "Welcome to the number guessing game!" << endl;
	cout << "In this gamne a number between 1 and 100 will be given your goal is to guess this number with the less tries as possible" << endl;
	cout << "Write anything to start: ";
	cin >> start;
	do {
		startgame();
		cout << "do you wanna to restart the game? (yes or no): ";
		cin >> restart;
		while (restart != "yes" && restart != "Yes" && restart != "no" && restart != "No") {
			cout << "please enter a valid word (yes or no): ";
			cin >> restart;
		}

	} while (restart == "yes" || restart == "Yes");
	cout << "Exiting game...";
	return 0;

}

