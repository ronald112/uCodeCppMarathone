#include <Map.h>
#include <MoveManager.h>
#include <Player.h>
#include <string>
#include <iostream>
#include <regex>
#include <memory>

using namespace std;

static void checkInputSizeMap(char* arg1, char* arg2) {
    try {
        size_t num = stoi(string(arg1));
        if (num < 5 || num > 20)
            throw string("Invalid map size");
        num = stoi(string(arg2));
        if (num < 5 || num > 20)
            throw string("Invalid map size");
    }
    catch(...) {
        throw string("Invalid map size");
    }
}

static void manageInput(shared_ptr<Map>& game_map, shared_ptr<MoveManager> move_m) {
    game_map->outputMap();
    cout << "\n:> ";
    string input;
    while(getline(cin, input)) {
        move_m->processInputAndMove(input);
        game_map->outputMap();
        cout << "\n:> ";
    }
}

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            throw string("usage: ./smartPointers [width] [height]");
        }
        else {
            checkInputSizeMap(argv[1], argv[2]);
            shared_ptr<Player> p(new Player);
            shared_ptr<Map> game_map(new Map(stoul(string(argv[1])), stoul(string(argv[2])), p));
            shared_ptr<MoveManager> move_m(new MoveManager(p, game_map));
            manageInput(game_map, move_m);
        }
    }
    catch(const string& ex) {
        cerr << ex << endl;
    }
    return 0;
}