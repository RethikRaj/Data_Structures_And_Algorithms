class Solution {
public:
    bool bruteForce(int num){
        if(num == 1){
            return true;
        }

        for(int i=1;i <= num/2 ;i++){
            double square = (double)i * i;
            if(square == num){
                return true;
            }
        }
        return false;
    }

    bool smarterBruteForce(int num) {
        if (num == 1) {
            return true;
        }

        for (long long int i = 1; i * i <= num; i++) {
            if (i * i == num) {
                return true;
            }
        }
        return false;
    }


    bool optimizedBinarySearch(int num){
        long long int low = 0;
        long long int high = num;

        while(low <= high){
            long long int mid = low + (high - low)/2;
            long long int isMidAns = (mid * mid);
            if(isMidAns == num){
                return true;
            }else if(isMidAns < num){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return false;
    }

    bool isPerfectSquare(int num) {
        // return bruteForce(num);

        return smarterBruteForce(num);

        // return optimizedBinarySearch(num);
    }
};