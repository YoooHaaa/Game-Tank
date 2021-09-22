#include "EnemyTank.h"

int ENEMYTANK::nTankCount = 20;//ʣ��̹������
int ENEMYTANK::nTankNow = 0;//�ִ�̹������

ENEMYTANK::ENEMYTANK(int x, int y)
{
    set_coord(x, y);
    pBullet = nullptr;
    tStartMove = clock();
    tStartBullet = clock();

    write_coord_info(CMAP::ENEMYTANK_DOWN);           
}
ENEMYTANK::~ENEMYTANK()
{
    if (pBullet != nullptr)
    {
        delete pBullet;
    }
}
void ENEMYTANK::intelligent_move()//�����ƶ�
{
    clock_t tCurrent = clock();


    if (tCurrent - tStartMove > 500)
    {
        tStartMove = tCurrent;

        if (get_x() - 10 < 0)
        {
            if (get_y() - 18 < 0)//̹�������Ͻ�
            {
                if ((rand() % 2) == 0)
                {
                    set_direction(OBJ_DOWN);
                    move(CMAP::ENEMYTANK_DOWN);
                }
                else
                {
                    set_direction(OBJ_RIGHT);
                    move(CMAP::ENEMYTANK_RIGHT);
                }
            }
            else//̹������߻����½�
            {
                if ((rand() % 2) == 0)
                {
                    set_direction(OBJ_UP);
                    move(CMAP::ENEMYTANK_UP);
                }
                else
                {
                    set_direction(OBJ_RIGHT);
                    move(CMAP::ENEMYTANK_RIGHT);
                }
            }
        }
        else if (get_x() - 10 == 0)//̹�������Ϸ�
        {
            switch (rand() % 3)
            {
                case 0:
                    set_direction(OBJ_RIGHT);
                    move(CMAP::ENEMYTANK_RIGHT);
                    break;
                case 1:
                    set_direction(OBJ_DOWN);
                    move(CMAP::ENEMYTANK_DOWN);
                    break;
                case 2:
                    set_direction(OBJ_LEFT);
                    move(CMAP::ENEMYTANK_LEFT);
                    break;
                default:break;
            }
        }
        else
        {
            if (get_y() - 18 < 0)//̹�������Ͻ�
            {
                if ((rand() % 2) == 0)
                {
                    set_direction(OBJ_DOWN);
                    move(CMAP::ENEMYTANK_DOWN);
                }
                else
                {
                    set_direction(OBJ_LEFT);
                    move(CMAP::ENEMYTANK_LEFT);
                }
            }
            else//̹�����ұ߻����½�
            {
                if ((rand() % 2) == 0)
                {
                    set_direction(OBJ_UP);
                    move(CMAP::ENEMYTANK_UP);
                }
                else
                {
                    set_direction(OBJ_LEFT);
                    move(CMAP::ENEMYTANK_LEFT);
                }
            }
        }
    }
}
void ENEMYTANK::random_move()//����ƶ�
{
    clock_t tCurrent = clock();
    
    if (tCurrent - tStartMove > 500)
    {
        tStartMove = tCurrent;

        switch (rand() % 4)
        {
            case 0:
                set_direction(OBJ_UP);
                move(CMAP::ENEMYTANK_UP);
                break;
            case 1:
                set_direction(OBJ_DOWN);
                move(CMAP::ENEMYTANK_DOWN);
                break;
            case 2:
                set_direction(OBJ_LEFT);
                move(CMAP::ENEMYTANK_LEFT);
                break;
            case 3:
                set_direction(OBJ_RIGHT);
                move(CMAP::ENEMYTANK_RIGHT);
                break;
            default:break;
        }
    }
}
void ENEMYTANK::creat_bullet()//�����ӵ�
{
    clock_t tCurrent = clock();

    if (tCurrent - tStartBullet > 500)
    {
        tStartBullet = tCurrent;

        if (has_bullet() == false)
        {
            if (rand() % 2 == 0)
            {
                if (pBullet == nullptr)
                {
                    pBullet = new BULLET;
                    pBullet->set_belong(BULLET::ENEMY);
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
        }
        
    }
}


void ENEMYTANK::destroy_bullet()//�ݻ��ӵ�
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

int ENEMYTANK::get_bullet_x() const
{
    if (pBullet != nullptr)
    {
        return pBullet->get_x();
    }
    return 0;
}
int ENEMYTANK::get_bullet_y() const
{
    if (pBullet != nullptr)
    {
        return pBullet->get_y();
    }
    return 0;
}
int ENEMYTANK::move_bullet()//�ƶ��ӵ�
{
    if (pBullet == nullptr)
    {
        return BULLET::CRASH_NONE;
    }
    return pBullet->move();
}
bool ENEMYTANK::has_bullet()
{
    if (pBullet == nullptr)
    {
        return false;
    }
    return true;
}
int ENEMYTANK::get_bullet_crash_bullet_x() const//��ȡ��ײ�ӵ�������
{
    if (pBullet != nullptr)
    {
        return pBullet->get_destroy_bullet_coord_x();
    }
    return 0;
}
int ENEMYTANK::get_bullet_crash_bullet_y() const//��ȡ��ײ�ӵ�������
{
    if (pBullet != nullptr)
    {
        return pBullet->get_destroy_bullet_coord_y();
    }
    return 0;
}
int ENEMYTANK::get_tank_num() //��ȡ�ִ�̹����
{
    return nTankNow;
}

int ENEMYTANK::get_tank_count() //��ȡʣ��̹������
{
    return nTankCount;
}
void ENEMYTANK::add_tank_now()//����һ���ִ�̹����
{
    nTankNow++;
}
void ENEMYTANK::del_tank_now()//����һ���ִ�̹����
{
    nTankNow--;
}
void ENEMYTANK::del_tank_count()//����̹������
{
    nTankCount--;
}
void ENEMYTANK::set_bullet_crash_bullet_coord()//������ײ�ӵ�������
{
    pBullet->set_destroy_bullet_coord(0, 0);
}