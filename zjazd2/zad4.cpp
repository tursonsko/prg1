#include <iostream>
//Zuzia Ciborowska
//Wojtek Turek
//Krzysztof Mierzejewski
using namespace std;
int main (){
int x,y;
cout<<"Podaj liczbe ";
cin>>x;
y=x;
while(x!=0)
{
cout<<"Podaj liczbe ";
cin>>x;
y=y+x;}
cout<<"Suma jest równa: "<<y<<endl;
return 0;
}
