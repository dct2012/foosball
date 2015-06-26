#include <stdio.h>
#include <stdbool.h>

typedef struct {
    // 0 = qb, 1 = receiver, 2 = defense
    bool position[3];
    int x, y;
} athlete;

typedef struct {
    //opengl coordinates
    athlete *player;
} field;

typedef struct {
    bool right;
    bool ascending;
    int position;
} yards;

field f[10][3];
yards yd = {.right = true, .ascending = true, .position = 35};
int score_home = 0;
int score_away = 0;
int down = 1;
int yards_to_go = 10;

void print_scoreboard()
{
    //print own side
    printf("home\tfield position\taway\n");
    printf("%d\t%d\t\t%d\n", score_home, yd.position, score_away);
    printf("down\tyards to go\ttime\n");
    printf("%d\t%d\n", down, yards_to_go);
}

void print_field()
{
    print_scoreboard();

    for(int i = 0; i < 21; i++)
        printf("-");
    printf("\n");
    
    for(int y = 0; y < 3; y++)
    {
        printf("|");

        for(int x = 0; x < 10; x++)
        {
            if (f[x][y].player && f[x][y].player->position[0])
                printf("X");
            else
                printf(" ");

            printf("|");
        }
        printf("\n");
    }
    
    for(int i = 0; i < 21; i++)
        printf("-");
    printf("\n"); 
}

void move_athlete(athlete *a, char c)
{
    switch (c){
        case 'a':
            if(a->x > 0)
            {
                f[a->x][a->y].player = NULL;
                f[--a->x][a->y].player = a;
            }
            break;
        case 's':
            if(a->y < 2)
            {
                f[a->x][a->y].player = NULL;
                f[a->x][++a->y].player = a;
            }
            break;
        case 'd':
            if(a->x < 9)
            {
                f[a->x][a->y].player = NULL;
                f[++a->x][a->y].player = a; 
            }
            else
            {
                f[a->x][a->y].player = NULL;
                f[a->x = 0][a->y].player = a;
            }

            if(yd.position == 50)
            {
                if(yd.ascending)
                    yd.ascending = false;
                else
                    yd.ascending = true;
            }

            if(yd.ascending)
                yd.position++;
            else
                yd.position--;

            if(yd.position == 0)
            {
                score_home += 7; //probably going to give the option 1 pt or 2 pt
                yd.position = 20; //really there should be a kickoff
            }

            yards_to_go--;

            break;
        case 'w':
            if(a->y > 0)
            {
                f[a->x][a->y].player = NULL;
                f[a->x][--a->y].player = a;
            }
            break;
    }
}

int main(int argc, char *argv[])
{
    athlete a = {.position[0] = true, .x = 0, .y = 1};
    f[a.x][a.y].player = &a;
    

    char input;
    while(1)
    {
        print_field();
 
        scanf(" %c", &input);
        move_athlete(&a, input);
    }
}
