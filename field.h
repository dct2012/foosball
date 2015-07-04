#ifndef field_H
#define field_H

#define GLEW_STATIC
#include <GL/glew.h>

#include "athlete.h"

class Field
{
    private:
        const GLuint WIDTH = 1400, HEIGHT = 600;

        GLfloat field_vertices[180] = {
            //top
             ((float)1/7)*6,  0.3f, 0.0f,  // Top right
             ((float)1/7)*6,  0.25f, 0.0f,  // Bottom right
            -((float)1/7)*6,  0.25f, 0.0f,  // Bottom Left
            -((float)1/7)*6,  0.3f, 0.0f,  // Top Left

            //bottom
             ((float)1/7)*6, -0.85f, 0.0f,  // top right
             ((float)1/7)*6, -0.9f, 0.0f,  // Bottom right
            -((float)1/7)*6, -0.9f, 0.0f,  // Bottom Left
            -((float)1/7)*6, -0.85f, 0.0f,  // Top Left

            //50 yard line
             .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
             .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
            -.05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
            -.05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            // right side
             ((float)1/7)*6 + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top right
             ((float)1/7)*6 + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
             ((float)1/7)*6 - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
             ((float)1/7)*6 - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            //40 yard line right
             ((float)1/7) + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
             ((float)1/7) + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
             ((float)1/7) - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
             ((float)1/7) - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            //30 yard line right
             ((float)1/7)*2 + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
             ((float)1/7)*2 + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
             ((float)1/7)*2 - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
             ((float)1/7)*2 - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            //20 yard line right
             ((float)1/7)*3 + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
             ((float)1/7)*3 + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
             ((float)1/7)*3 - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
             ((float)1/7)*3 - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            //10 yard line right
             ((float)1/7)*4 + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
             ((float)1/7)*4 + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
             ((float)1/7)*4 - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
             ((float)1/7)*4 - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            //endzone
             ((float)1/7)*5 + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
             ((float)1/7)*5 + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
             ((float)1/7)*5 - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
             ((float)1/7)*5 - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            // left side
            -((float)1/7)*6 - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
            -((float)1/7)*6 - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
            -((float)1/7)*6 + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
            -((float)1/7)*6 + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            // 40 yard line left side
            -((float)1/7)*1 - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
            -((float)1/7)*1 - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
            -((float)1/7)*1 + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
            -((float)1/7)*1 + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            // 30 yard line left side
            -((float)1/7)*2 - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
            -((float)1/7)*2 - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
            -((float)1/7)*2 + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
            -((float)1/7)*2 + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            // 20 yard line left side
            -((float)1/7)*3 - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
            -((float)1/7)*3 - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
            -((float)1/7)*3 + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
            -((float)1/7)*3 + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            // 10 yard line left side
            -((float)1/7)*4 - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
            -((float)1/7)*4 - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
            -((float)1/7)*4 + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
            -((float)1/7)*4 + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            // endzone
            -((float)1/7)*5 - .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // top right
            -((float)1/7)*5 - .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom right
            -((float)1/7)*5 + .05*((float)HEIGHT/WIDTH)/2, -0.9f, 0.0f,  // Bottom Left
            -((float)1/7)*5 + .05*((float)HEIGHT/WIDTH)/2,  0.3f, 0.0f,  // Top Left

            //field goal right
            // ((float)1/14)*13, -0.3f, 0.0f,
            // ((float)1/14)*13, -0.35f, 0.0f, 
            // ((float)1/7)*6,   -0.35f, 0.0f,
            // ((float)1/7)*6,   -0.3f, 0.0f,
        };

        GLuint field_indices[90] = {  // Note that we start from 0!
            0, 1, 3,  // First Triangle
            1, 2, 3,   // Second Triangle

            4, 5, 7,
            5, 6, 7,

            8, 9, 11,
            9, 10, 11,

            12, 13, 15,
            13, 14, 15,

            16, 17, 19,
            17, 18, 19,

            20, 21, 23,
            21, 22, 23,

            24, 25, 27,
            25, 26, 27,

            28, 29, 31,
            29, 30, 31,

            32, 33, 35,
            33, 34, 35,

            36, 37, 39,
            37, 38, 39,

            40, 41, 43,
            41, 42, 43,

            44, 45, 47,
            45, 46, 47,

            48, 49, 51,
            49, 50, 51,

            52, 53, 55,
            53, 54, 55,

            56, 57, 59,
            57, 58, 59,

            //60, 61, 63,
            //62, 63, 64,

        };

        GLuint VBO, VAO, EBO;

    public:
        Field();
        void Draw();
};

#endif
