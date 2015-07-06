#ifndef athlete_H
#define athlete_H

#define GLEW_STATIC
#include <GL/glew.h>

class Athlete
{
    public: 
        enum POSITION {QB, RECIEVER, DEFENSE, BALL};

        Athlete(/*POSITION p,*/ int x, int y);

        int getX();
        int getY();
        POSITION getPosition();
        
        void setX(int x);
        void setY(int y);
        //void setPosition(POSITION p);
        void setVertices(GLfloat *v);

        void Draw();


    private:
        POSITION position;
        int x, y;
        GLuint VBO, VAO, EBO;

        GLfloat indices[6] = {  // Note that we start from 0!
            0, 1, 3,  // First Triangle
            1, 2, 3   // Second Triangle
        };
 
    
};

#endif
