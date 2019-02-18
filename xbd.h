/** File: xbd.h
  * Names: Blake Meyers, Rahul Sharma
  * Class account username: Blake Meyers cssc0430,  Rahul Sharma cssc0417
  * Class information: CS530 Spring 2019
  * Assignment information: Assignment #1, HexDump. A basic hexdump program that opens a binary or text file, reads every byte in
  * the file and writes both the ASCII and hex value or Binary value for that byte as well as it’s printable
  * character to standard output. For bytes forming non-printable characters, prints a ‘.’character
**/


#ifndef XBD_H_
#define XBD_H_
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
#include <string.h>
#include <bitset>

int main(int, char **);
void handleHex (char[]);
void handleBinary (char[]);


#endif
