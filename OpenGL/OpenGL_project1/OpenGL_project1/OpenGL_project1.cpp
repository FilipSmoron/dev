#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"in vec2 position;\n"
"in vec3 color;\n"
"out vec3 Color;\n"
"void main()\n"
"{\n"
" Color = color;\n"
" gl_Position = vec4(position, 0.0, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderRainbowChess = "#version 330 core\n"
"in vec3 Color;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    // Calculate rainbow color based on pixel coordinates\n"
"    vec3 rainbowColor;\n"
"    rainbowColor.r = abs(sin(gl_FragCoord.x * 0.0123));\n"
"    rainbowColor.g = abs(sin(gl_FragCoord.y * 0.0123));\n"
"    rainbowColor.b = abs(sin((gl_FragCoord.x + gl_FragCoord.y) * 0.0123));\n"
"    // Apply the chess pattern\n"
"    int x = int(gl_FragCoord.x) / 40;\n"
"    int y = int(gl_FragCoord.y) / 40;\n"
"    if ((x + y) % 2 == 0)\n"
"        FragColor = vec4(rainbowColor, 1.0);\n"
"    else\n"
"        FragColor = vec4(1.0 - rainbowColor, 1.0);\n"
"}\n\0";

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Configure GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Window", NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Utwórz obiekt Vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Połącz istniejący obiekt z napisaną wcześniej implementacją shadera
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // Skompiluj gotowy kod
    glCompileShader(vertexShader);
    // Powtórz operację dla fragment shadera
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderRainbowChess, NULL);
    glCompileShader(fragmentShader);
    // Utwórz program
    GLuint shaderProgram = glCreateProgram();
    // Podłącz shadery pod program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // Usuń niepotrzebne shadery
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    // Indices for a rectangle
    GLuint indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };

    // Vertices coordinates for a triangle
    GLfloat vertices[] =
    {
        -1.0f, -1.0f, 0.0f, // Lower left corner
         1.0f, -1.0f, 0.0f, // Lower right corner
         1.0f,  1.0f, 0.0f, // Upper right corner
        -1.0f,  1.0f, 0.0f  // Upper left corner
    };



    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
    GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
        (void*)(2 * sizeof(float)));


    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glUniform3f(glGetUniformLocation(shaderProgram, "color1"), 0.8f, 0.3f, 0.02f);
        glUniform3f(glGetUniformLocation(shaderProgram, "color2"), 0.07f, 0.13f, 0.17f);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}
