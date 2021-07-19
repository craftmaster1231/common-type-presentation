template<bool b, class IfTrue>
struct enable_if;

template<class IfTrue>
struct enable_if<true,IfTrue> {
	using type = IfTrue;
};

template<class IfTrue>
struct enable_if<false,IfTrue> { }
