#ifndef COMMON_H
#define COMMON_H

#define NUM_SMB 8
#define LEN_NAME 25
#define STEP_CURSOR 10
#define MAX_SMB_LIST           50
#define SCREEN_WIDTH           1300
#define SCREEN_HEIGHT          690
#define IS_FULL_SCREEN         0
#define NUM_TEST               100
#define NUM_ALGORITHM          3
#define HEIGHT_OUTRANGE_BAR    2
#define MIN_HEIGHT_INRANGE_BAR 3
#define HEIGHT_AREA 2
#define WIDTH_AREA 8
#define SHIFT_TOP 1.5
#define WITH_POINT 8
#define RANGE_SCALE_TIME 0.01
#define RANGE_SCALE_VALUE 1
#define SHIFT_SCALE 1
#define LEVEL_SCALE_GA 23
#define LEVEL_SCALE_PSO 46
#define LEVEL_SCALE_SA 69
#define SIZE_SCALE_W 100
#define SIZE_SCALE_H 22
#define GA 0
#define SA 1
#define PSO 2
/* 0 - GA 1- SA 2 - PSO */
typedef void (*pf)();

typedef enum
{
    SETTINGS = 0,
    RESULTS,
    WAITING,
    PREPARE_SETTINGS,
    PREPARE_RESULT
}eState;

struct listTextArea
{
    int mX;
    int mY;
    char text[NUM_SMB];
    char name[LEN_NAME];
    int i; // the number of number in area
    int shift_area;
    double low;
    double hight;
    struct listTextArea* pNext;
};
struct sListText
{
    char text[MAX_SMB_LIST];
    int mX;
    int mY;
    struct sListText* pNext;
};
struct sListTexture
{
    int mX;
    int mY;
    int width;
    int height;
    unsigned int texture;
    struct sListTexture* pNext;
};
struct sListButton
{
    char name[NUM_SMB];
    int mX;
    int mY;
    unsigned int texture;
    int w;
    int h;
    pf action;
    struct sListButton* pNext;
};
struct sListScale
{
    int posX;
    int posY;
    int w;
    int h;
    int* dataValue;
    int* dataTime;
    struct sListScale* pNext;
};
typedef struct
{
    double mX;
    double mY;
    double value;
    double time;
    int iter;
}sResult;
typedef struct sListText    sListText;
typedef struct listTextArea listTextArea;
typedef struct sListTexture sListTexture;
typedef struct sListButton  sListButton;
typedef struct sListScale   sListScale;

#endif // COMMON_H
