# Quicksort-Benchmark
Exploring ways to improve the performance of quicksort

See quicksort_observations.md for report

## About the Project
This was part of an assignment I completed for 31251 Data Structures and Algorithms at UTS. The aim was to explore ways of improving the performance of a basic quicksort algorithm.

## Variations Tested
- lomuto: Lomuto partitioning
- insertion-base: above + insertion sort fallback with threshold 10*
- median-of-3: above + median-of-3 pivot selection
- hoare: above + replace lomuto partitioning with Hoare partitioning
- std::sort is also included for reference

*Different thresholds were also tested to determine which was optimal (included in report)

## Testing Methodology
Each variation was timed sorting vectors of random integers, already-sorted integers, and all-zero integers. Each test was run in at least 10 sets (pressing "run") of 10 (to avoid Ed's time and output limits and since there were often significant discrepancies between sets), with the average of each set recorded. The best average that appeared multiple times was taken as the final measurement. All tests were run on the Ed VM.

## Notes
- GoogleTest was used for verification of the sorting algorithms. It is included in the source code, but is not required to run the benchmark and can safely be removed.
