#ifndef FIELD_HPP
#define FIELD_HPP


class Field
{
public:
    Field();
    ~Field() = default;

    void draw();
    bool getIsVisited() const;
    void setIsVisited(bool value);

    int getNumberOfStep() const;
    void setNumberOfStep(int value);

private:
    bool isVisited;
    int numberOfStep;
};

#endif // FIELD_HPP
