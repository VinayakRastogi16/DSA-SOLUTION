#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height){
    int n = height.size();
    int i = 0, j = n-1;
    int maxArea = 0;
    while (i<j)
    {  
        int gaps = j-i;
        int area = min(height[i], height[j])*gaps;
        maxArea = max(area, maxArea);
        if (height[i]<height[j])
        {
            i++;
        }else{
            j--;
        }
        
    }
    
    return maxArea;
    
    
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout<<maxArea(height)<<endl;
    return 0;
}