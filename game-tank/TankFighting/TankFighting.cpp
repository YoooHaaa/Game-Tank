#include "head.h"
#include "Map.h"
#include "PlayGame.h"

int main(int argc, char *argv[])
{
    initgraph((CMAP::WIDTH - 1) * CMAP::MULTIPLE, CMAP::HIGH * CMAP::MULTIPLE);
    srand((unsigned)time(nullptr));
 
    CPLAYGAME player;

    int nResult = player.game_start();
    system("pause");
    system("pause");

    player.print_result(nResult);

/*
    CMAP map;
    map.test_map1();
    system("pause");
    map.test_map2();
    system("pause");
    map.win_map();
    system("pause");
    map.lose_map();
    system("pause");
    system("pause");*/

    system("pause");
    system("pause");
    closegraph();
    return 0;
}