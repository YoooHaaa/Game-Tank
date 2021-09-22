#pragma once
#include "head.h"
#include "MoveObj.h"
#include "Bullet.h"
#include "Map.h"



class ENEMYTANK :public CMOVEOBJ
{
public:

    ENEMYTANK(int x, int y);
    ~ENEMYTANK();

    void random_move();//����ƶ���2������ƶ���ɵ��̹��
    void intelligent_move();//�����ƶ���4�������ƶ��ķ��̹��

    void creat_bullet();//�����ӵ�
    int move_bullet();//�ƶ��ӵ�
    bool has_bullet();//�鿴�Ƿ����ӵ�
    void destroy_bullet();//�ݻ��ӵ�

    int get_bullet_x() const;
    int get_bullet_y() const;

    int get_bullet_crash_bullet_x() const;//��ȡ��ײ�ӵ�������
    int get_bullet_crash_bullet_y() const;//��ȡ��ײ�ӵ�������
    void set_bullet_crash_bullet_coord();//������ײ�ӵ�������
    
    /////////////////////////////////////////////////////////////////////////////////////////
    static int get_tank_num();//��ȡ�ִ�̹����
    static int get_tank_count();//��ȡʣ��̹������
    void add_tank_now();//����һ���ִ�̹����
    void del_tank_now();//����һ���ִ�̹����
    void del_tank_count();//����̹������
    /////////////////////////////////////////////////////////////////////////////////////////


private:
    static int nTankCount;//ʣ��̹������
    static int nTankNow;//�ִ�̹������
    clock_t tStartMove;//�����ƶ�ʱ���
    clock_t tStartBullet;//�������ʱ���
    CMAP map;
    BULLET *pBullet;
};

