/*笨办法，又臭又长，没有使用map     Runtime：12ms
**提交了8次才AC  -_-||
**1、对数字排序
**2、对每个数字i，find = sum - i
**3、再通过二分法查找
**4、得到符合条件的两个数后，在原始vector nums中查找他们的index，对index排序
**5、返回result
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1 = 0, index2;
	    bool flag = true;
	    vector<int> tmp(nums);
	    vector<int> result;//result
    	sort(tmp.begin(),tmp.end());
    	for (; index1 < tmp.size() && flag; index1++)
    	{
	    	int find = target - tmp[index1];
	    	int low = index1 + 1;
	    	int high = tmp.size() - 1;
	    	int mid = (low + high) / 2;
	    	while (flag && low <= high)
	    	{
		    	if (tmp[mid] == find)
		    	{
			    	flag = false;
		   	    	index2 = mid;
	    		}
		    	else if (find > tmp[mid])
			    {
			    	low = mid + 1;
				    mid = (low + high) / 2;
			    }
		    	else
		    	{
			    	high = mid - 1;
		    		mid = (low + high) / 2;
		    	}
	    	}
    	}
    	
    	if(!flag)
    	{
    	    for(int i = 0; i < nums.size(); i++)
    	    {
    	        if(tmp[index1-1] == nums[i])
    	        {
    	             result.push_back(i);
    	             break;
    	        }
    	    }
    	    for(int i = 0; i < nums.size(); i++)
        	{
    	        if(tmp[index2] == nums[i] && i != result[0])
    	        {
    	            result.push_back(i);
    	             break;
    	        }
        	}
        	sort(result.begin(), result.end());
    	}
    	return result;
    }
};