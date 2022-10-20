// T/C: O(nlogn), S/C: O(n)
static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end(), cmp);
        int res=1, en = v[0].second;
        for(int i=1; i<n; i++){
            if(v[i].first>en){
                res++;
                en = v[i].second;
            }
        }
        return res;
    }