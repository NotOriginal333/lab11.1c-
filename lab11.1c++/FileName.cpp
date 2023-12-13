#include <iostream> 
#include <fstream> 

using namespace std;

void CreateBIN(char* fname) {
    ofstream fout(fname, ios::binary);

    int num;
    char ch;
    do {
        cout << "Enter number: ";
        cin >> num;
        fout.write(reinterpret_cast<const char*>(&num), sizeof(num));

        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}

void PrintBIN(char* fname) {
    ifstream fin(fname, ios::binary);
    int num;

    while (fin.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        cout << num << endl;
    }
    std::cout << std::endl;
}

void ProcessBIN1(char* fname, char* gname) {
    ifstream f(fname, ios::binary);
    ofstream g(gname, ios::binary);

    int num, sum = 0;
    while (f.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        if (num < 0) {
            sum += num;
            g.write(reinterpret_cast<const char*>(&sum), sizeof(sum));
        }
    }
}

int main() {
    char fname[100];
    cout << "Enter file name 1: ";
    cin >> fname;

    CreateBIN(fname);
    PrintBIN(fname);

    char gname[100];
    cout << "Enter file name 2: ";
    cin >> gname;

    ProcessBIN1(fname, gname);
    PrintBIN(gname);

    return 0;
}
