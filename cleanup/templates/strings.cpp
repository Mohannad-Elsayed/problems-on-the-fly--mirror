namespace strings {
    bool palindrome(string &s){
        int sz = s.size();
        for (int i = 0; i<=sz/2; i++)
            if (s[i] != s[sz-i-1])
                return false;
        return true;
    }
}