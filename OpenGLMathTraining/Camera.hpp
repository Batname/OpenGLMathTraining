//
//  Camera.hpp
//  OpenGLMathTraining
//
//  Created by apple on 2017-03-09.
//  Copyright © 2017 apple. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

// Std. Includes
#include <vector>

// GL Includes
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
    enum Camera_Movement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };
    
    Camera();
    ~Camera();
    
    glm::mat4 GetViewMatrix() const;
    
    void ProcessMouseScroll(GLfloat yoffset);
    void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true);
    void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime);
    
protected:
private:
    void updateCameraVectors();
    
    // Default camera values
    const GLfloat YAW        = -90.0f;
    const GLfloat PITCH      =  0.0f;
    const GLfloat SPEED      =  3.0f;
    const GLfloat SENSITIVTY =  0.25f;
    const GLfloat ZOOM       =  45.0f;
    
    // Camera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // Eular Angles
    GLfloat Yaw;
    GLfloat Pitch;
    // Camera options
    GLfloat MovementSpeed;
    GLfloat MouseSensitivity;
    GLfloat Zoom;
};

#endif /* Camera_hpp */
