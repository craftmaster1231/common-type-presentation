template<class T>
struct is_array {
	static const bool value = false;
};

template<class T>
struct is_array<T[]> { // Specialization for unknown length array type
	static const bool value = true;
};

template<class T, auto N>
struct is_array<T[N]> { // Specialization for length-known array type
	static const bool value = true;
};
