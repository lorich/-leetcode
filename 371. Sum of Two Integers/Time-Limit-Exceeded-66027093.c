// 371. Sum of Two Integers
// https://leetcode.com/problems/sum-of-two-integers/
// 

int getSum(int a, int b) 
{
    char bCur = 0, bFor = 0;
    int bCb = 1;
    int iRes = 0;
    while(a || b || bFor)
    {
        int iCur = 0;
        iCur |= a&0x1;
        iCur <<= 1;
        iCur |= b&0x1;
        iCur <<= 1;
        iCur |= bFor;
        switch(iCur)
        {
            case 0:
                bCur=0;
                bFor=0;
                break;
            case 7:
                bCur=1;
                bFor=1;
                break;
            case 1:
            case 2:
            case 4:
                bCur=1;
                bFor=0;
                break;
            default:
                bCur=0;
                bFor=1;
                break;
        }
        if (bCur)
        {
            iRes |= bCb;
        }

        bCb <<= 1;
        a >>= 1;
        b >>= 1;
    }    
    return iRes;
}

/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -. Example: Given a = 1 and b = 2, return 3. Credits: Special thanks to @fujiaozhu for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Bit Manipulation Show Similar Problems (M) Add Two Numbers
*/
