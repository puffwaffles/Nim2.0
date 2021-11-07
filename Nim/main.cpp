#include <iostream>
#include "nim.hpp"
using namespace std;

int main() {
    Nim game(0, 0, 0, 0);
    game.main_menu();
    int nums = game.get_mode();
    bool ending = game.get_end();
    while (nums > 0) {
        cout << "Preparing game..." << endl;
        cout << endl;
        while (ending == false) {
            game.draw_blobs();
            game.opp_take_blobs();
            if (game.get_end()) {
                break;
            }
            game.draw_blobs();
            game.play_take_blobs();
            if (game.get_end()) {
                break;
            }
        }
        cout << game.get_winner() << endl;
        cout << endl;
        game.main_menu();
        nums = game.get_mode();
        if (nums > 0) {
            ending = false;
        }
    }
}