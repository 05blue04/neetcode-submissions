class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) { 
        if(small.empty() && big.empty()){
            small.push(num);
            return;
        }


        if(!big.empty() && num > big.top()){
            big.push(num);
        } else{
            small.push(num);
        }

        if(small.size() > big.size() + 1){
            big.push(small.top());
            small.pop();
        }

        if(big.size() > small.size() + 1){
            small.push(big.top());
            big.pop();
        }

    }
    
    double findMedian() {
        if(small.size() == big.size()){ //even case
            double l = small.top();
            double r = big.top();
            return (l + r ) / 2;
        }

        if(small.size() > big.size()){
            return small.top();
        }
        return big.top();
    }
private:
    priority_queue<int, vector<int>> small;
    priority_queue<int, vector<int>, greater<int>> big;
};
