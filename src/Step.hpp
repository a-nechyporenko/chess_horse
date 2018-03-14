#ifndef STEPS_HPP
#define STEPS_HPP

#include <vector>
#include <utility>

class Step
{
    public:
        Step();
        Step(int x, int y);
        Step(const std::pair<int, int>& coord_, bool isStepFaild_);

        ~Step();

        const std::pair<int, int>& getCoord() const;
        void setCoord(const std::pair<int, int> &value);

        bool getIsStepFaild() const;
        void setIsStepFaild(bool value);

        void addNewFaildNextStep(const Step &step);
        bool isNextStepAlreadyInFaild(const std::pair<int, int> &nextStepCoord);
        std::vector<Step> getFaildNextSteps() const;

    private:
        std::pair<int, int> coord;
        std::vector<Step> faildNextSteps;
        bool isStepFaild;

};

#endif // STEPS_HPP


