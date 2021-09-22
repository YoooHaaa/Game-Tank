#pragma once
#include "head.h"
#include "MoveObj.h"
#include "Map.h"

class BULLET:public CMOVEOBJ//子弹类
{
public:
    BULLET();
    ~BULLET();

    int move();//子弹前进,返回碰撞结果
    void clear_coord_info();
    void write_coord_info(int nCoordInfo);

    int crash(int x, int y);//碰撞判断，返回碰撞结果
    void set_belong(int nBelong);//设置子弹归属
    
    void set_enemy_coord(int x, int y);//设置被摧毁的敌方坦克坐标
    static int get_enemy_coord_x();//获取被摧毁的敌方坦克坐标
    static int get_enemy_coord_y();//获取被摧毁的敌方坦克坐标

    void set_destroy_bullet_coord(int x, int y);//设置被摧毁子弹的坐标
    int get_destroy_bullet_coord_x() const;//获取被摧毁子弹的坐标
    int get_destroy_bullet_coord_y() const;

    enum CRASH
    {
        CRASH_NONE,
        CRASH_WALL,
        CRASH_STONE,
        CRASH_HOME,
        CRASH_PLAYER,
        CRASH_BULLET,
        CRASH_ENEMY
    };
    enum BELONG
    {
        PLAYER,
        ENEMY
    };

private:
    CMAP map;

    clock_t tStart;

    static int nBeDestroyX;//被摧毁的敌方坦克坐标
    static int nBeDestroyY;

    static int nBulletX;//相撞的子弹的坐标
    static int nBulletY;//相撞的子弹的坐标

    int nBelong;//子弹归属
};