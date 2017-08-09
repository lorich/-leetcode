class Solution {
    public:
        int findMinMoves(const vector<int>& machines) {
            int size = machines.size();
            if (size == 0) {
                return 0;
            }
            vector<int> sum(size + 1, 0);
            for (int i = 0; i < size; i++) {
                /*前面i个洗衣机拥有的衣服的总量*/
                sum[i+1] = machines[i] + sum[i];
            }
            if (sum[size] % size != 0) {
                return -1;
            }
            /*每个洗衣机应该拥有的衣服数量*/
            int avg = sum[size] / size;
            /*整个数组空间所需最少操作数*/
            int minMoves = 0;
            /*从左边向右边输送的衣服数*/
            int left_to_right = 0;
            /*从右边向左边输送的衣服数*/
            int right_to_left = 0;

            for (int i = 0; i < size; i++) {
                left_to_right = sum[i] - avg * i;
                right_to_left = sum[size] - avg * (size - i - 1) - sum[i+1];
                /*两边都需要从第i位置获取衣服，不可并行*/
                if (left_to_right < 0 && right_to_left < 0) {
                    minMoves = max(minMoves, -left_to_right - right_to_left);
                } 
                /*其他，可并行*/
                else {
                    minMoves = max(minMoves, max(abs(left_to_right), abs(right_to_left)));
                }
            }
            return minMoves;
        }
};
