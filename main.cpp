#include<iostream>
#include<string>
#include<ctime>

using namespace std;

/* Funktion för att generar en kortlek.
Tar emot storleken på array och storleken för kortleken */
void createDeck(int deck[], int size) {
    for (int i = 0; i < size; i++) {
        deck[i] = i;
    }
}

/* Funktion som tar som blandar kortleken */
void shuffle(int deck[], int size) {
    for (int i = 0; i < size; i++) {
        int random = rand() % size;
        int card = deck[i];
        deck[i] = deck[random];
        deck[random] = card;
    }
}

/* Funktion som tar som generar ett kort till spelet */

int drawCard(int deck[], int &size) {
    if (size < 0)
        return -1;
    --size;
    return deck[size];
}

void playthegame() {
    srand(time(nullptr));
    // Arrays för kortleken , en för siffor och en för sviter
    string number[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string suit[4] = {"Club", "Diamond", "Heart", "Spade"};
    int win[2] = {0, 0};

    int gameCount = 1;
    // Loop som tillåter flera spel
    while (true) {
        cout << "\nGame# " << gameCount << "\n";
        // Array för kortleken
        int deck[52], size = 52;
        // Funktion som skapar en kortlek
        createDeck(deck, size);
        /* Funktion för att blanda kortleken
        Skickar array och storleken för kortleken*/
        shuffle(deck, size);
        cout << "Shuffling the deck before the game!" << endl;
        cout << "\nPlayer 1 wins = " << win[0] << " --- Player 2 wins = " << win[1] << "\n";
        /* Håller koll på den nuvarande ställningen i spelet */
        int playeroneScore = 0;
        int playertwoScore = 0;
        /* Boolean för att skriva ut resultat bara en gång */
        bool winner = false;
        // Räknare för att hålla koll på vinanre
        int count[2] = {0, 0};

        for (int round = 1; round <= 3; round++) {
            if (count[0] != 2 && count[1] != 2) {
                cout << "\nRound# " << round << "\n";
                int card1 = drawCard(deck, size);
                int card2 = drawCard(deck, size);
                cout << "Player 1 draw " << number[card1 / 4] << " of " << suit[card1 % 4] << "\n";
                cout << "Player 2 draw " << number[card2 / 4] << " of " << suit[card2 % 4] << "\n";
                if (card1 > card2) {
                    cout << "Player 1 win this round.\n";
                    count[0]++;
                    playeroneScore++;
                } else {
                    cout << "Player 2 win this round.\n";
                    count[1]++;
                    playertwoScore++;
                }
                cout << "Current Score is " << playeroneScore << "-" << playertwoScore << "\n";
            } else {

            }
            if (playeroneScore == 2 && !winner) {
                cout << "\nPlayer 1 win this game.\n\n";
                win[0]++;
                winner = true;

            } else if (playertwoScore == 2 && !winner) {
                cout << "\nPlayer 2 win this game.\n\n";
                win[1]++;
                winner = true;
            }


        }
        gameCount++;
        string choise;
        cout << "Do you want to play again? y/n" << endl;
        cin >> choise;
        if (choise == "n") {

            cout << "Exiting the program!";
            exit(0);
        }

    }


}

int main() {
    cout << "1. to start the game" << endl;
    cout << "2. to end the program" << endl;
    int menu;
    cin >> menu;
    switch (menu) {
        case 1:
            playthegame();
            break;
        case 2:
            exit(0);
        default:
            cout << "Inget val gjort " << endl;
    }

}



