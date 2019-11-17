#include <iostream>
using namespace std; int main() {
    string napis;
    int dl =0;
    
    cin >> napis;
    // do{
    // dl++;
    // cout<< napis[dl];
    // }while(napis[dl++]>0);
    while(napis[dl] > 0){
        dl++;
    }
    for(int j = dl; j>=0; j--) {
        cout << napis[j];
    }
    
    
    
    return 0;
}
