#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 64비트 랜덤 숫자 생성
uint64_t random64(uint32_t * seed) {
    uint64_t result;
    // 8비트 짜리 랜덤 숫자 8개 생성
    uint8_t * result8 = (uint8_t *)&result;
    for (size_t i = 0; i < sizeof(result); i++) {
        result8[i] = rand_r(seed);
    }
    return result;
}

// 각 자릿수를 제곱하고, 그 값을 모두 더함
uint64_t sum_digits_squared(uint64_t num) {
    uint64_t total = 0;
    while(num > 0) {
        uint64_t num_mod_base = num % 10;
        total += num_mod_base * num_mod_base;
        num = num / 10;
    }
    return total;
}

// 무한 루프를 통해 num의 값이 1 혹은 4가 될때까지 sum_digits_squared 를 계속 실행
bool is_happy(uint64_t num) {
    while(num != 1 && num != 4) {
        num = sum_digits_squared(num);
    }
    return num == 1;
}

int main() {
    uint32_t seed = time(NULL);
    int count = 0;
    for (int i = 1; i < 100;i++) {
        uint64_t random_num = is_happy(random64(&seed));
        printf("%" PRIu64 " ", random_num);
        count++;
    }
    printf("\ncount %d\n", count);
    return 0;
}
