#include <iostream>
using namespace std;

int main(){

    int tab[3][3]= {0,0,0,0,0,0,0,0,0};
    int i,x,j,k=0;
    
    while(1) {
        cin >> x ;
        i = (x-1)/3;
        j=(x-1)%3;
        if(tab[i][j]){
            break;
        }
    tab[i][j] = ((k++)%2==1 )  ? 2: 1;
        
    }
cout << 0;
 return 0;   
}
