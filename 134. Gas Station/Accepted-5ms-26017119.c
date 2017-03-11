// 134. Gas Station
// https://leetcode.com/problems/gas-station/
// 

int canCompCir(int gas[], int cost[], int start, int n, int* next)
{
	int gasCur = gas[start], total = n;
	while(total--)
	{
		gasCur -= cost[start];
		start = (start+1)%n;
		if (gasCur < 0)
		{
			*next = start;
			return -1;
		}
		gasCur += gas[start];
	}
	return 0;
}

int canCompleteCircuit(int gas[], int cost[], int n) 
{
	int i, next, counter = 0;
	for (i = 0; i < n;)
	{
		int ret = canCompCir(gas, cost, i, n, &next);
		if (0 == ret)
		{
			return i;
		}
		i = next;
		if (++counter > n)
		{
			return -1;
		}
	}
}

/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i]. You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations. Return the starting gas station's index if you can travel around the circuit once, otherwise return -1. Note: The solution is guaranteed to be unique. Subscribe to see which companies asked this question. Show Tags Greedy
*/
