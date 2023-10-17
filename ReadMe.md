# Week 3 Lab: Verification

1. What testing strategy did you adopt for this Exercise2? What decisions did you have to make and how did you come up with your answers?
My strategy was to randomly generate the "initial" input from the entire range, for each test, and inside each test, I implemented 10 tests. The numbers of tests was initialized to be 200 to get make sure the test is encompassing of all cases.

2. How does testing a Don't Care work? What must be done to ensure the input truly has no effect on output?
To test that a Don't Care work, we need to make sure that everything else in the system works exactly accordingly regardless of the value of the Don't Care Variable; this means that other than testing the other variables, we need to test a good quantity of random values for the Don't Care variable to ensure that it is actually insignificant to the output.
