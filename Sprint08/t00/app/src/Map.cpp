#include "Map.h"
#include "Player.h"
#include <iostream>

size_t Map::width() const {
    return m_width;
}

size_t Map::height() const {
    return m_height;
}

Map::Map(size_t width, size_t height, std::shared_ptr<Player>& player)
    : m_width(width), m_height(height), m_player(player), m_map(new char[m_width * m_width]) {
    generateMap();
}

void Map::generateMap() {
    srand(time(0));
    for (size_t i = 0; i < m_width * m_height; i++) {
        unsigned o_type = rand() % 3;
        if (o_type == 0) {
            m_map[i] = '@';
        }
        else if (o_type == 1) {
            m_map[i] = 'T';
        }
        else {
            m_map[i] = '.';
        }
    }
}

void Map::outputMap() const {
    size_t player_pos = m_player->posX() + m_player->posY()  * m_width;
    bool first = true;

    for (size_t i = 0; i < m_width * m_height; i++) {
        if (first == false)
            std::cout << " ";
        first = false;
        if (i % m_width == 0 && i != 0)
            std::cout << std::endl;
        if (player_pos == i)
            std::cout << m_player->getIdentifier();
        else
            std::cout << m_map[i];
    }
}
