/*11. Container With the Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n
vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.*/
#include <vector>
#include <iostream>
using namespace std;

int maxArea(vector<int>& height);

int main() {
	vector<int> height;
	int num;

	cout << "Enter a set of set of heights \n";
	cout << "Enter a non-number key to exit \n";

	while (cin >> num)
	{
		height.push_back(num);
		cin.clear();
	}

	int area = maxArea(height);
	cout << "Maximum Area: " << area << "\n";
	return 0;
}

int maxArea(vector<int>& height) {
	int max1 = 0;
	int max2 = height.size() - 1;
	int area = 0;
	int curArea = 0;

	while (max1 < max2)
	{

		if (height.at(max1) >= height.at(max2))
		{
			curArea = ((max2)-(max1)) * height.at(max2);
		}
		else
		{
			curArea = ((max2)-(max1)) * height.at(max1);
		}

		if (curArea > area)
		{
			area = curArea;
		}

		if (height.at(max1) > height.at(max2))
		{
			max2--;
		}
		else
		{
			max1++;
		}

	}
	return area;
}