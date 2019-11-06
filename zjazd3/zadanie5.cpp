#include <iostream>
using namespace std;

int main()
{
    string wyraz;
    int dl = 0;
    int palindrom = 1;
    
    
    cin >> wyraz;
        
    while(wyraz[dl] > 1)
    {
            dl++;
    }
    
    for (int i = 0; i<dl; i++)
    {
            if (wyraz[i]>=65 && wyraz[i]<=90)
            {
                    wyraz[i]+=32;
            }
    }
	dl--;
	
	for (int j = 0; j<dl; j++)
	{
		if(wyraz[j] != wyraz[dl])
		{
			palindrom = 0;
		}
		dl--;
	}

    cout << palindrom << endl;
        
    return 0;
}
