#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

int numOfVertices = 3;
float angle = 0.0;
float xPos = 0, yPos = 0, radius = 0.1f;
float prevX = xPos;
float prevY = yPos - radius;

float vertices[9]{
        0.0f, 0.0f, 0.0f,
       -0.5f, -0.5f, 0.0f,
        0.2f, 0.2f, 0.0f
};

/* 2D Transform Matrix */
float transformMatrix[9] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

void translateVertices(float distanceX, float distanceY)
{
    vertices[0] = vertices[0] + distanceX;
    vertices[3] = vertices[3] + distanceX;
    vertices[6] = vertices[6] + distanceX;

    vertices[1] = vertices[1] + distanceY;
    vertices[4] = vertices[4] + distanceY;
    vertices[7] = vertices[7] + distanceY;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1024, 768, "Fogle", NULL, NULL);
    
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* glewInit cannot be called before glfw context created */
    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    /* get opengl version */
    std::cout << glGetString(GL_VERSION) << std::endl;


    /* generate and bind buffer */
    //unsigned int buffer;
    //glGenBuffers(1, &buffer);
    //glBindBuffer(GL_ARRAY_BUFFER, buffer);
    //glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), triangleVertexPositions, GL_STATIC_DRAW); //buffer size in bytes

    


    /* define attributes */
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /*for (int i = 0; i <= numOfVertices; i++) {
            updateVertices(i);
        }*/
        
        float prevX = xPos;
        float prevY = yPos - radius;
        
        for (int i = 0; i <= numOfVertices; i++) {
            angle = M_PI * 2.0f / numOfVertices;

            float newX = radius * sin(angle * i);
            float newY = -radius * cos(angle * i);

            /*glBegin(GL_TRIANGLES);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(prevX, prevY, 0.0f);
            glVertex3f(newX, newY, 0.0f);
            glEnd();*/

            vertices[0] = 0.0f;
            vertices[1] = 0.0f;
            vertices[2] = 0.0f;
            vertices[3] = prevX;
            vertices[4] = prevY;
            vertices[5] = 0.0f;
            vertices[6] = newX;
            vertices[7] = newY;
            vertices[8] = 0.0f;

            translateVertices(-0.5, 0.5);

            glBegin(GL_TRIANGLES);
            glVertex3f(vertices[0], vertices[1], vertices[2]);
            glVertex3f(vertices[3], vertices[4], vertices[5]);
            glVertex3f(vertices[6], vertices[7], vertices[8]);
            glEnd();

            //glColor3f(0, 1, 0);
            //glDrawArrays(GL_TRIANGLES, 0, 3);

            prevX = newX;
            prevY = newY;
        }

        /* no index buffer defined so glDrawArrays defines index start and count */
        /* draws bounded buffer last called by glBindBuffer() */
        //glColor3f(0, 1, 0);
        //glDrawArrays(GL_TRIANGLES, 0, 3);

        /* used if we have index buffer*/
        //glDrawElements(GL_TRIANGLES, 3, NULL);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}