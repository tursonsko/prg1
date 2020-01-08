#include <iostream>
#include <math.h>
#include <iomanip>

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
void transferFromSavingsToDebitCount(double &savingsCount, double &debitCount);

void showDeposit(double clientAmount);
void showSavingsBalance(double clientSavingsAmount);
void showCreditAmount(double creditAmount);
void showCreditInstallments(double creditInstallments);
void showCreditAmountMonthly(double creditAmountMonthly);

void changeMonth(double &client, double &clientSave, double &clientCredit, double &creditInstallmentMonthly, double &clientCreditInstallment);
void preview(double client, double clientSave, double clientCredit, double clientCreditInstallment, double creditInstallmentMonthly);

void firstClientMenu();


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
        int option;
        cout << "\n********************************************************" << endl;
        cout << "\nWITAJ W TUREKBANK!"<< endl;
        cout << "ABY POPRAWNIE SKORZYSTAĆ Z NASZYCH USŁUG\nORAZ NIE SPOWODOWAĆ BŁĘDÓW PPROGRAMU\nSTOSUJ SIĘ DO ZALECEŃ" << endl;
        cout << "WYBIERZ KLIENTA I ZATWIERDŹ NACISKAJĄC 'ENTER'\n" << endl;
        cout << "[1] - KLIENT 1" << endl;
        cout << "[2] - KLIENT 2" << endl;
        cout << "[3] - KOLEJNY MIESIĄC" << endl;
        cout << "INNY KLAWISZ - POWROT DO MENU GŁÓWNEGO" << endl;

        cin >> option;
        // system("clear");

        switch(option)
        {
        case 1:
            system("clear");
            firstClientMenu();
            break;
        case 2:
            system("clear");
            //secondClientMenu();
            break;
        case 3:
            system("clear");
            changeMonth(client1, clientSave1, clientCredit1, creditInstallmentMonthly1, clientCreditInstallment1);
            changeMonth(client2, clientSave2, clientCredit2, creditInstallmentMonthly2, clientCreditInstallment2);
            //cout << "opcja 3" << endl; 
            //break;
        default:
            break;
        }
        
    }
    
}

//ZMIANA MIESIACA
void changeMonth(double &client, double &clientSave, double &clientCredit, double &creditInstallmentMonthly, double &clientCreditInstallment)
{
    clientSave = floorl((clientSave*1.02)*100)/100;
    
    if(clientCredit > 0 && clientCreditInstallment > 0)
    {
        clientCredit = floorl((clientCredit - creditInstallmentMonthly)*100)/100;
        client = floorl((client - creditInstallmentMonthly)*100)/100;
        clientCreditInstallment--;
        
        // cout << "\n********************************************************" << endl;
        // showCreditAmount(clientCredit1);
        // showCreditInstallments(clientCreditInstallment1);
        // showCreditAmountMonthly(creditInstallmentMonthly1);
    }
        // showDeposit(client1);
        // showSavingsBalance(clientSave1);
}

//PODGLAD KONTA
void preview(double client, double clientSave, double clientCredit, double clientCreditInstallment, double creditInstallmentMonthly)
{
    showDeposit(client);
    showSavingsBalance(clientSave);

    if(clientCredit > 0 && clientCreditInstallment > 0)
    {
        showCreditAmount(clientCredit);
        showCreditInstallments(clientCreditInstallment);
        showCreditAmountMonthly(creditInstallmentMonthly);
    }
    
}

void firstClientMenu()
{
    
    while(true)
    {
        //system("clear");
        
        int option;

        cout << "\n********************************************************" << endl;
        cout << "WITAJ KLIENCIE 1\n" << endl;
        cout << "WYBIERZ AKCJĘ NA KONCIE I ZATWIERDŹ NACISKAJĄC 'ENTER'" << endl;
        cout << "UWAGA! WPISUJ TYLKO LICZBY CAŁKOWITE!\n" << endl;
        cout << "[1] - WPŁATA" << endl;
        cout << "[2] - WYPŁATA" << endl;
        cout << "[3] - WZIĘCIE POŻYCZKI" << endl;
        cout << "[4] - PRZELEW NA KONTO KLIENTA 2" << endl;
        cout << "[5] - PRZELEW NA KONTO OSZCZĘDNOŚCIOWE" << endl;
        cout << "[6] - PRZELEW Z KONTA OSCZĘDNOŚCIOWEGHO NA KONTO ROR" << endl;
        cout << "[7] - PODGLĄD STANU KONTA" << endl;
        cout << "[8] - NASTĘPNY MIESIĄC" << endl;
        cout << "INNA CYFRA/LICZBA - POWROT DO MENU GŁÓWNEGO" << endl;


        
        cin >> option;

        switch(option)
        {
            case 1:
            system("clear");
                addMoney(client1);
                break;
            case 2:
            system("clear");
                substractMoney(client1);
                break;
            case 3:
            system("clear");
                takeCredit(client1, clientCredit1, clientCreditInstallment1, creditInstallmentMonthly1);
                break;
            case 4:
            system("clear");
                transferMoney(client1, client2);
                break;
            case 5:
            system("clear");
                transferToSavingsAccount(client1, clientSave1);
                break;
            case 6:
            system("clear");
                transferFromSavingsToDebitCount(clientSave1, client1);
                break;
            case 7:
            system("clear");
                preview(client1, clientSave1, clientCredit1, clientCreditInstallment1, creditInstallmentMonthly1);
                break;
            case 8:
            system("clear");
                changeMonth(client1, clientSave1, clientCredit1, creditInstallmentMonthly1, clientCreditInstallment1);
                break;
            default:
                system("clear");
                mainMenu();
                break;
        }
    }
}

void secondClientMenu()
{
    
}

//KREDYT
void takeCredit(double &client, double &clientCredit, double &clientCreditInstallment, double &creditInstallmentMonthly)
{
    int num;
    double creditAmount;
    double totalCreditAmount;
    double installment;
    double interest = 0.2;
    double bankCharge = 0.1;

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
        
        system("clear");

        installment = floorl((totalCreditAmount/num)*100)/100;

        //PRZYPISANIE ILOŚCI RAT KREDYTU KLIENTOWI
        clientCreditInstallment += num;

        creditInstallmentMonthly += installment;
        
        cout << "Łączna kwota kredytu na kwotę " << setprecision(15) << creditAmount << " zł wynosi " << setprecision(15) << totalCreditAmount << " zł" << endl;
        cout << "Rata kredytu wynosi " << setprecision(15) << installment << " zł" << endl;
        cout << "RRSO 20% kredytu wynosi " << setprecision(15) << floorl((creditAmount * interest)*100)/100 << " zł" << endl;
        cout << "Opłata bankowa 10% wynosi " << setprecision(15) << floorl((creditAmount * bankCharge)*100)/100 << " zł" << endl;
        cout << "********************************************************" << endl;
        
    }

}


// WPLATA NA KONTO
double addMoney(double &clientAmount)
{
    double y;

    cout<<"Podaj kwotę, którą chcesz wpłacić na konto"<<endl;
    cin >> y;
    if(y<=0)
    {
        cout << "Bardzo śmieszne..." << endl;
    }
    double z = floorl(y*100)/100;
    if (z>0)
    {
        clientAmount+=z;
        cout << "Transakcja zrealizowana poprawnie, dziękujemy" << endl;
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

    if (z>clientAmount)
    {
        cout << "Nie masz wystarczających środków na koncie" << endl;
    } else 
    {
        if(z<=0)
        {
            cout << "Nie możesz wypłacić 0 lub mniej" << endl;
        } else {
            clientAmount-=z;
            cout << "Transakcja zrealizowana poprawnie, dziękujemy" << endl;
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
    if(debitCount <= 0)
    {
        cout << "Nie masz środków na koncie" << endl;
    } else {
        if(floorl(z*100)/100 < 0)
        {
            cout << "Nie możesz przelać ujemnej kwoty!";
        } else {
            debitCount-= floorl(z*100)/100;
            savingsCount += floorl(z*100)/100;
        }
    }
}

//PRZELEW Z OSZCZEDNOSCIOWEGO NA DEBETOWE KONTO
void transferFromSavingsToDebitCount(double &savingsCount, double &debitCount)
{
    double z;

    cout << "Podaj kwotę, którą chcesz przelać na konto ROR" << endl;
    cin >> z;
    if(savingsCount <= 0)
    {
        cout << "Nie masz oszczędności" << endl;
    } else {
        if(floorl(z*100)/100 < 0)
        {
            cout << "Nie możesz przelać ujemnej kwoty!";
        } else {
            savingsCount-= floorl(z*100)/100;
            debitCount += floorl(z*100)/100;
        }
    }
}

//WYCIAG Z KONTA

//STAN KONTA ROR
void showDeposit(double clientAmount)
{
    cout << "Stan konta klienta wynosi: " << setprecision(15) << clientAmount << " zł" << endl;
}

//STAN KONTA OSZCZEDNOSCIOWEGO
void showSavingsBalance(double clientSavingsAmount)
{
    cout << "Stan konta osczędnościowego wynosi: " << setprecision(15) << clientSavingsAmount << " zł" << endl;
}

//ILOSC KREDYTU DO SPLACENIA
void showCreditAmount(double creditAmount)
{
    cout << "Zadłużenie wynosi: " << setprecision(15) << creditAmount << " zł" << endl;
}

//ILOSC RAT KREDYTU DO SPLACENIA
void showCreditInstallments(double creditInstallments)
{
    cout << "Liczba rat pozostałych do końca spłaty kredytu: " << setprecision(15) << creditInstallments << endl;
}

//WYSOKOSC RATY KREDYTU
void showCreditAmountMonthly(double creditAmountMonthly)
{
    cout << "Wysokość miesięcznej raty kredytu wynosi: " << setprecision(15) << creditAmountMonthly << endl;
}

