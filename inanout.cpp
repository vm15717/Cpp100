#include <iostream>
using namespace std;

int main(){
    int x, y;
    string str;
    cout << "May I know your name?:";
    getline(cin, str);
    cout << "Hello, " << str << endl; 
    cout << "Please enter two numbers:";
    cin >> x >> y;
    cout << x+y << endl;
    return 0;
}