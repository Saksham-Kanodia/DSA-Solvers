import numpy as np
# NumPy works on arrays, not single values and it does operations on the whole array at once (vectorization)
# numpy is a library.

#Created a 2D Numpy Array
#Each element is random between 1 and 50
arr = np.random.randint(1,51,size=(3,4))
print(arr)

#NumPy gives direct functions to calculate mean, median, standard derivation.(this is vectorization)
mean_val = np.mean(arr)
median_val = np.median(arr)
std_val = np.std(arr)

print("Mean: " , mean_val)
print("Median: ", median_val)
print("Standard Deviation: ", std_val)

#print sum of all elements and sum of each row
total_sum= np.sum(arr)
row_sum = np.sum(arr,axis=1)

print("Total Sum: ", total_sum)
print("Row Sum: ", row_sum)

#reshape arr into (2,6)
reshaped_arr = arr.reshape(2,6)
print("Reshaped Array: ", reshaped_arr)

