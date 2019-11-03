#include <iostream>

using namespace std;

int main()
{
    float tablica[5];
    float srednia=0;


    for(int i=0;i<=4;i++)cin>>tablica[i];

    for(int i=0;i<=4;i++)
    {
        srednia += tablica[i];
    }

    cout<<srednia/5<<endl;



    return 0;
}
