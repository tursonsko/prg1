#include <iostream>
using namespace std; int main() {
    string ch;
    cin >> ch;
    int i=0;
    while(ch[i]>0){
        if(ch[i]<97){
            ch[i]+=32;
        }
        i++;
    }
    cout<<ch<<endl;
    
    
    return 0;
}
