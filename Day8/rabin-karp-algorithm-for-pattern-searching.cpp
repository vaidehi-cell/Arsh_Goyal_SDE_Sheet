bool match(string s1, string s2, int i, int j, int len)
{
    for(int k = j; k < j + len; k++)
        if(s2[k] != s1[i + k - j])
            return false;
    return true;
}

void rabinKarp(string text, string pattern)
{ 
    int n = text.size(), m = pattern.size();
    int q = 101 // a prime no.
    int d = 256; // no. of possible characters;
    int i, j, h = 1;
    int p = 0; //hash value of pattern
    int t = 0; //hash value of a window of text

    for(int i = 0; i < m - 1; i++)
        h = (h * d) % q; // h = 256^(m-1)
    for(int i = 0; i < m; i++)
    {
        p = (p * d + pattern[i]) % q; //calculate hash for pattern
        t = (t * d + text[i]) % q;    //calculate hash for text
    }

    for(int i = 0; i < n - m + 1; i++)
    {
        if(p == t) //if hashes match, check if match is found
        {
            if(match(text, pattern, i, 0, m)) 
                cout << "Pattern found at index " << i << endl; 
        }
        if(i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q; //calculating hash for current window
            if(t < 0) //handling negative t
                t += q;
        }
    }
}
