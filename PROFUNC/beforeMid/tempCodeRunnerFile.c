void LV4() {
    int p, n;
    printf("Input round: ");
    scanf("%d", &p);
    printf("Input size: ");
    scanf("%d", &n);

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < j; k++) {
                printf(" ");
            }
            printf("*\n");
        }
        printf("\n");
    }
}
