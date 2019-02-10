#include <iostream>
#include <fstream>
#include<sstream>
#include <string>
#include <random>

using namespace std;

vector<vector <string> > OrganiseWords(vector<vector <string> > words, int numberOfLetters);
int WordListLength();
int CheckIfInt(int& length);
int GetWordLength(int minLength, int maxLength);
int RandomNumber(int maxNumber);
string GenerateWord(int wordLength, int minLength, vector<vector <string> > words);

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

vector<vector <string> > OrganiseWords(vector<vector <string> > words, int numberOfLetters)
{
	ifstream file("isogram.txt");
	string line;
	int wordIndex = 0;
	vector<string> wordColumn;

	// Read text file lines and push each X-Letter word to the corresponding column.
	while (getline(file, line))
	{
		if (line.length() == numberOfLetters)
		{
			wordColumn.push_back(line);
			wordIndex++;
		}
	}
	words.push_back(wordColumn); //Push word column as a row in multidimensional vector.
	return words;
}

int WordListLength()
{
	ifstream file("isogram.txt");
	string line;
	int numberOfLines = 0;

	//Get number of lines in the text file.
	while (getline(file, line))
	{
		numberOfLines++;
	}

	return numberOfLines;
}

int CheckIfInt(int& length)
{
	string input;

	while (1)
	{
		cout << "Please select an isogram length: ";
		cin >> input;

		istringstream stream(input);

		stream >> length;

		if (!stream.eof())
		{
			cout << "Error, please enter numerical values! \n";
			continue;
		}
		else
		{
			break;
		}
	}
	return length;
}

int GetWordLength(int minLength, int maxLength)
{
	int length = 0;
	bool bValid = false;

	while (1)
	{
		CheckIfInt(length);
		if (length < minLength || length > maxLength)
		{
			cout << "Error! Word length must be greater than " << minLength << " and less than " << maxLength << ".\n";
			continue;
		}
		break;
	}

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

	cout << "There are " << wordRowLength << " " << wordLength << " letter isograms. \n";

	newWord = words[wordColumn][pickword];
	
	return newWord;
}