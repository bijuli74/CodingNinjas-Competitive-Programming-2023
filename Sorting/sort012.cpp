void sort012(int *arr, int n)
{
  int f[3] = { 0 };
  for (int i = 0; i < n; ++i) f[arr[i]]++;
  int i=0;
  while(i<n){
    for (int num = 0; num < 3; num++) {
      for (int j = 0; j < f[num]; ++j)
        arr[i++] = num;
    }
  }
}
