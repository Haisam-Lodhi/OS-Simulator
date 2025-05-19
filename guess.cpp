#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void guess()
{
	int num, guess;
	char choice;
	int numb;
	cout << "enter number from which you want to guess: ";
	cin >> numb;
	again:
	srand(time(0));
	num = rand() % numb + 1;
	cout << "Guess My Number Game\n";
	
	do {
		cout << "Enter a guess between 1 and " << numb << ": ";
		cin >> guess;
		if (guess > num)
			cout << "Too high!\n";
		else if (guess < num)
			cout << "Too low!\n";
		else
		{
			cout << "\nExcellent You guessed the number!\n";
			cout << "press y if you want to play again else press n  ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
				goto again;
			if (choice == 'n' || choice == 'N')
				cout << "End of Game\n";
		}
	} while (guess != num);

}

int main()
{
	guess();
	system("pause");
}
