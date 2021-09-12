/*************************************************************************
    The purpose of this little program is allow you to test the input
    and output functions and operators that you have written for the
    Check class. You should write these BEFORE you start developing the
    Checkbook class, and you should test your functions by compiling 
    and running this little main.
	John Dolan          Ohio University EECS	September 2019
    Patricia Lindner    Ohio University EECS    August 2021
*************************************************************************/

#include<fstream>
#include <string>
#include "check.h"
using namespace std;

int main(){
    Check c1, c2;
    ifstream ifs;
    ofstream ofs;
    string file_name;
    string output_file;

    cout<<"Enter file name: ";
    cin >> file_name;
    ifs.open(file_name);
    if (ifs.fail()){
        cout << "error";
        exit(0);
    }
    ifs>>c2;
    ifs.close();

    output_file = file_name.insert(file_name.find("."), "output");
    ofs.open(output_file);
    ofs<<c2;
    ofs.close();
    cout << "File " << output_file << " was created." << endl;

    cout<<"Write a check.\n";
    cin>>c1;
    cout<<c1;

    return 0;
}
