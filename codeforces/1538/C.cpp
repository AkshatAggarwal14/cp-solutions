    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <set>
     
    long long countPair(long long arr[], int size, long long a, long long b) {
        long long cnt = 0;
        long long i = 0, low = size-1, high = size-1;
        while (i < high) {
            //find the lower bound such that arr[i] + arr[low] < a, 
            //meanwhile arr[i]+arr[low+1] >= a
             low = std::max(i, low);
             while (low > i && arr[i] + arr[low] >= a) --low;
     
            //find an upper bound such that arr[i] + arr[high] <= b 
            //meanwhile, arr[i]+arr[high+1] > b
            while (high > low && arr[i] + arr[high] > b) --high; 
            //all pairs: arr[i]+arr[low+1], arr[i]+arr[low+2],...,arr[i]+arr[high]
            //are in the rage[a, b], and we count it as follows.
            cnt += (high-low);
            ++i;
        }
        return cnt;
    }
     
    int main(){
    	std::ios::sync_with_stdio(false);
    	std::cin.tie(NULL);
    	
    	int testcases;
    	std::cin >> testcases;
    	
    	for(int test=0; test<testcases; test++){
    		long long n;
    		long long l,r;
    		std::cin >> n >> l >> r;
     
    		long long a[n];
     
    		for (long long i = 0; i < n; ++i){
    			std::cin >> a[i];
    		}
    		// n = removeDuplicates(a,n);
    		std::sort(a,a+n);
    		long long answer = countPair(a,n,l,r);
     
    		std::cout << answer << "\n";
    		
    	}//testcases
    		
    	return 0;
    }//main
    // 1 2 3 4 5