import numpy as np

#Create 2 (3x3) matrices
mat1 = np.random.randint(1,51,size=(3,3))
mat2 = np.random.randint(1,51,size=(3,3))

print("Matrix 1:")
print(mat1)
print("Matrix 2:")
print(mat2)

#Matrix addition
sum_matrix = np.add(mat1,mat2)
print("Sum of 2 matrices: ")
print(sum_matrix)

#Matrix Subtraction
diff_matrix = np.subtract(mat1,mat2)
print("Difference of 2 matrices: ")
print(diff_matrix)

#Matrix multiplication
product_matrix = np.multiply(mat1,mat2)
print("Multiplication of 2 matrices: ")
print(product_matrix)

#Transpose of matrix
transposed_mat1 = np.transpose(mat1)
transposed_mat2 = np.transpose(mat2)

print("Transposed matrix 1: ")
print(transposed_mat1)

print("Transposed matrix 2: ")
print(transposed_mat2)

#Determinant and inverse
determinant_mat1 = np.linalg.det(mat1)
inverse_mat1 = np.linalg.inv(mat1)

print("Determinant of matrix 1: ", determinant_mat1)
print("Inverse of matrix 1:")
print(inverse_mat1)

determinant_mat2 = np.linalg.det(mat2)
inverse_mat2 = np.linalg.inv(mat2)

print("Determinant of matrix 2: ", determinant_mat2)
print("Inverse of matrix 2:")
print(inverse_mat2)