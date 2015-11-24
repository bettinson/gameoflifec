#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 10
#define HEIGHT 10

void seed (unsigned grid[WIDTH][HEIGHT]) {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            grid[x][y] = rand() < RAND_MAX / 10 ? 1 : 0;
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
    //Edge cases
    int x = 0;
    int y = 0;

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            //Top left
            if (x == 0 && y == 0) {
                
            }
        }
    }

}

int numberOfNeighbours(unsigned grid[WIDTH][HEIGHT], int x, int y) {

    int dead = (grid[x][y] == 0 ) ? 0 : 1;
    int neighbours = 0;

    //if (grid[

    return neighbours;
}

void game (int w, int h) {
    unsigned grid[w][h];
    seed(grid);
    show(grid);
}

int main () {
    int w = 10, h = 10;
    game(w, h);
}
