#include <cstdio>
#include <iostream>

class Maze {

private:

    char** maze{};
    int start[2]{};
    int row{};
    int col{};

    void Allocation();
    void Clean();

public:

    ~Maze();

    void LoadMazeFromFile(char* input);
    void SaveMazeToFile(char* output);
    void PrintMaze();
    void Solve();

};