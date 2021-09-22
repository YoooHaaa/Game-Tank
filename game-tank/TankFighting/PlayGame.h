#pragma once
#include "head.h"
#include "MoveObj.h"
#include "Bullet.h"
#include "EnemyTank.h"
#include "PlayerTank.h"
#include "Map.h"


class CPLAYGAME
{
public:
    CPLAYGAME();
    ~CPLAYGAME();


    bool game_start();//��ʼ��Ϸ
    void print_result(int nResult);//��ӡ���

    void create_player();//����һ�����

    void del_life();//��������ֵ

    bool is_over();//�ж��Ƿ������Ϸ,false����
    bool is_win();//�ж��Ƿ��ʤ

    void player_operate_tank();//��Ҳ���̹��
    void enemy_operate_tank();//�з�����̹��

    void destroy_player_tank();//�ݻ����̹��
    void destroy_enemy_tank(ENEMYTANK *pTank);//�ݻٵз�̹��

    bool bullet_control();//�����ӵ��Ŀ��ƺ���

private:
    CMAP CPlayGameMap;//���ڳ�ʼ����ͼ������ֻ��������ʼ��һ��

    PLAYERTANK *pPlayerTank;//���̹�ˣ�������

    ENEMYTANK *pEnemyTank[6];//�з�̹��
    clock_t tStart;

    int nLifeCount;//�����������
};