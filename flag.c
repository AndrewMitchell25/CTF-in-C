#include "flagfunc.h"

int main(){
    Player playerArray[PCOUNT];

    setup(playerArray);
    showMenu();
    update(playerArray);
    return 0;
}