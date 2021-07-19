template<class...>
using void_t = void;

#include<utility>
#include<vector>

static_assert(std::is_same_v<void_t<char, int, decltype(std::vector<int>{}.begin())>, void>);
