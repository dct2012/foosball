#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other includes
#include "shader.h"


// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 1400, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop
int main()
{
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Foosball", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    glewInit();

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);

    // Build and compile our shader program
    Shader ourShader("vertexshader.c", "fragmentshader.c");


    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat field_vertices[] = {
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
    GLuint field_indices[] = {  // Note that we start from 0!
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

    GLfloat scoreboard_vertices[] = {
         0.57f,  0.9f, 0.0f,  // Top Right
         0.57f, 0.4f, 0.0f,  // Bottom Right
        -0.57f, 0.4f, 0.0f,  // Bottom Left
        -0.57f,  0.9f, 0.0f  // Top Left
    };
    GLuint scoreboard_indices[] = {  // Note that we start from 0!
        0, 1, 3,  // First Triangle
        1, 2, 3   // Second Triangle
    };

    GLuint VBO[2], VAO[2], EBO[2];
    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);
    glGenBuffers(2, EBO);
    
    //setup football field
    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(field_vertices), field_vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(field_indices), field_indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    //setup scoreboard
    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(scoreboard_vertices), scoreboard_vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(scoreboard_indices), scoreboard_indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);


    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.0f, 0.392f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ourShader.Use();

        glBindVertexArray(VAO[0]);
        glDrawElements(GL_TRIANGLES, 90, GL_UNSIGNED_INT, 0);
        
        glBindVertexArray(VAO[1]);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        glBindVertexArray(0);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, VAO);
    glDeleteBuffers(1, VBO);
    glDeleteBuffers(1, EBO);
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
