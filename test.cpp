#include <iostream>
#include <type_traits>

#define make_fn_trait(trait) \
template<typename T> typename std::enable_if<std::trait<T>::value>::type \
foo(T x) { std::cout << #trait << std::endl; }


make_fn_trait(is_integral)
make_fn_trait(is_floating_point)
make_fn_trait(is_pointer)

std::nullptr_t a;

#define pr_expr(e) std::cout << #e << " = " << (e) << std::endl;

int main(void) {
    foo(6);
    foo(0.5);
    foo(main);

    pr_expr(!NULL == !bool(a));



    return 0;
}
