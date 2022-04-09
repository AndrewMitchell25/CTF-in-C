#include "gfx.h"
#include <stdio.h>
#include <stdlib.h>
#define WINDOWX 700
#define WINDOWY 500
#define PCOUNT 2
#define PSIZE 15
#define PXI 100
#define PYI WINDOWY/2
#define PSPEED 4

typedef struct {
    int pnum;
    int x;
    int y;
    int vx;
    int vy;
} Player;

typedef struct {
    int pickedUp;
    int x;
    int y;
} Flag;

typedef struct {
    int length;
    int x;
    int y;
} Wall;

void showMenu();
void setup(Player []);
void update(Player []);
void fixedUpdate(Player []);
void reset(Player []);
void drawBackground();
void setupPlayer(Player*);
void drawPlayer(Player);