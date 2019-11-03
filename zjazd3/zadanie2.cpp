#include <iostream>
using namespace std; 
int main() {
    float oceny[5];
	int tmp = 0;
    float srednia;
    int i,j;

    
    for(i =0; i<5; i++){
oceny[i]=0;
        for(j = 0; j<5; j++){
            cin >> tmp;
		srednia = oceny[i]+tmp;

        }
	srednia=srednia/5;
	cout<<srednia <<endl;
    }


    return 0;
}
