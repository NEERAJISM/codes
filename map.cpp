#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    map<string, int> counters; // store each word as an associated counter
    string::size_type maxlen = 0;
    // read the input, keeping track of each word and how often we see it
    int i =5;
    while (i--)
    {
        cin >> s;
        ++counters[s];
        if (counters[s] > maxlen)
            maxlen = counters[s];
    }
    for(string::size_type i = 1; i <= maxlen; ++i)
    {
        // write the words and associated counts
        for (map<string, int>::const_iterator it = counters.begin();it != counters.end(); ++it)
        {
            if (it->second == i)
                cout << it->first << "\t" << it->second << endl;
        }
    }
    return 0;
}
