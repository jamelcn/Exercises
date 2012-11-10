int a[10] = { 5, 4, 1, 7, 9, 3, 8, 2, 6 };
int LEN=sizeof(a)/sizeof(a[0]);

void swap(int *a1, int *a2) 
{
    int temp;
    temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void print(int a[], int len)
{
    int i;
    for (i = 0; i < len; i++) {
    	printf("a[%d]: %d\t", i, a[i]);
    }
    printf("\n");
}
