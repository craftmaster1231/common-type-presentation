template<class T>
T&& declval() {};


#include<utility>

static_assert(std::is_same_v<decltype(declval<int>()),int&&>);

static_assert(std::is_same_v<decltype(declval<char&>()),char&>);



#include<vector>

static_assert(std::is_same_v<
	decltype(declval<std::vector<int>>().begin()),
	std::vector<int>::iterator>
);
