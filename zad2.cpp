#include <iostream>

using namespace std;

int main()
{
	int size, i, j;

	cout << "Podaj rozmiar ";
	cin >> size;
	
	for ( i = 1; i <= size + 1; i++ )
	{
		for( j = size + 1; j>i; j-- )
		{
			cout << " ";
		}
		
		cout << "*";
		cout << endl;
	}

	// for ( i = 1; i <= size; i++ )
	// {
	// 	for( j = size; j>i; j-- )
	// 	{
	// 		cout << " ";
	// 	}
		
	// 	cout << "*";
	// 	cout << endl;
	// }


return 0;
}
