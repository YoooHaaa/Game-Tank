#include "MoveObj.h"


CMOVEOBJ::CMOVEOBJ()
{
    
}

CMOVEOBJ::~CMOVEOBJ()
{

}
void CMOVEOBJ::clear_coord_info()//清除坐标信息
{
    map.modify_map(nX, nY, CMAP::GRAPH_BLACK);
}
void CMOVEOBJ::write_coord_info(int nCoordInfo)//写入坐标信息
{
    switch (nCoordInfo)
    {
        case CMAP::PLAYERTANK_UP:
            map.modify_map(nX, nY, CMAP::PLAYERTANK_UP);
            break;
        case CMAP::PLAYERTANK_DOWN:
            map.modify_map(nX, nY, CMAP::PLAYERTANK_DOWN);
            break;
        case CMAP::PLAYERTANK_LEFT:
            map.modify_map(nX, nY, CMAP::PLAYERTANK_LEFT);
            break;
        case CMAP::PLAYERTANK_RIGHT:
            map.modify_map(nX, nY, CMAP::PLAYERTANK_RIGHT);
            break;
        case CMAP::ENEMYTANK_UP:
            map.modify_map(nX, nY, CMAP::ENEMYTANK_UP);
            break;
        case CMAP::ENEMYTANK_DOWN:
            map.modify_map(nX, nY, CMAP::ENEMYTANK_DOWN);
            break;
        case CMAP::ENEMYTANK_LEFT:
            map.modify_map(nX, nY, CMAP::ENEMYTANK_LEFT);
            break;
        case CMAP::ENEMYTANK_RIGHT:
            map.modify_map(nX, nY, CMAP::ENEMYTANK_RIGHT);
            break;
        default:break;
    }
}
void CMOVEOBJ::move(int nCoordInfo)//移动，此方法继承给坦克用。子弹类会重新覆盖该函数
{
    switch (nDirection)
    {
        case OBJ_UP:
            write_coord_info(nCoordInfo);
            if (map.get_info(nX, nY - 1) == CMAP::GRAPH_BLACK)
            {
                clear_coord_info();
                set_coord(nX, nY - 1);
                write_coord_info(nCoordInfo);
            }
            break;
        case OBJ_DOWN:
            write_coord_info(nCoordInfo);
            if (map.get_info(nX, nY + 1) == CMAP::GRAPH_BLACK)
            {
                clear_coord_info();
                set_coord(nX, nY + 1);
                write_coord_info(nCoordInfo);
            }
            break;
        case OBJ_LEFT:
            write_coord_info(nCoordInfo);
            if (map.get_info(nX - 1, nY) == CMAP::GRAPH_BLACK)
            {                
                clear_coord_info(); 
                set_coord(nX - 1, nY);
                write_coord_info(nCoordInfo);
            }
            break;
        case OBJ_RIGHT:
            write_coord_info(nCoordInfo);
            if (map.get_info(nX + 1, nY) == CMAP::GRAPH_BLACK)
            {
                clear_coord_info();
                set_coord(nX + 1, nY);
                write_coord_info(nCoordInfo);
            }
            break;
        default:break;
    }
}
void CMOVEOBJ::set_coord(int x, int y)//设置移动物坐标
{
    nX = x;
    nY = y;
}
void CMOVEOBJ::set_direction(int nDire)//设置方向
{
    nDirection = nDire;
}
int CMOVEOBJ::get_x() const
{
    return nX;
}
int CMOVEOBJ::get_y() const
{
    return nY;
}
int CMOVEOBJ::get_direction() const
{
    return nDirection;
}