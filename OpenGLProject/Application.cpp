#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1020, 768, "Fogle", NULL, NULL);
    
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

    float vertexPositions[6] = {
        -0.5f,-0.5f,
         0.0f, 0.5f,
         0.5f,-0.5f
    };

    /* generate and bind buffer */
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertexPositions, GL_STATIC_DRAW); //buffer size in bytes

    /* define attributes */
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /*glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();*/

        /* no index buffer defined so glDrawArrays defines index start and count */
        /* draws bounded buffer last called by glBindBuffer() */
        glColor3f(0, 1, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);

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