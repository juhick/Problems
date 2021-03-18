class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length == 0) {
            return null;
        }

        int[][] res = new int[intervals.length][2];
        Arrays.sort(intervals, (a, b) -> {
            return a[0] - b[0];
        });

        res[0] = intervals[0];
        int now = 0;

        for(int i = 1; i < intervals.length; ++i){
            int[] curr = intervals[i];
            int[] last = res[now];
            if(curr[0] <= last[1]){
                last[1] = Math.max(last[1], curr[1]);
            }else{
                res[++now] = curr;
            }
        }

        int[][] temp = new int[now + 1][2];
        for(int i = 0; i <= now; ++i){
            temp[i] = res[i];
        }

        return temp;
    }
}