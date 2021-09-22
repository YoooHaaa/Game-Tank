#pragma once
#include "head.h"
#include "MoveObj.h"
#include "Map.h"

class BULLET:public CMOVEOBJ//�ӵ���
{
public:
    BULLET();
    ~BULLET();

    int move();//�ӵ�ǰ��,������ײ���
    void clear_coord_info();
    void write_coord_info(int nCoordInfo);

    int crash(int x, int y);//��ײ�жϣ�������ײ���
    void set_belong(int nBelong);//�����ӵ�����
    
    void set_enemy_coord(int x, int y);//���ñ��ݻٵĵз�̹������
    static int get_enemy_coord_x();//��ȡ���ݻٵĵз�̹������
    static int get_enemy_coord_y();//��ȡ���ݻٵĵз�̹������

    void set_destroy_bullet_coord(int x, int y);//���ñ��ݻ��ӵ�������
    int get_destroy_bullet_coord_x() const;//��ȡ���ݻ��ӵ�������
    int get_destroy_bullet_coord_y() const;

    enum CRASH
    {
        CRASH_NONE,
        CRASH_WALL,
        CRASH_STONE,
        CRASH_HOME,
        CRASH_PLAYER,
        CRASH_BULLET,
        CRASH_ENEMY
    };
    enum BELONG
    {
        PLAYER,
        ENEMY
    };

private:
    CMAP map;

    clock_t tStart;

    static int nBeDestroyX;//���ݻٵĵз�̹������
    static int nBeDestroyY;

    static int nBulletX;//��ײ���ӵ�������
    static int nBulletY;//��ײ���ӵ�������

    int nBelong;//�ӵ�����
};