#ifndef CUBE_H
#define CUBE_H

#include "Mesh.h"

class Cube : public Mesh {
public:
    Cube() : Mesh(cubeVertices, 36*3) {}


private:
     float cubeVertices[36 * 3] = {
        // front face
        -0.5f, -0.5f,  0.5f, 
         0.5f, -0.5f,  0.5f, 
         0.5f,  0.5f,  0.5f, 

         0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 
        -0.5f, -0.5f,  0.5f, 

        // back face
        -0.5f, -0.5f, -0.5f, 
        -0.5f,  0.5f, -0.5f, 
         0.5f,  0.5f, -0.5f, 

         0.5f,  0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 

        // left face
        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 

        // right face
         0.5f,  0.5f,  0.5f, 
         0.5f, -0.5f, -0.5f, 
         0.5f,  0.5f, -0.5f, 

         0.5f, -0.5f, -0.5f, 
         0.5f,  0.5f,  0.5f, 
         0.5f, -0.5f,  0.5f, 

        // top face
        -0.5f,  0.5f, -0.5f, 
        -0.5f,  0.5f,  0.5f, 
         0.5f,  0.5f,  0.5f, 

         0.5f,  0.5f,  0.5f, 
         0.5f,  0.5f, -0.5f, 
        -0.5f,  0.5f, -0.5f, 

        // bottom face
        -0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f,  0.5f, 

         0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f, -0.5f
    };
};


#endif