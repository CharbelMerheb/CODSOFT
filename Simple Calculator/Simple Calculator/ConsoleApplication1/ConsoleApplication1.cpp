#include <iostream>
using namespace std;

double calculate(double num1, double num2, string& operation) {
	if (operation == "+")
		return num1 + num2;
	else if (operation == "-")
		return num1 - num2;
	else if (operation == "*")
		return num1 * num2;
	else if (operation == "/")
		return num1 / num2;
	else {
		while (operation != "+" && operation != "-" && operation != "/" && operation != "*") {
			cout << "plese enter a correct operation: ";
			cin >> operation;
		}
		calculate(num1, num2, operation);
	}
}
int main()
{
	cout << "Welcome to THE CALCULATOR" << endl;
	string restart = "y";
	while (restart != "n") {
		double num1, num2;
		string operation;
		cout << "Enter the first number: ";
		cin >> num1;
		cout << "Enter the second number: ";
		cin >> num2;
		cout << "Enter the operation: (+ for addition, - for substraction, * for multiplication, / for division)";
		cin >> operation;
		double result = calculate(num1, num2, operation);
		cout << num1 << " " << operation << " " << num2 << " = " << result<<endl;
		cout << "Do you want to do another calculation? (y for yes, n for no)";
		cin >> restart;
	}
}