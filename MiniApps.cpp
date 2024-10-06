#include <iostream>
#include <time.h>
#include <iomanip>  // For setting decimal precision, square root calc
#include < stdio.h > // to allow placeholders in statements
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <string>
#include <cctype>   // For toupper

using namespace std; //cin and cout exist within the subspace of std in iostream

//function prototyping
void KeepCounting();
void SquarerootCalculator();
void EncryptTextCaesarCipher();
void DecryptTextCaesarCipher();


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
			cout << "--------------------------------- \n";
			KeepCounting();
			break;
		case 2:
			cout << "You have selected Square root Calculator \n";
			cout << "--------------------------------- \n";
			SquarerootCalculator();
			break;
		case 3:
			cout << "You have selected Encrypt Text (Caesar Cipher) \n";
			cout << "--------------------------------- \n";
			EncryptTextCaesarCipher();
			break;
		case 4:
			cout << "You have selected Decrypt Text (Caesar Cipher) \n";
			cout << "--------------------------------- \n";
			DecryptTextCaesarCipher();
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



	srand(time(0)); //initialise random seed based on current time

	int correctAnss = 0;
	int num1 = rand() % 10 + 1; //first rand num 1,10
	int num2;
	char operation;
	int userAns, correctAns;

	cout << "You will be presented with 10 arithmetic questions." << endl;

	for (int i = 1; i <= 10; i++)
	{
		num2 = rand() % 10 + 1; // randomly generate num2

		if (rand() % 2 == 0)  // randomly choose addition or subtraction
		{
			operation = '+';
			correctAns = num1 + num2;
		}
		else 
		{
			operation = '-';
			correctAns = num1 - num2;
		}
		//ask question
		cout << "Question " << i << ": " << num1 << " " << operation << " " << num2 << " = ";
		cin >> userAns;

		//check answer
		if (userAns == correctAns)
		{
			cout << "Correct! ";
			correctAnss++;
			num1 = userAns; //use the correct answer as the num1 for the next question
		}
		else
		{
			cout << "Incorrect! Answer is " << correctAns << endl;
			num1 = correctAns;
		}
	}
	//out total score
	cout << "You got " << correctAnss << " out of 10 questions right!" << endl;
}

void SquarerootCalculator()
{
	double number = 0;
	int precision = 0;
	double answer = 0;

	//while loop to validate +ve number
	cout << "Please enter a positive number: ";
	cin >> number;
	while (number < 0) //how to tackle uninitialised memory usage
	{
		cout << "Enter a positive number: ";
		cin >> number;
	}
	cout << "How many decimal points (between 1 and 6) do you want the solution calculated at: ";
	cin >> precision;
	while (precision < 1 || precision > 6) //outside of 1 and 6
	{
		cout << "Enter a number between 1 and 6: ";
		cin >> precision;
	}
	double precisionval = 1.0;
	for (int i = 0; i < precision; i++)
	{
		precisionval /= 10; //get the degree of closeness of the bounds
	}

	// main code
	double lowerbound = 0;  //numbber sqrt cannot be less than 0
	double upperbound = number; //number^2 cannot be less than number itself
	
	//iterate over bounds and refine
	while ((upperbound - lowerbound) > precisionval)
	{
		double mid = (lowerbound + upperbound) / 2; //calculating midpoint
		double midsquared = mid * mid; //checking

		if (midsquared > number) //too large, adjust upper bound
		{
			upperbound = mid;
		}
		else 
		{
			lowerbound = mid; 
		}
		//after updating, check the degree of difference between the bounds
	}
	//here the precision is what is required 
	// do the mid point to find answer
	answer = (upperbound + lowerbound) / 2;
	// main code

	cout << fixed << setprecision(precision); //format to required decimal places
	cout << "The square root of " << number << " to " << precision << " decimal places is " << answer << ".";
}

void EncryptTextCaesarCipher() 
{
	const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	string input; //declarw

	//validate input
	bool isValid = false;
	while (!isValid)
	{
		cout << "Enter text to encrypt: ";
		//cin >> input;
		cin.ignore();  // Clear the input buffer before calling getline
		getline(cin, input);  // Use getline to allow spaces in input

		isValid = true;
		for (char& c : input)
		{
			c = toupper(c); //convert to uppercase

			if (ALPHABET.find(c) == string::npos && c != ' ') //check each character is in ALPHABET
			{
				isValid = false;
				cout << "Invalid input! Please enter valid characters (A-Z, 0-9, space). \n";
				break;
			}
		}
	}

	int shift;
	cout << "Please enter shift (between 1 and 36): ";
	cin >> shift;
	//validate shift input
	while (shift < 1 || shift > 36)
	{
		cout << "Invalid shift amount. Please enter a value between 1 and 36.";
		cin >> shift;
	}
	
	// encrypt duh
	string encryptedmessage = "";
	for (char c : input)
	{
		if (c == ' ')
		{
			encryptedmessage += ' '; // preserve space in encryption
		}
		else
		{
			//find index of the character in ALPHABET
			//add shift to index
			// add char at new index to encryptdd messgae
			size_t index = ALPHABET.find(c);
			size_t newIndex = (index + shift) % ALPHABET.length();  // E_n(x) = (x+n) mod 26. formule
			encryptedmessage += ALPHABET[newIndex];
		}

	}
	//display encryped message
	cout << "The Encrypted message is: '"<< encryptedmessage << "' " << endl;
}

void DecryptTextCaesarCipher()
{
	const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

	string input;
	bool isValid = false;

	// Input validation
	while (!isValid)
	{
		cout << "Enter text to decrypt: ";
		cin.ignore();  // Clear the input buffer before calling getline
		getline(cin, input);  // Allow spaces in input

		isValid = true;
		for (char& c : input)
		{
			c = toupper(c);  // Convert to uppercase

			if (ALPHABET.find(c) == string::npos && c != ' ') // Check for invalid characters
			{
				isValid = false;
				cout << "Invalid input! Please enter valid characters (A-Z, 0-9, space). \n";
				break;
			}
		}
	}

	int shift;
	cout << "Please enter shift (between 1 and 36): ";
	cin >> shift;
	//validate shift input
	while (shift < 1 || shift > 36)
	{
		cout << "Invalid shift amount. Please enter a value between 1 and 36.";
		cin >> shift;
	}

	//decrypt duh
	string decryptedMessage = "";
	for (char c : input)
	{
		if (c == ' ')
		{
			decryptedMessage += ' '; // Preserve space
		}
		else
		{
			// Find index of the character in ALPHABET
			size_t index = ALPHABET.find(c);
			// Subtract shift to get new index
			size_t newIndex = (index + ALPHABET.length() - shift) % ALPHABET.length(); //formulee
			// Add the decrypted character to the result
			decryptedMessage += ALPHABET[newIndex];
		}
	}
	// Display decrypted message
	cout << "The Decrypted message is: '" << decryptedMessage << "' " << endl;
}