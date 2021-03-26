import approximath as am
import sys
import math

print("")

assert 'approximath' in sys.modules, "Failed to load the approximath module.\n"

with open("../data/dataset_0.txt", "r") as infile:
    for line in infile:
        value = float(line.strip())

        print("1/sqrt({}) = ".format(value))
        
        # Compute the values.
        approximated = abs(am.drsqrt(value, 4))
        exact        = 1 / math.sqrt(value)

        # Print the computed values.

        # At least a precisition to the six-th digit.
        approximated = round(approximated, 6)
        exact        = round(exact, 6)

        # Print the rounded values.
        print("    approximated = {}".format(approximated))
        print("    exact        = {}".format(exact))

        if approximated != exact:
            print("Error is too great!\n")
            sys.exit(1)

print("Errors were acceptable!\n")
sys.exit(0)