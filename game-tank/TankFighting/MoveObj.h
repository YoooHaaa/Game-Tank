#pragma once
#include "head.h"
#include "Map.h"

class CMOVEOBJ//移动对象类
{
public:

    CMOVEOBJ();//
    ~CMOVEOBJ();

    void move(int nCoordInfo);//移动,传入调用者信息

    void clear_coord_info();//清除坐标信息
    void write_coord_info(int nCoordInfo);//写入坐标信息

    void set_coord(int x, int y);//设置移动物坐标
    void set_direction(int nDire);//设置方向

    int get_x() const;
    int get_y() const;
    int get_direction() const;

    enum DIRECTION
    {
        OBJ_UP,
        OBJ_DOWN,
        OBJ_LEFT,
        OBJ_RIGHT
    };
private:
    CMAP map;
    int nDirection;//方向
    int nX;
    int nY;
};