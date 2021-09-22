#pragma once
#include "head.h"
#include "Map.h"

class CMOVEOBJ//�ƶ�������
{
public:

    CMOVEOBJ();//
    ~CMOVEOBJ();

    void move(int nCoordInfo);//�ƶ�,�����������Ϣ

    void clear_coord_info();//���������Ϣ
    void write_coord_info(int nCoordInfo);//д��������Ϣ

    void set_coord(int x, int y);//�����ƶ�������
    void set_direction(int nDire);//���÷���

    int get_x() const;
    int get_y() const;
    int get_direction() const;

    enum DIRECTION
    {
        OBJ_UP,
        OBJ_DOWN,
        OBJ_LEFT,
        OBJ_RIGHT
    };
private:
    CMAP map;
    int nDirection;//����
    int nX;
    int nY;
};