class Solution
{
public:
    string pushDominoes(string str)
    {
        string ans = "";
        int start = 1;
        for (int i = 0; i < str.size();)
        {
            if (str[i] == 'R')
            {
                string x = "";
                int cnt = 0;
                int j = i;

                while (j < str.size() && str[j] == 'R') { cnt++; j++; }
                int dots = 0;
                int k = j;
                while (k < str.size() && str[k] == '.') { dots++; k++; }
                int lcnt = 0;
                int l = k;
                while (l < str.size() && str[l] == 'L') { lcnt++; l++; }

                if (dots > 0 && lcnt > 0)
                {
                    int total = dots;
                    int temp = total / 2;
                    for (int z = 0; z < cnt; z++) ans += 'R';
                    for (int z = 0; z < temp; z++) ans += 'R';
                    if (total % 2) ans += '.';
                    for (int z = 0; z < temp; z++) ans += 'L';
                    for (int z = 0; z < lcnt; z++) ans += 'L';
                    i = l;
                }
                else
                {
                    for (int z = 0; z < cnt; z++) ans += 'R';
                    for (int z = 0; z < dots; z++) ans += 'R';
                    i = k;
                }
            }
            else if (str[i] == 'L')
            {
                int l = i;
                while (l < str.size() && str[l] == 'L') { ans += 'L'; l++; }
                i = l;
            }
            else if (str[i] == '.')
            {
                int j = i;
                while (j < str.size() && str[j] == '.') { j++; }
                if (j < str.size() && str[j] == 'L')
                {
                    for (int z = i; z < j; z++) ans += 'L';
                }
                else
                {
                    for (int z = i; z < j; z++) ans += '.';
                }
                i = j;
            }
        }
        return ans;
    }
};
