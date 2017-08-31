#include <vector>
#include <sstream>

using namespace std;

class Solution
{
  public:
    int findMinDifference(vector<string> &timePoints)
    {
        const int mini1day = 24 * 60;
        if (timePoints.size() > mini1day)
            return 0;
        vector<int> timep;
        for (const auto &timestr : timePoints)
        {
            int hour, mini;
            char buff;
            stringstream timess(timestr);
            timess >> hour >> buff >> mini;
            timep.push_back(hour * 60 + mini);
        }
        sort(timep.begin(), timep.end());
        timep.push_back(timep[0] + mini1day);
        int dif = mini1day;
        for (size_t i = 1; i < timep.size(); ++i)
        {
            dif = min(timep[i] - timep[i - 1], dif);
        }
        return dif;
    }
};

int main()
{
    return 0;
}