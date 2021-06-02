#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Enter your full name: ";
    char name[50];
    cin.getline(name, 50); // taking whole line with spaces.

    //ClassName objName(constructor arguments)
    fstream myFileWrite("test.txt", ios::app);
    cout << "File named test.txt is opened in APPEND mode.... \n";

    cout << "Writing to file... \n";
    myFileWrite << name << "\n";

    cout << "Closing the file... \n\n";
    myFileWrite.close(); //closing the file

    fstream myFileRead("test.txt", ios::in);
    cout << "File named test.txt is opened in READ mode... \n";

    char readName[50];
    cout << "Reading from file... \n\n";

    cout << "File content: \n";
    while (myFileRead)
    {
        myFileRead.getline(readName, 50);
        cout << readName << endl;
    }

    cout << "Closing the file..." << endl;
    myFileRead.close(); //closing the file
}