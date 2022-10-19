//NGE I
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums2.size(); i++){
            mp[nums2[i]] = i;
        }
        stack<int> st;
        vector<int> v(nums2.size());
        v[nums2.size()-1] = -1;
        st.push(nums2[nums2.size()-1]);
        for(int i=nums2.size()-2; i>=0; i--){
            if(nums2[i]<st.top()){
                v[i] = st.top();
            }else{
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    v[i] = -1;
                }else{
                    v[i] = st.top();
                }
            }
            st.push(nums2[i]);
        }
        vector<int> res(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            int ind = mp[nums1[i]];
            int ans = v[ind];
            res[i] = ans;
        }
        return res;
        
    }

//NGE II
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        for(int i=2*n-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                    res[i] = st.top();
                }else{
                    res[i] = -1;
                }
            }
            st.push(nums[i%n]);
        }
        return res;
    }