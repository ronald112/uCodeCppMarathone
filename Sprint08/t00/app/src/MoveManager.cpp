#include "MoveManager.h"
#include "Player.h"
#include "Map.h"
#include <regex>
#include <iostream>

using namespace std;

MoveManager::MoveManager(std::shared_ptr<Player>& player, std::shared_ptr<Map>& map)
    : m_map(map), m_player(player) {}


void MoveManager::processInputAndMove(const std::string& inputStr) {
    regex pattern(R"(^[udrle]$)");
    cmatch match;

    if (!regex_match(inputStr.c_str(), match, pattern)) {
        cerr << "Invalid input" << endl;
        return;
    }
    if (match.str(0) == "u" && checkMove(Direction::Up))
        m_player->movePlayer(Direction::Up);
    else if (match.str(0) == "d" && checkMove(Direction::Down))
        m_player->movePlayer(Direction::Down);
    else if (match.str(0) == "l" && checkMove(Direction::Left))
        m_player->movePlayer(Direction::Left);
    else if (match.str(0) == "r" && checkMove(Direction::Right))
        m_player->movePlayer(Direction::Right);
    else if (match.str(0) == "e")
        exit(EXIT_SUCCESS);
}

bool MoveManager::checkMove(Direction dir) const {
    size_t p_pos = m_player->posX() + m_player->posY() * m_map->width();
    if (dir == Direction::Up && static_cast<int>(p_pos) - static_cast<int>(m_map->height()) >= 0) {
        return true;
    } else if (dir == Direction::Down && p_pos + m_map->height() < m_map->height() * m_map->width()) {
        return true;
    } else if (dir == Direction::Right && m_player->posX() < m_map->height() - 1) {
        return true;
    } else if (dir == Direction::Left && m_player->posX() > 0) {
        return true;
    }
    else {
        cerr << "Invalid direction" << endl;
        return false;
    }
}
