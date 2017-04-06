#ifndef COMMON_H
#define COMMON_H

#define NUM_SMB 10
#define STEP_CURSOR 10
#define MAX_SMB_LIST 50
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
    char text_area[NUM_SMB];
    char name_area[NUM_SMB];
    int i; // the number of number in area
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
    struct sListTexture* pNext;
};
struct sListButton
{
    int mX;
    int mY;
    struct sListButton* pNext;
};

typedef struct sListText sListText;
typedef struct listTextArea listTextArea;
typedef struct sListTexture sListTexture;
typedef struct sListButton sListButton;

#endif // COMMON_H
