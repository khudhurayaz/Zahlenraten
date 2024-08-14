#include <iostream>
#include <random>
#include <string>

using namespace std;
string username;
int level = 1;
int highscor;

void intro();
void spiel();
void optionen();
void clear();
void clear(int);
int schwerigkeit();
void about();
int eingabePruefen();

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

    return 0;
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

    int guessNumber;
    int randomNumber;
    int versuche;
    int levelSchwierigkeit = level * 10;

    // Erzeuge einen Zufallsgenerator
    std::random_device rd;  // Seed für den Zufallsgenerator
    std::mt19937 gen(rd()); // Standard-Mersenne-Twister-Generator
    std::uniform_int_distribution<> distrib(1, levelSchwierigkeit); // Bereich von 1 bis der user sein level gewählt hat oder standard (1 - 10)

    // Generiere eine zufällige Zahl
    randomNumber = distrib(gen);

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
            cout << "Sie haben gewonnen!" << endl;
            cout << "Sehr schön '" << username << "'\n";
            cout << "Sie haben mit " << versuche << " Versuchen gewonnen!" << endl;
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
            case 1: level = schwerigkeit(); break;
            case 2: about(); break;
            case 3: weiter = 0; break;
            default: cout << "Bitte eine gültige auswahl treffen!" << endl;
        }

    } while (weiter != 0);
    clear(1);
}

int schwerigkeit()
{
    clear(2);
    int schwerigkeit;
    do 
    {
        cout << "Zahl zwischen 1 und 10 eingeben!" << endl;
        cout << "Schwerigkeit: ";
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

    cout << "Der Schwerigkeitgerade wurde auf " << schwerigkeit << " erhöht!" << endl;
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
