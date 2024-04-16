class RandomizedSet {

    private Random random;
    private ArrayList<Integer> array;
    private HashMap<Integer, Integer> map;
    public RandomizedSet() {
        random = new Random();
        array = new ArrayList<Integer>();
        map = new HashMap<Integer, Integer>();
    }
    
    public boolean insert(int val) {
        if(map.containsKey(val)){
            return false;
        } else{
            // insert
            array.add(val); // add at the end
            map.put(val, array.size()-1); // points to the end
            return true;
        }
    }
    
    public boolean remove(int val) {
        if(map.containsKey(val)){
            int index = map.get(val);
            array.set(index, array.get(array.size() - 1)); // set last element to that position
            map.put(array.get(index), index); // update index for that element

            map.remove(val);
            array.remove(array.size() - 1);
            return true;
        }else{
            return false;
        }
    }
    
    public int getRandom() {
        // nextInt(n) is exclusive n. So [0,n)
        return array.get(random.nextInt(array.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
