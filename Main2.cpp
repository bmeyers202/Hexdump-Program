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
//Get Address function already created
//R: Create Ascii to binary function, call binarySpacedBytes function to space bytes
//R: Create binary to hex function(Ascii to bianry then to hex), call hexSpacedBytes function to space bytes

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
  

  if(strcmp(argv[1], "-b") == 0){
	  isBinaryOutput = true;
	  ifstream myfile (argv[2]);
	  findIfTextFile(argv[2], ".txt");
  }
  else{
	  ifstream myfile (argv[1]);
	  findIfTextFile(argv[1], ".txt");
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
	if(isTextFile==true){
		if (isBinaryOutput == true){
			//R: Make call for Ascii to Binary function that you create
			binarySpacedBytes(line);
			cout << " " << (line) << endl;
		}
		else{
			hexSpacedBytes(line);
			//R: Make call for Ascii to hex function that you create
			cout << " " << (line) << endl;
		}

	}


	return 0;
}

