#include <cmath>

static const int DAILY_HOURS = 8;
static const int MONTHLY_DAYS = 22;

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return DAILY_HOURS * hourly_rate;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    double new_percent = 1 - discount/100;
    return before_discount * new_percent;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    double new_hourly_rate = apply_discount(hourly_rate, discount);
    double calc_daily_rate = daily_rate(new_hourly_rate);
    return std::ceil(MONTHLY_DAYS * calc_daily_rate);
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double new_hourly_rate = apply_discount(hourly_rate, discount);
    double calc_daily_rate = daily_rate(new_hourly_rate);
    return std::floor(budget / calc_daily_rate);
}