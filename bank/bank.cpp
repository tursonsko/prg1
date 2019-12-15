#include <iostream>
#include <math.h>

using namespace std;

double client1 = 0;
double client2 = 0;

double clientSave1 = 0;
double clientSave2 = 0;

double addMoney(double &x);
double substractMoney(double &x);

void transferMoney(double &x, double &y);
void showDeposit(double x);

int main()
{
    addMoney(client1);
    cout<<endl;
    showDeposit(client1);
    cout<<"********************************************"<<endl;

    substractMoney(client1);
    cout<<endl;
    showDeposit(client1);
    cout<<"********************************************"<<endl;

    transferMoney(client1, client2);
    cout<<endl;
    showDeposit(client1);
    showDeposit(client2);
    cout<<"********************************************"<<endl;

    return 0;
}

double addMoney(double &x)
{
    double y;

    cout<<"Podaj kwotę, którą wczesz wpłacić"<<endl;
    cin >> y;
    double z = floorl(y*100)/100;
    if (y>0)
    {
        x=floorl((x+z)*100)/100;
    }
    return x;
}

double substractMoney(double &x)
{
    double y;
    
    cout<<"Podaj kwotę, którą wczesz wypłacić"<<endl;
    cin >> y;
    double z = floorl(y*100)/100;

    if (y>x)
    {
        cout << "Nie masz wystarczających środków na koncie" << endl;
    } else 
    {
        if(y>0)
        {
            x-=z;
            return floorl(x*100)/100;
        }
    }
}

void transferMoney(double &x, double &y)
{
    double z;

    cout << "Podaj kwotę, którą chcesz przekazać innemu Klientowi"<<endl;
    cin >> z;

    if (floorl(z*100)/100 > x)
    {
        cout << "Nie masz wystatrczającej ilości środków na koncie" << endl;
    } else
    {
        if(z>0)
        {
            x-=floorl(z*100)/100;
            y+=floorl(z*100)/100;
        }
    }
}



void showDeposit(double x)
{
    cout << "Stan konta klienta wynosi " << x << endl;
}

