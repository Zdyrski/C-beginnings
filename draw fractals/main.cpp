#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <stack>
#include <time.h>
#include <string>
#include <conio.h>

std::string zbior;
std::string regula;
std::string regula_wzor;
std::string regula2;
std::string regula_wzor2;
std::string nastepna_sekw = "";
float px, py, a, b, przyrost_kat, kat;
int gd = DETECT, gm, ilosc_regul, it, dlugosc;
char powoli='n';

void iteracje()
{
    std::cout << "\n\n PODAJ ILOSC ITERACJI : " ;
    std::cin >> it;
    for(int j = 0; j < it; j++)
    {
        nastepna_sekw = "";
        for(int i = 0; i < zbior.length(); i++)
        {
            if(zbior.at(i) == regula.at(0))
            {
                nastepna_sekw+=regula_wzor;
            }
            else if(zbior.at(i) == regula2.at(0))
            {
                nastepna_sekw+=regula_wzor2;
            }
            else
            {
                nastepna_sekw+=zbior.at(i);
            }
        }
        zbior=nastepna_sekw;
    }
}
void rysuj()
{
    std::cout << "\n\n PODAJ DLUGOSC ODCINKA F : " ;
    std::cin >> dlugosc;
    std::cout << "\n\n CZY RYSOWAC FUNKCJE POWOLI? (t/n) :" ;
    std::cin >> powoli;
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth,screenHeight,"dzialaj");
    std::stack < int > stos_x;
    std::stack < int > stos_y;
    std::stack < float > stos_kat;
    px=screenWidth/2;
    py=screenHeight/2;
    kat=0;
    moveto(px,py);
    setaspectratio(0.3,0.3);
    int dl=zbior.length();


    for (int k=0; k<=dl; k++)
    {
        if(powoli == 't')
        {
            _sleep(0);
        }
        switch (zbior[k])
        {
        case 'F' :
            line(px,py,px+b,py+a);
            py=py+a;
            px=px+b;
            break;
        case '+' :
            kat+=przyrost_kat;
            b=dlugosc*cos(M_PI*kat/180);
            a=dlugosc*sin(M_PI*kat/180);
            break;
        case '-' :
            kat-=przyrost_kat;
            b=dlugosc*cos(M_PI*kat/180);
            a=dlugosc*sin(M_PI*kat/180);
            break;
        case '[' :
            stos_x.push(px);
            stos_y.push(py);
            stos_kat.push(kat);
            break;
        case ']' :
            px=stos_x.top();
            py=stos_y.top();
            kat=stos_kat.top();
            stos_x.pop();
            stos_y.pop();
            stos_kat.pop();
            moveto(px,py);
            break;
        default :
            break;
        }
    }
    switch (_getch())
        {
        case 27 :
            exit(0);
            break;
        }
    getch();
    closegraph();
}

int main()
{
    while(1)
    {
        system("cls");
        int wybor;
        std::cout << "\n 1.GOTOWY FRAKTAL \n\n 2.WLASNY FRAKTAL \n\n WYBIERZ : " ;
        std::cin >> wybor;
        switch(wybor)
        {
        case 1 :
            system("cls");
            std::cout << "\n 0.WROC \n\n 1.TROJKAT SIERPINSKIEGO \n\n 2.PLATEK SNIEGU KOCHA \n\n 3.KRZYWA HILBERTA \n\n 4.KRZYWA MOOR'A \n\n 5.KRZYWA PEANO \n\n 6.SMOK HEIGHWAY'A \n\n 7.SMOK LEVY'EGO \n\n 8.PENTADENDRYT \n\n 9.STRUKTURA DZREWIASTA 1 \n\n 10.STRUKTURA DZREWIASTA 2 \n\n 11. RANDOMOWE MOJE COS \n\n";
            std::cout << "\n WYBIERZ FRAKTAL : " ;
            std::cin >> wybor;

            switch(wybor)
            {
            case 1 :
                zbior = "F+F+F";
                regula = "F";
                regula_wzor = "F+F-F-F+F";
                regula2 = "f";
                regula_wzor2 = "f";
                przyrost_kat = 120;
                iteracje();
                rysuj();
                break;
            case 2 :
                zbior = "F++F++F";
                regula = "F";
                regula_wzor = "F-F++F-F";
                regula2 = "f";
                regula_wzor2 = "f";
                przyrost_kat = 60;
                iteracje();
                rysuj();
                break;
            case 3 :
                zbior = "X";
                regula = "X";
                regula_wzor = "-YF+XFX+FY-";
                regula2 = "Y";
                regula_wzor2 = "+XF-YFY-FX+";
                przyrost_kat = 90;
                iteracje();
                rysuj();
                break;
            case 4 :
                zbior = "XFX+F+XFX";
                regula = "X";
                regula_wzor = "-YF+XFX+FY-";
                regula2 = "Y";
                regula_wzor2 = "+XF-YFY-FX+";
                przyrost_kat = 90;
                iteracje();
                rysuj();
                break;
            case 5 :
                zbior = "X";
                regula = "X";
                regula_wzor = "XFYFX+F+YFXFY-F-XFYFX";
                regula2 = "Y";
                regula_wzor2 = "YFXFY-F-XFYFX+F+YFXFY";
                przyrost_kat = 90;
                iteracje();
                rysuj();
                break;
            case 6 :
                zbior = "FX";
                regula = "X";
                regula_wzor = "X+YF+";
                regula2 = "Y";
                regula_wzor2 = "-FX-Y";
                przyrost_kat = 90;
                iteracje();
                rysuj();
                break;
            case 7 :
                zbior = "F";
                regula = "F";
                regula_wzor = "+F--F+";
                regula2 = "f";
                regula_wzor2 = "f";
                przyrost_kat = 45;
                iteracje();
                rysuj();
                break;
            case 8 :
                zbior = "F";
                regula = "F";
                regula_wzor = "F+F-F--F+F+F";
                regula2 = "f";
                regula_wzor2 = "f";
                przyrost_kat = 72;
                iteracje();
                rysuj();
                break;
            case 9 :
                zbior = "F";
                regula = "F";
                regula_wzor = "F[+F]F[-F]F";
                regula2 = "f";
                regula_wzor2 = "f";
                przyrost_kat = 25;
                iteracje();
                rysuj();
                break;
            case 10 :
                zbior = "----F";
                regula = "F";
                regula_wzor = "FF+[+F-F-F]-[-F+F+F]";
                regula2 = "f";
                regula_wzor2 = "f";
                przyrost_kat = 22;
                iteracje();
                rysuj();
                break;
            case 11 :
                zbior = "XYX";
                regula = "X";
                regula_wzor = "+YFX-YFY-XFY+";
                regula2 = "Y";
                regula_wzor2 = "-XF+XFX+FX-";
                przyrost_kat = 90;
                dlugosc = 1;
                iteracje();
                rysuj();
                break;
            case 12 :
                zbior = "YXY";
                regula = "X";
                regula_wzor = "---FYX+YFY+XYF---";
                regula2 = "Y";
                regula_wzor2 = "+XF-XYX-FX+";
                przyrost_kat = 90;
                iteracje();
                rysuj();
                break;
            case 0 :
                main();
            }
            break;
        case 2 :
            system("cls");
            std::cout << "\n KROTKA INSTRUKCJA (rysuje na zasadzie idacego zolwia ,\n ktory skreca w prawo/lewo o podany kat i rysuje albo nie linie za soba): " <<std::endl;
            std::cout << "\n F  IDZIE DO PRZODU RYSUJAC LINIE" <<std::endl;
            std::cout << "\n f  IDZIE DO PRZODU NIE RYSUJAC LINII" <<std::endl;
            std::cout << "\n +  SKRECA W PRAWO O PODANY KAT" <<std::endl;
            std::cout << "\n -  SKRECA W PRAWO O PODANY KAT" <<std::endl;
            std::cout << "\n [  ZAPAMIETUJE MIEJSCE(odklada na stos) " <<std::endl;
            std::cout << "\n ]  WRACA DO ZAPAMIETANEGO MIEJSCA(zdejmuje ze stosu)" <<std::endl;
            std::cout << "\n AKSJOMAT - POCZATKOWY ZBIOR NA KTORYM BEDA OPEROWALY REGULY" <<std::endl;
            std::cout << "\n REGULA - JESLI WYSTEPUJE W AKSJOMACIE ZASTEPUJE JA WZOREM (powinna wystepowac \n co najmniej jedna regula w podanym aksjomacie)" <<std::endl;
            std::cout << "\n WZOR REGULY - ZASTEPUJE WYSTEPUJACE W AKSJOMACIE REGULY ICH WZOREM" <<std::endl;
            std::cout << "\n PRZYROST KATA - O JAKI STOPIEN MA SKRECIC W PRAWO/LEWO" <<std::endl;
            std::cout << "\n ILOSC ITERACJI - ILE RAZY POWTORZYC (wpisywac bez przesady np. do 13)" <<std::endl;
            std::cout << "\n\n -----------------------------------------------------------------------\n" <<std::endl;
            std::cout << "\n PODAJ AKSJOMAT : " ;
            std::cin >> zbior;
            std::cout << "\n PODAJ ILOSC REGUL(1 LUB 2) : " ;
            std::cin >> ilosc_regul;
            std::cout << "\n PODAJ REGULE : " ;
            std::cin >> regula;
            std::cout << "\n PODAJ WZOR REGULY : " ;
            std::cin >> regula_wzor;
            if(ilosc_regul==2)
            {
                std::cout << "\n PODAJ REGULE 2 : " ;
                std::cin >> regula2;
                std::cout << "\n PODAJ WZOR REGULY 2 : " ;
                std::cin >> regula_wzor2;
            }
            else
            {
                regula2="~";
                regula_wzor2="~";
            }
            std::cout << "\n PODAJ PRZYROST KATA : " ;
            std::cin >> przyrost_kat;
            iteracje();
            rysuj();
            break;
        }
    }
}

