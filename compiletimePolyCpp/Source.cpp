#include <stdexcept>
#include <type_traits>


template<typename T>//template
T mean(const T* values, size_t length) {
	static_assert(std::is_default_constructible<T>(),
		"Type must be default constructible.");// in case concepts dont work
	T result{};
	for (int i = 0; i < length;i++)
	{
		result += values[i];
	}
	return result / length;

}

template<typename T>
requires std::is_copy_constructible<T>::value
T get_copy(T* pointer) {
	if (!pointer) throw std::runtime_error{ "Null-pointer dereference" };
	return *pointer;
}

struct highLander {
	highLander() = default;
	highLander(const highLander&) = delete;
};

void test_req() {

	highLander connor; 
	auto connor_ptr = &connor; 
	auto connor_copy = get_copy(connor_ptr);
}

//template<typename T>
//concept bool Averageable() {
//	return std::is_default_constructible<T>::value u
//		&& requires (T a, T b) {
//			{ a += b } -> T; v
//			{ a / size_t{ 1 } } -> T; w
//	};
//}

//template<Averageable T>
//T mean(T* values, size_t length) {
//	T result{};
//		for (size_t i{}; i < length; i++) {
//			result += values[i];
//		}
//	return result / length;
//}


void test_temp() {
	const double nums_d[] = { 1.0,2.0,3.0,4.0,5.0 };
	const auto result1 = mean<double>(nums_d, 5);
	printf("double:%f", result1);

	const float nums_f[] = { 1.0f,2.0f,3.0f,4.0f };
	const auto result2 = mean<float>(nums_f, 4);
	printf("Float:%f", result2);

	const char nums_c[] = { 'a','b','c','d' };
	const auto result3 = mean<char>(nums_c, 4);
	printf("char:%c", result3);
	

}
int main() {

	//test_temp();

	return 0; 

}