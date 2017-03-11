// 6. ZigZag Conversion
// https://leetcode.com/problems/zigzag-conversion/
// 

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <= 1)
    	{
    		return s;
    	}
    	string strOutStr("");
    	int iLen = s.length();
    	int iStart = 0;
    	for (int iRow = 1; iRow <= nRows; ++iRow)
      	{
      		iStart = iRow;
      		while(iStart <= iLen)
      		{
      			strOutStr.push_back(s[iStart-1]);
      			if (iRow == 1 || iRow == nRows)
      			{
      				iStart += 2*(nRows - 1);
      			}
      			else
      			{
      				iStart += 2*(nRows - iRow);
      				if (iStart > iLen )
      				{
      					break;
      				}
      				strOutStr.push_back(s[iStart-1]);
      				iStart += 2*(iRow -1);
      			}
      		}
      	}	   
      	return strOutStr;
    }
};

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility) 
P   A   H   N
A P L S I I G
Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR" Write the code that will take a string and make this conversion given a number of rows: string convert(string text, int nRows); convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". Subscribe to see which companies asked this question. Show Tags String
*/
