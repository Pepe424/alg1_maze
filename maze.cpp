#include "maze.h"

Maze::~Maze() {

    delete[] this->maze;
}

void Maze::LoadMazeFromFile(char *input) {

    FILE* file;

    if ((file = fopen(input, "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    else
    {
        fscanf(file, "%d", &this->row);
        fscanf(file, "%d", &this->col);
    }

    Allocation();

    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->maze[i][j] = getc(file);

            if (this->maze[i][j] == '\n')
            {
                this->maze[i][j] = getc(file);
            }

            if (this->maze[i][j] == '2')
            {
                this->start[0] = i;
                this->start[1] = j;
            }
        }
    }
    fclose(file);
}

void Maze::SaveMazeToFile(char *output) {

    FILE *file = fopen(output, "w");

    if (file != NULL)
    {
        fprintf(file, "%d\n", this->row);
        fprintf(file, "%d\n", this->col);

        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                fprintf(file, "%c", this->maze[i][j]);
            }
            fprintf(file, "\n");
        }
    }
    else
    {
        printf("Error! saving file");
    }
}

void Maze::PrintMaze() {

    printf("%d\n%d\n", row, col);

    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            printf("%c ", this->maze[i][j]);
        }
        printf("\n");
    }
}

void Maze::Allocation() {

    this->maze = (char**)malloc(this->row * sizeof(char*));

    for (int i = 0; i < this->row; i++)
    {
        this->maze[i] = (char*)malloc(this->col * sizeof(char*));
    }
}

void Maze::Solve() {

    int r = start[0];
    int c = start[1];

    while (this->maze[r][c + 1] != '3')
    {
        if (this->maze[r - 1][c] == '0')
            this->maze[--r][c] = '4';

        else if (this->maze[r][c + 1] == '0')
            this->maze[r][++c] = '4';

        else if (this->maze[r + 1][c] == '0')
            this->maze[++r][c] = '4';

        else if (this->maze[r][c - 1] == '0')
            this->maze[r][--c] = '4';

        // Coming back from blind allay
        else if (this->maze[r - 1][c] == '4')
            this->maze[r--][c] = '5';

        else if (this->maze[r][c + 1] == '4')
            this->maze[r][c++] = '5';

        else if (this->maze[r + 1][c] == '4')
            this->maze[r++][c] = '5';

        else if (this->maze[r][c - 1] == '4')
            this->maze[r][c--] = '5';

        else
            printf("Something went wrong!\n");
    }
    Clean();
}

void Maze::Clean() {

    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            if (this->maze[i][j] == '5')
            {
                this->maze[i][j] = '0';
            }
        }
    }
}




