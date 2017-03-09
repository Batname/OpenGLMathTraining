//
//  Camera.hpp
//  OpenGLMathTraining
//
//  Created by apple on 2017-03-09.
//  Copyright © 2017 apple. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <glm/glm.hpp>

class Camera
{
public:
    Camera();
    ~Camera();
    
    glm::mat4 GetCameraMat4() const;
protected:
private:
};

#endif /* Camera_hpp */
