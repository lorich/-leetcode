// 164. Maximum Gap
// https://leetcode.com/problems/maximum-gap/
// 

/*
Suppose there are N elements and they range from A to B.
Then the maximum gap will be no smaller than ceiling[(B - A) / (N - 1)]
Let the length of a bucket to be len = ceiling[(B - A) / (N - 1)], then we will have at most num = (B - A) / len + 1 of bucket
for any number K in the array, we can easily find out which bucket it belongs by calculating loc = (K - A) / len and therefore maintain the maximum and minimum elements in each bucket.
Since the maximum difference between elements in the same buckets will be at most len - 1, so the final answer will not be taken from two elements in the same buckets.
For each non-empty buckets p, find the next non-empty buckets q, then q.min - p.max could be the potential answer to the question. Return the maximum of all those values.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findMaxMin(int num[], int n, int* iMax, int* iMin)
{
  *iMax = *iMin = num[0];
  int i;
  for (i = 1; i < n; ++i)
  {
    if (num[i] > *iMax)
    {
      *iMax = num[i];
    }
    if (num[i] < *iMin)
    {
      *iMin = num[i];
    }
  }
}

int maximumGap(int num[], int n) 
{
  if (n < 2)
  {
    return 0;
  }
  int iMax = 0, iMin = 0;
  findMaxMin(num, n, &iMax, &iMin);
  if (iMax == iMin)
  {
    return 0;
  }
  const int iBucketLen = (0 == (iMax-iMin)%(n-1)) ? (iMax-iMin)/(n-1) : (iMax-iMin)/(n-1)+1;
  const int iBucketNum = (iMax - iMin)/iBucketLen + 1;
  int ** bucket = (int**)malloc(iBucketNum*sizeof(int*));
  int i;
  for (i = 0; i < iBucketNum; ++i)
  {
    bucket[i] = (int*)malloc(2*sizeof(int));
    bucket[i][0] = bucket[i][1] = -1;
  }
  int iLoc;
  for (i = 0; i < n; ++i)
  {
    iLoc = (num[i]-iMin)/iBucketLen;
    if (-1 == bucket[iLoc][0] || num[i] < bucket[iLoc][0])
    {
      bucket[iLoc][0] = num[i];
    }
    if (-1 == bucket[iLoc][1] || num[i] > bucket[iLoc][1])
    {
      bucket[iLoc][1] = num[i];
    }
  }
  //debug
  /*
  for (i = 0; i < iBucketNum; ++i)
  {
    printf("%d %d %d\n", i, bucket[i][0], bucket[i][1]);
  }
  */
  int iMaxGap = 0, j=0;
  i=0;
  while(i < iBucketNum)
  {
    while(i < iBucketNum && -1 == bucket[i][1])i++;
    j=i+1;
    while(j < iBucketNum && -1 == bucket[j][0])j++;
    if (j < iBucketNum && -1 != bucket[i][1] && -1 != bucket[j][0] && bucket[j][0]-bucket[i][1] > iMaxGap)
    {
      iMaxGap = bucket[j][0]-bucket[i][1];
    }
    i=j;
  }
  for (i = 0; i < iBucketNum; ++i)
  {
    free(bucket[i]);
  }
  free(bucket);
  return iMaxGap;
}

/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form. Try to solve it in linear time/space. Return 0 if the array contains less than 2 elements. You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range. Credits: Special thanks to @porker2008 for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Sort
*/
