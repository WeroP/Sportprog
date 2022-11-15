#include <iostream>
#include <set>
#include <vector>

std::set<int> convertToSet(std::vector<int> v)
{
	std::set<int> s;
	copy(v.begin(),v.end(),std::inserter(s, s.end()));
	return s;
}

int main() {
	int a;
	int b;
	int c;
	int res = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	std::vector<int> v1;

	int tmp = 0;

	std::set<int> s2;
	std::set<int> s2c;
	std::set<int> s3;
	std::set<int> s3c;

	for (size_t i = 0; i < a; i++)
	{
		std::cin >> tmp;
		v1.push_back(tmp);
	}
	for (size_t i = 0; i < b; i++)
	{
		std::cin >> tmp;
		s2.emplace(tmp);
	}
	s2c.insert(s2.begin(), s2.end());
	for (size_t i = 0; i < c; i++)
	{
		std::cin >> tmp;
		s3.emplace(tmp);
	}
	s3c.insert(s3.begin(), s3.end());

	if (a < b)
	{
		s2.clear();
		s2.insert(v1.begin(),v1.end());
		v1.clear();
		std::copy(v1.begin(), v1.end(), std::back_inserter(s2c));
		s2c.clear();
		s2c.insert(v1.begin(), v1.end());
	} else if (a < c){
		s3.clear();
		s3.insert(v1.begin(), v1.end());
		v1.clear();
		std::copy(v1.begin(), v1.end(), std::back_inserter(s3c));
		s3c.clear();
		s3c.insert(v1.begin(), v1.end());
	}

	for (size_t i = 0; i < v1.size() - 2; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			s2.emplace(v1[i+j]);
		}
		for (size_t j = 0; j < 3; j++)
		{
			s3.emplace(v1[i+j]);
		}

		if (s2.size() == b)
		{
			res++;
		}
		if (s3.size() == c)
		{
			res++;
		}
		s2.clear();
		s3.clear();

		s2.insert(s2c.begin(),s2c.end());
		s3.insert(s3c.begin(),s3c.end());
	}

	if (res != 0)
	{
		res++;
	}
	std::cout << res;
}
