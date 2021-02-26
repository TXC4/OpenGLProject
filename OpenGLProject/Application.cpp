#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <iostream>

// Prototypes
void drawPolygon(int, float, float, float, float, std::string, float[3]);
void translateVertices(float, float);

// Global Values
int numOfVertices = 10;
float angle = 0.0;
float xPos = 0, yPos = 0, radius = 0.1f;
float prevX = xPos;
float prevY = yPos - radius;

// Colors
float red[3] = { 1,0,0 };
float green[3] = { 0,1,0 };
float blue[3] = { 0,0,1 };
float yellow[3] = { 1, 1, 0 };
float purple[3] = { 1, 0, 1 };
float cyan[3] = { 0,1,1 };
float white[3] = { 1,1,1 };
float orange[3] = { 1,0.5,0 };
float greenYellow[3] = { 0.5, 1, 0 };
float lightGreen[3] = { 0.5,1,0.5 };
float darkGreen[3] = { 0,0.5,0 };
float pink[3] = { 1,0.43, 0.78 };
float copper[3] = { 0.85, 0.53,0.1 };
float orchid[3] = { 0.85, 0.54, 0.85 };
float brass[3] = { 0.71, 0.65, 0.26 };

// Initial vertices of polygon
float vertices[9]{
        0.0f, 0.0f, 0.0f,
       -0.5f, -0.5f, 0.0f,
        0.2f, 0.2f, 0.0f
};

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

    // Make the window's context current
    glfwMakeContextCurrent(window);

    //glViewport(0, 0, 1024, 768);

    //glew is an extension wrangler for shaders
    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    // Print opengl version 
    std::cout << glGetString(GL_VERSION) << std::endl;

    // IGNORE
    /* Generate and bind buffer for glDrawArrays or glDrawElement*/
    //unsigned int buffer;
    //glGenBuffers(1, &buffer);
    //glBindBuffer(GL_ARRAY_BUFFER, buffer);
    //glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), triangleVertexPositions, GL_STATIC_DRAW); //buffer size in bytes

    // Sets line width
    glLineWidth(2.0f);

    // Define attributes
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        float prevX = xPos;
        float prevY = yPos - radius;

        // Draw calls
        drawPolygon(3, -0.7, 0.6, prevX, prevY, "fill", red);
        drawPolygon(3, -0.5, 0.6, prevX, prevY, "outline", blue);

        drawPolygon(4, -0.1, 0.6, prevX, prevY, "fill", green);
        drawPolygon(4, 0.1, 0.6, prevX, prevY, "outline", yellow);

        drawPolygon(5, 0.5, 0.6, prevX, prevY, "fill", cyan);
        drawPolygon(5, 0.7, 0.6, prevX, prevY, "outline", orange);

        drawPolygon(6, -0.7, 0.0, prevX, prevY, "fill", purple);
        drawPolygon(6, -0.5, 0.0, prevX, prevY, "outline", greenYellow);

        drawPolygon(7, -0.1, 0.0, prevX, prevY, "fill", lightGreen);
        drawPolygon(7, 0.1, 0.0, prevX, prevY, "outline", copper);

        drawPolygon(8, 0.5, 0.0, prevX, prevY, "fill", pink);
        drawPolygon(8, 0.7, 0.0, prevX, prevY, "outline", darkGreen);

        drawPolygon(1000, -0.1, -0.6, prevX, prevY, "fill", orchid);
        drawPolygon(1000, 0.1, -0.6, prevX, prevY, "outline", brass);

        // IGNORE
        /* No index buffer defined so glDrawArrays defines index start and count
        draws bounded buffer last called by glBindBuffer() */
        //glColor3f(0, 1, 0);
        //glDrawArrays(GL_TRIANGLES, 0, 3);

        // IGNORE
        /* Used if we have index buffer*/
        //glDrawElements(GL_TRIANGLES, 3, NULL);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// Adds a value to vertices to translate position
void translateVertices(float distanceX, float distanceY)
{
    // Translate x values
    vertices[0] = vertices[0] + distanceX;
    vertices[3] = vertices[3] + distanceX;
    vertices[6] = vertices[6] + distanceX;

    // Translate y values
    vertices[1] = vertices[1] + distanceY;
    vertices[4] = vertices[4] + distanceY;
    vertices[7] = vertices[7] + distanceY;
}

// Polygon drawing function
void drawPolygon(int numVert, float translateX, float translateY, float oldX, float oldY, std::string type, float color[3]) {
    
    // Loop thru triangles
    for (int i = 0; i <= numVert; i++) {
        // Divides circle by number of vertices
        angle = M_PI * 2.0f / numVert;

        // Sets coordinates of next point along radius
        float newX = radius * sin(angle * i);
        float newY = -radius * cos(angle * i);

        // Updates array vertices for translation
        vertices[0] = 0.0f;
        vertices[1] = 0.0f;
        vertices[2] = 0.0f;
        vertices[3] = oldX;
        vertices[4] = oldY;
        vertices[5] = 0.0f;
        vertices[6] = newX;
        vertices[7] = newY;
        vertices[8] = 0.0f;

        // Translates vertices on screen
        translateVertices(translateX, translateY);

        // Sets color
        glColor3f(color[0], color[1], color[2]);

        if (type == "outline") {
            // Draw lines outlining polygon
            glBegin(GL_LINES);
            glVertex3f(vertices[3], vertices[4], vertices[5]);
            glVertex3f(vertices[6], vertices[7], vertices[8]);
            glEnd();
        }
        else if (type == "fill") {
            // Draw filled polygon
            glBegin(GL_TRIANGLES);
            glVertex3f(vertices[0], vertices[1], vertices[2]);
            glVertex3f(vertices[3], vertices[4], vertices[5]);
            glVertex3f(vertices[6], vertices[7], vertices[8]);
            glEnd();
        }

        // Sets new reference point for next triangle to be drawn
        oldX = newX;
        oldY = newY;
    }
}
