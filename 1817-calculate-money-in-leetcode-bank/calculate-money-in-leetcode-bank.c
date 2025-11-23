int totalMoney(int n) {
    int weeks = n / 7;      // full weeks
    int days  = n % 7;      // remaining days

    // Sum for full weeks:
    // week 1: 1..7  -> 28
    // week 2: 2..8  -> 35
    // week k: k..(k+6) -> 7*(k+3)
    // sum_{k=1..weeks} 7*(k+3) = 7*(weeks*(weeks+1)/2 + 3*weeks)
    int fullWeeksSum = 7 * (weeks * (weeks + 1) / 2 + 3 * weeks);

    // Sum for remaining days in the next week:
    // starts at (weeks + 1) and increases by 1 each day
    // arithmetic series: days * (2*start + (days-1)) / 2
    int start = weeks + 1;
    int remainingSum = days * (2 * start + (days - 1)) / 2;

    return fullWeeksSum + remainingSum;
}
