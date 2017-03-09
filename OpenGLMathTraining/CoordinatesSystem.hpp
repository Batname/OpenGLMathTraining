//
//  CoordinatesSystem.hpp
//  OpenGLMathTraining
//
//  Created by apple on 2017-03-09.
//  Copyright © 2017 apple. All rights reserved.
//

#ifndef CoordinatesSystem_hpp
#define CoordinatesSystem_hpp

#include <GL/glew.h>

class CoordinatesSystem
{
public:
    CoordinatesSystem(class Shader *shader);
    ~CoordinatesSystem();
    
    void Bind();
    void Render();
protected:
private:
    enum Constants
    {
        VERTICES_QTY = 36
    };
    
    GLfloat Vertices[VERTICES_QTY];
    GLuint VBO, VAO;
    class Shader *myShader;
};

#endif /* CoordinatesSystem_hpp */
