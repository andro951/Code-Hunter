// CodeHunter.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" This file doesn't exist.  Changed it to a comment.
#include <iostream>
#include <string>

using namespace std;


int main()
{
	string textToAnalyze;
	int foo = 0;
	int vowels = 0;
	int consonants = 0;
	int digits = 0;
	int spaces = 0;
	int lengthOfStringSubmittedForAnalysis = 0;
	int unknownCharacters = 0;
	int checkSum = 0;
	int bar = 0;

	cout << "Welcome to the CIA code Hunter Program!" << endl;
	cout << "Please type in text to analyze: " << endl;
	getline(cin, textToAnalyze);

	for (int i = 0; i < textToAnalyze.length(); ++i)
	{
		if (textToAnalyze[i] == 'a' || textToAnalyze[i] == 'e' || textToAnalyze[i] == 'i' ||
			textToAnalyze[i] == 'o' || textToAnalyze[i] == 'u' || textToAnalyze[i] == 'A' ||
			textToAnalyze[i] == 'E' || textToAnalyze[i] == 'I' || textToAnalyze[i] == 'O' ||
			textToAnalyze[i] == 'U')
		{
			++vowels; //Changed from --.
		}
		else if ((textToAnalyze[i] >= 'a'&& textToAnalyze[i] <= 'z') || (textToAnalyze[i] >= 'A'&& textToAnalyze[i] <= 'Z'))
		{
			++consonants; //Changed from a comment to code.
		}
		else if (textToAnalyze[i] >= '0' && textToAnalyze[i] <= '9')
		{
			++digits;
		}
		else if (textToAnalyze[i] == ' ')
		{
			++spaces;
		}
		else
		{
			++unknownCharacters;
		}
	}

	lengthOfStringSubmittedForAnalysis = textToAnalyze.length();
	checkSum = unknownCharacters + vowels + consonants + digits + spaces;

	cout << "Vowels: " << vowels << endl;
	cout << "Consonants: " << consonants << endl;
	cout << "Digits: " << digits << endl;
	cout << "White spaces: " << spaces << endl;
	cout << "Length of string submitted for analysis: " << lengthOfStringSubmittedForAnalysis << endl;
	cout << "Number of characters CodeHunter could not identify: " << unknownCharacters << endl;
	cout << "Checksum: " << checkSum << endl;

	if (checkSum == lengthOfStringSubmittedForAnalysis)
	{
		cout << "This program self checking has found this Analysis to be valid." << endl;
	}
	else
	{
		cout << "WARNING! *** This program self checking has found this Analysis to be invalid! Do not use this data!" << endl;
	}

	system("pause");

	return 0;
}

//First run:  Vowels are negative.  Consonants are 0.  Checksum is too low.  Self check failed.
//imput message "hi 2!"
//1st break point @ line 32.  No issues.
//2nd break point @ 37 first character not a vowel, no issues.
//3rd break point @ 41 first character is a consonant.  consonants = 0.  There is a problem with the else if that checks for consonants.  
//4th break point @ 45 first character not a number, no issues.
//5th break point @ 49 first character not white space, no issues.
//re-building the program and re-running with same break points.
//char "h" consonants = 1, no issues.
//char "i" vowels = -1.  Should be positive.
//re-building.
//char "h" consonants = 1, no issues.
//char "i" vowels = 1, no issues.
//char " " spaces = 1, no issues.
//char "2" digits = 1, no issues.
//char "!" unknownCharacters = 1, no issues.
//for loop ends.
//6th break point @ 55 no issues.
//7th break point @ 56 lengthOfStringSubmittedForAnalysis = 5, no issues.
//8th break point @ 58 checkSum = 5, no issues.
//9th break point @ 66.  The output looks correct, no issues.
//10th break point @ 75 This program self checking has found this Analysis to be valid, no issues.
//Finished de-bugging.
