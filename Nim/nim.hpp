#include <string>
using namespace std;

class Nim {

	int mode;

	int blob;

	int maxblob;

	string winner;

	int maxtake;

	int playtake;

	int opptake;

	bool turn;

	bool end;

public:

	Nim(int modes, int maxblobs, int blobs, int maxtakes);

	~Nim();

	void menu2();

	void menu1();

	void main_menu();

	int get_mode();

	void get_turn();

	string get_winner();

	void draw_blobs();

	void play_take_blobs();

	void opp_take_blobs();

	bool get_end();
};
