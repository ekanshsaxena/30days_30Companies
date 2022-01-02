//https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/#

class Solution {
  public:
    bool check(int l1,int r1,int l2,int r2){
        if(r1>l2 || r2>l1){
            return false;
        }else{
            return true;
        }
    }
    int doOverlap(int l1[], int r1[], int l2[], int r2[]) {
        if(r1[0]<l2[0] || r2[0]<l1[0]){
            return false;
        }else{
            return check(l1[1], r1[1], l2[1], r2[1]);
        }
    }
};
