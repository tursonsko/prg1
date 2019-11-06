#include <iostream>

using namespace std;

int main()
{
    int st1[5], st2[5], st3[5], st4[5], st5[5];
    float st1_wynik = 0;
    float st2_wynik = 0;
    float st3_wynik = 0;
    float st4_wynik = 0;
    float st5_wynik = 0;
    float srednia;
    
    for ( int i = 0; i<5; i++)
    {
        cin >> st1[i];
        st1_wynik+=st1[i];
    }
    
    for ( int i = 0; i<5; i++)
    {
        cin >> st2[i];
        st2_wynik+=st2[i];
    }
    
    for ( int i = 0; i<5; i++)
    {
        cin >> st3[i];
        st3_wynik+=st3[i];
    }
    
    for ( int i = 0; i<5; i++)
    {
        cin >> st4[i];
        st4_wynik+=st4[i];
    }
    
    for ( int i = 0; i<5; i++)
    {
        cin >> st5[i];
        st5_wynik+=st5[i];
    }
    
    srednia = (st1_wynik+st2_wynik+st3_wynik+st4_wynik+st5_wynik)/25;
    cout << srednia << endl;
    
    if(st1_wynik/5 > srednia)
    {
        cout << "1" << endl;
    }
    
    if(st2_wynik/5 > srednia)
    {
        cout << "2" << endl;
    }
    
    if(st3_wynik/5 > srednia)
    {
        cout << "3" << endl;
    }
    
    if(st4_wynik/5 > srednia)
    {
        cout << "4" << endl;
    }
    
    if(st5_wynik/5 > srednia)
    {
        cout << "5" << endl;
    }
        
    return 0;
}
