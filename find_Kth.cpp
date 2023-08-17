#include <iostream>
#include <vector>
using namespace std;

class Solution {

  public:
    void print(vector<int>& nums) {
      for (int n : nums) {
        cout << n << " ";
      }
      cout << endl;
    }
    int findKthLargest(vector<int>& nums, int k) {
      int pos = nums.size() - k;
      int left = 0;
      int right = nums.size() - 1;
      int pivot = 0;
      do {
        pivot = partition(nums, left, right);
        if (pivot == pos) {
          break;
        }
        if (pivot > pos) {
          right = pivot - 1;
        } else {
          left = pivot + 1;
        }
      } while(true);
      return nums[pivot];
    }

    int partition(vector<int>& nums, int left, int right) {
      while (left < right) {
        while(nums[left] < nums[right]) right--;
        if (left < right) {
          swap(nums[left], nums[right]);
          left++;
        }
        while(nums[left] < nums[right]) left++;
        if (left < right) {
          swap(nums[left], nums[right]);
          right--;
        }
      }
      return left;
    }

    void swap(int& a, int& b){
      int tmp = a;
      a = b;
      b = tmp;
    }
};

int main() {
  vector<int> nums = {2, 1};
  Solution s;
  int n = s.findKthLargest(nums, 2);
  cout << n << endl;
}
