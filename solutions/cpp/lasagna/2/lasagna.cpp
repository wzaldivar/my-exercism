static const int LASAGNA_OVEN_TIME = 40;
static const int LAYER_PREPARATION_TIME = 2;

// ovenTime returns the amount in minutes that the lasagna should stay in the
// oven.
int ovenTime() {
    return LASAGNA_OVEN_TIME;
}

/* remainingOvenTime returns the remaining
   minutes based on the actual minutes already in the oven.
*/
int remainingOvenTime(int actualMinutesInOven) {
    return LASAGNA_OVEN_TIME - actualMinutesInOven;
}

/* preparationTime returns an estimate of the preparation time based on the
   number of layers and the necessary time per layer.
*/
int preparationTime(int numberOfLayers) {
    return LAYER_PREPARATION_TIME * numberOfLayers;
}

// elapsedTime calculates the total time spent to create and bake the lasagna so
// far.
int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    return preparationTime(numberOfLayers) + actualMinutesInOven;
}
