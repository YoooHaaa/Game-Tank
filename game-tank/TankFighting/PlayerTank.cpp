#include "PlayerTank.h"


PLAYERTANK::PLAYERTANK()
{
    if (map.get_info(8, 18) == CMAP::GRAPH_BLACK)
    {
        set_coord(8, 18);
        set_direction(OBJ_UP);
    }
    else
    {
        set_coord(12, 18);
        set_direction(OBJ_UP);
    }
    
    write_coord_info(CMAP::PLAYERTANK_UP);
            
    pBullet = nullptr;
}
PLAYERTANK::~PLAYERTANK()
{
    if (pBullet != nullptr)
    {
        delete pBullet;
    }
}

void PLAYERTANK::creat_bullet()//创造子弹
{
    if (pBullet == nullptr)
    {
        pBullet = new BULLET();
        pBullet->set_belong(BULLET::PLAYER);       
        pBullet->set_direction(get_direction());   

        switch (get_direction())
        {
            case OBJ_UP:
                pBullet->set_coord(get_x(), get_y() - 1);
                break;
            case OBJ_DOWN:
                pBullet->set_coord(get_x(), get_y() + 1);
                break;
            case OBJ_LEFT:
                pBullet->set_coord(get_x() - 1, get_y());
                break;
            case OBJ_RIGHT:
                pBullet->set_coord(get_x() + 1, get_y());
                break;
            default:break;
        }
    }
}

void PLAYERTANK::destroy_bullet()//摧毁子弹
{    
    if (pBullet != nullptr)
    {
        switch (map.get_info(pBullet->get_x(), pBullet->get_y()))
        {
            case CMAP::BULLET_UP:
            case CMAP::BULLET_DOWN:
            case CMAP::BULLET_LEFT:
            case CMAP::BULLET_RIGHT:
               pBullet->clear_coord_info();
                break;
            default:break;
        }
        delete pBullet;
        pBullet = nullptr;
    }
}
int PLAYERTANK::move_bullet()//移动子弹
{
    if (pBullet == nullptr)
    {
        return BULLET::CRASH_NONE;
    }
    return pBullet->move();
}
int PLAYERTANK::get_bullet_crash_bullet_x() const//获取碰撞子弹的坐标
{
    if (pBullet != nullptr)
    {
        return pBullet->get_destroy_bullet_coord_x();
    }
    return 0;
}
int PLAYERTANK::get_bullet_crash_bullet_y() const//获取碰撞子弹的坐标
{
    if (pBullet != nullptr)
    {
        return pBullet->get_destroy_bullet_coord_y();
    }
    return 0;
}
int PLAYERTANK::get_bullet_crash_tank_x() const//获取碰撞坦克的坐标
{
    if (pBullet != nullptr)
    {
        return pBullet->get_enemy_coord_x();
    }
    return 0;
}
int PLAYERTANK::get_bullet_crash_tank_y() const//获取碰撞坦克的坐标
{
    if (pBullet != nullptr)
    {
        return pBullet->get_enemy_coord_y();
    }
    return 0;
}
bool PLAYERTANK::has_bullet()
{
    if (pBullet == nullptr)
    {
        return false;
    }
    return true;
}
int PLAYERTANK::get_bullet_x() const
{
    if (pBullet != nullptr)
    {
        return pBullet->get_x();
    }
    return 0;
}
int PLAYERTANK::get_bullet_y() const
{
    if (pBullet != nullptr)
    {
        return pBullet->get_y();
    }
    return 0;
}