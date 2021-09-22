#include "Bullet.h"

int BULLET::nBulletX = 0;//��ײ���ӵ�������
int BULLET::nBulletY = 0;//��ײ���ӵ�������
int BULLET::nBeDestroyX = 0;//���ݻٵĵз�̹������
int BULLET::nBeDestroyY = 0;

BULLET::BULLET()
{
    tStart = clock();
}
BULLET::~BULLET()
{

}

int BULLET::move()//�ӵ�ǰ��,������ײ���,����CRASH_NONE��ʾû����ײ����������ʱ��ע�������ӵ�
{
    clock_t tCurrent = clock();

    switch (map.get_info(get_x(), get_y()))//����ճ����ӵ�
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
        case CMAP::BULLET_UP://�ӵ�����֮��ÿ��ѭ��������������
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

int BULLET::crash(int x, int y)//��ײ�жϣ�������ײ���
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

void BULLET::set_belong(int nBelong)//�����ӵ�����
{
    this->nBelong = nBelong;
}
void BULLET::set_enemy_coord(int x, int y)//���ñ��ݻٵĵз�̹������
{
    nBeDestroyX = x;
    nBeDestroyY = y;
}
int BULLET::get_enemy_coord_x()//��ȡ���ݻٵĵз�̹������
{
    return nBeDestroyX;
}
int BULLET::get_enemy_coord_y()//��ȡ���ݻٵĵз�̹������
{
    return nBeDestroyY;
}
void BULLET::set_destroy_bullet_coord(int x, int y)//���ñ��ݻ��ӵ�������
{
    nBulletX = x;
    nBulletY = y;
}

int BULLET::get_destroy_bullet_coord_x() const//��ȡ���ݻ��ӵ�������
{
    return nBulletX;
}

int BULLET::get_destroy_bullet_coord_y() const
{
    return nBulletY;
}