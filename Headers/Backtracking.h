//
// Created by jorgegc on 16/05/23.
//

#ifndef PROYECTO2PACMAN_BACKTRACKING_H
#define PROYECTO2PACMAN_BACKTRACKING_H

#endif //PROYECTO2PACMAN_BACKTRACKING_H

class Backtracking{
public:
    static int PosEnemy;
    static int PosPower;
    static int arrPath[];
    static std::list<std::list<int>> paths;

    Backtracking();

    [[maybe_unused]] void findPath(int posEnemy, int posPower);
    void showPath();
    bool search(int x);
private:

    static int arrayLabyrinth[];
};