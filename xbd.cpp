/**
 *  Program #1
 *  A basic hexdump program that opens a binary or text file, read every byte in
 *  the file and write both the ASCII hex value for that byte as well as it’s printable
 *  character to standard output. For bytes forming non-printable characters, prints a ‘.’
 *  character
 *  CS 530 - 1
 *  2/17/19
 *  @author Blake Meyers cssc0430
 *  @author Rahul Sharma cssc0417
 */

#include "xbd.h"

using namespace std;

/*
 * Checks to see if -b argument is entered
 * and calls the appropriate function for the output format.
 */
int main (int argc, char *argv[]) {

    if(strcmp(argv[1], "-b") == 0){
        handleBinary(argv[2]);
    }
    else{
        handleHex(argv[1]);
    }

    return 0;
}

/*
 * Converts the file contents into hex format
 */
void handleHex (char fileName[]) {
    unsigned char buffer[100];
    long int bufferCnt;
    long int indexCnt;
    long int address;
    ifstream fileIn;
    long index;

    //  Open the file.
    fileIn.open (fileName);

    if (!fileIn) {
        cout << endl;
        cout << "Cannot open \"" << fileName << "\"" << endl;
        return;
    }

    //  Dump the file contents.
    address = 0;

    while(cin.good()) {
        fileIn.read ((char *) buffer, 16 );

        bufferCnt = fileIn.gcount();

        if (bufferCnt <= 0) {
            break;
        }

        //  Prints the address in hexadecimal.
        cout << hex << setw(7) << setfill('0') << (int) address << "  ";
        address = address + 16;

        //  Print 16 data items in hexadecimal with 16 bits in one column.
        indexCnt = 0;
        for (index = 0; index < 16; index++) {
            indexCnt = indexCnt + 1;
            if (indexCnt <= bufferCnt) {
                cout << hex << setw(2) << setfill ('0') << (int) buffer[index];
            }
            else {
                cout << "  ";
            }
            if(indexCnt % 2 ==0)
                cout << " ";
        }

        cout << setfill (' ');

        //  Prints printable characters or a period otherwise.
        cout << " ";
        indexCnt = 0;
        for (index = 0; index < 16; index++) {
            indexCnt = indexCnt + 1;
            if (indexCnt <= bufferCnt) {
                if (buffer[index] < 32 || 126 < buffer[index]) {
                    cout << '.';
                }
                else {
                    cout << buffer[index];
                }
            }
        }
        cout << endl;
        cout << dec;
    }

    // Close the file
    fileIn.close( );

    return;
}

/*
 * Converts the file contents into binary format
 */
void handleBinary (char fileName[]) {
    long int address;
    unsigned char buffer[100];
    long int bufferCnt;
    long int indexCnt;
    ifstream fileIn;
    long index;

    //  Open the file.
    fileIn.open (fileName);

    if (!fileIn) {
        cout << endl;
        cout << "Cannot open \"" << fileName << "\"" << endl;
        return;
    }

    //Dump the file contents.
    address = 0;

    while(cin.good()) {
        fileIn.read ((char *) buffer, 6 );

        bufferCnt = fileIn.gcount();

        if (bufferCnt <= 0) {
            break;
        }

        //Prints the address in Hex.
        cout << hex << setw(7) << setfill( '0') << (int) address << "  ";
        address = address + 6;

        //Print 6 data items in binary with 8 bits each.
        indexCnt = 0;
        for (index = 0; index < 6; index++) {
            indexCnt = indexCnt + 1;
            if(indexCnt <= bufferCnt) {
                cout << bitset<8>((int) buffer[index]);
            }
            else {
                cout << "        ";
            }
            cout << " ";
        }

        cout << setfill (' ');

        //  Prints printable characters or a period otherwise.
        cout << " ";
        indexCnt = 0;
        for (index = 0; index < 6; index++) {
            indexCnt = indexCnt + 1;
            if (indexCnt <= bufferCnt) {
                if (buffer[index] < 32 || 126 < buffer[index]) {
                    cout << '.';
                }
                else {
                    cout << buffer[index];
                }
            }
        }
        cout << endl;
        cout << dec;
    }

    // Close the file.
    fileIn.close( );

    return;
}
