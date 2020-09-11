#include <iostream>
using namespace std;

int main()
{
    int data_size;
    cin >> data_size;
    int data[data_size][2];
    for(int i=0; i<data_size; ++i)
    {
        int a, b;
        cin >> data[i][0] >> data[i][1];
        cout << data[i][0] << data[i][1];
    }
    // cout << data[0][0] << endl;
    return 0;
}