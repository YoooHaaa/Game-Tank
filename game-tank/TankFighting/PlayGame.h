#pragma once
#include "head.h"
#include "MoveObj.h"
#include "Bullet.h"
#include "EnemyTank.h"
#include "PlayerTank.h"
#include "Map.h"


class CPLAYGAME
{
public:
    CPLAYGAME();
    ~CPLAYGAME();


    bool game_start();//开始游戏
    void print_result(int nResult);//打印结果

    void create_player();//创造一个玩家

    void del_life();//减少生命值

    bool is_over();//判断是否结束游戏,false结束
    bool is_win();//判断是否获胜

    void player_operate_tank();//玩家操作坦克
    void enemy_operate_tank();//敌方操作坦克

    void destroy_player_tank();//摧毁玩家坦克
    void destroy_enemy_tank(ENEMYTANK *pTank);//摧毁敌方坦克

    bool bullet_control();//所有子弹的控制函数

private:
    CMAP CPlayGameMap;//用于初始化地图，并且只能用他初始化一次

    PLAYERTANK *pPlayerTank;//玩家坦克，三条命

    ENEMYTANK *pEnemyTank[6];//敌方坦克
    clock_t tStart;

    int nLifeCount;//玩家生命次数
};