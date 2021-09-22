#pragma once
#include "head.h"
#include "MoveObj.h"
#include "Bullet.h"
#include "Map.h"



class ENEMYTANK :public CMOVEOBJ
{
public:

    ENEMYTANK(int x, int y);
    ~ENEMYTANK();

    void random_move();//随机移动，2个随机移动的傻瓜坦克
    void intelligent_move();//智能移动，4个智能移动的疯狂坦克

    void creat_bullet();//创造子弹
    int move_bullet();//移动子弹
    bool has_bullet();//查看是否有子弹
    void destroy_bullet();//摧毁子弹

    int get_bullet_x() const;
    int get_bullet_y() const;

    int get_bullet_crash_bullet_x() const;//获取碰撞子弹的坐标
    int get_bullet_crash_bullet_y() const;//获取碰撞子弹的坐标
    void set_bullet_crash_bullet_coord();//重置碰撞子弹的坐标
    
    /////////////////////////////////////////////////////////////////////////////////////////
    static int get_tank_num();//获取现存坦克数
    static int get_tank_count();//获取剩余坦克总数
    void add_tank_now();//增加一个现存坦克数
    void del_tank_now();//减少一个现存坦克数
    void del_tank_count();//减少坦克总数
    /////////////////////////////////////////////////////////////////////////////////////////


private:
    static int nTankCount;//剩余坦克总数
    static int nTankNow;//现存坦克总数
    clock_t tStartMove;//计算移动时间差
    clock_t tStartBullet;//计算射击时间差
    CMAP map;
    BULLET *pBullet;
};

