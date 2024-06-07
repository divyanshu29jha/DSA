// M-1 (Two Pointer Approach)  ---> Intersection will not contain duplicates

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums1 = {1,2,2,3,3,4,5,6};
    vector<int> nums2 = {2,3,3,5,6,6,7};
    
    vector<int> ans;    // intersection of nums1 and nums2
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();
    
    while(i < n && j < m){
        if(nums1[i] < nums2[j])
            i++;
        else if(nums1[i] == nums2[j]){
            if(ans.size() == 0 || ans.back() != nums1[i]){
                ans.push_back(nums1[i]);
            }
            i++;
        }
        else
            j++;
    }
    
    for(auto i : ans){
        cout<< i << " ";
    }

    return 0;
}

-----------------------------------------------------------------------------
// M-2 (Two Pointer Approach)   ---> Intersection can contain duplicates


#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums1 = {1,2,2,3,3,4,5,6};
    vector<int> nums2 = {2,3,3,5,6,6,7};
    
    vector<int> ans;    // intersection of nums1 and nums2
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();
    
    while(i < n && j < m){
        if(nums1[i] < nums2[j])
            i++;
        else if(nums1[i] > nums2[j])
            j++;
        else{
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    
    for(auto i : ans){
        cout<< i << " ";
    }

    return 0;
}

---------------------------------------------------



























