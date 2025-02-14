class ProductOfNumbers {
    List<Integer> pre = new ArrayList<>();
    public ProductOfNumbers() {
        pre.add(1);
    }
    
    public void add(int num) {
        if(num == 0){
            pre.clear();
            pre.add(1);
        } else {
            int size = pre.size();
            pre.add(pre.get(size - 1) * num);
        }
    }
    
    public int getProduct(int k) {
        int size = pre.size();
        if(k >= size){
            return 0;
        } else {
            return pre.get(size - 1) / pre.get(size - k - 1);
        }
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */