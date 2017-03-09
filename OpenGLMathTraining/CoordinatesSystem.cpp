//
//  CoordinatesSystem.cpp
//  OpenGLMathTraining
//
//  Created by apple on 2017-03-09.
//  Copyright © 2017 apple. All rights reserved.
//

#include "CoordinatesSystem.hpp"
#include "Shader.h"
#include "Camera.hpp"


#include <stdlib.h>
#include <stdio.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

extern Camera *camera;

CoordinatesSystem::CoordinatesSystem(Shader *shader) :
    myShader(shader)
{
    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[VERTICES_QTY] = {
        // Positions         // Colors
        0.5f,  0.0f,  0.0f,   1.0f, 0.0f, 0.0f,  // X main
       -0.5f,  0.0f,  0.0f,   0.0f, 1.0f, 0.0f,  // X main
        0.0f,  0.5f,  0.0f,   1.0f, 0.0f, 0.0f,  // Y main
        0.0f, -0.5f,  0.0f,   0.0f, 1.0f, 0.0f,  // Y main
        0.0f,  0.0f, -0.5f,   1.0f, 0.0f, 0.0f,  // Z main
        0.0f,  0.0f,  0.5f,   0.0f, 1.0f, 0.0f   // Z main
    };
    
    memcpy(Vertices, vertices, sizeof(vertices));
}

CoordinatesSystem::~CoordinatesSystem()
{
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void CoordinatesSystem::Bind()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0); // Unbind VAO
}

void CoordinatesSystem::Render()
{
    // Draw the triangle
    myShader->Use();
    glBindVertexArray(VAO);
    
    // Transformation matrix
    glm::mat4 transformMatrix;
    
    glm::mat4 view;
    view = camera->GetViewMatrix();
    
    glm::mat4 projection;
    projection = camera->GetProjection();
    
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.0f));
    model = glm::scale(model, glm::vec3(2.0f));
    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    
    transformMatrix = projection * view * model;
    
    
    // Camera transformation
    GLuint transformLoc = glGetUniformLocation(myShader->Program, "transformMatrix");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transformMatrix));
    
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_LINES, 0, 6);
    glBindVertexArray(0);
}
