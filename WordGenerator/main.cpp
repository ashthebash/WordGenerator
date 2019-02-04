#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

int OrganiseWords(int minLength, int maxLength)
{

	return 0;
}

int GetWordLength(int minLength,int maxLength)
{	
	int length = 0;
	bool bValid = false; 

	//user select word length.
	cout << "Please select an isogram length: ";
	
	do
	{
		if (cin >> length && length >= minLength && length <= maxLength)
		{
			bValid = true;
		}
		else
		{
			cout << "Error! Word length must be greater than " << minLength << " and less than " << maxLength << ".\n";
		}
	} while (!bValid);

	//repeat to user.
	cout << "You selected a " << length << " letter isogram." << "\n";

	return length;
}

int RandomNumber(int maxNumber)
{
	random_device randSeed;  //Seed random number gen.
	mt19937 randNumber(randSeed());
	uniform_int_distribution<int> randRange(1, maxNumber);

	return randRange(randNumber);
}

string GenerateWord(int wordLength)
{
	string newWord = "hello";
	string line;
	ifstream isograms("isogram.txt");
	int numberOfLines = 0;

	while (getline(isograms, line))
	{
		numberOfLines++;
	}

	int pickLine = RandomNumber(numberOfLines);
	cout << pickLine << "\n";
	
	return newWord;
}

int main()
{
	const int minLength = 4, maxLength = 15;

	//Organise words
	OrganiseWords(minLength, maxLength);

	//Get word length
	const int wordLength = GetWordLength(minLength,maxLength);

	//generate word.
	string word = "";
	word = GenerateWord(wordLength);
	cout << "The word is: " << word << endl;

	return 0;
}