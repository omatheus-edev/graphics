
class Geometry {
public:
    virtual ~Geometry() = default;

    virtual void loadVerticesObjects() = 0;

    virtual void draw() = 0;
};