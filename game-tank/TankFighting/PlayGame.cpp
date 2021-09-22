#include "PlayGame.h"


CPLAYGAME::CPLAYGAME()
{
    CPlayGameMap.init_map();
    nLifeCount = 3;
    pPlayerTank = nullptr;
    for (int i = 0; i < 6; i++)
    {
        pEnemyTank[i] = nullptr;
    }
    tStart = clock();
}
CPLAYGAME::~CPLAYGAME()
{
    if (pPlayerTank != nullptr)
    {
        delete pPlayerTank;
        pPlayerTank = nullptr;
    }
    for (int i = 0; i < 6; i++)
    {
        if (pEnemyTank[i] != nullptr)
        {
            delete pEnemyTank[i];
            pEnemyTank[i] = nullptr;
        }
    }

}

void CPLAYGAME::del_life()
{
    nLifeCount--;
}
bool CPLAYGAME::is_over()//�ж��Ƿ������Ϸ,false����
{
    if (nLifeCount == 0 && pPlayerTank == nullptr)
    {
        return false;
    }
    return true;
}
void CPLAYGAME::create_player()//����һ�����
{
    if (nLifeCount > 0 && pPlayerTank == nullptr)
    {
        pPlayerTank = new PLAYERTANK;
    }
}
void CPLAYGAME::player_operate_tank()//��Ҳ���̹��,1 ����Ƿ����̹�ˣ�������̹�ˣ� 2 ����̹��
{
    int nOperate = 0;

    create_player();
    if (_kbhit())
    {
        nOperate = _getch();
    }
    if (nOperate != 0)
    {
        switch (nOperate)
        {
            case 'w':
            case 'W':
                pPlayerTank->set_direction(CMOVEOBJ::OBJ_UP);
                pPlayerTank->move(CMAP::PLAYERTANK_UP);
                break;
            case 'a':
            case 'A':
                pPlayerTank->set_direction(CMOVEOBJ::OBJ_LEFT);
                pPlayerTank->move(CMAP::PLAYERTANK_LEFT);
                break;
            case 'd':
            case 'D':
                pPlayerTank->set_direction(CMOVEOBJ::OBJ_RIGHT);
                pPlayerTank->move(CMAP::PLAYERTANK_RIGHT);
                break;
            case 's':
            case 'S':
                pPlayerTank->set_direction(CMOVEOBJ::OBJ_DOWN);
                pPlayerTank->move(CMAP::PLAYERTANK_DOWN);
                break;
            case 'k':
            case 'K':
                pPlayerTank->creat_bullet();               
                break;
            default:break;
        }
    }
}
void CPLAYGAME::enemy_operate_tank()//�з�����̹�ˣ�����6��̹��
{
    clock_t tCurrent = clock();

    
    if (tCurrent - tStart > 1000)
    {
        tStart = tCurrent;

        if (ENEMYTANK::get_tank_count() != 0 && ENEMYTANK::get_tank_num() < 6)
        {
            for (int i = 0; i < 6; i++)
            {
                if (pEnemyTank[i] == nullptr)
                {
                    switch (rand() % 4 + 1)
                    {
                        case 1:
                            if (CPlayGameMap.get_info(1, 1) == CMAP::GRAPH_BLACK)
                            {
                                pEnemyTank[i] = new ENEMYTANK(1, 1);
                                pEnemyTank[i]->add_tank_now();
                                pEnemyTank[i]->del_tank_count();   
                            }
                            break;
                        case 2:
                            if (CPlayGameMap.get_info(19, 1) == CMAP::GRAPH_BLACK)
                            {
                                pEnemyTank[i] = new ENEMYTANK(19, 1);
                                pEnemyTank[i]->add_tank_now();
                                pEnemyTank[i]->del_tank_count();
                            }
                            break;
                        case 3:
                            if (CPlayGameMap.get_info(1, 9) == CMAP::GRAPH_BLACK)
                            {
                                pEnemyTank[i] = new ENEMYTANK(1, 9);
                                pEnemyTank[i]->add_tank_now();
                                pEnemyTank[i]->del_tank_count();
                            }
                            break;
                        case 4:
                            if (CPlayGameMap.get_info(19, 9) == CMAP::GRAPH_BLACK)
                            {
                                pEnemyTank[i] = new ENEMYTANK(19, 9);
                                pEnemyTank[i]->add_tank_now();
                                pEnemyTank[i]->del_tank_count();
                            }
                            break;
                        default:break;
                    }
                    break;
                }
            }
        }

        for (int i = 0; i < 6; i++)
        {
            if (pEnemyTank[i] != nullptr)
            {
                if (i <= 4)
                {
                    pEnemyTank[i]->intelligent_move();//4�������ƶ�
                }
                else
                {
                    pEnemyTank[i]->random_move();//2������ƶ�
                }           
                pEnemyTank[i]->creat_bullet();
            }
        }
    }   
}
void CPLAYGAME::destroy_player_tank()//�ݻ����̹��
{
    pPlayerTank->clear_coord_info();
    delete pPlayerTank;
    pPlayerTank = nullptr;
}
void CPLAYGAME::destroy_enemy_tank(ENEMYTANK *pTank)//�ݻٵз�̹��
{
    if (pTank != nullptr)
    {
        pTank->clear_coord_info();
        delete pTank;
    }
   
}
bool CPLAYGAME::bullet_control()//�����ӵ��Ŀ��ƺ���
{
    int nCrash = 0;

    if (pPlayerTank->has_bullet())
    {   
        nCrash = pPlayerTank->move_bullet();
    
        switch (nCrash)
        {
            case BULLET::CRASH_HOME:
            
                return false;//������Ϸ
                break;
            case BULLET::CRASH_BULLET:
                for (int i = 0; i < 6; i++)
                {
                    if (pEnemyTank[i] != nullptr)
                    {
                        if (pEnemyTank[i]->get_bullet_x() == pPlayerTank->get_bullet_crash_bullet_x() 
                            && pEnemyTank[i]->get_bullet_y() == pPlayerTank->get_bullet_crash_bullet_y())
                        {
                            pEnemyTank[i]->destroy_bullet();
                        }
                    }               
                }
                break;
            case BULLET::CRASH_ENEMY:
                for (int i = 0; i < 6; i++)
                {
                    if (pEnemyTank[i] != nullptr)
                    {
                        if (pEnemyTank[i]->get_x() == BULLET::get_enemy_coord_x() && pEnemyTank[i]->get_y() == BULLET::get_enemy_coord_y())
                        {
                            pEnemyTank[i]->del_tank_now();
                            pEnemyTank[i]->destroy_bullet();
                            destroy_enemy_tank(pEnemyTank[i]);
                            pEnemyTank[i] = nullptr;
                        }
                    }
                }
                break;
            default:break;
        }
        if (nCrash != BULLET::CRASH_NONE)
        {
            pPlayerTank->destroy_bullet();
        }
    }

//6���з�̹�˵��ӵ�����
    for (int i = 0; i < 6; i++)
    {
        nCrash = 0;

        if (pEnemyTank[i] != nullptr)
        {
            if (pEnemyTank[i]->get_bullet_x() == pEnemyTank[i]->get_bullet_crash_bullet_x()
                && pEnemyTank[i]->get_bullet_y() == pEnemyTank[i]->get_bullet_crash_bullet_y()
                && pEnemyTank[i]->get_bullet_x() != 0 && pEnemyTank[i]->get_bullet_y() != 0)
            {
                pEnemyTank[i]->destroy_bullet();
            }
            
 
            if (pEnemyTank[i]->has_bullet())
            {
            
                nCrash = pEnemyTank[i]->move_bullet();
                switch (nCrash)
                {
                case BULLET::CRASH_HOME:
                    return false;//������Ϸ
                    break;
                case BULLET::CRASH_PLAYER:
                    pPlayerTank->destroy_bullet();//�ȴݻ��ӵ����ٴݻ�̹�ˣ�˳���ܴ���Ȼ�ӵ��͹̶�����ͼ��
                    destroy_player_tank();
                    del_life();
                    break;
                case BULLET::CRASH_BULLET:                  
                    for (int j = 0; j < 6; j++)
                    {
                        if (pEnemyTank[i]->get_bullet_crash_bullet_x() == pPlayerTank->get_bullet_x()//�������������ӵ�
                            && pEnemyTank[i]->get_bullet_crash_bullet_y() == pPlayerTank->get_bullet_y()
                            && pPlayerTank->get_bullet_x() != 0 && pPlayerTank->get_bullet_y() != 0)
                        {
                            pPlayerTank->destroy_bullet();
                            break;
                        }
                        if (i == j)
                        {
                            continue;
                        }
                        if (pEnemyTank[j] != nullptr)
                        {
                            if (pEnemyTank[j]->get_bullet_x() == pEnemyTank[i]->get_bullet_crash_bullet_x()//��������ǵз��ӵ����ҵ��ǵڼ����з�̹�˵��ӵ�
                                && pEnemyTank[j]->get_bullet_y() == pEnemyTank[i]->get_bullet_crash_bullet_y()
                                && pEnemyTank[j]->get_bullet_x() != 0 && pEnemyTank[j]->get_bullet_y() != 0)
                            {
                                pEnemyTank[j]->destroy_bullet();
                                break;
                            }                          
                        }
                    }
                    break;
                default:break;
                }

                if (nCrash != BULLET::CRASH_NONE)
                {
                    pEnemyTank[i]->destroy_bullet();
                }
            }
            else
            {
                pEnemyTank[i]->creat_bullet();
            }
        }
    }
//    CPlayGameMap.test_map2();
    return true;
}

bool CPLAYGAME::game_start()//��ʼ��Ϸ,true���Ӯ��false�����
{
    CPlayGameMap.draw_map();
    while (true)
    {
        if (is_over() == false)
        {
            return false;
        }
       
        if (is_win() == true)
        {
            return true;
        }
  
        player_operate_tank();
        CPlayGameMap.draw_map();

        enemy_operate_tank();
        CPlayGameMap.draw_map();

        if (bullet_control() == false)
        {
            return false;
        }
        CPlayGameMap.draw_map();
    }
}
bool CPLAYGAME::is_win()//�ж��Ƿ��ʤ
{
    if (ENEMYTANK::get_tank_count() == 0 && ENEMYTANK::get_tank_num() == 0)
    {
        return true;
    }
    return false;
}
void CPLAYGAME::print_result(int nResult)
{
    if (nResult == 0)
    {
        CPlayGameMap.lose_map();
    }
    else
    {
        CPlayGameMap.win_map();
    }
}

