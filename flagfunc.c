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
    char a, b, c, d; 
    int i;
    int timer = 0;
    while(1){
        if(c == 'q') break;
        //can't use switch so we get multiple inputs
        if(a == 'w' || b == 'w' || c == 'w' || d == 'w') playerArray[0].vy = PSPEED;
        if(a == 'a' || b  == 'a' || c == 'a' || d == 'a') playerArray[0].vx = -PSPEED;
        if(a == 's' || b  == 's' || c == 's' || d == 's') playerArray[0].vy = -PSPEED;
        if(a == 'd' || b  == 'd' || c == 'd' || d == 'd') playerArray[0].vx = PSPEED;

        if(a == 'i' || b == 'i' || c == 'i' || d == 'i') playerArray[1].vy = PSPEED;
        if(a == 'j' || b  == 'j' || c == 'j' || d == 'j') playerArray[1].vx = -PSPEED;
        if(a == 'k' || b  == 'k' || c == 'k' || d == 'k') playerArray[1].vy = -PSPEED;
        if(a == 'l' || b  == 'l' || c == 'l' || d == 'l') playerArray[1].vx = PSPEED;

        //reset
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        
        if(gfx_event_waiting()){
            a = gfx_wait();
            printf("a : %c", a);
        }
        if(gfx_event_waiting()){
            b = gfx_wait();
            printf("b : %c", b);
        }
        if(gfx_event_waiting()){
            c = gfx_wait();
            printf("c : %c", c);
        }
        if(gfx_event_waiting()){
            d = gfx_wait();
            printf("d : %c", d);
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