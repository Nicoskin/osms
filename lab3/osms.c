#include <stdio.h>
#include <math.h>

int Corr(int a[], int b[], int n) {
    int p = 0;
    for (int i = 0; i < n; i++) {
        p += a[i] * b[i];
    }
    return p;
}

double Corr2(int a[], int b[], int n) {
    float p = 0;
    int a_2 = 0;
    int b_2 = 0;

    for (int i = 0; i < n; i++) {
        p += a[i] * b[i];
        a_2 += a[i];
        b_2 += b[i];
    }
    
    return (p / (sqrt(pow(a_2,2)) * sqrt(pow(b_2,2))));
}

int main() {
    int a[] = {2, 3, 6, -1, -4, -2, 2, 5};
    int b[] = {2, 5, 8, 10, 4, -3, -1, 2};
    int c[] = {-3, -1, 3, -7, 2, -8, 5, -1};

    int n = sizeof(a) / sizeof(a[0]);
    
    int ab = Corr(a, b, n);
    int bc = Corr(b, c, n);
    int ac = Corr(a, c, n);
    printf("Корреляция между a, b и с\n");
    printf("  | a | b | c |\n");
    printf(" a| - |%d |%d |\n",ab,ac);
    printf(" b|%d | - |%d|\n",ab,bc);
    printf(" c|%d |%d| - |\n",ac,bc);
    
    
    float ab_2 = Corr2(a, b, n);
    float bc_2 = Corr2(b, c, n);
    float ac_2 = Corr2(a, c, n);
    printf("Нормализованная корреляция между a, b и с\n");
    printf("  |  a   |  b  |  c  |\n");
    printf(" a|   -  |%.2f |%.2f |\n",ab_2,ac_2);
    printf(" b| %.2f |  -  |%.2f|\n",ab_2,bc_2);
    printf(" c| %.2f |%.2f|  -  |\n",ac_2,bc_2);
    
    return 0;
}
