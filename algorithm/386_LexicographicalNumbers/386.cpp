/*
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. 
The input size may be as large as 5,000,000.

*/

//dfs 
void helper(int cur, int n, vector<int>& res) {
    if (cur > n)
        return;
    for(int i=1; i<=9; i++) {
        if (cur + i < n) {
            res.push_back(cur+i);
            helper(cur*10, n, res);
    }
}

vector<int> lexicalOrder(int n) {
    // 
    // The Most Significant num(MSG) 
    //1, 10, 100, 101, 102, 103, ..., 109
    //   11, 110, 111, 112, 113, ..., 119
    //...
    //   19  190, 191, ... , 199
    //  

    //2, 20, 200, 201, ... , 209
    //   21, 210, 211, ... , 219
    //       220, 221, ... , 229
    //..
    //   29, 290, 291, ... , 299

    vector<int> res;
    for(int i=1; i<=9; i++) {
        helper(i, n, res);
    }
}


vector<int> lexicalOrder_iterative(int n) {
    vector<int> res(n);
    int cur = 1;
    for(i=0; i<n; i++) {
        res[i] = cur;
        if (cur*10 < n) {
            cur = cur*10;
        } else {
            if (cur >= n) cur = cur/10;
            cur = cur+1;
            while( cur % 10 == 0) cur = cur/10;
        }
    }
}

int main() {

}




