// My WRONG approach
/*
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1 == sentence2)
            return true;
        int n1 = sentence1.size(), n2 = sentence2.size();

        string prefix = "";
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(sentence1[i] != sentence2[j]){
                if(i > 0 && j > 0 && sentence1[i-1] == ' ' && sentence2[j-1] == ' ') 
                    break;
                else{ 
                    prefix = "";
                    break;
                }
            }
            if(sentence1[i] == sentence2[j]) 
                prefix += sentence1[i];
            i++;
            j++;
        }

        string suffix = "";
        i=n1-1, j=n2-1;
        while(i>=0 && j>=0){
            if(sentence1[i] != sentence2[j]){
                if(i < n1-1 && j < n2-1 && sentence1[i+1] == ' ' && sentence2[j+1] == ' ') 
                    break;
                else{ 
                    suffix = "";
                    break;
                }
            }
            if(sentence1[i] == sentence2[j]) 
                suffix += sentence1[i];
            i--;
            j--;
        }

        if(!prefix.empty() && isspace(prefix.back()))
            prefix.pop_back();
        reverse(suffix.begin(), suffix.end());

        // cout<<prefix<<endl;
        // cout<<suffix<<endl;
        // cout<<prefix+suffix<<endl;
        if(n1 < n2){
            if(prefix + suffix == sentence1)
                return true;
            return false;
        }
        else{
            if(prefix + suffix == sentence2)
                return true;
            return false;
        }

    }
};
*/


// T.C: O(m+n), we iterate through the words of the sentence1 and sentence2 exactly once. The total sum of the length of the words is given by m and n for both sentences. Therefore, the total time complexity is given by O(m+n).
// S.C: O(m+n), we store the words of both sentences in an array. The total sum of the length of the words is given by m and n for both sentences. Therefore, the total space complexity is given by O(m+n).
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss1(s1), ss2(s2);     // Convert sentences to vector of words
        string word;
        vector<string> s1Words, s2Words;
        while(ss1 >> word) s1Words.push_back(word);
        while(ss2 >> word) s2Words.push_back(word);
        int n1 = s1Words.size(), n2 = s2Words.size();

        int start = 0, ends1 = n1-1, ends2 = n2-1;

        if(n1 > n2) return areSentencesSimilar(s2, s1);  // If words in s1 are more than s2, swap them and return the answer.

        while(start < n1 && s1Words[start] == s2Words[start]){   // Find the maximum words matching from the beginning.
            start++;
        }

        while(ends1 >= 0 && s1Words[ends1] == s2Words[ends2]){  // Find the maximum words matching in the end.
            ends1--;
            ends2--;
        }

        if(ends1 < start)  // If ends1 index is less than start, then sentence is similar.
            return true;
        return false;
    }
};