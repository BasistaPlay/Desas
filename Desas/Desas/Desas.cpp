#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

char lauks[9] = {
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
};

void radit_lauku();
void dabut_x_speletaja_gajienu();
void dabut_o_speletaja_gajienu();
void dabut_bota_gajienu();
int skatit_lauku(char symbol);
char skatit_uzvaretaju();
void dators_vs_speletajs();
void speletajs_vs_speletajs();
void noteikumi();
void starts();
void turpinat();
void turpinat2();

int main()
{

    starts();
    return 0;
}

void starts()
{

    int rezims;
    cout << "1. Bot vs player" << endl;
    cout << "2. player vs player" << endl;
    cout << "3. Regulations" << endl;
    cout << "Choose a mode:" << endl;
    cin >> rezims;
    switch (rezims)
    {
    case 1:
        system("cls");
        dators_vs_speletajs();
        break;
    case 2:
        system("cls");
        speletajs_vs_speletajs();
        break;
    case 3:
        system("cls");
        noteikumi();
        break;
    default:
        cout << "Please enter the correct mode!" << endl;
        break;
    }
}

void turpinat()
{

    int jautajums;
    cout << "1. To continue" << endl;
    cout << "2. Modes" << endl;
    cout << "3. End the game" << endl;
    cout << "Choose:" << endl;
    cin >> jautajums;
    switch (jautajums)
    {
    case 1:
        system("cls");
        dators_vs_speletajs();
        break;
    case 2:
        system("cls");
        starts();
        break;
    case 3:
        exit(EXIT_FAILURE);
    default:
        cout << "Please enter the correct mode!" << endl;
        break;
    }
}

void turpinat2()
{

    int jautajums;
    cout << "1. To continue" << endl;
    cout << "2. Modes" << endl;
    cout << "3. End the game" << endl;
    cout << "Choose:" << endl;
    cin >> jautajums;
    switch (jautajums)
    {
    case 1:
        system("cls");
        speletajs_vs_speletajs();
        break;
    case 2:
        system("cls");
        starts();
        break;
    case 3:
        exit(EXIT_FAILURE);
    default:
        cout << "Please enter the correct mode!" << endl;
        break;
    }
}

void dators_vs_speletajs()
{
    string spletaju_vards;
    cout << "Enter your name: ";
    cin >> spletaju_vards;
    while (true)
    {
        system("cls");
        radit_lauku();
        if (skatit_lauku('X') == skatit_lauku('O'))
        {
            cout << spletaju_vards << "round goes." << endl;
            dabut_x_speletaja_gajienu();
        }
        else
        {
            dabut_bota_gajienu();
        }
        char uzvaretajs = skatit_uzvaretaju();
        if (uzvaretajs == 'X')
        {
            system("cls");
            radit_lauku();
            cout << spletaju_vards << ", won the game!" << endl;
            turpinat();
        }
        else if (uzvaretajs == 'O')
        {
            system("cls");
            radit_lauku();
            cout << "The computer won the game!" << endl;
            turpinat();
        }
        else if (uzvaretajs == 'D')
        {
            cout << "Draw!" << endl;
            turpinat();
        }
    }
}

void dabut_bota_gajienu()
{

    srand(time(0));
    int izvele;
    do
    {
        izvele = rand() % 10;
    } while (lauks[izvele] != ' ');
    lauks[izvele] = 'O';
}

void dabut_x_speletaja_gajienu()
{
    while (true)
    {
        cout << "Choose your position (1-9): ";
        int izvele;
        cin >> izvele;
        izvele--;
        if (izvele < 0 || izvele > 8)
        {
            cout << "Please select your position (1-9)." << endl;
        }
        else if (lauks[izvele] != ' ')
        {
            cout << "Please select an empty position." << endl;
        }
        else
        {
            lauks[izvele] = 'X';
            break;
        }
    }
}

void dabut_o_speletaja_gajienu()
{
    while (true)
    {
        cout << "Choose your position (1-9): ";
        int izvele;
        cin >> izvele;
        izvele--;
        if (izvele < 0 || izvele > 8)
        {
            cout << "Please select your position (1-9)." << endl;
        }
        else if (lauks[izvele] != ' ')
        {
            cout << "Please select an empty position." << endl;
        }
        else
        {
            lauks[izvele] = 'O';
            break;
        }
    }
}

void speletajs_vs_speletajs()
{
    string x_speletaju_vards, o_speletaju_vards;
    cout << "Enter the name of the X player: ";
    cin >> x_speletaju_vards;
    cout << "Enter the O player name: ";
    cin >> o_speletaju_vards;
    while (true)
    {
        system("cls");
        radit_lauku();
        if (skatit_lauku('X') == skatit_lauku('O'))
        {
            cout << x_speletaju_vards << ", the round goes." << endl;
            dabut_x_speletaja_gajienu();
        }
        else
        {
            cout << o_speletaju_vards << ", the round goes." << endl;
            dabut_o_speletaja_gajienu();
        }
        char uzvaretajs = skatit_uzvaretaju();
        if (uzvaretajs == 'X')
        {
            system("cls");
            radit_lauku();
            cout << x_speletaju_vards << ", won the game!" << endl;
            turpinat2();
        }
        else if (uzvaretajs == 'O')
        {
            system("cls");
            radit_lauku();
            cout << o_speletaju_vards << ", won the game!" << endl;
            turpinat2();
        }
        else if (uzvaretajs == 'D')
        {
            cout << "Draw!!!" << endl;
            turpinat2();
        }
    }
}

int skatit_lauku(char symbol)
{
    int kopa = 0;
    for (int i = 0; i < 9; i++)
    {
        if (lauks[i] == symbol)
            kopa += 1;
    }
    return kopa;
}

char skatit_uzvaretaju()
{
    //horizontâli
    if (lauks[0] == lauks[1] && lauks[1] == lauks[2] && lauks[0] != ' ')
        return lauks[0];
    if (lauks[3] == lauks[4] && lauks[4] == lauks[5] && lauks[3] != ' ')
        return lauks[3];
    if (lauks[6] == lauks[7] && lauks[7] == lauks[8] && lauks[6] != ' ')
        return lauks[6];
    //vertikali
    if (lauks[0] == lauks[3] && lauks[3] == lauks[6] && lauks[0] != ' ')
        return lauks[0];
    if (lauks[1] == lauks[4] && lauks[4] == lauks[7] && lauks[1] != ' ')
        return lauks[1];
    if (lauks[2] == lauks[5] && lauks[5] == lauks[8] && lauks[2] != ' ')
        return lauks[2];
    //diognale
    if (lauks[0] == lauks[4] && lauks[4] == lauks[8] && lauks[0] != ' ')
        return lauks[0];
    if (lauks[2] == lauks[4] && lauks[4] == lauks[6] && lauks[2] != ' ')
        return lauks[2];

    if (skatit_lauku('X') + skatit_lauku('O') < 9)
        return 'C';
    else
        return 'D';
}

void radit_lauku()
{
    cout << "    "
        << "     |   "
        << "      |   " << endl;
    cout << "    " << lauks[0] << "    |    " << lauks[1] << "    |    " << lauks[2] << endl;
    cout << "    "
        << "     |   "
        << "      |   " << endl;
    cout << "-----------------------------" << endl;
    cout << "    "
        << "     |   "
        << "      |   " << endl;
    cout << "    " << lauks[3] << "    |    " << lauks[4] << "    |    " << lauks[5] << endl;
    cout << "    "
        << "     |    "
        << "     |    " << endl;
    cout << "-----------------------------" << endl;
    cout << "    "
        << "     |    "
        << "     |    " << endl;
    cout << "    " << lauks[6] << "    |    " << lauks[7] << "    |    " << lauks[8] << endl;
    cout << "    "
        << "     |    "
        << "     |    " << endl;
}

void noteikumi()
{
    int menu;
    cout << "Tic-tac-toe" << endl;
    cout << "This game teaches you to think, make choices, predict different situations and possible versions." << endl;
    cout << "Draw who will draw the circles, who will cross, X will start first, and go!" << endl;
    cout << "The winner is the first to draw the same characters horizontally, vertically or diagonally." << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Here's how to set the pitch!" << endl;
    cout << endl;
    cout << "    "
        << "     |   "
        << "      |   " << endl;
    cout << "    " << 1 << "    |    " << 2 << "    |    " << 3 << endl;
    cout << "    "
        << "     |   "
        << "      |   " << endl;
    cout << "-----------------------------" << endl;
    cout << "    "
        << "     |   "
        << "      |   " << endl;
    cout << "    " << 4 << "    |    " << 5 << "    |    " << 6 << endl;
    cout << "    "
        << "     |    "
        << "     |    " << endl;
    cout << "-----------------------------" << endl;
    cout << "    "
        << "     |    "
        << "     |    " << endl;
    cout << "    " << 7 << "    |    " << 8 << "    |    " << 9 << endl;
    cout << "    "
        << "     |    "
        << "     |    " << endl;
    cout << endl;
    cout << endl;
    starts();
}
