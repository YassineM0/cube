#include <glad/gl.h>
#include <glfw/glfw3.h>
#include <chrono>
#include <iostream>

#include "Shader.h"
#include "Mesh.h"

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
    glfwSwapInterval(0);

    if(!gladLoadGL(glfwGetProcAddress)) {
        std::cerr << "failed to initialize glad" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Shader shader("../src/shader.vert", "../src/shader.frag");

    const int NUM_TRIANGLES = 1000;
    float vertices[NUM_TRIANGLES * 9];
    for (int i = 0; i < NUM_TRIANGLES * 9; ++i)
        vertices[i] = ((rand() % 2000) / 1000.0f) - 1.0f;

    Mesh mesh(vertices, NUM_TRIANGLES * 9);



    while(!glfwWindowShouldClose(window)) {

        auto frameStart = std::chrono::high_resolution_clock::now();    

        glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        mesh.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();

        auto frameEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float, std::milli> frameTime = frameEnd - frameStart; 

        float fps = 1000.0f / frameTime.count();
        std::cout << "FPS: " << fps << std::endl; 

    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
