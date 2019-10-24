#include <iostream>

using namespace std;

int main()
{
	int size;
	int x = 1;

	cout << "Podaj rozmiar ";
	cin >> size;	

	
	for ( int i = 0; i <= size; i++ )
  	{
    	for (int j = size; j > i; j-- )
    	{
      		cout << " ";
    	}

    	cout << "#";

    	if ( i > 0 )
    	{
      		for ( int k = 1; k <= x; k++ )
      		{
        		cout << " ";
      		}
      		x+=2;
      		cout << "^";
    	}
    
    cout << endl;

    }

	for ( int i = 1; i < size+1; i++ ) 
	{
	    for ( int k = 0; k < i; k++ )
	    {
	    	cout << "+";
	    }
	    cout << "^";

	    for( int j = 0 ; j <= x-5; j++ )
	    {
	    	cout << "+";
	    }
	    x-=2;

	    if ( i != size )
	    {
	    	cout << "#";
	    }

	    cout << endl;
	}
		
return 0;

}
