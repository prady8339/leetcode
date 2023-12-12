class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for(int i = 0 ; i < arr.length ; i++){
           if(mp.containsKey(arr[i])){
               int prev = mp.get(arr[i]);
               mp.put(arr[i], prev + 1);
           }else{
               mp.put(arr[i], 0);
           }
        }
        Set<Integer> st = new HashSet<Integer> ();
        for(int freqs : mp.values()){
            if(st.contains(freqs)) return false;
            st.add(freqs);
        }
        return true;
    }
}