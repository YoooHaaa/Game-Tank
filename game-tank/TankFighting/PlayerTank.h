#pragma once
#include "head.h"
#include "MoveObj.h"
#include "Bullet.h"
#include "Map.h"


class PLAYERTANK :public CMOVEOBJ
{
public:
    PLAYERTANK();
    ~PLAYERTANK();

    void creat_bullet();//�����ӵ�
    int move_bullet();//�ƶ��ӵ�
    void destroy_bullet();//�ݻ��ӵ�

    int get_bullet_x() const;
    int get_bullet_y() const;

    int get_bullet_crash_bullet_x() const;//��ȡ��ײ�ӵ�������
    int get_bullet_crash_bullet_y() const;//��ȡ��ײ�ӵ�������

    bool has_bullet();

    int get_bullet_crash_tank_x() const;//��ȡ��ײ̹�˵�����
    int get_bullet_crash_tank_y() const;//��ȡ��ײ̹�˵�����

private:
    BULLET *pBullet;
    CMAP map;
};
