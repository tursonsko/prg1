#include <iostream>
using namespace std;
//Zuzia Ciborowska
//Wojtek Turek
//Krzysztof Mierzejewski
int main (){
cout<<"Podaj liczbe ";
int i,j;
cin>>i;
do {
	cout<<"Podaj liczbe ";
	cin>>j;
	if(j<i){
		cout<<"za mało!\n";}
	if(j>i)
	{
		cout<<"za dużo!\n";
}
}while(i!=j);
cout<<"wow zgadłeś\n";
return 0;
}
