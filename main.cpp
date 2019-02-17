# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
//# include <ctime>

using namespace std;

int main ( int argc, char *argv[] );
void handle ( char file_in_name[] );

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


int main ( int argc, char *argv[] )



{
    char file_in_name[80];
    int i;
    bool VERBOSE = true;
    
    if ( VERBOSE )
    {
       
        
        cout << "\n";
        cout << "HEXDUMP:\n";
        cout << "  C++ version\n";
        cout << "\n";
        cout << "  Compiled on " << __DATE__ << " at " << __TIME__ << ".\n";
        cout << "\n";
        cout << "  Produce a hexadecimal dump of a file.\n";
    }
    //
    //  If the input file was not specified, get it now.
    //
    if ( argc <= 1 )
    {
        cout << "\n";
        cout << "HEXDUMP:\n";
        cout << "  Please enter the name of a file to be analyzed.\n";
        
        cin.getline ( file_in_name, sizeof ( file_in_name ) );
        
        handle ( file_in_name );
    }
    //
    //  Otherwise, get the file(s) from the argument list.
    //
    else
    {
        for ( i = 1 ; i < argc ; ++i )
        {
            handle ( argv[i] );
        }
    }
    
    if ( VERBOSE )
    {
        cout << "\n";
        cout << "HEXDUMP:\n";
        cout << "  Normal end of execution.\n";
        
        cout << "\n";
        //timestamp ( );
    }
    
    return 0;
}
//****************************************************************************80

void handle ( char file_in_name[] )



{
    long int addr;
    unsigned char buffer[20];
    long int cnt;
    long int cnt2;
    ifstream file_in;
    long n;
    //
    //  Open the file.
    //
    file_in.open ( file_in_name );
    
    if ( !file_in )
    {
        cout << "\n";
        cout << "HANDLE - Fatal error!\n";
        cout << "  Cannot open \"" << file_in_name << "\"\n";
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
    
    while ( 1 )
    {
        file_in.read ( ( char * ) buffer, 16 );
        
        cnt = file_in.gcount();
        
        if ( cnt <= 0 )
        {
            break;
        }
        //
        //  Print the address in decimal and hexadecimal.
        //
        cout << setw(7) << ( int ) addr << "  ";
        
        addr = addr + 16;
        //
        //  Print 16 data items, in pairs, in hexadecimal.
        //
        cnt2 = 0;
        for ( n = 0; n < 16; n++ )
        {
            cnt2 = cnt2 + 1;
            if ( cnt2 <= cnt )
            {
                cout << hex << setw(2) << setfill ( '0' ) << ( int ) buffer[n];
                cout << hex << setw(2) << setfill ( '0' ) << ( int ) buffer[++n];
            }
            else
            {
                cout << "__";
            }
        }
        
        cout << setfill ( ' ' );
        //
        //  Print the printable characters, or a period if unprintable.
        //
        cout << " ";
        cnt2 = 0;
        for ( n = 0; n < 16; n++ )
        {
            cnt2 = cnt2 + 1;
            if ( cnt2 <= cnt )
            {
                if ( buffer[n] < 32 || 126 < buffer[n] )
                {
                    cout << '.';
                }
                else
                {
                    cout << buffer[n];
                }
            }
        }
        cout << "\n";
        cout << dec;
        
        if ( file_in.eof ( ) )
        {
            break;
        }
        
    }
    //
    // Close the file.
    //
    file_in.close ( );
    
    return;
}
