struct EraseHeap{//两个堆维护可删堆
    priority_queue<int>a,b;//a存所有状态,b存无用状态
    void push(int x){
        a.push(x);
    }
    void erase(int x){
        b.push(x);
    }
    void pop(){
        while(!b.empty()&&a.top()==b.top())
            a.pop(),b.pop();
        a.pop();
    }
    int top(){//最大
        while(!b.empty()&&a.top()==b.top())
            a.pop(),b.pop();
        return a.empty()?0:a.top();
    }
    int size(){
        return a.size()-b.size();
    }   
    int stop(){//次大
        if(size()<2)return 0;
        int x=top();pop();
        int y=top();push(x);
        return y;
    }
};