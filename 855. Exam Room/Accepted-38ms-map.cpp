#include <map>

using namespace std;

class ExamRoom
{
  private:
    int m_iMaxSeat;
    map<int, bool> m_mapSeat;

  public:
    ExamRoom(int N) : m_iMaxSeat(N - 1)
    {
    }

    int seat()
    {
        int iRetSeat = 0;
        int i = m_mapSeat.size();
        if (0 == i)
        {
            iRetSeat = 0;
        }
        else
        {
            int iMaxDis = m_mapSeat.begin()->first;
            auto itrPre = m_mapSeat.begin();
            for (auto itrCur = ++m_mapSeat.begin(); itrCur != m_mapSeat.end(); ++itrCur)
            {
                int iCurDis = (itrCur->first - itrPre->first) >> 1;
                if (iCurDis > iMaxDis)
                {
                    iMaxDis = iCurDis;
                    iRetSeat = (itrCur->first + itrPre->first) >> 1;
                }
                itrPre = itrCur;
            }
            if (iMaxDis < (m_iMaxSeat - itrPre->first))
            {
                iRetSeat = m_iMaxSeat;
            }
        }
        m_mapSeat[iRetSeat] = true;
        return iRetSeat;
    }

    void leave(int p)
    {
        m_mapSeat.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
