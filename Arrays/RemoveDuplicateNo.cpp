// Aproach 1- Using LinkedList Cycle method
#include<vector>
#include<algorithm>
class Solution{
    public:
    int findDuplicate(vector<int> & nums){
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// Aproach 2- Using Sorting
int findDuplicates(vector<int> & arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0;i<n-1;i++){
        if (arr[i]==arr[i+1]){
            return arr[i];
        }
    }
}

//Aproach 3- Using Frequency array
int findDuplicates(vector<int> & arr){
    int n = arr.size();
    int freq[n+1] = {
        0
    };
    for(int i=0;i<n;i++){
        if(freq[arr[i]]==0){
            freq[arr[i]]+=1;
        } else{
            return arr[i];
        }
    }
    return 0;
}