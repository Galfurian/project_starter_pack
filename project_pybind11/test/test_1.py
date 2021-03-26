import approximath as am
import sys
import math

print("")

assert 'approximath' in sys.modules, "Failed to load the approximath module.\n"

for i in range(0, 5):
    print(i," : ", am.drsqrt(1.5, i))

# Compute the values.
approximated = abs(am.drsqrt(1.5, 4))
exact        = 1 / math.sqrt(1.5)

# Print the computed values.
print("Approximated = {}".format(approximated))
print("Exact        = {}".format(exact))

# At least a precisition to the six-th digit.
approximated = round(approximated, 6)
exact        = round(exact, 6)

# Print the rounded values.
print("Rounded approximated = {}".format(approximated))
print("Rounded exact        = {}".format(exact))

if approximated != exact:
    print("Error is too great!\n")
    sys.exit(1)
else:
    print("Error is acceptable!\n")
    sys.exit(0)
