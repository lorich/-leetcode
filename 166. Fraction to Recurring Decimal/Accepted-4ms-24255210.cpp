// 166. Fraction to Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal/
// 

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        if (0 == denominator)
        {
            return "";
        }
        if (0 == numerator)
        {
            return "0";
        }
        stringstream ssCardinal, ssFraction, ssSign;
        unsigned nNumerator, nDenominator;
        if (numerator < 0 || denominator < 0)
        {
            if (numerator < 0 && denominator < 0)
            {
                nNumerator = (unsigned)(int)numerator * -1;
                nDenominator = (unsigned)(int)denominator * -1;
            }
            else
            {
                ssSign << "-";
                if(numerator < 0)
                {
                    nNumerator = (unsigned)(int)numerator * -1;
                    nDenominator = denominator;
                }
                else
                {
                    nNumerator = numerator;
                    nDenominator = (unsigned)(int)denominator * -1;
                }
            }
        }
        else
        {
            nNumerator = numerator;
            nDenominator = denominator;
        }
        ssCardinal << nNumerator/nDenominator;
        map<uint64_t, int> mapRemainderBits;
        uint64_t iRemainder = nNumerator%nDenominator;
        if (iRemainder)
        {
        	ssFraction<<".";
        }
        int bitCounter=0;
        while(iRemainder)
        {
            iRemainder *=10;
            bitCounter++;
            map<uint64_t, int>::const_iterator itr = mapRemainderBits.find(iRemainder);
            if (itr != mapRemainderBits.end())
            {
                string strFraction = ssFraction.str();
                string strRepetend = strFraction.substr(itr->second);
                string strHead = strFraction.substr(0, itr->second);
                ssFraction.str("");
                ssFraction << strHead << "(" << strRepetend << ")";
                break;
            }
            else
            {
                ssFraction << iRemainder/nDenominator;
                mapRemainderBits[iRemainder] = bitCounter;
                iRemainder = iRemainder % nDenominator;
            }
        }
        return ssSign.str() + ssCardinal.str()+ssFraction.str();
    }
};

/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format. If the fractional part is repeating, enclose the repeating part in parentheses. For example, Given numerator = 1, denominator = 2, return "0.5". Given numerator = 2, denominator = 1, return "2". Given numerator = 2, denominator = 3, return "0.(6)". No scary math, just apply elementary math knowledge. Still remember how to perform a long division? Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern? Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly. Credits: Special thanks to @Shangrila for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Hash Table Math
*/
