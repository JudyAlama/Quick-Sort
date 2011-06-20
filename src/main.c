#include <stdio.h>

int DEBUG = 1;

/*
 * return higher
 */
int
pivot_picker(int num1, int num2, int num[])
{
    return (num[num1] <= num[num2] ? num1 : num2);
}

void
print_nums(int begin, int end, int nums[])
{
    int i;

    for (i = begin; i < end - 1; i++) {
        printf("%d, ", nums[i]);
    }
    printf("%d\n", nums[end]);
}

int
quicksort(int head, int tail, int num[])
{
    int l = head, r = tail;
    int l_hit, r_hit;
    int tmp;
    int pivot = pivot_picker(head, head + 1, num);
    int rval;
    
    if (DEBUG != 0)
        print_nums(head, tail, num);

    // swap pivot
    tmp = num[pivot];
    num[pivot] = num[head];
    num[head] = tmp;
    l++;

    while (l < r) {
        l_hit = 0;
        r_hit = 0;
        for (l = l; l < tail + 1; l++) {
            if (num[l] >= num[head]) {
                l_hit = 1;
                if (DEBUG != 0)
                    printf("%d(l = %d)\n", num[l], l);
                break;
            } else if (l == r) {
                break;
            }
        }
        for (r = r; r > head - 1; r--) {
            if (num[r] < num[head]) {
                r_hit = 1;
                if (DEBUG != 0)
                    printf("%d(r = %d)\n", num[r], r);
                break;
            } else if (l == r) {
                break;
            }
        }
        if (l_hit == 1 && r_hit == 1) {
            tmp = num[r];
            num[r] = num[l];
            num[l] = tmp;
        } else if (l_hit == 1 && r_hit == 0) {
            tmp = num[head];
            num[head] = num[l];
            num[l] = tmp;
            l--;
            r--;
            break;
        } else if (l_hit == 0 && r_hit == 1) {
            tmp = num[head];
            num[head] = num[r];
            num[r] = tmp;
            l--;
            r--;
            break;
        }

        l++;
        r--;
    }

    if (DEBUG != 0) {
        printf("pivot = %d, l = %d, r = %d\n", num[head], l, r);
        print_nums(head, tail, num);
    }

    //quicksort();
    if (l == head)
        rval = quicksort(head, l, num);
    if (r == tail)
        rval = quicksort(r, tail, num);

    return 0;
}

int
main(int argc, char* argv[])
{
    int n_nums1, n_nums2;
    int nums1[] = {49, 10, 6, 30, 50, 2, 17};
    int nums2[] = {8, 49, 10, 6, 30, 50, 2, 17};
    int rval;

    n_nums1 = sizeof nums1 / sizeof nums1[0];
    n_nums2 = sizeof nums2 / sizeof nums2[0];

    print_nums(0, n_nums1 - 1, nums1);
    print_nums(0, n_nums2 - 1, nums2);

    rval = quicksort(0, n_nums1 - 1, nums1);
    rval = quicksort(0, n_nums2 - 1, nums2);

    print_nums(0, n_nums1 - 1, nums1);
    print_nums(0, n_nums2 - 1, nums2);

    return 0;
}
