#include <stdio.h>
#include <stdbool.h>

typedef struct {
    //  bright           dim/ blinking  dim         bright/blinking
    // 0 = qb or runner, 1 = receiver, 2 = defense, 3 = ball
    bool position[4];
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
            if (f[x][y].player){
                if(f[x][y].player->position[0])
                    printf("X");
                else if(f[x][y].player->position[1])
                    printf("H");
                else if(f[x][y].player->position[1])
                    printf("O");
                else
                    printf("#");
            }
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

void add_player_to_field(athlete *a)
{
    f[a->x][a->y].player = a;
}

void remove_player_from_field(athlete *a)
{
    f[a->x][a->y].player = NULL;
}

void kickoff()
{
    //when the kick button is pressed, the three dots in 
    //the triangle formation move towards the ball, when
    //they reach the ball they disappear and the ball is
    //kicked. we follow the ball until it stops (direction
    //needs to change) and then they can run. defensive players
    //seem to appear by couples in random spots, I think one per
    //move.
    //the ball is bright red and blinking. the kicker is dim and blinking
    //the two others are bright red


    yd.position = 35;

    if(yd.right)
    {
        //we need dots at [0][0], [1][1], [0][2], [5][1]
        //X
        // X   X
        //X


        //create players and add them to the field
        athlete s1 = {.position[0] = true, .x = 0, .y = 0};
        add_player_to_field(&s1);
        
        athlete s2 = {.position[0] = true, .x = 0, .y = 2};
        add_player_to_field(&s2);
        
        athlete kicker = {.position[1] = true, .x = 1, .y = 1};
        add_player_to_field(&kicker);

        athlete ball = {.position[3] = true, .x = 5, .y = 1};
        add_player_to_field(&ball);

        print_field();


        //wait for kick button
        char kick = ' ';
        while(kick != 'a')
            scanf("%c",&kick);

        
        //animate kick
        // first we'll need to decide how for it goes
        // then move line to ball
        //  animate
        // ball turns into qb
        // ball moves for decided distance
        for(int i = 0; i < 3; i++)
        {
            remove_player_from_field(&s1);
            s1.x++;
            add_player_to_field(&s1);
            
            remove_player_from_field(&s2);
            s2.x++;
            add_player_to_field(&s2);

            remove_player_from_field(&kicker);
            kicker.x++;
            add_player_to_field(&kicker);

            print_field();
        }
        



        //change directions
        //run
        //generate defense players
        //down or td (exit)
        
        
        
    }

}

int main(int argc, char *argv[])
{
    kickoff();

    /*athlete a = {.position[0] = true, .x = 0, .y = 1};
    f[a.x][a.y].player = &a;
    

    char input;
    while(1)
    {
        print_field();
 
        scanf(" %c", &input);
        move_athlete(&a, input);
    }*/
}
