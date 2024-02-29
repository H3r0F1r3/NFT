#include <vector>
#include <string>
using namespace std;

vector<pair<int, int>> compress(const string& s)
{
    vector<pair<int, int>> result;

    /* a|b|b|ab|abbab
     *       ^
     *      pos - posizione iniziale del blocco corrente
     */

    int pos = 0;
    int s_len = s.length();
    while (pos < s_len)
    {
        pair<int, int> best_match {0, 0};
        for (int i = 0; i < pos; ++i)
        {
            int len = 0; // lunghezza match tra s[pos, ...] e s[i, ...]
            while(pos+len < s_len && s[pos+len] == s[i+len]) len++;
            if (len > best_match.first)
            {
                best_match = {len, i};
            }
        }
        if (!best_match.first) best_match = {0, int(s[pos])};
        result.push_back(best_match);
        pos += max(best_match.first, 1);
    }
    return result;
}
