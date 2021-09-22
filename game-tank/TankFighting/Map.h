#pragma once
#include "head.h"


class CMAP//地图信息类
{
public:
    CMAP();
    ~CMAP();
    void init_map();//初始化地图,由于地图是静态的，所以只能在playgame的构造里初始化一次，子弹和坦克类里的地图成员无需初始化地图
    void test_map1();//测试地图
    void test_map2();//测试地图
    void draw_map();//画地图
    void win_map();
    void lose_map();

    void be_attack(int xAttack, int yAttack);//墙受到攻击，砖墙就会被销毁，铁墙没影响,参数为被子弹攻击点的坐标

    void modify_map(int nX, int nY, int nMapFlag);//子弹和坦克把自己的坐标传进来，修改地图，所有成员公用一张地图。

    int get_info(int nX, int nY) const;//获取坐标点的信息

    enum MAPSIZE
    {
        HIGH = 20,
        WIDTH = 22,
        MULTIPLE = 30//放大的倍数
    };
    enum MAPFLAG//用于打印时作为标识
    {
        //地图信息
        GRAPH_BLACK,
        GRAPH_WALL,
        GRAPH_STONE,
        GRAPH_HOME,

        //玩家坦克信息
        PLAYERTANK_UP,
        PLAYERTANK_DOWN,
        PLAYERTANK_LEFT,
        PLAYERTANK_RIGHT,

        //敌方坦克信息
        ENEMYTANK_UP ,       
        ENEMYTANK_DOWN,
        ENEMYTANK_LEFT,
        ENEMYTANK_RIGHT,

        //子弹信息
        BULLET_UP,
        BULLET_DOWN,
        BULLET_LEFT,
        BULLET_RIGHT,

        //坦克爆炸图片
        TANKBOOM,
        //标记的总个数
        FLAGSIZE 
    };
private:
    void LoadImages();//装载图片
private:
    static char szMap[HIGH][WIDTH];
    IMAGE image[FLAGSIZE];
};