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

int main() {
    uint32_t seed = time(NULL);
    int count = 0;
    for (int i = 1; i < 10;i++) {
        uint64_t random_num = random64(&seed);
        printf("%" PRIu64 " ", random_num);
        count++;
    }
    printf("\ncount %d\n", count);
    return 0;
}
