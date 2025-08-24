#ifndef MESH_H
#define MESH_H

#include <glad/gl.h>

#include <iostream>

class Mesh {
public:
    unsigned int VBO, VAO;
    int vertexCount;

    Mesh(float* vertices, int count) {
        vertexCount = count;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }

    void draw() {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertexCount / 3);
    }
};


#endif