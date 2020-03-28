/**

ReadWords.cpp file

**/

using namespace std;

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "ReadWords.h"

//opens a file to read the words. If file does not exist then error message is displayed and terminated
ReadWords::ReadWords(const char *filename)
{
    fileofwords.open(filename);
    if (!fileofwords)
    {   cout << "Sorry the file could not be opened " << filename << endl;
        exit(1);
    }
}

//closes the file
void ReadWords::close()
{
	fileofwords.close();
}

//Returns a string, being the next word in the file.
string ReadWords::getNextWord()
{
	fileofwords >> nxtW;
	for (int x = 0 ; x < nxtW.length(); ++x)
	{
		nxtW[x] = tolower(nxtW[x]); //all letters are converted to lower case
	}
	return nxtW;

}

bool ReadWords::isNextWord(){
	if (fileofwords.eof()) //checking if we reached end of file and if there are any words left.
    {
        return false;
    }
	else
	{
		return true;
    }
}

