int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back({end[i], start[i]});
        }
        sort(v.begin(), v.end());
        int end_limit = v[0].first, res=1;
        for(int i=1; i<n; i++){
            if(v[i].second>end_limit){
                res++;
                end_limit = v[i].first;
            }
        }
        return res;
    }