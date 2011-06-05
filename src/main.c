#include <stdio.h>

int quicksort (int numsc, int numsv[]) {
    int i;
    int l = 0, r = numsc -1;
    int lastl, lastr;
    int tmp;
    int pivot = (numsv[0] <= numsv[1] ? numsv[0] : numsv[1]);
    int solve[numsc];
    
    for (i = 0; i < numsc; i++) {
        printf("%d, ", numsv[i]);
    }
    printf("\n");

    while (l < r) {
        for (l = l; l < numsc; l++) {
            if (numsv[l] >= pivot) {
                printf("%d(l = %d)\n", numsv[l], l);
                break;
            }
        }
        for (r = r; r > 0; r--) {
            if (numsv[r] < pivot) {
                printf("%d(r = %d)\n", numsv[r], r);
                break;
            }
        }

        tmp = numsv[r];
        numsv[r] = numsv[l];
        numsv[l] = tmp;

        l++;
        r--;
    }

    printf("pivot = %d, l = %d, r = %d\n", pivot, l, r);
    for (i = 0; i < numsc; i++) {
        printf("%d, ", numsv[i]);
    }
    printf("\n");

    return 0;
}


int main (int argc, char** argv) {
    int nums[] = {49, 10, 6, 30, 50, 2, 17};
    int nums2[] = {8, 49, 10, 6, 30, 50, 2, 17};
    int rval;

    rval = quicksort(sizeof nums / sizeof nums[0], nums);
    rval = quicksort(sizeof nums / sizeof nums2[0], nums2);

    return rval;

}
