template<class U, class V>
struct is_same {
	static const bool value = false; 
};

template<class T>
struct is_same<T, T> {
	static const bool value = true; 
};
