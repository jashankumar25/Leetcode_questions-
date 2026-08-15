class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        string temp = s + s;

        return temp.find(goal) != string::npos;
    }
}; /*bool rotateString(string s, string goal) {
          if(s.length() != goal.length())
             return false;

         for(int i = 0; i < s.length(); i++)
         {
             if(s == goal)
                 return true;
             //rotate one shift
             rotate(s.begin(), s.begin() + 1, s.end());
         }

         return false;
     }


 rotate(first, mid, last);

 Parameters:
 first: Iterator to the first element in the range.
 mid: Iterator to the element that becomes the new first element.
 which positiion willl become starting position of the range
 last: Iterator to the theoretical element just after the last element in the
 range.


 #### NOTE:if yoy concatenate a str with itself ,it containn all rotaions as a
 substring in it
 */