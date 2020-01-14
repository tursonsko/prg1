
#include <iostream>
using namespace std; int main() {
    
    int tabOne[3][3];
    int tabTwo[3][3];
    int tabSum[3][3];

    for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>tabOne[i][j];
            
        }
    }

    for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>tabTwo[i][j];
            tabSum[i][j]=tabOne[i][j] + tabTwo[i][j];
        }
    }
    
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<tabSum[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}
