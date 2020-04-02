class Solution {
public:
    
    bool isDigit(char c)
    {
        return c >= '0' && c <= '9';
    }

    string decompress(int repeat, string& str)
    {
        int num = 0;
        int i = 0;
        string rst = "";
        while(i < str.length())
        {
            char c = str[i];
            if(isDigit(c))
            {
                num *= 10;
                num += c - '0';
                i++;
            }
            else if(c == '[')
            {
                str = str.substr(i+1);
                rst += decompress(num, str);
                num = 0;
                i = 0;
            }
            else if(c == ']')
            {
                string tmp = rst;
                for(int rp = 1; rp < repeat; rp++) 
                {
                    rst += tmp;
                }

                str = str.substr(i + 1);

                return rst;
            }else{
                rst += c;
                i++;
            }
        }
        return rst;
    }
    string decodeString(string s) {
        return decompress(1, s);
    }
};