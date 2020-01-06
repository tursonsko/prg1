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
    cout << "3 - KOLEJNY MIESIĄC" << endl;
    cout << "INNY KLAWISZ - WYJŚCIE" << endl;

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
        cout << "opcja 2" << endl; 
        break;
    case 3:
        cout << "opcja 3" << endl; 
        break;
    default:
        break;
    }
}


void changeMonth()
{

}


void firstClientMenu()
{

}


void secondClientMenu()
{
    
}


//KREDYT
void takeCredit( double &client, double &clientCredit, double &clientCreditIntallment)
{
    double creditAmount;
    double totalCreditAmount;
    int num;
    double installment;
    double interest = 0.16;
    double bankCharge = 0.08;

    cout << "Jaka kwota kredytu?" << endl;
    cin >> creditAmount;
    creditAmount = floorl(creditAmount*100)/100;

    if(creditAmount <= 0)
    {
        cout << "Nie zaciągasz kredytu w tym miesiącu" << endl;
        return;
    } else {
        //KWOTA KREDYTU Z OPROCENTOWANIEM I OPLATA BANKOWA
        totalCreditAmount = creditAmount + floorl((creditAmount * interest)*100)/100 + floorl((creditAmount * bankCharge)*100)/100;

        //PRZYPISANIE KREDYTU ORAZ RATY KREDYTU KLIENTOWI
        client += creditAmount;
        clientCredit += totalCreditAmount;

        do {
            cout << "Na ile rat rozłożyć kredyt?" <<endl;
            cin >> num;
        } while (num <= 0);
        
        installment = floorl((totalCreditAmount/num)*100)/100;

        //PRZYPISANIE RATY KREDYTU KLIENTOWI
        clientCreditIntallment += num;
        
        cout << "Łączna kwota kredytu na kwotę " << creditAmount << " zł wynosi " << totalCreditAmount << " zł" << endl;
        cout << "Rata kredytu wynosi " << installment << " zł" << endl;
        cout << "RRSO 16% kredytu wynosi " << floorl((creditAmount * interest)*100)/100 << " zł" << endl;
        cout << "Opłata bankowa 8% wynosi " << floorl((creditAmount * bankCharge)*100)/100 << " zł" << endl;
        cout << "***************************************************" << endl;
        
    }

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
    cout << "Stan konta klienta wynosi: " << clientAmount << " zł" << endl;
}

//STAN KONTA OSZCZEDNOSCIOWEGO
void showSavingsBalance(double clientSavingsAmount)
{
    cout << "Stan konta osczędnościowego wynosi: " << clientSavingsAmount << " zł" << endl;
}

//ILOSC KREDYTU DO SPLACENIA
void showCreditAmount(double creditAmount)
{
    cout << "Zadłużenioe konta: " << creditAmount << " zł" << endl;
}

//ILOSC RAT KREDYTU DO SPLACENIA
void showCreditInstallments(double creditInstallments)
{
    cout << "Liczba rat pozostałych do końca spłaty kredytu: " << creditInstallments << endl;
}
