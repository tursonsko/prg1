#include <iostream>
using namespace std;
int main(){
//Zuzia Ciborowska
//Wojtek Turek
//Krzysztof Mierzejewski
int size;
cout<<"Podaj rozmiar ";
cin >>size;
int i;
int j;
for (i=1;i<=size+1;i++){
	for(j=size+1;j>i;j-- ){
		cout<<" ";
	}
cout<<"*";
cout<<endl;

}
return 0;}
