template<class T>
struct remove_extent {
	using type = T;
};

template<class T, auto N>
struct remove_extent<T[N]> {
	using type = T;
};

template<class T>
struct remove_extent<T[]> {
	using type = T;
};
