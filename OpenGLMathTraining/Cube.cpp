//
//  Cube.cpp
//  OpenGLMathTraining
//
//  Created by apple on 2017-03-10.
//  Copyright © 2017 apple. All rights reserved.
//

#include "Cube.hpp"

#include "Camera.hpp"
#include "Shader.h"


#include <string.h>
#include <stdio.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

extern Camera *camera;

using namespace glm;

Cube::Cube(class Shader *shader) : myShader(shader)
{
    vec3 cubeVertices[] =
    {
        vec3(-1.0f, +1.0f, +1.0f),  // 0
        vec3(+0.0f, +1.0f, +0.0f),	// Color
        vec3(+1.0f, +1.0f, +1.0f),  // 1
        vec3(+0.0f, +1.0f, +0.0f),	// Color
        vec3(+1.0f, +1.0f, -1.0f),  // 2
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(-1.0f, +1.0f, -1.0f),  // 3
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        
        vec3(-1.0f, +1.0f, -1.0f),  // 4
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(+1.0f, +1.0f, -1.0f),  // 5
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(+1.0f, -1.0f, -1.0f),  // 6
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(-1.0f, -1.0f, -1.0f),  // 7
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        
        vec3(+1.0f, +1.0f, -1.0f),  // 8
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(+1.0f, +1.0f, +1.0f),  // 9
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(+1.0f, -1.0f, +1.0f),  // 10
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(+1.0f, -1.0f, -1.0f),  // 11
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        
        vec3(-1.0f, +1.0f, +1.0f),  // 12
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(-1.0f, +1.0f, -1.0f),  // 13
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(-1.0f, -1.0f, -1.0f),  // 14
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(-1.0f, -1.0f, +1.0f),  // 15
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        
        vec3(+1.0f, +1.0f, +1.0f),  // 16
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(-1.0f, +1.0f, +1.0f),  // 17
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(-1.0f, -1.0f, +1.0f),  // 18
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(+1.0f, -1.0f, +1.0f),  // 19
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        
        vec3(+1.0f, -1.0f, -1.0f),  // 20
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(-1.0f, -1.0f, -1.0f),  // 21
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(-1.0f, -1.0f, +1.0f),  // 22
        vec3(+0.0f, +1.0f, +0.0f),  // Color
        vec3(+1.0f, -1.0f, +1.0f),  // 23
        vec3(+0.0f, +1.0f, +0.0f),  // Color
    };
    
    CubeNumVertices = NUM_ARRAY_ELEMENTS(cubeVertices);
    SizeCubeVertices = sizeof(cubeVertices);

    CubeVertices = new vec3[CubeNumVertices];
    memcpy(CubeVertices, cubeVertices, SizeCubeVertices);
    
    unsigned short cubeIndices[] = {
        0,   1,  2,  0,  2,  3, // Top
        4,   5,  6,  4,  6,  7, // Front
        8,   9, 10,  8, 10, 11, // Right
        12, 13, 14, 12, 14, 15, // Left
        16, 17, 18, 16, 18, 19, // Back
        20, 22, 21, 20, 23, 22, // Bottom
    };
    
    CubeNumIndices = NUM_ARRAY_ELEMENTS(cubeIndices);
    SizeCubeIndices = sizeof(cubeIndices);
    CubeIndices = new GLushort[CubeNumIndices];
    memcpy(CubeIndices, cubeIndices, SizeCubeIndices);
    
    // Vectors
    vec3 vectorVertices[] =
    {
        vec3(+2.5f, +0.0f, +0.5f),  // 0
        vec3(+0.0f, +0.0f, +1.0f),	// Color
        vec3(+0.0f, +0.0f, +0.5f),  // 1
        vec3(+0.0f, +0.0f, +1.0f),	// Color
    };
    
    VectorNumVertices = NUM_ARRAY_ELEMENTS(vectorVertices);
    SizeVectorVertices = sizeof(VectorNumVertices);
    
    VectorVertices = new vec3[VectorNumVertices];
    memcpy(VectorVertices, vectorVertices, SizeVectorVertices);
    
}

Cube::~Cube()
{
    delete CubeVertices;
    delete CubeIndices;
    delete VectorVertices;
    
    glDeleteVertexArrays(1, &Cube_VAO);
    glDeleteBuffers(1, &Cube_VBO);
    glDeleteBuffers(1, &Cube_EBO);
    
    glDeleteVertexArrays(1, &Vector_VAO);
    glDeleteBuffers(1, &Vector_VBO);
}

void Cube::BindVectors()
{
    glGenVertexArrays(1, &Vector_VAO);
    glGenBuffers(1, &Vector_VBO);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(Vector_VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, Vector_VBO);
    
    glBufferData(GL_ARRAY_BUFFER, SizeVectorVertices, VectorVertices, GL_STATIC_DRAW);
    
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0); // Unbind VAO
}

void Cube::RenderVectors()
{
    // Draw the triangle
    myShader->Use();
    glBindVertexArray(Vector_VAO);
    
//    // append new vertex
//    glBindBuffer(GL_ARRAY_BUFFER, Vector_VBO);
//    glBufferSubData(GL_ARRAY_BUFFER, 3, 6 * sizeof(GLfloat), VectorVertices);
    
    // Transformation matrix
    glm::mat4 transformMatrix;
    
    glm::mat4 view;
    view = camera->GetViewMatrix();
    
    glm::mat4 projection;
    projection = camera->GetProjection();
    
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    model = glm::scale(model, glm::vec3(7.0f, 2.0f, 7.0f));
    
    
    transformMatrix = projection * view * model;
    
    
    // Camera transformation
    GLuint transformLoc = glGetUniformLocation(myShader->Program, "transformMatrix");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transformMatrix));
    
    glDrawArrays(GL_LINES, 0, VectorNumVertices);
    glBindVertexArray(0);
}

void Cube::BindCube()
{
    glGenVertexArrays(1, &Cube_VAO);
    glGenBuffers(1, &Cube_VBO);
    glGenBuffers(1, &Cube_EBO);
    
    glBindVertexArray(Cube_VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, Cube_VBO);
    glBufferData(GL_ARRAY_BUFFER, SizeCubeVertices, CubeVertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Cube_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, SizeCubeIndices, CubeIndices, GL_STATIC_DRAW);
    
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Cube::RenderCube()
{
    myShader->Use();
    glBindVertexArray(Cube_VAO);
    
    // Transformation matrix
    glm::mat4 transformMatrix;
    
    glm::mat4 view;
    view = camera->GetViewMatrix();
    
    glm::mat4 projection;
    projection = camera->GetProjection();
    
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(0.5f, 0.5f, 0.5f));
    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
    
    
    transformMatrix = projection * view * model;
    
    
    // Camera transformation
    GLuint transformLoc = glGetUniformLocation(myShader->Program, "transformMatrix");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transformMatrix));
    
	glDrawElements(GL_TRIANGLES, CubeNumIndices, GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);
}
