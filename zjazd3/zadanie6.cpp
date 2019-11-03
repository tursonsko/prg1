#include <iostream>
using namespace std; int main() {
    
    int tab[3][3];
    
    for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>tab[i][j];
            
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<tab[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}
