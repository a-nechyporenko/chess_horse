#ifndef STEPS_HPP
#define STEPS_HPP

#include <vector>
#include <utility>

class Step
{
public:
    Step();
    Step(int x, int y);
    Step(const std::pair<int, int>& coord_, bool isStepFailed_);

    ~Step() = default;

    const std::pair<int, int> &getCoord() const;
    void setCoord(const std::pair<int, int> &value);

    bool getIsStepFailed() const;
    void setIsStepFailed(bool value);

    void addNewFailedNextStep(const Step &step);
    bool isNextStepAlreadyInFailed(const std::pair<int, int> &nextStepCoord);
    std::vector<Step> getFailedNextSteps() const;

private:
    std::pair<int, int> coord;
    std::vector<Step> FailedNextSteps;
    bool isStepFailed;

};

#endif // STEPS_HPP
