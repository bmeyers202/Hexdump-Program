# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
#include <string.h>
//# include <ctime>

using namespace std;

int main ( int argc, char *argv[] );
void handleHex ( char file_in_name[] );
bool findIfTextFile (string fileName, string fileExt);

int main ( int argc, char *argv[] ) {

	if(strcmp(argv[1], "-b") == 0){
	  //make binary function call
	}
	else{
	  handleHex(argv[1]);
	}

    //  Get the file from the argument list.

    for (int i = 1 ; i < argc ; ++i ) {
         handleHex ( argv[i] );
    }

    return 0;
}
//****************************************************************************80

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
        //  Print 16 data items, in pairs, in hexadecimal.
        //
        cnt2 = 0;
        for ( n = 0; n < 16; n++ ) {
            cnt2 = cnt2 + 1;
            if ( cnt2 <= cnt ) {
            	cout << hex << setw(2) << setfill ( '0' ) << ( int ) buffer[n];
            	cout << hex << setw(2) << setfill ( '0' ) << ( int ) buffer[++n];
            }
            else {
                cout << "__";
            }
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

bool findIfTextFile (string fileName, string fileExt) {
    if (fileName.length() >= fileExt.length()) {
        return (0 == fileName.compare (fileName.length() - fileExt.length(), fileExt.length(), fileExt));
    } else {
        return false;
    }
}
