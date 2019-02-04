#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int GetWordLength()
{
	int length = 0, minLength = 4, maxLength = 15;
	bool valid = false; 

	//user select word length.
	cout << "Please select an isogram length: ";
	
	do
	{
		if (cin >> length && length >= minLength && length <= maxLength)
		{
			valid = true;
		}
		else
		{
			cout << "Error! Word length must be greater than " << minLength << " and less than " << maxLength << ".\n";
		}
	} while (!valid);

	//repeat to user.
	cout << "You selected a " << length << " letter isogram." << "\n";

	return length;
}

string GenerateWord(int wordLength)
{
	string newWord = "";
	ifstream isograms("isogram.txt");

	return newWord;
}

int main()
{
	//Get word length
	int wordLength = GetWordLength();

	//generate word.
	string word = "";
	word = GenerateWord(wordLength);
	cout << "The word is: " << word << endl;

	return 0;
}