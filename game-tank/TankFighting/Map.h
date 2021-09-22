#pragma once
#include "head.h"


class CMAP//��ͼ��Ϣ��
{
public:
    CMAP();
    ~CMAP();
    void init_map();//��ʼ����ͼ,���ڵ�ͼ�Ǿ�̬�ģ�����ֻ����playgame�Ĺ������ʼ��һ�Σ��ӵ���̹������ĵ�ͼ��Ա�����ʼ����ͼ
    void test_map1();//���Ե�ͼ
    void test_map2();//���Ե�ͼ
    void draw_map();//����ͼ
    void win_map();
    void lose_map();

    void be_attack(int xAttack, int yAttack);//ǽ�ܵ�������שǽ�ͻᱻ���٣���ǽûӰ��,����Ϊ���ӵ������������

    void modify_map(int nX, int nY, int nMapFlag);//�ӵ���̹�˰��Լ������괫�������޸ĵ�ͼ�����г�Ա����һ�ŵ�ͼ��

    int get_info(int nX, int nY) const;//��ȡ��������Ϣ

    enum MAPSIZE
    {
        HIGH = 20,
        WIDTH = 22,
        MULTIPLE = 30//�Ŵ�ı���
    };
    enum MAPFLAG//���ڴ�ӡʱ��Ϊ��ʶ
    {
        //��ͼ��Ϣ
        GRAPH_BLACK,
        GRAPH_WALL,
        GRAPH_STONE,
        GRAPH_HOME,

        //���̹����Ϣ
        PLAYERTANK_UP,
        PLAYERTANK_DOWN,
        PLAYERTANK_LEFT,
        PLAYERTANK_RIGHT,

        //�з�̹����Ϣ
        ENEMYTANK_UP ,       
        ENEMYTANK_DOWN,
        ENEMYTANK_LEFT,
        ENEMYTANK_RIGHT,

        //�ӵ���Ϣ
        BULLET_UP,
        BULLET_DOWN,
        BULLET_LEFT,
        BULLET_RIGHT,

        //̹�˱�ըͼƬ
        TANKBOOM,
        //��ǵ��ܸ���
        FLAGSIZE 
    };
private:
    void LoadImages();//װ��ͼƬ
private:
    static char szMap[HIGH][WIDTH];
    IMAGE image[FLAGSIZE];
};