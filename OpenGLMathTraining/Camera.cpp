//
//  Camera.cpp
//  OpenGLMathTraining
//
//  Created by apple on 2017-03-09.
//  Copyright © 2017 apple. All rights reserved.
//

#include <GLFW/glfw3.h>

extern GLFWwindow *window;

#include "Camera.hpp"


Camera::Camera()
{
}

Camera::~Camera()
{
}

glm::mat4 Camera::GetCameraMat4() const
{
    return glm::mat4();
}
