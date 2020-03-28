/**

WriteWords.cpp file

**/

#include <stdlib.h>
#include <fstream>
#include<iostream>

#include "WriteWords.h"

using namespace std;

// Opens a file for writing. Prints an error message then terminates the program if it cannot create the file.
WriteWords::WriteWords(const char *filename)
{   out.open(filename);
    if (!out)
    {   cout << "Sorry the file could not be opened" << filename << endl;
        exit(1);
    }
}

// writes an integer to the file, no end of line.
void WriteWords::writeInt(int n) // n is the integer
{
	out << n;
}

// closes the file
void WriteWords::close()
{
    out.close();
}

// Writes a string to the file, no end of line.
void WriteWords::writeString(string s)
{
	out << s;
}

// Writes a newline character to the file
void WriteWords::writeEol()
{
  	out << endl;
}

// Writes a character to the file, no end of line.
void WriteWords::writeChar(char s)
{
       out << s;
}
