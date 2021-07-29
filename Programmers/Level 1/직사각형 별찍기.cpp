#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    int i = 1;
    cin >> a >> b;
    while(i <= a*b)
    {
        cout << "*";
        if( i % a == 0) cout << endl;
        i++;
    }
    return 0;
}
