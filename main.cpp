#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;


int check_size (string nazwaPliku)
{
    int ile;
    fstream plik;
    plik.open(nazwaPliku);
    string linia;
    if(getline (plik, linia))
        ile = atoi( linia.c_str() );
    plik.close();
    return ile;
}

/*
void sezamie_otworz_sie(string zamek[], string klucz[], int i)
{
        cout << "Zamek: " << zamek[i] << endl;
        cout << "Klucz: " << klucz[i] << endl;
}
*/
void sezamie_otworz_sie(string zamek, string klucz, int rozmiar)
{

        char exch;

        //  dlugosc zamka, moze byc tez klucza
        int dlugosc = zamek.length(), licznik=0;

        // Jezeli zamek i klucz maja rozne dlugosci to false
        if ( zamek.length() != klucz.length()  )
        {
            cout << "Niepoprawna dlugosc" << endl;

        }

        bool znaleziono = false;
        while (znaleziono == false)
            if( zamek == klucz )
            {
                cout << "true" << endl;
                znaleziono = true;
            }
            else
            {
                //cout << "klucz: " << klucz << endl;
                exch = klucz[dlugosc-1];
                //cout << "exch: " << exch << endl;
                for (int j=dlugosc-2; j>=0; j--)
                {
                    klucz[j+1] = klucz[j];
                    //cout << j << " k: " << klucz << endl;
                }

                klucz[0] = exch;
                //cout << "klucz: " << klucz << endl;

                licznik++;
                if(licznik == dlugosc)
                {
                    cout << "false" << endl;
                    break;
                }
            }

}


int main()
{
    int nr_linii = 1, ile=0, i;
    string nazwaPliku = "input.txt";
    const int rozmiar = check_size(nazwaPliku);
    string zamek[rozmiar], klucz[rozmiar];

    fstream plik;        //zmienna plik
    plik.open(nazwaPliku, ios::in); //otwiera plik do odczytu


    // Wynik niepoprawnej nazwy pliku
    if( plik.good() == false )
    {
        cout << "Plik nie istnieje!" << endl;
        exit(0); // zakoncz program
    }

    string linia;
    // Jezeli poprawnie odczytujemy linie to wykonujemy zawartosc while'a
    while ( getline(plik, linia) )
    {
        switch( nr_linii )
        {
            case 2:
                zamek[ile]  = linia;  break;
            case 3:
                klucz[ile]  = linia;  break;
        }
        if (nr_linii == 3) { nr_linii=1; ile++; }
        nr_linii++;
    }

    plik.close();

    cout << "Rozmiar: " << rozmiar << endl;
    for(int i=0; i<rozmiar; i++)
    {
        sezamie_otworz_sie(zamek[i], klucz[i], rozmiar);
    }

    return 0;
}
