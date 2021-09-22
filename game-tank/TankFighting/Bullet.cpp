#include "Bullet.h"

int BULLET::nBulletX = 0;//相撞的子弹的坐标
int BULLET::nBulletY = 0;//相撞的子弹的坐标
int BULLET::nBeDestroyX = 0;//被摧毁的敌方坦克坐标
int BULLET::nBeDestroyY = 0;

BULLET::BULLET()
{
    tStart = clock();
}
BULLET::~BULLET()
{

}

int BULLET::move()//子弹前进,返回碰撞结果,返回CRASH_NONE表示没有碰撞，返回其他时，注意销毁子弹
{
    clock_t tCurrent = clock();

    switch (map.get_info(get_x(), get_y()))//处理刚出膛子弹
    {
        case CMAP::GRAPH_BLACK:
            switch (get_direction())
            {
                case OBJ_UP:
                    write_coord_info(OBJ_UP);
                    break;
                case OBJ_DOWN:
                    write_coord_info(OBJ_DOWN);
                    break;
                case OBJ_LEFT:
                    write_coord_info(OBJ_LEFT);
                    break;
                case OBJ_RIGHT:
                    write_coord_info(OBJ_RIGHT);
                    break;
                default:break;
            }
            break;
        case CMAP::BULLET_UP://子弹出膛之后每次循环都会跳到这里
        case CMAP::BULLET_DOWN:
        case CMAP::BULLET_LEFT:
        case CMAP::BULLET_RIGHT:
            break;
        case CMAP::GRAPH_WALL:
        case CMAP::GRAPH_STONE:
        case CMAP::GRAPH_HOME:
        case CMAP::PLAYERTANK_UP:
        case CMAP::PLAYERTANK_DOWN:
        case CMAP::PLAYERTANK_LEFT:
        case CMAP::PLAYERTANK_RIGHT:
        case CMAP::ENEMYTANK_UP:
        case CMAP::ENEMYTANK_DOWN:
        case CMAP::ENEMYTANK_LEFT:
        case CMAP::ENEMYTANK_RIGHT:
            return crash(get_x(), get_y());
        default:break;
    }
   
    if (tCurrent - tStart > 100)
    {
        tStart = tCurrent;
   
        switch (get_direction())
        {
            case OBJ_UP:
                if (map.get_info(get_x(), get_y() - 1) == CMAP::GRAPH_BLACK)
                {
                    clear_coord_info();
                    set_coord(get_x(), get_y() - 1);
                    write_coord_info(OBJ_UP);
                }
                else
                {
                    return crash(get_x(), get_y() - 1);
                }
                break;
            case OBJ_DOWN:
                
                if (map.get_info(get_x(), get_y() + 1) == CMAP::GRAPH_BLACK)
                {  
                    clear_coord_info();
                    set_coord(get_x(), get_y() + 1);
                    write_coord_info(OBJ_DOWN);
                }
                else
                {
                    return crash(get_x(), get_y() + 1);
                }
                break;
            case OBJ_LEFT:
                if (map.get_info(get_x() - 1, get_y()) == CMAP::GRAPH_BLACK)
                {
                    clear_coord_info();
                    set_coord(get_x() - 1, get_y());
                    write_coord_info(OBJ_LEFT);
                }
                else
                {
                    return crash(get_x() - 1, get_y());
                }
                break;
            case OBJ_RIGHT:
                if (map.get_info(get_x() + 1, get_y()) == CMAP::GRAPH_BLACK)
                {
                    clear_coord_info();
                    set_coord(get_x() + 1, get_y());
                    write_coord_info(OBJ_RIGHT);
                }
                else
                {
                    return crash(get_x() + 1, get_y());
                }
                break;
            default:break;
        }
    }
    return CRASH_NONE;
}
void BULLET::clear_coord_info()
{
    map.modify_map(get_x(), get_y(), CMAP::GRAPH_BLACK);
}
void BULLET::write_coord_info(int nCoordInfo)
{

    switch (nCoordInfo)
    {
        case OBJ_UP:
            map.modify_map(get_x(), get_y(), CMAP::BULLET_UP);
            break;
        case OBJ_DOWN:
            map.modify_map(get_x(), get_y(), CMAP::BULLET_DOWN);
            break;
        case OBJ_LEFT:
            map.modify_map(get_x(), get_y(), CMAP::BULLET_LEFT);
            break;
        case OBJ_RIGHT:
            map.modify_map(get_x(), get_y(), CMAP::BULLET_RIGHT);
            break;
        default:break;
    }
}

int BULLET::crash(int x, int y)//碰撞判断，返回碰撞结果
{
    switch (map.get_info(x, y))
    {
        case CMAP::GRAPH_WALL:
            map.be_attack(x, y);           
            return CRASH_WALL;

        case CMAP::GRAPH_STONE:
            return CRASH_STONE;

        case CMAP::GRAPH_HOME:
            map.be_attack(x, y);
            map.draw_map();
            return CRASH_HOME;

        case CMAP::PLAYERTANK_UP:
        case CMAP::PLAYERTANK_DOWN:
        case CMAP::PLAYERTANK_LEFT:
        case CMAP::PLAYERTANK_RIGHT:
            return CRASH_PLAYER;

        case CMAP::ENEMYTANK_UP:
        case CMAP::ENEMYTANK_DOWN:
        case CMAP::ENEMYTANK_LEFT:
        case CMAP::ENEMYTANK_RIGHT:
            if (nBelong == PLAYER)
            {
                set_enemy_coord(x, y);
                return CRASH_ENEMY;
            }
            return CRASH_ENEMY;
            break;

        case CMAP::BULLET_UP:
        case CMAP::BULLET_DOWN:
        case CMAP::BULLET_LEFT:
        case CMAP::BULLET_RIGHT:

            set_destroy_bullet_coord(x, y);
            return CRASH_BULLET;

        default:break;
    }
    return CRASH_NONE;     
}

void BULLET::set_belong(int nBelong)//设置子弹归属
{
    this->nBelong = nBelong;
}
void BULLET::set_enemy_coord(int x, int y)//设置被摧毁的敌方坦克坐标
{
    nBeDestroyX = x;
    nBeDestroyY = y;
}
int BULLET::get_enemy_coord_x()//获取被摧毁的敌方坦克坐标
{
    return nBeDestroyX;
}
int BULLET::get_enemy_coord_y()//获取被摧毁的敌方坦克坐标
{
    return nBeDestroyY;
}
void BULLET::set_destroy_bullet_coord(int x, int y)//设置被摧毁子弹的坐标
{
    nBulletX = x;
    nBulletY = y;
}

int BULLET::get_destroy_bullet_coord_x() const//获取被摧毁子弹的坐标
{
    return nBulletX;
}

int BULLET::get_destroy_bullet_coord_y() const
{
    return nBulletY;
}