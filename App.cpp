#include <iostream>
#include <random>
#include <string>

using namespace std;
string username;
int level = 1;
static int highscore;

void intro();
void spiel();
void optionen();
void clear();
void clear(int);
int schwierigkeit();
void about();
int eingabePruefen();
int bonus(int level, int versuche);

int main()
{
    cout << "Enter your username: ";
    cin >> username;
    clear(1);
    intro();
    cout << "Eingeloggt als: " << username << endl;
    int weiter = 0;
    while(weiter != 1) {
        char cChoice;
        cout << "(I)ntro, (S)pielen, (O)ptionen, (B)eenden" << endl;
        cin >> cChoice;

        switch(cChoice) 
        {
            case 'i':
            case 'I': intro(); break;
            case 's':
            case 'S': spiel(); break;
            case 'o':
            case 'O': optionen(); break;
            case 'b':
            case 'B': cout << "Das Spiel wird beendet!" << endl; weiter = 1;break;
            default: cout << "Kein treffer!" << endl; break;
        }
    }
}

void intro() 
{
    clear(2);
    cout << "############ INTRO ############" << endl;
    cout << "#### HERZLICHEN WILLKOMMEN ####" << endl;
    cout << "######### ERSTELLT VON ########" << endl;
    cout << "######### AYAZ KHUDHUR ########" << endl;
    clear(1);
}

void spiel() 
{
    clear(2);

    int guessNumber = 0;
    int versuche = 0;
    int levelSchwierigkeit = level * 10;

    // Erzeuge einen Zufallsgenerator
    std::random_device rd;  // Seed für den Zufallsgenerator
    std::mt19937 gen(rd()); // Standard-Mersenne-Twister-Generator
    std::uniform_int_distribution<> distrib(1, levelSchwierigkeit); // Bereich von 1 bis der user sein level gewählt hat oder standard (1 - 10)

    // Generiere eine zufällige Zahl
    int randomNumber = distrib(gen);

    int weiter = 0;
    cout << "Spiel wird gestartet!" << endl;
    while(weiter != 1) 
    {
        cout << "Suche den Zahl zwischen 1 bis " << levelSchwierigkeit<< "!" << endl;
        cout << "Dein Zahl: ";
        cin >> guessNumber;

        if (eingabePruefen() != 0)
        {
            continue;
        }

        if (guessNumber == randomNumber)
        {
            clear();
            cout << "Du hast Gewonnen!!!!" << endl;
            cout << "Du hast mit " << versuche << " Versuchen gewonnen!" << endl;
            int bonusRechner = bonus(level, versuche);

            if (highscore < bonusRechner) {
                cout << "Glückwunsch, du hast deinen Highscore geknackt! Punkte: " << bonusRechner << endl;
                highscore = bonusRechner;
            }else if (bonusRechner != -1) {
                cout << "Bonus: " << bonusRechner << endl;
            }

            versuche = 0;
            weiter = 1;
        }
        else if (guessNumber > randomNumber)
        {
            cout << "Der gesuchte Zahl ist kleiner als dein Eingabe!" << endl;
            versuche++;
        }
        else if (guessNumber < randomNumber) 
        {
            cout << "Der gesuchte Zahl ist Groesser als dein Eingabe!" << endl;
            versuche++;
        }
    }
    clear(1);
}

void optionen() 
{
    clear(2);
    int weiter = 1;
    int cChoice;
    do 
    {
        cout << "########## OPTIONEN ##########" << endl;
        cout << "1. Schwierigkeit" << endl;
        cout << "2. About" << endl;
        cout << "3. Menü" << endl;
        cout << "Wähle eine Option: ";
        cin >> cChoice;
        clear();

        if (eingabePruefen() != 0)
        {
            continue;
        }

        switch(cChoice)
        {
            case 1: level = schwierigkeit(); break;
            case 2: about(); break;
            case 3: weiter = 0; break;
            default: cout << "Bitte eine gültige auswahl treffen!" << endl;
        }

    } while (weiter != 0);
    clear(1);
}

int schwierigkeit()
{
    clear(2);
    int schwerigkeit;
    do 
    {
        cout << "Zahl zwischen 1 und 10 eingeben!" << endl;
        cout << "Schwierigkeit: ";
        cin >> schwerigkeit;

        if (eingabePruefen() != 0)
        {
            continue;
        }

        if (schwerigkeit < 1 || schwerigkeit > 10)
        {
            cout << "Bitte eine Zahl zwischen 1 und 10 eingeben!" << endl;
            continue;
        }
    } while(schwerigkeit <= 0 || schwerigkeit > 10);

    cout << "Der Schwierigkeitgerade wurde auf " << schwerigkeit << " erhöht!" << endl;
    clear(1);
    return schwerigkeit;
}

void about() 
{
    clear(2);
    cout << "Über das Spiel: \n" << endl;
    cout << "Erstellt von Ayaz Khudhur." << endl;
    clear(1);
}

int berechneBonus(int bonusPunkte, int versuche)
{
    int versucheRechnung = versuche * 10;
    if (bonusPunkte - versucheRechnung > 0) {
        bonusPunkte = bonusPunkte - versucheRechnung;
    }
    return bonusPunkte;
}

int bonus(int level, int versuche)
{
    int bonusPunkte[11];
    bonusPunkte[0] = 50;
    bonusPunkte[1] = 100;
    bonusPunkte[2] = 200;
    bonusPunkte[3] = 300;
    bonusPunkte[4] = 450;
    bonusPunkte[5] = 600;
    bonusPunkte[6] = 850;
    bonusPunkte[7] = 1100;
    bonusPunkte[8] = 1450;
    bonusPunkte[9] = 1850;
    bonusPunkte[10] = 2300;

    if (level >= 1 && level <= 2) {
        return berechneBonus((bonusPunkte[0] + bonusPunkte[1]) * level, versuche);
    }
    if (level >= 3 && level <= 4) {
        return berechneBonus((bonusPunkte[2] + bonusPunkte[3]) * level, versuche);
    }
    if (level >= 5 && level <= 6) {
        return berechneBonus((bonusPunkte[4] + bonusPunkte[5]) * level, versuche);
    }
    if (level >= 7 && level <= 8) {
        return  berechneBonus((bonusPunkte[6] + bonusPunkte[7]) * level, versuche);
    }
    if (level >= 9 && level <= 10) {
        return  berechneBonus((bonusPunkte[8] + bonusPunkte[9]) * level, versuche);
    }

    return -1;
}


int eingabePruefen() 
{
    if (std::cin.fail()) {
        std::cin.clear(); // Eingabefehler zurücksetzen
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer löschen
        std::cout << "\nUngültige Eingabe! Bitte eine Zahl zwischen 1 und 10 eingeben." << std::endl;
        return 1;
    }

    return 0;
}

void clear() 
{
    cout << "\n\n\n\n";
}

void clear(int i)
{
    for(int x = 0; x < i; x++)
    {
        cout << "\n";
    }
}
