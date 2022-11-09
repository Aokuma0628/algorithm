#include <stdio.h>

int lower_bound(
  int a[],
  int n,
  int x
)
{
    int l = 0;
    int h = n;
    while (l < h) {
      int mid = l + (h - l) / 2;
      printf("l=%d h=%d mid=%d a[mid]=%d\n", l,h,mid,a[mid]);
      if (x <= a[mid]) {
        h = mid;
      } else {
        l = mid + 1;
      }
    }

    return l;
}

