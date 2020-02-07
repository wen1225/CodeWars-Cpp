/*  
Problem: Implement a function called exchange that takes in argument as an array of
		 integers and modify it so that the smallest and largest value are exchanged.
		 Assume that there is at least one element. If the largest value occur more
		 than once, exchange the first instance. Similarly, if the smallest value
		 occurs more than once, exchange the last instance.

Origin:  First quiz in CS49J class. Had the option to choose C, C++, or
		 Python. 

Notes:	 Can still be refactor to simplify logic.

Time to Solve: ~1 day. 1/27/20 - 1/28/20
*/

#include <iostream>
#include <string>
#include <vector>

void ft_first_largest(std::vector<int>& a, int& b, int& b_index)
{
	for(unsigned int i = 0; i < a.size(); i++)
	{
		if (a[i] >= a[i+1])
		{
			if (a[i] > b)
			{
				b = a[i];
				b_index = i;
			}
		}
		else
		{
			if (a[i+1] > b)
			{
				b = a[i+1];
				b_index = i + 1;
			}
		}
	}
}

void ft_last_smallest(std::vector<int>& a, int& s, int& s_index)
{
	for(unsigned int i = a.size() - 1; i > 0; i--)
	{
		if (a[i-1] <= a[i])
		{
			if (a[i-1] < s)
			{
				s = a[i-1];
				s_index = i - 1;
			}
		}
		else
		{
			if (a[i] < s)
			{
				s = a[i];
				s_index = i;
			}
		}
	}
}

void exchange(std::vector<int>& a)
{
	if (a.size() == 1)
	return;
	
	//find first encountered largest element
	int b, b_index;
	b = b_index = 0;
	ft_first_largest(a, b, b_index);

	//find last encountered smallest element
	int s, s_index;
	s_index = a.size() - 1;
	s = a[s_index];
	ft_last_smallest(a, s, s_index);

	//swap
	a[b_index] = s;
	a[s_index] = b;
}

int main()
{
	std::vector<int> a;
	a.push_back(4);
	a.push_back(2);
	a.push_back(1);
	a.push_back(1);
	a.push_back(5);
	
	exchange(a);
	for(unsigned int i = 0; i < a.size(); i++)
	{
	  std::cout << a[i] << " "; 
	}

	return 0;
}
