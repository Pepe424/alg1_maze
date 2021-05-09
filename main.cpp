#include <stdio.h>
#include "maze.h"


int main()
{
    Maze m;

    m.LoadMazeFromFile("input_maze.txt");
    m.PrintMaze();
    m.Solve();
    m.PrintMaze();
    m.SaveMazeToFile("output_maze.txt");

    return 0;
}