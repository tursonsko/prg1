#include <iostream>
#include <math.h>

using namespace std;

double client1 = 0.0;
double client2 = 0.0;

double clientSave1 = 0.0;
double clientSave2 = 0.0;

double clientCredit1 = 0.0;
double clientCredit2 = 0.0;

double clientCreditInstallment1 = 0.0;
double clientCreditInstallment2 = 0.0;

double creditInstallmentMonthly1 = 0.0;
double creditInstallmentMonthly2 = 0.0;


double addMoney(double &clientAmount);
double substractMoney(double &clientAmount);

void mainMenu();
void takeCredit(double &client, double &clientCredit, double &clientCreditInstallment, double &creditInstallmentMonthly);
void transferMoney(double &giver, double &recipient);
void transferToSavingsAccount(double &debitCount, double &savingsCount);

void showDeposit(double clientAmount);
void showSavingsBalance(double clientSavingsAmount);
void showCreditAmount(double creditAmount);
void showCreditInstallments(double creditInstallments);
void showCreditAmountMonthly(double creditAmountMonthly);

void changeMonth(double &client, double &clientSave, double &clientCredit, double &creditInstallmentMonthly, double &clientCreditInstallment);


int main()
{
    
    mainMenu();


    return 0;
}   


//MENU GLOWNE
void mainMenu()
{
    while(true)
    {
        int y;
        cout << "WITAJ W TUREKBANK!"<< endl;
        cout << "WYBIERZ KLIENTA I ZATWIERDŹ NACISKAJĄC 'ENTER'" << endl;
        cout << "1 - KLIENT 1" << endl;
        cout << "2 - KLIENT 2" << endl;
        cout << "3 - KOLEJNY MIESIĄC" << endl;
        cout << "INNY KLAWISZ - POWROT DO MENU GŁÓWNEGO" << endl;

        cin >> y;
        // system("clear");

        switch(y)
        {
        case 1:
            cout << "**************************************" << endl;
            cout << "\nKlient 1\n" << endl;
            takeCredit(client1, clientCredit1, clientCreditInstallment1, creditInstallmentMonthly1);
            //changeMonth(client1, clientSave1, clientCredit1, creditInstallmentMonthly1, clientCreditInstallment1);

            // showDeposit(client1);
            // showCreditAmount(clientCredit1);
            // showCreditInstallments(clientCreditInstallment1);
            // showCreditAmountMonthly(creditInstallmentMonthly1);
            // addMoney(client1);
            // transferMoney(client1, client2);
            break;
        case 2:
            cout << "**************************************" << endl;
            cout << "\nKlient 2\n" << endl;
            showDeposit(client2);
            
            break;
        case 3:
            changeMonth(client1, clientSave1, clientCredit1, creditInstallmentMonthly1, clientCreditInstallment1);
            //cout << "opcja 3" << endl; 
            //break;
        default:
            break;
        }
        
    }
    
}

void changeMonth(double &client, double &clientSave, double &clientCredit, double &creditInstallmentMonthly, double &clientCreditInstallment)
{
    clientSave = floorl((clientSave*1.02)*100)/100;
    
    if(clientCredit > 0 && clientCreditInstallment > 0)
    {
        clientCredit = floorl((clientCredit - creditInstallmentMonthly)*100)/100;
        client = floorl((client - creditInstallmentMonthly)*100)/100;
        clientCreditInstallment--;
        
        showDeposit(client1);
        showCreditAmount(clientCredit1);
        showCreditInstallments(clientCreditInstallment1);
        showCreditAmountMonthly(creditInstallmentMonthly1);
    }
}

void firstClientMenu()
{

}

void secondClientMenu()
{
    
}

//KREDYT

void takeCredit( double &client, double &clientCredit, double &clientCreditInstallment, double &creditInstallmentMonthly)
{
    int num;
    double creditAmount;
    double totalCreditAmount;
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
        totalCreditAmount = creditAmount + creditAmount * interest + creditAmount * bankCharge;

        //PRZYPISANIE KREDYTU ORAZ RATY KREDYTU KLIENTOWI
        client += creditAmount;
        clientCredit += totalCreditAmount;

        do {
            cout << "Na ile rat rozłożyć kredyt?" <<endl;
            cin >> num;
        } while (num <= 0);
        
        installment = floorl((totalCreditAmount/num)*100)/100;

        //PRZYPISANIE ILOŚCI RAT KREDYTU KLIENTOWI
        clientCreditInstallment += num;

        creditInstallmentMonthly += installment;
        
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
    cout << "Zadłużenie wynosi: " << creditAmount << " zł" << endl;
}

//ILOSC RAT KREDYTU DO SPLACENIA
void showCreditInstallments(double creditInstallments)
{
    cout << "Liczba rat pozostałych do końca spłaty kredytu: " << creditInstallments << endl;
}

//WYSOKOSC RATY KREDYTU
void showCreditAmountMonthly(double creditAmountMonthly)
{
    cout << "Wysokość miesięcznej raty kredytu wynosi: " << creditAmountMonthly << endl;
}

