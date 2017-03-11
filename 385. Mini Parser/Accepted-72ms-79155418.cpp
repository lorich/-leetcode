// 385. Mini Parser
// https://leetcode.com/problems/mini-parser/
// 

//Given s = "324"
//324
//Given s = "[123,[456,[789]],[324],666]"
//Expected answer: [123,[456,[789]],[324],666]
//"[[[[]]],[]]"
class Solution {
public:
    const vector<string> explode(const string& s, const char c, const char l, const char r)
    {
        string buff{""};
        vector<string> v;
        int counter=0;

        for(auto n:s)
        {
            if(n == l)counter++;
            if(n == r)counter--;
            if(n == c && counter == 0) 
            { 
                v.push_back(buff); 
                buff.clear(); 
            }
            else buff += n;
        }
        if(!buff.empty()) v.push_back(buff);

        return v;
    }

    NestedInteger deserialize(string s) {
		NestedInteger ni;
		if(s.empty())
		{
			return ni;
		}
		auto posStart = s.find_first_of('['), posEnd = s.find_last_of(']');
        if(posStart == string::npos && posEnd == string::npos)
		{
            cout << "##" << s << endl;
			ni.setInteger(atoi(s.c_str()));
			return ni;
		}
		else if(posStart == 0 && posEnd == s.size()-1)
		{
            vector<string> vecStr = this->explode(s.substr(posStart+1, posEnd - posStart - 1), ',', '[', ']');
            for(auto str:vecStr)
            {
                cout << "#" << str << endl;
                ni.add(deserialize(str));
            }
            return ni;
		}
		else
		{
			return ni;
		}
    }
};

/*
Given a nested list of integers represented as a string, implement a parser to deserialize it. Each element is either an integer, or a list -- whose elements may also be integers or other lists. Note: You may assume that the string is well-formed: String is non-empty. String does not contain white spaces. String contains only digits 0-9, [, - ,, ]. Example 1: 
Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
 Example 2: 
Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
 Subscribe to see which companies asked this question. Show Tags Stack String Show Similar Problems (M) Flatten Nested List Iterator (M) Ternary Expression Parser
*/
