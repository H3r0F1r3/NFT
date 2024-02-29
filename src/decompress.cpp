#include <vector>
#include <string>
using namespace std;

string decompress(const vector<pair<int, int>>& input)
{
    string output;
    for (auto element: input)
    {
        if (element.first == 0)
        {
            output += char(element.second);
        } else {
            for (int i = element.second; i != element.second + element.first; ++i)
            {
                output += char(output[i]);
            }
        }
    }
    return output;
}
