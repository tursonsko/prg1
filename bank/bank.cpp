#include <iostream>
#include <math.h>

using namespace std;

double client1 = 0.0;
double client2 = 0.0;

double clientSave1 = 0.0;
double clientSave2 = 0.0;

double clientCredit1 = 0.0;
double clientCredit2 = 0.0;

double clientCreditIntallment1 = 0.0;
double clientCreditIntallment2 = 0.0;



double addMoney(double &clientAmount);
double substractMoney(double &clientAmount);

void mainMenu();
void takeCredit(double &client, double &clientCredit, double &clientCreditIntallment);
void transferMoney(double &giver, double &recipient);
void transferToSavingsAccount(double &debitCount, double &savingsCount);

void showDeposit(double clientAmount);
void showSavingsBalance(double clientSavingsAmount);
void showCreditAmount(double creditAmount);
void showCreditInstallments(double creditInstallments);


int main()
{
    
    mainMenu();


    return 0;
}   


//MENU GLOWNE
void mainMenu()
{
    int y;
    cout << "WITAJ W TUREKBANK!"<< endl;
    cout << "WYBIERZ KLIENTA" << endl;
    cout << "1 - KLIENT 1" << endl;
    cout << "2 - KLIENT 2" << endl;

    cin >> y;

    switch(y)
    {
    case 1:
        takeCredit(client1, clientCredit1, clientCreditIntallment1);
        showDeposit(client1);
        showCreditAmount(clientCredit1);
        showCreditInstallments(clientCreditIntallment1);
        addMoney(client1);
        break;
    case 2:
        // 
        break;
    default:
        break;
    }
}

//KREDYT

void takeCredit( double &client, double &clientCredit, double &clientCreditIntallment)
{
    double creditAmount;
    double totalCreditAmount;
    double num;
    double installment;
    double interest = 1.16;

    cout << "Jaka kwota kredytu?" << endl;
    cin >> creditAmount;
    //KWOTA KREDYTU Z OPROCENTOWANIEM
    totalCreditAmount = creditAmount * interest;

    //PRZYPISANIE KREDYTU ORAZ RATY KREDYTU KLIENTOWI
    client += creditAmount;
    clientCredit += totalCreditAmount;

    //cout << "kwota kredytu " << amount << endl;

    
    cout << "Ile rat kredytu?" <<endl;
    cin >> num;

    installment = totalCreditAmount/num;

    //PRZYPISANIE RATY KREDYTU KLIENTOWI
    clientCreditIntallment += num;
     
    cout << "Rata kredytu wynosi " << installment << endl;


}


// WPLATA NA KONTO
double addMoney(double &clientAmount)
{
    double y;

    cout<<"Podaj kwotę, którą chcesz wpłacić na konto"<<endl;
    cin >> y;
    double z = floorl(y*100)/100;
    if (z>0)
    {
        clientAmount+=z;
    }
    return clientAmount;
}

//WYPLATA Z KONTA
double substractMoney(double &clientAmount)
{
    double y;
    
    cout<<"Podaj kwotę, którą chcesz wypłacić z konta"<<endl;
    cin >> y;
    double z = floorl(y*100)/100;

    if (y>clientAmount)
    {
        cout << "Nie masz wystarczających środków na koncie" << endl;
    } else 
    {
        if(y>0)
        {
            clientAmount-=z;
            return floorl(clientAmount*100)/100;
        }
    }
}




//PRZELEW Z KONTA NA KONTO
void transferMoney(double &giver, double &recipient)
{
    double z;

    cout << "Podaj kwotę, którą chcesz przekazać innemu Klientowi" << endl;
    cin >> z;

    if (floorl(z*100)/100 > giver)
    {
        cout << "Nie masz wystatrczającej ilości środków na koncie" << endl;
    } else
    {
        if(z>0)
        {
            giver-=floorl(z*100)/100;
            recipient+=floorl(z*100)/100;
        }
    }
}


//PRZELEW NA KONTO OSZCZEDNSOCIOWE
void transferToSavingsAccount(double &debitCount, double &savingsCount)
{
    double z;

    cout << "Podaj kwotę, którą chcesz przelać na konto oszczędnościowe" << endl;
    cin >> z;

    if(floorl(z*100)/100 < 0)
    {
        cout << "Nie możesz przelać ujemnej kwoty!";
    } else 
    {
        debitCount-= floorl(z*100)/100;
        savingsCount += floorl(z*100)/100;
    }

}


//WYCIAG Z KONTA

//STAN KONTA ROR
void showDeposit(double clientAmount)
{
    cout << "Stan konta klienta wynosi " << clientAmount << endl;
}

//STAN KONTA OSZCZEDNOSCIOWEGO
void showSavingsBalance(double clientSavingsAmount)
{
    cout << "Stan konta osczędnościowego wynosi " << clientSavingsAmount << endl;
}

//ILOSC KREDYTU DO SPLACENIA
void showCreditAmount(double creditAmount)
{
    cout << "Pozostała kwota kredytu to: " << creditAmount << endl;
}

//ILOSC RAT KREDYTU DO SPLACENIA
void showCreditInstallments(double creditInstallments)
{
    cout << "Pozostało " << creditInstallments << " rat do końca spłaty kredytu" << endl;
}


