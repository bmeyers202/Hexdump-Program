/*
 * Main.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Blake Meyers
 */
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <bitset>
#include <sstream>

#include <fstream>
#include <string.h>


using namespace std;

bool findIfTextFile (string fileName, string fileExt) {
    if (fileName.length() >= fileExt.length()) {
        return (0 == fileName.compare (fileName.length() - fileExt.length(), fileExt.length(), fileExt));
    } else {
        return false;
    }
}

string hexToAscii(string hexString){
	string text;
	const char *asciiChar = hexString.c_str();
	unsigned int asciiDecNum;
	while(*asciiChar != 0) {
		sscanf(asciiChar, "%2X", &asciiDecNum);
	    if(asciiDecNum < 32 || asciiDecNum > 126){
	    	text += ".";
	    }
	    else{
	    	text += asciiDecNum;
	    }
		asciiChar += 2;
	}
	return text;
}

string binaryToAscii(string binaryString){
	string text = "";
	stringstream sstream(binaryString);
	while (sstream.good()) {
		bitset<8> binaryByte;
	    sstream >> binaryByte;
	    long decodedByte = binaryByte.to_ulong();
	    if((decodedByte < 32 || decodedByte > 126) && (decodedByte != 0)){
	    	text += ".";
	    }
	    else{
		    text += binaryByte.to_ulong();
	    }
	}
	return text;
}

void binarySpacedBytes(string stringToSpace){
	for (int index = 0; index < int(stringToSpace.length()); index++){
		if(index % 8 == 0){
			cout << " ";
		}
		cout << stringToSpace[index];
	}
}

void hexSpacedBytes(string stringToSpace){
	for (int index = 0; index < int(stringToSpace.length()); index++){
		if(index % 4 == 0){
			cout << " ";
		}
		cout << stringToSpace[index];
	}
}

void getAddress(string fileString){
	string *stringPointer = &fileString;
	cout << stringPointer << ":";
}

int main (int argc, char *argv[]) {
  string line;
  bool isBinaryOutput = false;
  bool isTextFile = false;
  ifstream myfile (argv[2]);

  findIfTextFile(argv[2], ".txt");
  if(strcmp(argv[1], "-b") == 0){
	  isBinaryOutput = true;
  }

  //Open File
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
    }
    myfile.close();
  }
  else{
	  cout << "Unable to open file";
	  return 0;
  }

	getAddress(line);
	if(isBinaryOutput==true){
		if (isTextFile == true){
			binarySpacedBytes(line);
			cout << " " << binaryToAscii(line) << endl;
		}
	}
	else{
		hexSpacedBytes(line);
		cout << " " << hexToAscii(line) << endl;
	}


	return 0;
}

