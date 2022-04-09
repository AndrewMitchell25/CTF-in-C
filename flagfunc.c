# include "flagfunc.h"

void setup(Player playerArray[]){
    gfx_open(WINDOWX, WINDOWY, "Capture The Flag");
    gfx_color(32, 214, 81); 
    int i;

    for(i = 0; i<PCOUNT; i++){
        Player newPlayer = {i+1, 0, 0};
        setupPlayer(&newPlayer);
        playerArray[i] = newPlayer;
    }

    drawBackground();
}

void update(Player playerArray[]){
    char w, a, s, d, i, j, k, l, q; 
    int timer = 0;
    while(1){
        if(q == 'q') break;
        //can't use switch so we get multiple inputs
        if(w == 'w') playerArray[0].vy = PSPEED;
        if(a == 'a') playerArray[0].vx = -PSPEED;
        if(s == 's') playerArray[0].vy = -PSPEED;
        if(d == 'd') playerArray[0].vx = PSPEED;

        if(i == 'i') playerArray[1].vy = PSPEED;
        if(j == 'j') playerArray[1].vx = -PSPEED;
        if(k == 'k') playerArray[1].vy = -PSPEED;
        if(l == 'l') playerArray[1].vx = PSPEED;

        //reset
        w = 0;
        a = 0;
        s = 0;
        d = 0;
        i = 0;
        j = 0;
        k = 0;
        l = 0;
        
        while(gfx_event_waiting()){
            printf("hi");
            if(gfx_wait() == 'w') w = 'w';
            if(gfx_wait() == 'a') w = 'a';
            if(gfx_wait() == 's') w = 's';
            if(gfx_wait() == 'd') w = 'd';
            if(gfx_wait() == 'i') w = 'i';
            if(gfx_wait() == 'j') w = 'j';
            if(gfx_wait() == 'k') w = 'k';
            if(gfx_wait() == 'l') w = 'l';
            if(gfx_wait() == 'q') q = 'q';        
        }


        if(timer == 1000){
            fixedUpdate(playerArray);
            timer = 0;
            reset(playerArray);
        }
        timer++;
    }
}

void fixedUpdate(Player playerArray[]){
    gfx_clear();
    int i;
    for(i = 0; i < PCOUNT; i++){
        playerArray[i].x += playerArray[i].vx;
        playerArray[i].y += playerArray[i].vy;
        drawPlayer(playerArray[i]);
    }

    gfx_flush(); 
}

void reset(Player playerArray[]){
    int i;
    for(i = 0; i < PCOUNT; i++){
        playerArray[i].vx = 0;
        playerArray[i].vy = 0;
    }
}

void setupPlayer(Player* player){
    player->x = PXI;
    player->y = PYI;
    if(player->pnum % 2 == 0){
        player->x = WINDOWX-PXI;
    }
}

void drawPlayer(Player player){
    if(player.pnum % 2 == 1){
        //red
        gfx_color(181, 14, 14);
    } else {
        //blue
        gfx_color(20, 36, 204);
    }
    gfx_circle(player.x, player.y, PSIZE);
}

void drawBackground(){
    /*
    int i;
    for(i = 0; i < WINDOWX/2; i++){
        gfx_line(i, 0, i, WINDOWY);
    }
    gfx_color(7, 102, 33); 
    for(i = WINDOWX/2; i < WINDOWX; i++){
        gfx_line(i, 0, i, WINDOWY);
    }
    gfx_flush();
    */
    gfx_clear_color(7, 102, 33);

}