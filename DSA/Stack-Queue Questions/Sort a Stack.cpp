void sortStack(stack<int> &stack)
{
	
    if(stack.size()==1) return;
    int temp = stack.top();
    stack.pop();
    
    sortStack(stack);
    vector<int> v;
    while(!stack.empty() && stack.top()>temp){
        v.push_back(stack.top());
        stack.pop();
    }
    stack.push(temp);
    for(int i=v.size()-1; i>=0; i--){
        stack.push(v[i]);
    }
    v.clear();
}

// insert also recursive
void insertInSorted(int x, stack<int> &st){
    if(st.empty() || st.top()<=x){
        st.push(x);
        return;
    }
    int t = st.top();
    st.pop();
    insertInSorted(x, st);
    st.push(t);
}
void sortStack(stack<int> &st)
{
	// Write your code here
    if(st.size()==1){
        return;
    }
    int x = st.top();
    st.pop();
    sortStack(st);
    insertInSorted(x, st);
}