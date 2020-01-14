
#include <iostream>
using namespace std; int main() {
    
    int tabOne[3][3];
    int tabTwo[3][3];
    int tabThree[3][3]; 

   for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>tabOne[i][j];

        }
}

   for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>tabTwo[i][j];
	    
        }
}

    for(int i =0; i<3; i++){

        for(int j=0; j<3; j++){
	    tabThree[i][j]=0;        	
		for(int k=0; k<3 ; k++){

		  tabThree[i][j] = tabThree[i][j] + tabOne[i][k] * tabTwo[k][j];   
        }
    }
}
     
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<tabThree[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}
