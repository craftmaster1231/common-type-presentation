struct Special {
	Special(int) {}
	Special() = delete;
};

template<class T>
struct container {
	T content{};
};

template<>
struct container<Special> {
	Special content{0};
};
