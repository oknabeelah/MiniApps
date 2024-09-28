#include <iostream>
#include <time.h>

using namespace std; //cin and cout exist within the subspace of std in iostream

//function prototyping
void KeepCounting();

int main()
{
	cout << "Welcome to P4CS Mini Applications \n";
	cout << "--------------------------------- \n";
	cout << "Please select an Option: \n";
	//add use case options with function calls inside them
	cout << "1) Keep Counting \n";
	cout << "2) Square root Calculator \n";
	cout << "3) Encrypt Text (Caesar Cipher) \n";
	cout << "4) Decrypt Text (Caesar Cipher) \n";
	cout << "5) Quit \n";

	//accept int input 
	int menucase;
	cout << "Please enter your option: ";
	cin >> menucase; // streams in input 
	//check if number?

	
	//use cases
	switch (menucase)
	{
		case 1:
			cout << "You have selected Keep Counting \n";
			//func here
			break;
		case 2:
			cout << "You have selected Square root Calculator \n";
			//here
			break;
		case 3:
			cout << "You have selected Encrypt Text (Caesar Cipher) \n";
			//here
			break;
		case 4:
			cout << "You have selected Decrypt Text (Caesar Cipher) \n";
			//here
			break;
		case 5:
			cout << "You have selected to Quit, ";
			cout << "Goodbye!";
		break;
	}
	//generating a random number
	//  #include <time.h> // do this at the top of the page
	// srand(time(nullptr));
	// 1+(rand()%10);

	return 0;
}


void KeepCounting()
{
	//int rather than void 
	// no inputs

	//random numbers to add or subtract together
	//solution bleeds to next question 
	//arithmetic sign is also assigned randomly
	
	//present 10 arith questions to solve
	//allow user to solve and see solution before showing next question
	//first operand of next question = solution to prev question
	// arith signs are decided randomly 
	// at the end of all questions the score x/10 is shown 

	srand(time(nullptr));
	int randomNum1 = 1+(rand()%10);
	int randomNum2 = 1+(rand()%10); // how to ensure its not > num1 when subtracting

	//for (i = 11, i++ /?huh, )
	// {
	//    for loop to iterate through question x: x +- y = ? input
	// input is correct, add to score count and next question or input is wrong, correct answer is bahblah, dont add to counter




}
