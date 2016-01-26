#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 10
#define HEIGHT 10
int numberOfNeighbours(unsigned grid[WIDTH][HEIGHT], int x, int y);

void seed (unsigned grid[WIDTH][HEIGHT]) {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            grid[x][y] = rand() < RAND_MAX / 3 ? 1 : 0;
        }
    }
   }

void show (unsigned grid[WIDTH][HEIGHT]) {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }
}

void evolve (unsigned grid[WIDTH][HEIGHT]) {
    unsigned gridcopy[WIDTH][HEIGHT];
    int x = 0; int y = 0;
    int neighbours = 0;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
           neighbours = numberOfNeighbours(grid, x, y); 
           if (neighbours < 2)
                gridcopy[x][y] = 0;    
           else if (grid[x][y] && (neighbours == 2 || neighbours == 3))
               gridcopy[x][y] = 1;
           else if (neighbours > 3)
               gridcopy[x][y] = 0;
           else if (grid[x][y] == 0 && neighbours == 3) 
               gridcopy[x][y] = 1;
           else 
               gridcopy[x][y] = grid[x][y];
        }
    }

    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j)
            grid[i][j] = gridcopy[i][j];
    }
}

int numberOfNeighbours(unsigned grid[WIDTH][HEIGHT], int x, int y) {
    int dead = (grid[x][y] == 0 ) ? 0 : 1;
    int neighbours = 0;
    //Edge cases
    //Top left
    if (x == 0 && y == 0) {
        if (grid[x+1][y] == 1) 
            neighbours++;
        if (grid[x][y-1] == 1)
            neighbours++;
        if (grid[x+1][y-1] == 1)
            neighbours++;
    }
    //Left side
    if (x == 0 && y != 0 && y != HEIGHT) {
        if (grid[x][y+1] == 1)
            neighbours++;
        if (grid[x+1][y] == 1)
            neighbours++;
        if (grid[x][y-1] == 1)
            neighbours++;
        if (grid[x+1][y-1] == 1)
            neighbours++;
        if (grid[x+1][y+1] == 1)
            neighbours++;
    }
    //Bottom left
    if (x == 0 && y == HEIGHT) {
        if (grid[x+1][y] == 1)
            neighbours++;
        if (grid[x+1][y+1] == 1)
            neighbours++;
        if (grid[x][y-1] == 1)
            neighbours++;
    }
    //Bottom
    if (x != 0 && y == HEIGHT && x != WIDTH) {
        if (grid[x-1][y] == 1)
            neighbours++;
        if (grid[x+1][y] == 1)
            neighbours++;
        if (grid[x][y-1] == 1)
            neighbours++;
        if (grid[x+1][y-1] == 1)
            neighbours++;
        if (grid[x-1][y-1] == 1)
            neighbours++;
    }
    //Bottom right
    if (x == WIDTH && y == HEIGHT) {
        if (grid[x-1][y] == 1) 
            neighbours++;
        if (grid[x-1][y-1] == 1)
            neighbours++;
        if (grid[x][y-1] == 1)
            neighbours++;
    }

    // Top right
    if (x == WIDTH && y == 0) 
    {
        if (grid[x-1][y] == 1)
            neighbours++;
        if (grid[x-1][y+1] == 1)
            neighbours++;
        if (grid[x][y+1] == 1)
            neighbours++;
    }

    // Right
    if (x == WIDTH && y != 0 && y != HEIGHT) 
    {
        if (grid[x-1][y] == 1)
            neighbours++;
        if (grid[x-1][y+1] == 1)
            neighbours++;
        if (grid[x][y-1] == 1)
            neighbours++;
        if (grid[x][y+1] == 1)
            neighbours++;
        if (grid[x-1][y-1] == 1)
            neighbours++;
    }

    
    // Top
    if (x != 0 && x != WIDTH && y == 0)
    {
        if (grid[x-1][y] == 1)
            neighbours++;
        if (grid[x-1][y+1] == 1)
            neighbours++;
        if (grid[x][y+1] == 1)
            neighbours++;
        if (grid[x+1][y+1] == 1)
            neighbours++;
        if (grid[x+1][y] == 1)
            neighbours++;
    }
    
    if (x != 0 && x != WIDTH && y != 0 && y != HEIGHT) 
    {
        if (grid[x-1][y] == 1)
            neighbours++;
        if (grid[x-1][y-1] == 1)
            neighbours++;
        if (grid[x-1][y+1] == 1)
            neighbours++;
        if (grid[x][y-1] == 1) 
            neighbours++;
        if (grid[x][y+1] == 1)
            neighbours++;
        if (grid[x+1][y] == 1)
            neighbours++;
        if (grid[x+1][y-1] == 1)
            neighbours++;
        if (grid[x+1][y+1] == 1)
            neighbours++;
    }


    return neighbours;
}

void game () {
    unsigned grid[WIDTH][HEIGHT];
    seed(grid);
        //Glider
/*         = {{0,0,1,0,0,0,0,0,0,0},
            {0,0,0,1,0,0,0,0,0,0},
            {0,1,1,1,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}};
            */
    while (1) {
        show(grid);
        printf("\n\n");
        evolve(grid);
        sleep(1);
    }
}

int main () {
    int w = 10, h = 10;
        game();
}
