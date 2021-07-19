#include<utility>

template<class U, class V>
using cond_t = decltype(false? std::declval<U>() : std::declval<V>());

template<class...>
struct common_type { };

template<class T>
struct common_type<T> : common_type<T,T> { };

template<class U, class V, class = void>
struct common_type_2_impl { };

template<class U, class V>
struct common_type_2_impl<U, V, std::void_t<cond_t<U, V>>> {
    using type = cond_t<U, V>;
};

template<class U, class V>
struct common_type<U, V> : common_type_2_impl<std::decay_t<U>, std::decay_t<V>> { };

template<class AlwaysVoid, class U, class V, class... Args>
struct common_type_multi_impl { };

template< class U, class V, class... Args>
struct common_type_multi_impl<std::void_t<typename common_type<U, V>::type>, U, V, Args...>
        : common_type<typename common_type<U,V>::type,Args...> { };

template<class U, class V, class... Args>
struct common_type<U, V, Args...> : common_type_multi_impl<void, U, V, Args...> {};


#include<utility>

static_assert(std::is_same_v<common_type<bool,char>::type,int>);

