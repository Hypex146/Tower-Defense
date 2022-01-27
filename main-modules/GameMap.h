#ifndef TOWER_DEFENSE_GAMEMAP_H
#define TOWER_DEFENSE_GAMEMAP_H


class TowerDefense;

enum class FieldType {
    WATER,
    MOUNTAIN,
    PLAIN
};

class GameMap {
private:
    int height_;
    int width_;
    FieldType **map_;
    TowerDefense *tower_defense_;
    Graph<Position> *road_graph_;
    Graph<Position> *road_graph_with_wall_;
    Position castle_position_;
    List<Position> lairs_positions_;

    MyString intToString(int a);

public:
    explicit GameMap(TowerDefense *tower_defense);

    ~GameMap();

    void loadMap();

    void loadGraphs();

    void deleteRoadCell(Position pos, bool in_road_graph_, bool in_road_graph_with_wall_);

    void addRoadCell(Position pos, bool in_road_graph_, bool in_road_graph_with_wall_);

    FieldType getFieldType(int x, int y) const;

    FieldType getFieldType(Position pos) const;

    const Graph<Position> *getRoadGraph() const;

    const Graph<Position> *getRoadGraphWithWall() const;

    int getHeight() const;

    int getWidth() const;

    List<Position> getLairsPositions() const;

    Position getCastlePosition() const;
};


#endif //TOWER_DEFENSE_GAMEMAP_H
