#include <glad/gl.h>
#include <glfw/glfw3.h>
#include <iostream>

#include "Shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
    
    if(!glfwInit()) {
        std::cerr << "failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(700, 500, "window", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    if(!gladLoadGL(glfwGetProcAddress)) {
        std::cerr << "failed to initialize glad" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Shader shader("../src/shader.vert", "../src/shader.frag");

    float vertices[] = {
     0.0f,  0.5f, 0.0f, 
    -0.5f, -0.5f, 0.0f, 
     0.5f, -0.5f, 0.0f  
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);



    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
