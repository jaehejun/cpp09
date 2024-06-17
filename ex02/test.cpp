merge-insertion sort performs the following steps, on an input X of n elements.

1. Group the elements of X into [n/2] pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
2. Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.
3. Recursively sort the [n/2] larger elements from each pair, creating a sorted sequence S of [n/2] of the input elements, in ascending order.
4. Insert at the start of S the element that was paired with the first and smallest element of S.
5. Insert the remaining [n/2] - 1 elements of X \ S into S, one at a time, with a specially chosen insertion ordering described below. 
Use binary search in subsequences of S (as described below) to determine the position at which each element should be inserted.

The algorithm is designed to take advantage of the fact that the binary searches used to insert elements into S are most efficient (from the point of view of worst case analysis) when the length of the subsequence that is searched is one less than a power of two. 
This is because, for those lengths, all outcomes of the search use the same number of comparisons as each above (before inserting the remaining elements), and let Xi denote the ith element of this sorted sequence.
Thus, S = (x1, x2, x3, ...),
where each element xi with i >= 3 is paired with an element yi < xi that has not yet been inserted.(there are no elements y1 or y2 because x1 and x2 were paired with each other.)
If n is odd, the remaining unpaired element should also be numbered as yi with i larger than the indexes of the paired elements. Then, the final step of the outline above can be expanded into the following steps.
 - Partitioning the uninserted elements yi into groups with contiguous indexes. There are two elements y3 and y4 in the first group, and the sums of sizes of every two adjacent groups form a sequence of powers of two.
 Thus, the sizes of groups are : 2, 2, 6, 10, 22, 42, ...
 - Order the uninserted elements by their groups(smaller indexes to larger indexes), but within each group order them from larger indexes to smaller indexes. Thus, the ordering becomes
 y4, y3, y6, y5, y12, y11, y10, y9, y8, y7, y22, y21 ...
 - Use this ordering to insert the elements yi into S. For each element yi, use a binary search from the start of S up to but not including xi to determine where to insert yi.