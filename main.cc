#include <cstdlib>

constexpr const char *number(const char *const sentence) {
    return sentence == nullptr || sentence[0] == '\0'
               ? nullptr
               : sentence[0] <= '9' && sentence[0] >= '0' ? sentence : number(sentence + 1);
}

constexpr int toi(const char *const number) {
    return number + 1 == nullptr || number[1] == '\0' || number[1] > '9' || number[1] < '0'
               ? number[0] - '0'
               : ((number[0] - '0') * 10) + toi(number + 1);
}

static_assert(toi("1") == 1, "1 didnt convert");
static_assert(toi("10") == 10, "10 didnt convert");
static_assert(toi("31") == 31, "31 didnt convert");
static_assert(toi("31  ") == 31, "31   didnt convert");
static_assert(toi("31f") == 31, "31f didnt convert");
static_assert(toi("1f") == 1, "1 didnt convert");

constexpr bool december(const char *str) { return str[0] == 'D' && str[1] == 'e' && str[2] == 'c'; }

int main(int, char **) {
    constexpr auto *d = __DATE__;
    constexpr auto *n = number(d);
    constexpr auto day = toi(number(n));
    constexpr auto is_dec = december(d);
    constexpr auto christmas_day = day == 25 && is_dec;
    return christmas_day ? EXIT_SUCCESS : EXIT_FAILURE;
}
