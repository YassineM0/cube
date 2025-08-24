#include <glad/gl.h>
#include <glfw/glfw3.h>
#include <chrono>
#include <iostream>

#include "shaders/Shader.h"
#include "mesh/Mesh.h"
#include "mesh/Cube.h"

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

    Shader shader("../src/shaders/shader.vert", "../src/shaders/shader.frag");

    Cube cube;



    while(!glfwWindowShouldClose(window)) {

        unsigned int query;
        glGenQueries(1, &query);


        auto frameStart = std::chrono::high_resolution_clock::now();    

        glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glBeginQuery(GL_TIME_ELAPSED, query);

        shader.use();
        cube.draw();

        glEndQuery(GL_TIME_ELAPSED);

        glfwSwapBuffers(window);
        glfwPollEvents();

        auto frameEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float, std::milli> frameTime = frameEnd - frameStart; 

        GLuint64 gpuTime = 0;
        glGetQueryObjectui64v(query, GL_QUERY_RESULT, &gpuTime);

        float gpuMs = gpuTime / 1e6f;

        float cpuFps = 1000.0f / frameTime.count();
        float gpuFPS = 1000.0f / gpuMs;

        std::cout << "CPU FPS: " << cpuFps 
          << " | GPU Time: " << gpuFPS  
          << std::endl;


    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
