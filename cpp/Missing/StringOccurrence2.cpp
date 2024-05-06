//https://www.tutorialcup.com/interview/stack/pattern-occurrences-using-stack.htm

#include<bits/stdc++.h> 
using namespace std; 
 
void PatternOccurence(char pattern[], char text[], int ps, int ts){ 
        vector<int> list; 
        stack<string> st; 
        int p = 0; 
        int counter = 0 ; 
        int lastOccurrence = -10; 
        for(int i = 0; i < ts; i ++){ 
            if(text[i] == pattern[p]){ 
                if(text[i] == pattern[ps - 1]){ 
                    list.push_back(i); 
                    counter ++; 
                    lastOccurrence = i; 
                    p = 0; 
                } 
                else{ 
                    p ++; 
                } 
            } 
            else{ 
                if(text[i] == pattern[0]){ 
                    string temp = ""; 
                    for (int i1 = p; i1 < ps; i1 ++){ 
                        temp += pattern[i1]; 
                    }
                    st.push(temp); 
                    p = 1; 
                } 
                else{ 
                    if(lastOccurrence == i - 1){        
                        if(st.empty()){ 
                            p = 0; 
                        }                        
                        else{ 
                            string temp = st.top();
                            st.pop(); 
                
                            if(temp[0] == text[i]){ 
                                lastOccurrence = i; 
                
                                if(temp[0] == pattern[ps - 1]){ 
                                    list.push_back(i); 
                                    counter ++; 
                                }                                 
                                else{ 
                                    temp = temp.substr(1, temp.length()); 
                                    st.push(temp); 
                                } 
                            } 
                            else{ 
                                if(!st.empty()) 
                                    while(!st.empty()){
                                        st.pop();
                                    } 
                                    p = 0; 
                                } 
                            } 
                        } 
                        
                    else{ 
                        if (!st.empty()){ 
                            while(!st.empty()){
                                st.pop();
                            }  
                        }
                        p = 0; 
                    } 
                } 
            } 
        } 
        cout<<counter<<endl;
        if(counter>0){
            cout<<"Occurrences found at:"<<endl;
            for(auto i = list.begin(); i != list.end(); ++i){ 
                cout << *i << " "; 
            }
        }
    }   
int main(){ 
    char pattern[] = {'A','B','C'}; 
    char text[] = {'A','B','A','B','C','A','B','C','C'}; 
    int ps = sizeof(pattern)/sizeof(pattern[0]);
    int ts = sizeof(text)/sizeof(text[0]);
    PatternOccurence(pattern, text, ps, ts);
    return 0; 
}

/*  https://www.tutorialcup.com/interview/hashing/maximum-occurring-character.htm
Problem Statement :

Maximum Number of Occurrences of a Substring Leetcode Solution – Given a string s, return the maximum number of occurrences of any substring under the following rules:

    The number of unique characters in the substring must be less than or equal to maxLetters.
    The substring size must be between minSize and maxSize inclusive.

Example :
Example 1
Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
Example 2
Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
*/
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
         int n=s.size();
        // To store  frequency of characters in string s
        unordered_map<char,int>freqMap;
        // To store  Substring of string s with given constraint of size minSize
        unordered_map<string,int>ansFreqMap;
        //tells us about unique characters in string s
        int countOfUniqueChar=0;
        int ans=0;
        // i -> for acquiring
        int i=0;
         //j->for relasing
        int j=-1;
        // acquire till less than minsize-1
      for(;i<minSize-1;i++){
          char ch=s[i];
          freqMap[ch]++;
      }
        i--;
        //now make the minSize window by acquring and relasing
        while(i<n-1){
            i++;
               char ch=s[i];
          freqMap[ch]++;
            countOfUniqueChar=freqMap.size();
            if(countOfUniqueChar<=maxLetters){
               string sub= s.substr(j+1,i-j);
                ansFreqMap[sub]++;
            }
            j++;
              ch=s[j];
             freqMap[ch]--;
            if(freqMap[ch]==0)freqMap.erase(ch);
            
        }
        
        for(auto key:ansFreqMap){
            int freqVal=key.second;
            ans=max(ans,freqVal);
            //cout<<key.first<<" "<<key.second<<endl;
        }
        //cout<<ansFreqMap.size()<<endl;
        return ans;
        
    }
};