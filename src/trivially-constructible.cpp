#include <string>

namespace sanitizer_impl {

    template <typename T>
    constexpr bool IsTriviallyCopyable()
    {
        return static_cast<bool>(std::is_trivially_copy_constructible<T>::value &&
            (std::is_trivially_copy_assignable<T>::value ||
                !std::is_copy_assignable<T>::value) &&
            std::is_trivially_destructible<T>::value);
    }

}