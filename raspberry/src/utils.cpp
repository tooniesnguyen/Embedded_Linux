#include "utils.h"

int rand_num(int min, int max) {
    return min + rand() % (max - min + 1);
}
