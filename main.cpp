# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
#include <string.h>
#include <bitset>

using namespace std;

int main ( int argc, char *argv[] );
void handleHex ( char file_in_name[] );
void handleBinary ( char file_in_name[] );
bool findIfTextFile (string fileName, string fileExt);

int main ( int argc, char *argv[] ) {
    
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
void handleHex ( char file_in_name[] ) {
    long int addr;
    unsigned char buffer[100];
    long int cnt;
    long int cnt2;
    ifstream file_in;
    long n;
    //
    //  Open the file.
    //
    file_in.open ( file_in_name);
    
    if ( !file_in ) {
        cout << "\n";
        cout << "Cannot open \"" << file_in_name << "\"\n";
        return;
    }
    
    cout << "\n";
    cout << "Hexdump of \"" << file_in_name << "\":\n";
    cout << "\n";
    cout <<
    "Address               Hexadecimal values                  Printable\n";
    cout <<
    "-------  -----------------------------------------------  -------------\n";
    cout << "\n";
    //
    //  Dump the file contents.
    //
    addr = 0;
    
    while ( 1 ) {
        file_in.read ( ( char * ) buffer, 16 );
        
        cnt = file_in.gcount();
        
        if ( cnt <= 0 ) {
            break;
        }
        //
        //  Print the address in decimal and hexadecimal.
        //
        cout << hex << setw(7) << setfill( '0') << ( int ) addr << "  ";
        
        addr = addr + 16;
        //
        //  Print 16 data items, in pairs of 4, in hexadecimal.
        //
        cnt2 = 0;
        for ( n = 0; n < 16; n++ ) {
            cnt2 = cnt2 + 1;
            if ( cnt2 <= cnt ) {
                cout << hex << setw(2) << setfill ( '0' ) << ( int ) buffer[n];
            }
            else {
             cout << "  ";
            }
            if(cnt2 % 2 ==0)
            cout << " ";
        }
        
        cout << setfill ( ' ' );
        //
        //  Print the printable characters, or a period if unprintable.
        //
        cout << " ";
        cnt2 = 0;
        for ( n = 0; n < 16; n++ ) {
            cnt2 = cnt2 + 1;
            if ( cnt2 <= cnt ) {
                if ( buffer[n] < 32 || 126 < buffer[n] ) {
                    cout << '.';
                }
                else {
                    cout << buffer[n];
                }
            }
        }
        cout << "\n";
        cout << dec;
        
        if ( file_in.eof ( ) ) {
            break;
        }
        
    }
    //
    // Close the file.
    //
    file_in.close ( );
    
    return;
}

/**
  * Dumps the file contents into binary format
**/
void handleBinary ( char file_in_name[] ) {
    long int addr;
    unsigned char buffer[100];
    long int cnt;
    long int cnt2;
    ifstream file_in;
    long n;
    //
    //  Open the file.
    //
    file_in.open ( file_in_name);
    
    if ( !file_in ) {
        cout << "\n";
        cout << "Cannot open \"" << file_in_name << "\"\n";
        return;
    }
    
    cout << "\n";
    cout << "Hexdump of \"" << file_in_name << "\":\n";
    cout << "\n";
    cout <<
    "Address               Binary values                        Printable\n";
    cout <<
    "-------  -----------------------------------------------  -------------\n";
    cout << "\n";
    //
    //  Dump the file contents.
    //
    addr = 0;
    
    while ( 1 ) {
        file_in.read ( ( char * ) buffer, 6 );
        
        cnt = file_in.gcount();
        
        if ( cnt <= 0 ) {
            break;
        }
        //
        //  Print the address in decimal and binary.
        //
        cout << hex << setw(7) << setfill( '0') << ( int ) addr << "  ";
        
        addr = addr + 6;
        //
        //  Print 6 data items in binary.
        //
        cnt2 = 0;
        for ( n = 0; n < 6; n++ ) {
            cnt2 = cnt2 + 1;
            if ( cnt2 <= cnt ) {
                cout << bitset<8>(( int ) buffer[n]);
            }
            else {
                cout << "        ";
            }
            cout << " ";
        }
        
        cout << setfill ( ' ' );
        //
        //  Print the printable characters, or a period if unprintable.
        //
        cout << " ";
        cnt2 = 0;
        for ( n = 0; n < 6; n++ ) {
            cnt2 = cnt2 + 1;
            if ( cnt2 <= cnt ) {
                if ( buffer[n] < 32 || 126 < buffer[n] ) {
                    cout << '.';
                }
                else {
                    cout << buffer[n];
                }
            }
        }
        cout << "\n";
        cout << dec;
        
        if ( file_in.eof ( ) ) {
            break;
        }
        
    }
    //
    // Close the file.
    //
    file_in.close ( );
    
    return;
}


bool findIfTextFile (string fileName, string fileExt) {
    if (fileName.length() >= fileExt.length()) {
        return (0 == fileName.compare (fileName.length() - fileExt.length(), fileExt.length(), fileExt));
    } else {
        return false;
    }
}

