#include <utility>
template< class T, class = void, class... Args>
struct is_constructible_impl {
	static const bool value = false;
};

template<class T, class... Args>
struct is_constructible_impl<T, std::void_t<decltype(T(std::declval<Args>()...))>, Args...> {
	static const bool value = true;
};

template<class T, class... Args>
struct is_constructible : is_constructible_impl<T, void, Args...> { };


#include<memory>

static_assert(is_constructible<std::unique_ptr<int>, int*>::value);

static_assert(not is_constructible<std::unique_ptr<int>, char*>::value);
