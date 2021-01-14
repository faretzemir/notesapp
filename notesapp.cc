#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string txtFileType = {".txt"};
int EXIT = 0000;
string ENDLINE = "XXXX";

class File{
  public:
    File(){}
    void noteCreation();
    void noteRead();
};

void File::noteCreation(){

    stringstream ss;
    string noteLine, fileName;

    cout << "Please enter a file name." << endl;
    cin >> fileName;
    cout << endl;

    ofstream myfile;
    myfile.open (fileName + txtFileType);
    cout << "Please enter notes to be taken:" << endl;
    cout << "Enter XXXX to exit." << endl;

    while (noteLine != "XXXX"){
        cin >> noteLine;
        myfile << noteLine;
        myfile << endl;
    }
    cout << endl;
    myfile.close();
}

void File::noteRead(){
  string line, fileName;
  cout << "Please enter file name to be opened." << endl;
  cin >> fileName;
  cout << endl;
  ifstream myfile (fileName + txtFileType);

  if (myfile.is_open())
  {
    cout << fileName + txtFileType << ":";
    while (! myfile.eof() )
    {
      getline(myfile,line);
      cout << line << endl;
    }
    myfile.close();
  }
  else cout << "Unable to open file." << endl;
  
}

int main(){

    int selection;
    File f;

while(selection != EXIT){

    cout << "Welcome to the Note-taking app." << endl;
    cout << "Enter a number to begin." << endl;
    cout << "Enter 0000 to exit" << endl;
    cout << "1. Take notes." << endl;
    cout << "2. Read notes." << endl;
    cin >> selection;
    cout << endl;

    switch(selection){

        case 1:
            f.noteCreation();
            break;

        case 2:
            f.noteRead();
            break;
    }
}
    return 0;

}