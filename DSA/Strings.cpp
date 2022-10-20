1. Valid palindrome //[ Given String have upper,lower,numeric]

class Solution 
{
private:
       bool isValid(char ch)
       {
           if((ch>='a' and ch<='z') || (ch>='A' and ch<='Z')||(ch>='0' and ch<='9'))
                  return 1;
            else  return 0;
       }
        
       void toLowerCase(char &ch)
       {
          if((ch>='a' and ch<='z') || (ch>='0' and ch<='9'));
           else ch= ch-'A'+'a';
       }

public:
    bool palindrome(string val)
    {
       int s=0,e=val.size()-1;
        while(s<=e)
        {
            if(val[s++]==val[e--])
                 continue;
            else return 0;
        }
         
        return 1;
    }
    
    bool isPalindrome(string s)  // Driver Function 
    {
        string val;
        for(int i =0; i<s.length() ;i++)
             if(isValid(s[i]))
                 val.push_back(s[i]);
        
        for(int i=0; i<val.length(); i++)
            toLowerCase(val[i]);
        
        return palindrome(val);
    }
};

2. Reverse Words in a String 
   Input: s = "Let's take LeetCode contest"
   Output: "s'teL ekat edoCteeL tsetnoc"

string reverseWords(string s)
    {
        int st=0,i=0,e,n=s.size();
       while(i<n)
       {
           while(i<n and s[i]!=' ') i++;
               e = i -1;
           while(st<=e)
             swap(s[st++],s[e--]);
           
           st = ++i;
       }
        return s;
    }

3.First Unique (Non-Repeating)Character in a String

char FirstUniqueCharacter(string s)
    {
        int arr[26] = {0},n= s.size();
        for(int i=0; i<n; i++)
             arr[s[i]-'a']++;
        
        for(int i=0; i<n ;i++)
            if(arr[s[i]-'a']==1)
                return s[i];
        return '$';
    }

4.Find first repeated character 
 whose index of second occurrence is smallest
   Input: S="geeksforgeeks"
   Output: e  //Explanation: 'e' repeats at third position

string firstRepChar(string s)
{
    int arr[26]={0},n= s.size();
    for(int i=0; i<n; i++)
     {
        // as we found freq of 2 it is the smallest index
       if(++arr[s[i]-'a']==2) 
         return s=s[i]; 
     }
     return "-1";
}

5. Longest Common Prefix  in given Array of Strings
   //   Input:  ["flower","fkow"]    Output:"f"
  string longestCommonPrefix(vector<string>& strs)
    {
        string s=strs[0];
        int n,N=strs.size(),flag;
        for(int i=1 ;i<N ;i++)
        {      
            n = s.size(),flag=1;
            for(int j=0; j<n; j++)
            {
                if(flag and s[j]==strs[i][j]);
                else
                {
                    flag=0; // once not match pop all
                    s.pop_back();
                }
            }
        }
        return s;
    }

6.Reverse the first k characters for every 2k characters
 string reverseStr(string s, int k) 
    {
        int st=0,l=k-1,i=0,n=s.size();
         if(n<k) l=n-1; //fewer than k  elements present
          while(i<n)
        {
            while(st<=l)
                swap(s[st++],s[l--]);
               
              i = i+2*k; 
            st=i; l= i+k-1 ;
              if(l>=n) l=n-1; //fewer than k elements left
        }
        return s;
    }

7. Distinct Substring of size 2 that is contiguous in S:
   int fun(string s)
{
    set<string> strln2;
     for(int i=0;i<s.size()-1; i++)
     {
         string temp;
          temp.push_back(s[i]);
          temp.push_back(s[i+1]);
          strln2.insert(temp);
     }
       return strln2.size();
}

8. Remove all duplicates from a given string
   // Input: Str = HappyNewYear
   // Output: HapyNewYr
        string removeDuplicates(string str) 
    {
        int a[26]={0},A[26]={0};
        for(int i=0; i<str.size(); i++)
           {
               if(isupper(str[i]))
                  A[(int)str[i]-65]++;
                else
                  a[(int)str[i]-97]++;
           }
        string s;
        for(int i=0 ; i<str.size(); i++)
        {
            if(islower(str[i]) and a[(int)str[i]-97]>0)
            {
                s.push_back(str[i]);
                  a[(int)str[i]-97]=0;
            }
            
            else if(isupper(str[i]) and A[(int)str[i]-65]>0)
            {
                 s.push_back(str[i]);
                  A[(int)str[i]-65]=0;
            }
        }
        return s;
    }

9. Second most repeated string in a sequence
 //Input:arr[] = {aaa, bbb, ccc, bbb, aaa, aaa} 
         // Output: bbb
   string secFrequent (string arr[], int n)
    {
        int max=0,smax=0;
        string ans;
        unordered_map<string, int> mp;
        for(int i=0 ; i<n ; i++)
         {
            mp[arr[i]]++;  // storing frequency in map
            
            if(mp[arr[i]]> max)   //finding max
                 max=mp[arr[i]];
         }
        
         for (auto const &pair: mp)
           {    // finding second max
             if(pair.second!=max and pair.second> smax)
             {
               smax=pair.second;
               ans = pair.first;  // store string at ans
             }
           }
        return ans;
    }

10. Minimum Swaps for Bracket Balancing 
  // Input  : ]]][[[    Output : 6
  
  int minimumNumberOfSwaps(string s)
    { 
        //Try thinking when  number of Closing 
        // bracket is greater than opening bracket
        int open=0,close=0,ct,n=s.size();
        for(int i=0; i<n ;i++)
        {
           if(s[i]=='[') open++;
           else 
            {
                close++;
                if(close>open)
                   ct += close-open;
            }
        }
        return ct;
    }

11. Reverse Vowels of a String  
Input: s = "leetcode"   Output: "leotcede"
class Solution 
{
public:
    int vovel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return 1;
        else return 0;
    }
    string reverseVowels(string s) 
    {
           int i=0,j=s.size()-1; 
              while(i<j)
        {
            if(vovel (s[i]));
            else i++;
            if(vovel(s[j])) ;
            else j--;
            if(vovel(s[i])&&vovel(s[j]))
                swap(s[i++],s[j--]);  
        }
        return s;
    }
};

12(a). Longest Substring  Distinct (Without Repeating) Characters
       // Brute Force - O(n*n)  space - O(1)
      //   ASCII of ' '  is  32   range- (32  - 127)
     // take hash array size of 96 when all char(a,A,1,$) present
    int lengthOfLongestSubstring(string s) 
    {
         int maxlen=0,n = s.size();
    for(int i =0; i<n ; i++)
     {
         int mx=0,arr[96]={0};
         for(int j= i; j<n ; j++)
         {
             if(arr[s[j]-' ']==0)
              {
                 mx++;
                 arr[s[j]-' ']++;
                 maxlen = max(mx,maxlen);
              }
              else  break;
         }
     }
     return maxlen;
    }

12.(b). Optimal Approach - O(n) - Sliding Window
        Sliding Window  Question 4

13. Isomorphic Strings - One to One Mapping from Both Side

    bool areIsomorphic(string str1, string str2)
    {
          int n=str1.size(),k=str2.size();
         if(n!=k) return false;

         int hash[256]= {0};
         for(int i=0; i<n ; i++)
          {
              if(!hash[str1[i]])
                  hash[str1[i]] = int(str2[i]) ;
              else if(hash[str1[i]]!=str2[i])
                      return false;
          }
         
          memset(hash,0,sizeof(hash));
          // can only set value 0 and -1
          for(int i=0; i<n ; i++)
          {
              if(!hash[str2[i]])
                  hash[str2[i]] = int(str1[i]) ;
              else if(hash[str2[i]]!=str1[i])
                      return false;
          }
        return true;
    }

14(a).  String Matching - Brurte Force in JAVA --strStr
    class Solution{
    public int strStr(String haystack, String needle) 
    {
         if(needle.equals("")) return 0;
       int p = haystack.length(),q=needle.length(),ans=-1;
      for(int i=0; i<p ;i++)
      {
           for(int j=0; j<q; j++)
           {
               try
               {
                   if( i haystack.charAt(i+j)==needle.charAt(j) )
                   ans=i;
                   else 
                    {  ans =-1; break; }
               }
               catch(Exception e)
               {
                // S.O.P("index out of the bounds");
                   return -1;
               }      
           }
          if(ans>=0) break;
      }
         return ans;
    }
}        
  ->      // USING JAVA FUNCTION indexOf
             return  string.indexOf(str);
          
14.(b)  String Matching Using Functions- C++;
        // S = "Hello" ; s= "ll"
       int strStr(string S, string s,int x=0)
        {    
            return x = S.find(s); 
            // x is  first index of matched string
            // return  -1 if not found;
            // if not found x==string::npos
        }
      // usING C++ strstr function 
       // http:www.cplusplus.com/reference/cstring/strstr/

14.(c) Python Functions - for String Matching
        //   Only Bool Value
      return if(Str in String)
      // return index of first occurence 
       return haystack.find(needle); 
       // return -1 if not found 

15.  Simplyfy PATH - LEETCODE  71
  // Input: path = "/home//foo/"     Output: "/home/foo" 
    string simplifyPath(string path) 
    {
        string s;
        stringstream ss (path); 
         vector<string> ans;
        while(getline(ss,s,'/'))
        {
            if(!ans.empty() and s=="..")  ans.pop_back();
            else if(s==".")    continue;
            else if(s!=".." and s!="")  ans.push_back(s);
        }

        s="";
        for(auto i : ans)
        {
            s = s + "/" + i;
        }
        if(s.empty()) s ="/";
        return s;
     }

16. Valid I.P. Address in IPv4 connection 
    //  leading zeroes are'nt allowed except zero
   // Test case ->   222.111.111.111. 
     int isValid(string s)
        {
            int ct=0,k,i;
            string str;
        // coverting in stringstream so t treat as input 
            stringstream ss(s); 
            // '.' is seprater  str get value b/w two dots
            while(getline(ss,str,'.'))
            {
                ct++;i=0;
                while(str[i]!='\0')
                {  // alpha is not  convertible in  integer 
                    if(isalpha(str[i++]))
                    return false;
                }
                  // ip can not large than  3 digit
                if(str.size()==0 or str.size()>3) return 0;
                
                //  coverting string in integer using fun  
                  k = stoi(str) ;
               
               // if String  is still greater than  256   
                 if(k>=0 and k<256);
                    else return false;
                
              // if leading zero found ensure that it is only zero 
                //   by using size of String if size!=1 it is not allowed
                 if(str[0]=='0' and str.size()!=1) 
                     return false;
            }
            // ensure that only 4 intger in b/w dots
            // string must not contain only dots 
          if(str!="" and ct==4) return 1;
          else return 0;
        }

17. Valid palindrome II - (is Sting is palindrome after removing at most one char)
    class Solution {
 private:
      bool ispalindrome (string &str, int i, int j)
      {
          while(i<j)
          {
              if(str[i++]==str[j--]);
              else return false;
          }
          return true;
      }
    
public:
    bool validPalindrome(string &str) 
    {
       for(int i=0,j=str.size()-1; i<j; i++,j--)
       {
           if(str[i]!=str[j])
               return  (ispalindrome(str,i,j-1) || ispalindrome(str,i+1,j));
       }
        return true ;
    }
};

18. Sort Characters By Decresing  Frequency - priority Queue
     // use of priority queeue 
     string frequencySort(string nums) 
    {
          int n = nums.size();
        unordered_map<char ,int> hash;
        priority_queue<pair<int,char>> pq;
        string ans;
        for(int i=0 ;i<n ; i++)
            hash[nums[i]]++;
        
        for(auto val: hash)
            pq.push({val.second,val.first}) ;
        
        while(!pq.empty())
        {
            int n = pq.top().first;
            while(n--)
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

 18.(b) string frequencySort(string nums) 
    {
        int n = nums.size();
        unordered_map<char ,int> hash;
        string ans;
        for(int i=0 ;i<n ; i++)
            hash[nums[i]]++;
        sort(nums.begin(),nums.end(),[&hash](int a ,int b) 
              { return  hash[a]==hash[b]? a>b : hash[a]>hash[b] ;} );    
        return nums;
    }

20. Remove All Adjacent Duplicates in String- if K adjacent are same 
    
   string removeDuplicates(string s, int k) 
    {
        int n = s.size();
        stack<pair<char,int>> st ;
        for(int i=0; i<n ;i++)
        {
            if(!st.empty() and s[i]==st.top().first)
                st.push({s[i],st.top().second+1}) ;
            
            else st.push({s[i],1}) ;
            
            if(st.top().second==k)
            {
                int temp = k ;
                while(temp--) st.pop();
            }
        }
           s  = "";
        while(!st.empty())
        {
            s.push_back(st.top().first);
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s ;
    }

21. Minimum Deletions to Make Character Frequencies Unique - LEETCODE
class Solution { 
public:
    int minDeletions(string s) 
    {
        int n = s.size(),hash[26]={0},ans=0;
        unordered_set<int> freq ;
        
        for(int i=0; i<n ; i++)
        {
            hash[s[i]-'a']++;   // storing freq
        }
        
        sort(hash,hash+26,greater<int>()); // sorting
        
        for(int i=0 ; i<26; i++)
        {
            if(hash[i]==0) continue;
            int k = hash[i] ;
            while(freq.count(k) and k>0) // if freq is not unique
            {
                k-- ; ans++ ;
            }
            if(!freq.count(k))
                freq.insert(k) ; // if unique store it
        }
        return ans;
    }
};

22.  Number of Matching Subsequences - Leetcode 
  // Input: s = "abcde", words = ["a","bb","acd","ace"]  Output: 3
 int numMatchingSubseq (string s, vector<string>& words) 
    {
        int n = words.size(),l=s.size(),ans=0;
        unordered_map<string,int> hash ;
        
        for(int i=0; i<n ; i++)
            hash[words[i]]++ ;  
        
        for(auto it : hash)
        {
            string str = it.first;
            int k=0,x=str.size();
            for(int j=0; k<x and j<l; j++)
            {
                if(str[k]==s[j])
                    k++;
            }
            if(k==x)
                ans += it.second ;
        }
        return ans ;
    }

