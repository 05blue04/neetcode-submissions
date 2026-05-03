class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }

        int freqmap1[26];
        int freqmap2[26];

        for(int i = 0; i < 26; i++){
            freqmap1[i] = 0;
            freqmap2[i] = 0;
        }


        for(int i = 0; i < s.size(); i++){
            char a = s[i];
            char b = t[i];
            freqmap1[a - 'a']++;
            freqmap2[b - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freqmap1[i] != freqmap2[i]){
                return false;
            }
        }

       return true; 
    }
};
