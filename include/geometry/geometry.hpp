#pragma once

class Geometry {
public:
    virtual ~Geometry() = default;

    unsigned int VBO = 0;

    unsigned int VAO = 0;

    virtual void draw() const = 0;

protected:
    virtual void loadVerticesObjects() = 0;
};
