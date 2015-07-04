#ifndef scoreboard_H
#define scoreboard_H

#define GLEW_STATIC
#include <GL/glew.h>

class Scoreboard
{
    private:
        GLfloat scoreboard_vertices[12] = {
         0.57f,  0.9f, 0.0f,  // Top Right
         0.57f, 0.4f, 0.0f,  // Bottom Right
        -0.57f, 0.4f, 0.0f,  // Bottom Left
        -0.57f,  0.9f, 0.0f  // Top Left
        };
        GLuint scoreboard_indices[6] = {  // Note that we start from 0!
            0, 1, 3,  // First Triangle
            1, 2, 3   // Second Triangle
        };
        GLuint VBO, VAO, EBO;

    public:
        Scoreboard();
        void Draw();
};

#endif
