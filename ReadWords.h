/**

ReadWords.h file

**/

#ifndef _READWORDS_H_
#define _READWORDS_H_

using namespace std;

#include <iostream>
#include <string>
#include <fstream>

 class ReadWords
 {
   public:

     //Constructor. Opens the file with the given file name.
     //Prints an error message then terminates the program if file does not exist.

     ReadWords(const char *filename);


     //Closes the file.

     void close();


     //Returns a string, being the next word in the file. All letters are converted
     //to lower case
     //Leading and trailing punctuation marks are not included in the word


     string getNextWord();


     //Returns true if there is a further word in the file, false if we have reached the
     //end of file.

     bool isNextWord();


   private:
     string nxtW; //next words
     ifstream fileofwords;
     bool eoffound;
 };

 #endif
