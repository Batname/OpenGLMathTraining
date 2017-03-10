//
//  Cube.hpp
//  OpenGLMathTraining
//
//  Created by apple on 2017-03-10.
//  Copyright © 2017 apple. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <stdio.h>

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a)

class Cube
{
public:
    Cube(class Shader *shader);
    ~Cube();
    
    void BindVectors();
    void RenderVectors();
    void BindCube();
    void RenderCube();
    
protected:
private:

    GLfloat *VectorVertices;
    GLuint Vector_VBO, Vector_VAO;
    
    glm::vec3 *CubeVertices;
    unsigned int CubeNumVertices;
    unsigned int SizeCubeVertices;
    
    unsigned short *CubeIndices;
    unsigned int CubeNumIndices;
    unsigned int SizeCubeIndices;
    GLuint Cube_VBO, Cube_VAO, Cube_EBO;

    
    class Shader *myShader;
};

#endif /* Cube_hpp */
