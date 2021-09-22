#include "Map.h"


char CMAP::szMap[HIGH][WIDTH] = { 0 };

CMAP::CMAP()
{
    LoadImages();
}
CMAP::~CMAP()
{

}
void CMAP::win_map()//打印YOU WIN
{
    char szInitMap[HIGH][WIDTH] =
    {
        "000000000000000000000",
        "000000000000000000000",
        "010001001111001000010",
        "001010010000101000010",
        "000100010000101000010",
        "000100010000101000010",
        "000100001111000111100",
        "000000000000000000000",
        "000000000000000000000",
        "000000000000000000000",
        "000000000000000000000",
        "000000000000000000000",
        "010010010001000100010",
        "010010010001000110010",
        "010010010001000101010",
        "010010010001000100110",
        "001101100001000100010",
        "000000000000000000000",
        "000000000000000000000",
        "000000000000000000000"
    };

    for (int x = 0; x < WIDTH - 1; x++)
    {
        for (int y = 0; y < HIGH; y++)
        {
            if (szInitMap[y][x] == '0')
            {
                putimage(x * MULTIPLE, y * MULTIPLE, &image[GRAPH_STONE]);
            }
            else
            {
                putimage(x * MULTIPLE, y * MULTIPLE, &image[GRAPH_WALL]);
            }
        }
    }
}
void CMAP::lose_map()//打印YOU LOSE
{
    char szInitMap[HIGH][WIDTH] =
    {
        "000000000000000000000",
        "000000000000000000000",
        "010001001111001000010",
        "001010010000101000010",
        "000100010000101000010",
        "000100010000101000010",
        "000100010000101000010",
        "000100001111000111100",
        "000000000000000000000",
        "000000000000000000000",
        "000000000000000000000",
        "000000000000000000000",
        "010000111001111011110",
        "010001000101000010000",
        "010001000101111011110",
        "010001000100001010000",
        "010001000100001010000",
        "011100111001111011110",
        "000000000000000000000",
        "000000000000000000000"
    };

    for (int x = 0; x < WIDTH - 1; x++)
    {
        for (int y = 0; y < HIGH; y++)
        {
            if (szInitMap[y][x] == '0')
            {
                putimage(x * MULTIPLE, y * MULTIPLE, &image[GRAPH_STONE]);
            }
            else
            {
                putimage(x * MULTIPLE, y * MULTIPLE, &image[GRAPH_WALL]);
            }
        }
    }
}
void CMAP::init_map()//初始化地图,由于地图是静态的，所以只能在playgame的构造里初始化一次，子弹和坦克类里的地图成员无需初始化地图
{
    char szInitMap[HIGH][WIDTH] =
    {
    "222222222222222222222",
    "200000000010000000002",
    "201100110020011111002",
    "201100110020110001102",
    "200111100020110001102",
    "200011000020110001102",
    "200011000020011111002",
    "200000000010000000002",    
    "212221222111222122212",
    "200000000010000000002",
    "200000000020000000002",
    "201100011020001110002",
    "201100011020011011002",
    "201111111020110001102",
    "201100011020111111102",
    "201100011020110001102",
    "200000000000000000002",
    "200222110111011222002",
    "200010000232000010002",
    "222222222222222222222"
    };

    for (int i = 0; i < HIGH; i++)
    {
        for (int j = 0; j < WIDTH - 1; j++)
        {
            switch (szInitMap[i][j])
            {
                case '0':
                    szInitMap[i][j] = 0;
                    break;
                case '1':
                    szInitMap[i][j] = 1;
                    break;
                case '2':
                    szInitMap[i][j] = 2;
                    break;
                case '3':
                    szInitMap[i][j] = 3;
                    break;
                default:break;
            }
        }
    }

    for (int i = 0; i < HIGH; i++)
    {
        for (int j = 0; j < WIDTH - 1; j++)
        {
            szMap[i][j] = szInitMap[i][j];
        }
    }
}

void CMAP::LoadImages()//装载图片
{
    loadimage(&image[GRAPH_BLACK],_T(".\\big\\black.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[GRAPH_WALL], _T(".\\big\\wall.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[GRAPH_STONE], _T(".\\big\\stone.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[GRAPH_HOME], _T(".\\big\\home.gif"), MULTIPLE, MULTIPLE);

    loadimage(&image[PLAYERTANK_UP], _T(".\\big\\player_up.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[PLAYERTANK_DOWN], _T(".\\big\\player_down.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[PLAYERTANK_LEFT], _T(".\\big\\player_left.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[PLAYERTANK_RIGHT], _T(".\\big\\player_right.gif"), MULTIPLE, MULTIPLE);

    loadimage(&image[ENEMYTANK_UP], _T(".\\big\\enemy_up.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[ENEMYTANK_DOWN], _T(".\\big\\enemy_down.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[ENEMYTANK_LEFT], _T(".\\big\\enemy_left.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[ENEMYTANK_RIGHT], _T(".\\big\\enemy_right.gif"), MULTIPLE, MULTIPLE);

    loadimage(&image[BULLET_UP], _T(".\\big\\bullet_up.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[BULLET_DOWN], _T(".\\big\\bullet_down.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[BULLET_LEFT], _T(".\\big\\bullet_left.gif"), MULTIPLE, MULTIPLE);
    loadimage(&image[BULLET_RIGHT], _T(".\\big\\bullet_right.gif"), MULTIPLE, MULTIPLE);

    loadimage(&image[TANKBOOM], _T(".\\big\\boom.gif"), MULTIPLE, MULTIPLE);
}
void CMAP::test_map1()//测试地图，调试bug用，用于定位bug
{
    for (int x = 0; x < WIDTH - 1; x++)
    {
        for (int y = 0; y < HIGH; y++)
        {
            
             putimage(x * MULTIPLE, y * MULTIPLE, &image[GRAPH_WALL]);

        }
    }
}
void CMAP::test_map2()////测试地图，调试bug用，用于定位bug
{
    for (int x = 0; x < WIDTH - 1; x++)
    {
        for (int y = 0; y < HIGH; y++)
        {
            putimage(x * MULTIPLE, y * MULTIPLE, &image[GRAPH_STONE]);
        }
    }
}
void CMAP::draw_map()//画地图,
{ 
    for (int x = 0; x < WIDTH - 1; x++)
    {
        for (int y = 0; y < HIGH; y++)
        {
            switch (szMap[y][x])
            {
            case GRAPH_BLACK:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[GRAPH_BLACK]);
                break;
            case GRAPH_WALL:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[GRAPH_WALL]);
                break;
            case GRAPH_STONE:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[GRAPH_STONE]);
                break;
            case GRAPH_HOME:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[GRAPH_HOME]);
                break;
            case PLAYERTANK_UP:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[PLAYERTANK_UP]);
                break;
            case PLAYERTANK_DOWN:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[PLAYERTANK_DOWN]);
                break;
            case PLAYERTANK_LEFT:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[PLAYERTANK_LEFT]);
                break;
            case PLAYERTANK_RIGHT:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[PLAYERTANK_RIGHT]);
                break;
            case ENEMYTANK_UP:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[ENEMYTANK_UP]);
                break;
            case ENEMYTANK_DOWN:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[ENEMYTANK_DOWN]);
                break;
            case ENEMYTANK_LEFT:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[ENEMYTANK_LEFT]);
                break;
            case ENEMYTANK_RIGHT:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[ENEMYTANK_RIGHT]);
                break;
            case BULLET_UP:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[BULLET_UP]);
                break;
            case BULLET_DOWN:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[BULLET_DOWN]);
                break;
            case BULLET_LEFT:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[BULLET_LEFT]);
                break;
            case BULLET_RIGHT:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[BULLET_RIGHT]);
                break;
            case TANKBOOM:
                putimage(x * MULTIPLE, y * MULTIPLE, &image[TANKBOOM]);
                break;
            default:break;
            }
        }
    }
}

int CMAP::get_info(int nX, int nY) const//获取坐标点的信息
{
    return szMap[nY][nX];
}

void CMAP::be_attack(int xAttack, int yAttack)//墙受到攻击，砖墙就会被销毁，铁墙没影响,参数为被子弹攻击点的坐标
{
    szMap[yAttack][xAttack] = GRAPH_BLACK;
}

void CMAP::modify_map(int nX, int nY, int nMapFlag)//子弹和坦克把自己的坐标,和地图标记传进来，修改地图，所有成员公用一张地图。
{
    szMap[nY][nX] = nMapFlag;
}
