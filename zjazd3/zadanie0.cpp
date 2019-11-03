#include <iostream>
using namespace std;
int main()
{
int x[10];
for (int i=0; i<10; i++)
{
cin >> i;	
x[i] = i;
cout << x[i];
}
for (int j = 9; j>=0; j--)
{
cout << x[j] << endl;
}

return 0;
}
