// Jareš Ondøej
//E20B0188P

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

double a, b, c, objem, objemValce, r;
int cislo, pocetOsob, pole[];

double vypocet_objem(double a, double b, double c) 
{
    objem = a * b * c;
    return objem;
}

double vypocet_objemValce(double c, double objem)
{
    r = sqrt(objem / (M_PI * c));
    return r;
}

int random(int dolni, int horni) {
    cislo = rand() % ((horni - dolni) + 1) + dolni;
    return cislo;
}

int vypocetPocetOsob(int cislo, int objem)
{
    objem = objem * 1000;
    pocetOsob = (objem / cislo) / 3;
    return pocetOsob;

}

void myName()
{
    cout << "Ondrej Jares\n";
    cout << "E20B0188P\n" << endl;
}


int main()
{
	myName();
    srand((unsigned int)time(nullptr));
    
    while (true) {
        cout << "Zadej hranu a - zadej cislo od 1 do 100: ";
        cin >> a;
        if ((a > 0) && (a < 101)) {
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true) {
        cout << "Zadej hranu b - zadej cislo od 1 do 100: ";
        cin >> b;
        if ((b > 0) && (b < 101)) {
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true) {
        cout << "Zadej hranu c vetsi nez a, b - cislo od 1 do 100: ";
        cin >> c;
        if ((c > 0) && (c < 101) && (c > a) && (c > b)) {
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    vypocet_objem(a,b,c);
    cout << "Objem kvadru o hranach " << fixed << setprecision(2) << a <<", "<< b << ", " << c << " je: " << objem << " m3 " << endl;
    cout << "Podstavou kvadru je: ";
    if (a == b) {
        cout << "ctverec" << endl;
    }
    else {
        cout << "obdelnik" << endl;
    }

    cout << "Polomer podstavy valce o stejnem objemu je: " << fixed << setprecision(6) << vypocet_objemValce(c, objem) << " m" << endl;
    
    
    for (int i = 1; i <= 2; i++) {
        random(1, 7);
        vypocetPocetOsob(cislo, objem);
        cout << "Voda vystaci pro " << pocetOsob << " osob na " << cislo << " dni" << endl;



        fstream soubor("objem.txt", ios::out);
        if (soubor.is_open()) {
            soubor << "Voda vystaci pro " << pocetOsob << " osob na " << cislo << " dni" << endl;
            soubor << "Voda vystaci pro " << pocetOsob << " osob na " << cislo << " dni" << endl;

            soubor.close();
        }
        else {
            cout << "Soubor nelze otevrit";
        }
    }
    fstream soubor("data.txt", ios::out);
    if (soubor.is_open()) {
        cout << a << "\t" << b << "\t" << c << "\t" << objem << endl;
        soubor << a << "\t" << b << "\t" << c << "\t" << objem << endl;
        soubor.close();
    }
    else {
        cout << "Soubor nelze otevrit";
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
