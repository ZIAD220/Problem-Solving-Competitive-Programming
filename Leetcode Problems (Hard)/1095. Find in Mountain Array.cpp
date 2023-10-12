/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 1, r = mountainArr.length() - 2;
        int peak;
        while(l <= r){
            int mid = l + (r - l) / 2;

            int before = mountainArr.get(mid - 1);
            int current = mountainArr.get(mid);
            int after = mountainArr.get(mid + 1);

            if (current > before && current > after){
                peak = mid;
                break;
            }
            else if (current > before && current < after){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        l = 0, r = peak;
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int current = mountainArr.get(mid);
            
            if (current > target){
                r = mid - 1;
            }
            else if (current < target){
                l = mid + 1;
            }
            else{
                ans = mid;
                break;
            }
        }

        if (ans != -1)
            return ans;
        
        l = peak + 1, r = mountainArr.length() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int current = mountainArr.get(mid);
            
            if (current > target){
                l = mid + 1;
            }
            else if (current < target){
                r = mid - 1;
            }
            else{
                ans = mid;
                break;
            }
        }

        return ans;
    }
};