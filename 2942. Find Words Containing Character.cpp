class Solution {
public:
    bool search(string word,char x){
        for(int i=0;i<word.size();i++){
            if(x==word[i]) return true;
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {

        vector<int> ans;
        for(int i=0;i<words.size();i++){
            string temp=words[i];
            if(search(temp,x)==true) ans.push_back(i);
        }
        return ans;
    }
};
