#include <iostream>
using namespace std;
int* twoSum(int* nums, int numsSize, int target);
void quick_sort(int *num, int *index, int low, int high);
int BinarySearch(int numbers[], int target, int low, int high);
const int number_length = 3;
const int target_num = 6;
int main()
{
	int  index[2] = {0};
	int numbers[number_length] = { 3,2,4};
	int numbers2[number_length] = { 3, 2, 4 };
	index[0] = *twoSum(numbers, number_length, target_num);
	
	index[1] = *(twoSum(numbers2, number_length, target_num) + 1);

	cout << index[0] << endl;
	cout << index[1] << endl;
	return 0;
}
//快速排序
void quick_sort(int *num, int *num_index, int low, int high)
{
	if (high > low)
	{
		int i = low, j = high, x = num[low], index_num = num_index[low];
		while (i < j)
		{
			while (i < j && num[j] >= x) j--;// 从右向左找第一个小于x的数
			if (i < j){
				num[i] = num[j];
				num_index[i] = num_index[j];
				i++;
			}
			while (i < j && num[i] < x) i++;// 从左向右找第一个大于等于x的数
			if (i < j)	{
				num[j] = num[i];
				num_index[j] = num_index[i];
				j--;
			}
		}
		num[i] = x;
		num_index[i] = index_num;
		quick_sort(num, num_index, low, i - 1); // 递归调用 
		quick_sort(num, num_index, i + 1, high);
	}
}
int BinarySearch(int numbers[], int target, int low, int high)
{
	if (low > high)
		return -1;
	int mid = low + (high - low) / 2;
	if (target < numbers[mid])
		return BinarySearch(numbers, target, low, mid - 1);
	else if (target > numbers[mid])
		return BinarySearch(numbers, target, mid + 1, high);
	else
		return mid;
}
int* twoSum(int* nums, int numsSize, int target) {
	int *nums_index = (int *)malloc(numsSize* sizeof(int));
	int *target_index = (int *)malloc(2*sizeof(int));
	int get_target = 0;
	int result = 0;
	int i, j;
	for (i = 0; i < numsSize; i++)
	{
		nums_index[i] = i + 1;
	}
	quick_sort(nums, nums_index, 0, numsSize - 1);
	for (i = 0; i < numsSize; i++)
	{
		get_target = target - nums[i];
		j = i + 1;
		result = BinarySearch(nums, get_target, j, numsSize - 1);
		if (result != -1){
			target_index[0] = nums_index[i];
			target_index[1] = nums_index[result];
			return target_index;
		}
	}
	return NULL;
}