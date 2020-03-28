/**

main.cpp

**/

#include "ReadWords.h"
#include "WriteWords.h"

#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	string fileName;

	/**
	output file that asks user to provide the name of the file.
	**/

	cout << "Please enter the name of the file containing the result: " << endl;
	cin >> fileName;
	WriteWords writer(fileName.c_str());


	/**
	Testwords.txt contains the list of words that are read and put into the array
	**/


	int i = 0;
	string arr[100]; //stores the list of words. Set to be able to store 100 words.
	string words;

	cout << "Please enter the name of file containing list of words: " << endl;
	cin >> fileName;
	ReadWords readWord(fileName.c_str()); //opens file for reading

        //puts words in the file into an array
    	while (readWord.isNextWord())
    	{
    		 words = readWord.getNextWord();
    		 arr[i] = words;
    		 cout << arr[i] << endl;
    		 i++;
    	}
	readWord.close();

	/**
	hamlet.txt - counts total number of words in the script and the number of occurrence in the
	script of each word from the list of words in the file testwords.txt
	**/

	int occ[10] = {0}; //array that stores occurrence
	string hamlet[100000]; //array for script
	string wordsOfScr; //words in the script.

	cout << "Please enter the name of script file: " << endl;
	cin >> fileName;
	ReadWords readScript(fileName.c_str());

	int s = 0;

	while (readScript.isNextWord())
	{
	 wordsOfScr = readScript.getNextWord(); // as the file read words into scriptwords, keep count of the words entered
	 hamlet[s] = wordsOfScr;
	 s++;

	 for ( int x = 0; x < wordsOfScr.length(); x++)
     {
			wordsOfScr[x] = tolower(wordsOfScr[x]); //converting to lower case
     }

		    //removes punct from end
			int p = 0;

			//checks if there is punctuation at the end of a word
			while (ispunct(wordsOfScr[wordsOfScr.length()-(p+1)]))
			{
				p++;
			}
			wordsOfScr.erase(wordsOfScr.length()-p,p); //removes the occurrences of that punctuation from that position

		//removes punct from start
		int c =0;

		while (ispunct(wordsOfScr[c]))
		{
			c++;
		}
		wordsOfScr.erase(0,c);

		int y = 0;

		//Counts the occurrences of a word if word in script matches the words in the testwords.txt
		while (y < i)
		{
			if (wordsOfScr == arr[y])
			{
				occ[y]++;
				y++;
            }
            else
            {
				y++;
            }

        }


    }
    readScript.close();


	/**
	Writes the result to the output file. (test.txt)
	**/

	int element = 0;
		while (element < i)
        {
            cout << "Occurrences of " << arr[element] << " are: "<< occ[element] << endl;
            writer.writeString("Occurrences of "); //writes to result file
            writer.writeString(arr[element]);
            writer.writeString(" are: ");
            writer.writeInt(occ[element]);
            writer.writeEol();
            element++;
		}
	cout << "The total number of words in script are: " << s << endl;
	writer.writeString("The total number of words in script are: "); //writes to result file.
	writer.writeInt(s);
	writer.writeEol();
	writer.close();

}
