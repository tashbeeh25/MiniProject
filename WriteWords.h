/**

WriteWords.h file

**/

#ifndef _WRITEWORDS_H_
#define _WRITEWORDS_H_

using namespace std;

#include <iostream>
#include <fstream>
#include <string>

class WriteWords {
    private:
      ofstream out;

    public:

       //Constructor to create a file.
       //Prints an error message then terminates the program if it cannot create the file.

      WriteWords(const char *filename);


       //writes an integer to the file, no end of line.

      void writeInt(int n);

     // Writes a character to the file, no end of line.

      void writeChar(char s);

      // Writes a string to the file, no end of line.

      void writeString(string s);

      // Writes a newline character to the file

      void writeEol();

      // function to close the file, thus ensuring it is stable on disk,

      void close();
};

#endif
