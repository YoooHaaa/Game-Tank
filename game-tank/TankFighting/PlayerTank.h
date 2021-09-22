#pragma once
#include "head.h"
#include "MoveObj.h"
#include "Bullet.h"
#include "Map.h"


class PLAYERTANK :public CMOVEOBJ
{
public:
    PLAYERTANK();
    ~PLAYERTANK();

    void creat_bullet();//创造子弹
    int move_bullet();//移动子弹
    void destroy_bullet();//摧毁子弹

    int get_bullet_x() const;
    int get_bullet_y() const;

    int get_bullet_crash_bullet_x() const;//获取碰撞子弹的坐标
    int get_bullet_crash_bullet_y() const;//获取碰撞子弹的坐标

    bool has_bullet();

    int get_bullet_crash_tank_x() const;//获取碰撞坦克的坐标
    int get_bullet_crash_tank_y() const;//获取碰撞坦克的坐标

private:
    BULLET *pBullet;
    CMAP map;
};
