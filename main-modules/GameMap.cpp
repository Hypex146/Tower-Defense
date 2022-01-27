#define ALL_INCLUDE

#include "AllHeaders.h"
#include "GameMap.h"


GameMap::GameMap(TowerDefense *tower_defense) {
    tower_defense_ = tower_defense;
    loadMap();
    loadGraphs();
}

const Graph<Position> *GameMap::getRoadGraph() const {
    return road_graph_;
}

const Graph<Position> *GameMap::getRoadGraphWithWall() const {
    return road_graph_with_wall_;
}

FieldType GameMap::getFieldType(int x, int y) const {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) { throw std::runtime_error("Invalid coordinates"); }
    return map_[y][x];
}

FieldType GameMap::getFieldType(Position pos) const {
    return getFieldType(pos.x_, pos.y_);
}

MyString GameMap::intToString(int a) {
    MyString res;
    bool isNegative = false;
    if (a < 0) {
        a *= -1;
        isNegative = true;
    }
    if (a == 0) { res = "0"; }
    while (a > 0) {
        char number[2];
        number[0] = a % 10 + 48;
        number[1] = '\0';
        res = number + res;
        a /= 10;
    }
    if (isNegative) { res = "-" + res; }
    return res;
}

void GameMap::loadMap() {
    Configurator cfg("map.yml");
    castle_position_ = Position(-1, -1);
    height_ = cfg.getInt(MyString("Height"));
    width_ = cfg.getInt(MyString("Width"));
    map_ = new FieldType *[height_];
    for (int i = 0; i < height_; i++) {
        MyString line;
        line = cfg.getString(MyString("Line-") + intToString(i));
        if (line.getLength() != width_) { throw std::runtime_error("Invalid map"); }
        map_[i] = new FieldType[width_];
        for (int j = 0; j < width_; j++) {
            char cell = line[j];
            if (cell == '.') { map_[i][j] = FieldType::PLAIN; }
            else if (cell == '~') { map_[i][j] = FieldType::WATER; }
            else if (cell == '^') { map_[i][j] = FieldType::MOUNTAIN; }
            else if (cell == '@') {
                map_[i][j] = FieldType::PLAIN;
                castle_position_.y_ = i;
                castle_position_.x_ = j;
            } else if (cell == '*') {
                map_[i][j] = FieldType::PLAIN;
                Position pos(j, i);
                lairs_positions_.insert(pos, 0);
            } else throw std::runtime_error("Invalid map");
        }
    }
    if (castle_position_ == Position(-1, -1)) {
        throw std::runtime_error("Invalid map");
    }
    if (lairs_positions_.getLen() < 1) { throw std::runtime_error("Invalid map"); }
}

void GameMap::loadGraphs() {
    road_graph_ = new Graph<Position>;
    road_graph_with_wall_ = new Graph<Position>;
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            if (getFieldType(j, i) == FieldType::PLAIN) {
                road_graph_with_wall_->addVertex(Position(j, i));
                road_graph_->addVertex(Position(j, i));
            }
        }
    }
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            if (getFieldType(j, i) == FieldType::PLAIN) {
                if (i + 1 < height_ && getFieldType(j, i + 1) == FieldType::PLAIN) {
                    road_graph_with_wall_->addEdge(Position(j, i), Position(j, i + 1));
                    road_graph_->addEdge(Position(j, i), Position(j, i + 1));
                }
                if (j + 1 < width_ && getFieldType(j + 1, i) == FieldType::PLAIN) {
                    road_graph_with_wall_->addEdge(Position(j, i), Position(j + 1, i));
                    road_graph_->addEdge(Position(j, i), Position(j + 1, i));
                }
            }
        }
    }
}

void GameMap::deleteRoadCell(Position pos, bool in_road_graph_, bool in_road_graph_with_wall_) {
    if (in_road_graph_) { road_graph_->rmVertex(pos); }
    if (in_road_graph_with_wall_) { road_graph_with_wall_->rmVertex(pos); }
}

void GameMap::addRoadCell(Position pos, bool in_road_graph_, bool in_road_graph_with_wall_) {
    if (in_road_graph_) {
        road_graph_->addVertex(pos);
        if (pos.y_ - 1 >= 0 && road_graph_->hasVertex(Position(pos.x_, pos.y_ - 1))) {
            road_graph_->addEdge(pos, Position(pos.x_, pos.y_ - 1));
        }
        if (pos.y_ + 1 < height_ && road_graph_->hasVertex(Position(pos.x_, pos.y_ + 1))) {
            road_graph_->addEdge(pos, Position(pos.x_, pos.y_ + 1));
        }
        if (pos.x_ - 1 >= 0 && road_graph_->hasVertex(Position(pos.x_ - 1, pos.y_))) {
            road_graph_->addEdge(pos, Position(pos.x_ - 1, pos.y_));
        }
        if (pos.x_ + 1 < width_ && road_graph_->hasVertex(Position(pos.x_ + 1, pos.y_))) {
            road_graph_->addEdge(pos, Position(pos.x_ + 1, pos.y_));
        }
    }
    if (in_road_graph_with_wall_) {
        road_graph_with_wall_->addVertex(pos);
        if (pos.y_ - 1 >= 0 && road_graph_->hasVertex(Position(pos.x_, pos.y_ - 1))) {
            road_graph_with_wall_->addEdge(pos, Position(pos.x_, pos.y_ - 1));
        }
        if (pos.y_ + 1 < height_ && road_graph_->hasVertex(Position(pos.x_, pos.y_ + 1))) {
            road_graph_with_wall_->addEdge(pos, Position(pos.x_, pos.y_ + 1));
        }
        if (pos.x_ - 1 >= 0 && road_graph_->hasVertex(Position(pos.x_ - 1, pos.y_))) {
            road_graph_with_wall_->addEdge(pos, Position(pos.x_ - 1, pos.y_));
        }
        if (pos.x_ + 1 < width_ && road_graph_->hasVertex(Position(pos.x_ + 1, pos.y_))) {
            road_graph_with_wall_->addEdge(pos, Position(pos.x_ + 1, pos.y_));
        }
    }
}

int GameMap::getHeight() const {
    return height_;
}

int GameMap::getWidth() const {
    return width_;
}

Position GameMap::getCastlePosition() const {
    return castle_position_;
}

List<Position> GameMap::getLairsPositions() const {
    return lairs_positions_;
}

GameMap::~GameMap() {
    for (int i = 0; i < height_; i++) {
        delete[] map_[i];
    }
    delete[] map_;
    delete road_graph_;
    delete road_graph_with_wall_;

}
