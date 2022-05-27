void count(string s)
{ 
    unordered_map<char, int> count;
    for(int i = 0; i < s.size(); i++)
        count[s[i]]++;
    cout << "Count of duplicates\n";
    for(auto it: count)
    {
        if(it.se > 1)
        cout << it.fi << ": " << it.se << endl;
    }
}
