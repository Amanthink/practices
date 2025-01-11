class Solution {
  public:
    bool isLucky(int n) {
        int position = n; // Start with the given number
        int step = 2;     // Start removing every 2nd number in the first step

        while (step <= position) {
            // If the number is divisible by the current step, it's removed
            if (position % step == 0) {
                return false;
            }

            // Recalculate the position after removing numbers
            position = position - (position / step);

            // Move to the next step
            step++;
        }

        return true; // If the number survives all rounds, it's lucky
    }
};
