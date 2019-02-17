/**
*  Program #1
*  A basic hexdump program that opens a binary or text file, read every byte in
*  the file and write both the ASCII hex value for that byte as well as it’s printable
*  character to standard output. For bytes forming non-printable characters, prints a ‘.’
*  character
*  CS 530 - 1
*  2/17/19
*  @author Blake Meyers cssc0430
*  @author Rahul Sharma XXXXXXXX
*/

#include "xbd.h"

using namespace std;

int main (int argc, char *argv[]) {

    if(strcmp(argv[1], "-b") == 0){
        handleBinary(argv[2]);
    }
    else{
        handleHex(argv[1]);
    }

    return 0;
}

/**
  * Dumps the file contents into hex format
**/
void handleHex (char file_in_name[]) {
    long int addr;
    unsigned char buffer[100];
    long int bufferCnt;
    long int indexCnt;
    ifstream file_in;
    long index;
    //
    //  Open the file.
    //
    file_in.open (file_in_name);

    if ( !file_in ) {
        cout << "\n";
        cout << "Cannot open \"" << file_in_name << "\"\n";
        return;
    }

    //
    //  Dump the file contents.
    //
    addr = 0;

    while (1) {
        file_in.read ((char *) buffer, 16 );

        bufferCnt = file_in.gcount();

        if (bufferCnt <= 0) {
            break;
        }
        //
        //  Print the address in decimal and hexadecimal.
        //
        cout << hex << setw(7) << setfill('0') << (int) addr << "  ";

        addr = addr + 16;
        //
        //  Print 16 data items, in pairs of 4, in hexadecimal.
        //
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
        //
        //  Print the printable characters, or a period if unprintable.
        //
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
        cout << "\n";
        cout << dec;

        if (file_in.eof( )) {
            break;
        }

    }
    //
    // Close the file.
    //
    file_in.close( );

    return;
}

/**
  * Dumps the file contents into binary format
**/
void handleBinary (char file_in_name[]) {
    long int addr;
    unsigned char buffer[100];
    long int bufferCnt;
    long int indexCnt;
    ifstream file_in;
    long index;
    //
    //  Open the file.
    //
    file_in.open (file_in_name);

    if (!file_in) {
        cout << "\n";
        cout << "Cannot open \"" << file_in_name << "\"\n";
        return;
    }

    //
    //  Dump the file contents.
    //
    addr = 0;

    while (1) {
        file_in.read ((char *) buffer, 6 );

        bufferCnt = file_in.gcount();

        if (bufferCnt <= 0) {
            break;
        }
        //
        //  Print the address in decimal and binary.
        //
        cout << hex << setw(7) << setfill( '0') << (int) addr << "  ";

        addr = addr + 6;
        //
        //  Print 6 data items in binary.
        //
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
        //
        //  Print the printable characters, or a period if unprintable.
        //
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
        cout << "\n";
        cout << dec;

        if (file_in.eof( )) {
            break;
        }

    }
    //
    // Close the file.
    //
    file_in.close( );

    return;
}
