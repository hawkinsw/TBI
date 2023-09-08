#include <__config>
#include <cstdint>

const int RETURN_VALUE{0x5f};

template <typename T>
T *set_tbi_tag(T *ptr) {
	uintptr_t mask = (uintptr_t)(0xac) << 56;
	return (T*)(((uintptr_t)ptr) | mask);
}

template <typename T>
T *unset_tbi_tag(T *ptr) {
	uintptr_t mask = ((uintptr_t)(-1) << 8) >> 8;
	return (T*)(((uintptr_t)ptr) & mask);
}

template <typename T>
T *get() {
	return new T{};
}

template <typename T>
void forget(T *to_forget) {
	delete to_forget;
}

int main() {
	auto *ptr = get<int>();

	ptr = set_tbi_tag(ptr);

	// determine that it is still usable.
	*ptr = 0x77;

	forget(unset_tbi_tag(ptr));
	return RETURN_VALUE;
}
