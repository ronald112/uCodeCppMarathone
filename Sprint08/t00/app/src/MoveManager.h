#pragma once

#include <memory>
#include <string>

class Player;
class Map;

class MoveManager final {
 public:
    enum class Direction { Up, Down, Left, Right };

    MoveManager(std::shared_ptr<Player>& player, std::shared_ptr<Map>& map);
    ~MoveManager() = default;

    void processInputAndMove(const std::string& inputStr);

 private:
    bool checkMove(Direction dir) const;

    std::shared_ptr<Map> m_map;
    std::shared_ptr<Player> m_player;
};
