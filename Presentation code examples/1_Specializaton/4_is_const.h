template<class T>
struct is_const {
	static const bool value = false;
};

template<class T>
struct is_const<const T> {
	static const bool value = true;
};
