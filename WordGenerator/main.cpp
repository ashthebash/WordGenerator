#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

vector<vector <string> > OrganiseWords(vector<vector <string> > words, int numberOfLetters)
{
	ifstream file("isogram.txt");
	string line;
	int wordIndex = 0;
	vector<string> wordColumn;

	while (getline(file, line))
	{
		if (line.length() == numberOfLetters)
		{
			wordColumn.push_back(line);
			cout << wordColumn[wordIndex] << endl;
			wordIndex++;
		}
	}
	words.push_back(wordColumn);
	return words;
}

int WordListLength()
{
	ifstream file("isogram.txt");
	string line;
	int numberOfLines = 0;

	while (getline(file, line))
	{
		numberOfLines++;
	}

	return numberOfLines;
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

string GenerateWord(int wordLength, int minLength, vector<vector <string> > words)
{
	string newWord = "";
	int wordColumn = wordLength - minLength;
	int wordRowLength = words[wordColumn].size();
	int pickword = RandomNumber(wordRowLength);

	newWord = words[wordColumn][pickword];
	
	return newWord;
}

int main()
{
	const int minLength = 4, maxLength = 15;
	vector< vector<string> > words;
	int numberOfLines = WordListLength();
	int numberOfLetters = minLength;
	int wordRow = 0;

	//Organise words
	for (int i = 0; i < maxLength - minLength + 1; i++)
	{
		words = OrganiseWords(words, numberOfLetters);
		wordRow++;
		numberOfLetters++;
	}

	//Get word length
	const int wordLength = GetWordLength(minLength,maxLength);

	//generate word.
	string word = "";
	word = GenerateWord(wordLength, minLength, words);
	cout << "The word is: " << word << endl;

	return 0;
}