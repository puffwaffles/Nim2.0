#include <iostream>
#include "nim.hpp"
#include <cmath>
using namespace std;

Nim::Nim(int modes, int maxblobs, int blobs, int maxtakes) {
    mode = 0;

    maxblob = 0;

    blob = 0;

    winner = "unknown";

    maxtake = 0;

    playtake = 0;

    opptake = 0;

    turn = false;

    end = false;
}

Nim::~Nim() {
    std::cout << "\nThanks for playing!";
}

void Nim::menu2() {
    cout << "\tMode Selection" << endl;
    cout << endl;
    cout << "1. Mode 1" << endl;
    cout << "2. Mode 2" << endl;
    cout << "3. Mode 3" << endl;
    cout << "4. Mode 4" << endl;
    cout << "Please select a mode: ";
    int num;
    cin >> num;
    while (num < 1 || num > 4) {
        cout << "Error: The entered input is not within the range. Please enter another number from 1-3: ";
        cin >> num;
    }
    if (num == 1) {
        mode = num;
        cout << "Please select the number of blobs: ";
        int blobs;
        cin >> blobs;
        while (blobs < 20 || blobs > 50) {
            cout << "Error: The entered input is not within the range. Please enter another number from 20-50: ";
            cin >> blobs;
        }
        maxblob = blobs;
        blob = maxblob;
        maxtake = (maxblob - 20) / 10 + 3;
    }
    else if (num == 2) {
        mode = num;
        cout << "Please select the number of blobs: ";
        int blobs;
        cin >> blobs;
        while (blobs < 20 || blobs > 50) {
            cout << "Error: The entered input is not within the range. Please enter another number from 20-50: ";
            cin >> blobs;
        }
        maxblob = blobs;
        blob = maxblob;
        maxtake = (maxblob - 20) / 10 + 3;
    }
    else if (num == 3) {
        mode = num;
        maxblob = rand() % 31 + 20;
        blob = maxblob;
        maxtake = (maxblob - 20) / 10 + 3;
    }
    else if (num == 4) {
        mode = num;
        maxblob = rand() % 31 + 20;
        blob = maxblob;
        maxtake = (maxblob - 20) / 10 + 3;
    }
}

void Nim::menu1() {
    cout << "\tInstructions" << endl;
    cout << endl;
    cout << "This game involves taking turns to select an amount of blobs from a set of blobs. The opponent will go first." << endl;
    cout << "Each game will have 20 - 50 blobs each. If you choose modes 1 and 2, you can select the number of blobs." << endl;
    cout << "20 - 29 blobs from the start -> Players can take 1-3 blobs" << endl;
    cout << "30 - 39 blobs from the start -> Players can take 1-4 blobs" << endl;
    cout << "40 - 49 blobs from the start -> Players can take 1-5 blobs" << endl;
    cout << "50 blobs from the start -> Players can take 1-6 blobs" << endl;
    cout << "The player and opponent will take turns selecting a number of blobs. The game ends when the opponent or player takes";
    cout << "the last blob." << endl;
    cout << "Happy blob: (0 w 0)" << endl;
    cout << "Sad blob: (0 _ 0)" << endl;
    cout << "Mode 1- The player can choose the original amount of blobs. Player wins if they select the Happy blob." << endl;
    cout << "Mode 2- The player can choose the original amount of blobs. Player wins if opponent selects the Sad blob." << endl;
    cout << "Mode 3- The original amount of blobs is selected randomly. The player will not see the amount of blobs.";
    cout << " Player wins if they select the Happy blob." << endl;
    cout << "Mode 4- The original amount of blobs is selected randomly. The player will not see the amount of blobs.";
    cout << " Player wins if opponent selects the Sad blob." << endl;
    cout << endl;
    main_menu();
}

void Nim::main_menu() {
    cout << "\tNim game" << endl << endl;
    cout << "1. Instructions" << endl;
    cout << "2. Play game" << endl;
    cout << "3. Quit" << endl;
    cout << "Please make a selection from 1-3: ";
    int num;
    cin >> num;
    while (num < 1 || num > 3) {
        cout << "Error: The entered input is not within the range. Please enter another number from 1-3: ";
        cin >> num;
    }
    cout << endl;
    if (num == 1) {
        menu1();
    }
    else if (num == 2) {
        menu2();
    }
    else {
        mode = 0;
    }
}


int Nim::get_mode() {
    return mode;
}

void Nim::get_turn() {
    if (turn) {
        cout << "Player's turn" << endl;
    }
    else {
        cout << "Opponent's turn" << endl;
    }
}

string Nim::get_winner() {
    if (blob == 0 && turn == true && (mode == 1 || mode == 3)) {
        winner = "Player wins";
    }
    else if (blob == 0 && turn == false && (mode == 2 || mode == 4)) {
        winner = "Player wins";
    }
    else if (blob == 0 && turn == false && (mode == 1 || mode == 3)) {
        winner = "Opponent wins";
    }
    else if (blob == 0 && turn == true && (mode == 2 || mode == 4)) {
        winner = "Opponent wins";
    }
    else {
        winner = "Unknown";
    }
    return winner;
}

void Nim::draw_blobs() {
    if (mode == 1) {
        cout << blob << " blobs left.";
        cout << endl;
        int count = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                count++;
                if (count < blob) {
                    cout << "(0 _ 0) ";
                }
                else if (count == blob) {
                    cout << "(0 w 0)";
                }
                else {
                    break;
                }
            }
            if (count > blob) {
                break;
            }
            cout << endl;
        }
    }
    else if (mode == 2) {
        cout << blob << " blobs left.";
        cout << endl;
        int count = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                count++;
                if (count < blob) {
                    cout << "(0 w 0) ";
                }
                else if (count == blob) {
                    cout << "(0 _ 0)";
                }
                else {
                    break;
                }
            }
            if (count > blob) {
                break;
            }
            cout << endl;
        }
    }
    cout << endl;
}

void Nim::play_take_blobs() {
    cout << "Player's turn" << endl;
    if (maxtake > blob) {
        maxtake = blob;
        if (mode == 3 || mode == 4) {
            cout << "Please enter an amount: ";
        }
        else {
            cout << "Please enter a number from 1-" << maxtake << ": ";
        }
        cin >> playtake;
        if (mode == 1 || 2) {
            while (playtake < 1 || playtake > maxtake) {
                if (playtake < 1) {
                    cout << "Error: The entered input is not within the range. Please enter another number from 1-" << maxtake << ": ";
                }
                else {
                    cout << "Error: The entered input is too large. Please enter another number from 1-" << maxtake << ": ";
                }
                cin >> playtake;
            }
        }
        else {
            while (playtake < 1 || playtake > maxtake) {
                if (playtake < 1) {
                    cout << "Error: The entered input is not within the range. Please enter another number: ";
                }
                else {
                    cout << "Error: The entered input is too large. Please enter another number: ";
                }
                cin >> playtake;
            }
        }
    }
    cout << "Please enter a number from 1-" << maxtake << ": ";
    cin >> playtake;
    while (playtake < 1 || playtake > maxtake) {
        cout << "Error: The entered input is not within the range. Please enter another number from 1-" << maxtake << ": ";
        cin >> playtake;
    }
    blob = blob - playtake;
    cout << "Player takes " << playtake << " blobs" << endl;
    if (blob == 0) {
        cout << "Player takes the last blob" << endl;
    }
    else {
        turn = false;
    }
    cout << endl;
}

void Nim::opp_take_blobs() {
    cout << "Opponent's turn" << endl;
    if (blob <= maxtake && (mode == 1 || mode == 3)) {
        opptake = blob;
        blob = blob - opptake;
        cout << "Opponent takes the last blob" << endl;
    }
    else {
        opptake = rand() % maxtake + 1;
        while (opptake < 1 || opptake > maxtake) {
            cout << "Error: The entered input is not within the range. Please enter another number from 1-" << maxtake << ": ";
            opptake = rand() % maxtake + 1;
        }
        blob = blob - opptake;
        cout << "Opponent takes " << opptake << " blobs" << endl;
        turn = true;
    }
    cout << endl;
}

bool Nim::get_end() {
    if (blob == 0) {
        end = true;
        return end;
    }
    else {
        end = false;
        return end;
    }
}

