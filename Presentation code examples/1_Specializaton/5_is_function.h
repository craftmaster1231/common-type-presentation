template<class T>
struct is_function {
	static const bool value = not std::is_const<const T>::value; //Only functions and references have this trait
};

template<class T>
struct is_function<T&> { //Filtering out l-references
	static const bool value = false;
};

template<class T>
struct is_function<T&&> { //Filtering out r-references
	static const bool value = false;
};
