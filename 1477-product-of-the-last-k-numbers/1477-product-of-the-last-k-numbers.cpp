class ProductOfNumbers {
    vector<int>v;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        if(k>v.size())
            return -1;
        int p=1;
        int n=v.size();
        for(int i=0;i<k;i++)
        {
            p*=v[n-i-1];
        }
        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */