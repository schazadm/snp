#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 10

int main(void) {
    double conversionRate;
    (void)printf("Enter conversion rate (1.00 BTC -> CHF): ");
    scanf("%lf", &conversionRate);
    for(int i = 1; i < NUM_ROWS; i++) {
        int chf = i*200;
        double btc = chf/conversionRate;
        (void)printf("%d\tCHF\t\t<-->\t\t%lf BTC\n", chf, btc);
    }
    return EXIT_SUCCESS;
}
