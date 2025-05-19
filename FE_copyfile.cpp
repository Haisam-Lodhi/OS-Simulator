#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
 
int main()
{
    string line;
    //For writing text file
    //Creating ofstream & ifstream class object
    
    string source,dest;
    std::cout << "Enter the source file: ";
    std::cin >> source;
    std::cout << "Enter the destination file: ";
    std::cin >> dest;


    ifstream ini_file {source};
    ofstream out_file {dest};
 
    if(ini_file && out_file){
 
        while(getline(ini_file,line)){
            out_file << line << "\n";
        }
 
        cout << "Copy Finished \n";
 
    } else {
        //Something went wrong
        printf("Cannot read File");
    }
 
    //Closing file
    ini_file.close();
    out_file.close();
 
    return 0;
}